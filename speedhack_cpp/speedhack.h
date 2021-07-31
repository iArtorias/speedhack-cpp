#pragma once

// MinHook (https://github.com/TsudaKageyu/minhook)
#include <minhook/MinHook.h>

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
        __clear_proc( QueryPerformanceCounter );
    }

private:

    // Local variables
    DWORD m_time{ 0 };
    ULONGLONG m_time64{ 0 };
    LARGE_INTEGER m_time_largeint{};
    double m_speed_multiplier{ 0.0 };

    // 'GetTickCount' hook
    static DWORD WINAPI hook_GetTickCount();


    // 'GetTickCount64' hook
    static ULONGLONG WINAPI hook_GetTickCount64();


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
            ((m_GetTickCount() - m_time64) * m_speed_multiplier));
    }


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
    __typedef_func( GetTickCount, DWORD );
    __typedef_func( GetTickCount64, ULONGLONG );
    __typedef_func( QueryPerformanceCounter, BOOL, LARGE_INTEGER* );


    /// <summary>
    /// Setup all the required API hooks for redirection
    /// </summary>
    /// <returns>Returns "true" upon success, "false" otherwise</returns>
    bool setup_hooks()
    {
        MH_STATUS status{ MH_ERROR_NOT_INITIALIZED };

        status = MH_Initialize();

        if (status != MH_STATUS::MH_OK)
            return false;

        // Create and enable 'GetTickCount' API hook
        status = MH_CreateHook(
            &GetTickCount,
            &hook_GetTickCount,
            reinterpret_cast<void**>(&m_GetTickCount) );

        if (status != MH_STATUS::MH_OK)
            return false;

        status = MH_QueueEnableHook( &GetTickCount );
        if (status != MH_STATUS::MH_OK)
            return false;


        // Create and enable 'GetTickCount64' API hook
        status = MH_CreateHook(
            &GetTickCount64,
            &hook_GetTickCount64,
            reinterpret_cast<void**>(&m_GetTickCount64) );

        if (status != MH_STATUS::MH_OK)
            return false;

        status = MH_QueueEnableHook( &GetTickCount64 );
        if (status != MH_STATUS::MH_OK)
            return false;


        // Create and enable 'QueryPerformanceCounter' API hook
        status = MH_CreateHook(
            &QueryPerformanceCounter,
            &hook_QueryPerformanceCounter,
            reinterpret_cast<void**>(&m_QueryPerformanceCounter) );

        if (status != MH_STATUS::MH_OK)
            return false;

        status = MH_QueueEnableHook( &QueryPerformanceCounter );
        if (status != MH_STATUS::MH_OK)
            return false;


        // Apply all the previously created hooks
        status = MH_ApplyQueued();
        if (status != MH_STATUS::MH_OK)
            return false;


        // Set the current time for 'GetTickCount', 'GetTickCount64' and 'QueryPerformanceCounter'
        m_time = hook_GetTickCount();
        if (m_time == 0)
            return false;

        m_time64 = hook_GetTickCount64();
        if (m_time64 == 0)
            return false;

        hook_QueryPerformanceCounter( &m_time_largeint );
        if (m_time_largeint.QuadPart == 0)
            return false;

        return true;
    }
};