#pragma once

// Detours (https://github.com/microsoft/Detours)
#include <detours/detours.h>

class CSpeedHack
{
protected:

    CSpeedHack() 
    {
        // Try reading the 'speedhack.txt' to obtain the speed multiplier for our speedhack
        std::wfstream stream( CProxyStub::instance().m_proxy_path / "speedhack.txt" );

        if (stream.good() || !stream.fail())
        {
            std::wstring _speed;
            std::getline( stream, _speed );

            if (!_speed.empty())
            {
                try
                {
                    size_t ldx;
                    auto speed = std::stod( _speed, &ldx );

                    m_speed_multiplier = speed;
                }
                catch (const std::invalid_argument&)
                {}
            }
        }
    };

    ~CSpeedHack()
    {
        __clear_proc( GetTickCount );
        __clear_proc( GetTickCount64 );
        __clear_proc( timeGetTime );
        __clear_proc( QueryPerformanceCounter );
    }

private:

    // Local variables
    DWORD m_time{ 0 };
    ULONGLONG m_time64{ 0 };
    DWORD m_time_get_time{ 0 };
    LARGE_INTEGER m_time_largeint{};
    double m_speed_multiplier{ 1.0 };


    // 'GetTickCount' hook
    static DWORD WINAPI hook_GetTickCount();


    // 'GetTickCount64' hook
    static ULONGLONG WINAPI hook_GetTickCount64();


    // 'timeGetTime' hook
    static DWORD WINAPI hook_timeGetTime();


    // 'QueryPerformanceCounter' hook
    static BOOL WINAPI hook_QueryPerformanceCounter( LARGE_INTEGER* lpPerformanceCount );


    // Sets the new value to return for 'GetTickCount'
    DWORD set_tick_count()
    {
        return static_cast<DWORD>(m_time +
            ((m_GetTickCount() - m_time) * m_speed_multiplier));
    }


    // Sets the new value to return for 'GetTickCount64'
    ULONGLONG set_tick_count64()
    {
        return static_cast<ULONGLONG>(m_time64 +
            ((m_GetTickCount64() - m_time64) * m_speed_multiplier));
    }


    // Sets the new value to return for 'timeGetTime'
    DWORD set_time_get_time()
    {
        return static_cast<DWORD>(m_time_get_time +
            ((m_timeGetTime() - m_time_get_time) * m_speed_multiplier));
    }

    #ifdef _WIN64
    // Gets a new place for the function hook (precisely for 'GetTickCount' and 'GetTickCount64')
    template<typename T>
    uint64_t check_instruction( T _func )
    {
        auto maybe_jmp = *(reinterpret_cast<unsigned char*>(_func));

        // Check if the first byte is equal to '0xEB', meaning there's a jump
        if (maybe_jmp == 0xEB)
        {
            auto address{ (reinterpret_cast<uint64_t>(_func)) };
            // new_address = old_address + delta + 2
            return (address + *(reinterpret_cast<unsigned char*>(address + 1)) + 2);
        }

        return 0;
    }
    #else
    // Gets a new place for the function hook (precisely for 'GetTickCount' and 'GetTickCount64')
    template<typename T>
    uint32_t check_instruction( T _func )
    {
        auto maybe_jmp = *(reinterpret_cast<unsigned char*>(_func));

        // Check if the first byte is equal to '0xEB', meaning there's a jump
        if (maybe_jmp == 0xEB)
        {
            auto address{ (reinterpret_cast<uint32_t>(_func)) };
            // new_address = old_address + delta + 2
            return (address + *(reinterpret_cast<unsigned char*>(address + 1)) + 2);
        }

        return 0;
    }
    #endif


    // Sets the new QuadPart value for 'QueryPerformanceCounter'
    void set_performance_counter( LARGE_INTEGER* perf_count )
    {
        LARGE_INTEGER _perf_count{};
        m_QueryPerformanceCounter( &_perf_count );

        perf_count->QuadPart = static_cast<LONGLONG>(m_time_largeint.QuadPart +
            ((_perf_count.QuadPart - m_time_largeint.QuadPart) * m_speed_multiplier));
    }

public:

    /// <summary>
    /// Gets the current 'CSpeedHack' class instance
    /// </summary>
    static CSpeedHack& instance()
    {
        static CSpeedHack instance;
        return instance;
    }


    // Resolve typedefs
    __typedef_func_winapi( GetTickCount, DWORD );
    __typedef_func_winapi( GetTickCount64, ULONGLONG );
    __typedef_func_winapi( timeGetTime, DWORD );
    __typedef_func_winapi( QueryPerformanceCounter, BOOL, LARGE_INTEGER* );


    /// <summary>
    /// Setup all the required API hooks for redirection
    /// </summary>
    /// <returns>Returns "true" upon success, "false" otherwise</returns>
    bool setup_hooks()
    {
        // Set the current time for 'GetTickCount', 'GetTickCount64', 'timeGetTime' and 'QueryPerformanceCounter'
        m_time = GetTickCount();
        if (m_time == 0)
            return false;

        m_time64 = GetTickCount64();
        if (m_time64 == 0)
            return false;

        m_time_get_time = timeGetTime();
        if (m_time_get_time == 0)
            return false;

        QueryPerformanceCounter( &m_time_largeint );
        if (m_time_largeint.QuadPart == 0)
            return false;

        auto inst_check = check_instruction( m_GetTickCount );
        if (inst_check > 0)
            m_GetTickCount = reinterpret_cast<GetTickCount_t>(inst_check);

        inst_check = check_instruction( m_GetTickCount64 );
        if (inst_check > 0)
            m_GetTickCount64 = reinterpret_cast<GetTickCount64_t>(inst_check);

        DetourTransactionBegin();
        DetourUpdateThread( GetCurrentThread() );
        DetourAttach( reinterpret_cast<PVOID*>(&m_GetTickCount), hook_GetTickCount );
        DetourAttach( reinterpret_cast<PVOID*>(&m_GetTickCount64), hook_GetTickCount64 );
        DetourAttach( reinterpret_cast<PVOID*>(&m_timeGetTime), hook_timeGetTime );
        DetourAttach( reinterpret_cast<PVOID*>(&m_QueryPerformanceCounter), hook_QueryPerformanceCounter );
        DetourTransactionCommit();

        return true;
    }

    /// <summary>
    /// Remove all the created hooks.
    /// </summary>
    void remove_hooks()
    {
        DetourTransactionBegin();
        DetourUpdateThread( GetCurrentThread() );

        if (m_GetTickCount != nullptr)
            DetourDetach( reinterpret_cast<PVOID*>(&m_GetTickCount), hook_GetTickCount );
        if (m_GetTickCount64 != nullptr)
            DetourDetach( reinterpret_cast<PVOID*>(&m_GetTickCount64), hook_GetTickCount64 );
        if (m_timeGetTime != nullptr)
            DetourDetach( reinterpret_cast<PVOID*>(&m_timeGetTime), hook_timeGetTime );
        if (m_QueryPerformanceCounter != nullptr)
            DetourDetach( reinterpret_cast<PVOID*>(&m_QueryPerformanceCounter), hook_QueryPerformanceCounter );

        DetourTransactionCommit();
    }
};