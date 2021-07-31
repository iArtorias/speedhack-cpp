#pragma once

namespace fs = std::filesystem;

class CProxyStub
{
protected:

    CProxyStub() {}
    ~CProxyStub()
    {
        __clear_proc( GetFileVersionInfoA );
        __clear_proc( GetFileVersionInfoByHandle );
        __clear_proc( GetFileVersionInfoExA );
        __clear_proc( GetFileVersionInfoExW );
        __clear_proc( GetFileVersionInfoSizeA );
        __clear_proc( GetFileVersionInfoSizeExA );
        __clear_proc( GetFileVersionInfoSizeExW );
        __clear_proc( GetFileVersionInfoSizeW );
        __clear_proc( GetFileVersionInfoW );
        __clear_proc( VerFindFileA );
        __clear_proc( VerFindFileW );
        __clear_proc( VerInstallFileA );
        __clear_proc( VerInstallFileW );
        __clear_proc( VerLanguageNameA );
        __clear_proc( VerLanguageNameW );
        __clear_proc( VerQueryValueA );
        __clear_proc( VerQueryValueW );
    }

private:

    // A list of supported proxy libraries
    std::vector<std::wstring> m_supported_proxies
    {
        L"version.dll",
        L"d3d8.dll",
        L"d3d9.dll"
    };

public:

    /// <summary>
    /// Gets the current 'CProxyStub' class instance
    /// </summary>
    static CProxyStub& instance()
    {
        static CProxyStub instance;
        return instance;
    }


    // A full path to the proxy library
    fs::path m_proxy_path{};


    // Resolve typedefs
    // 'version.dll'
    __typedef_func( GetFileVersionInfoA, BOOL, LPCSTR, DWORD, DWORD, LPVOID );
    __typedef_func( GetFileVersionInfoByHandle, BOOL, size_t, HANDLE, size_t, size_t );
    __typedef_func( GetFileVersionInfoExA, BOOL, DWORD, LPCSTR, DWORD, DWORD, LPVOID );
    __typedef_func( GetFileVersionInfoExW, BOOL, DWORD, LPCWSTR, DWORD, DWORD, LPVOID );
    __typedef_func( GetFileVersionInfoSizeA, DWORD, LPCSTR, LPDWORD );
    __typedef_func( GetFileVersionInfoSizeExA, DWORD, DWORD, LPCSTR, LPDWORD );
    __typedef_func( GetFileVersionInfoSizeExW, DWORD, DWORD, LPCWSTR, LPDWORD );
    __typedef_func( GetFileVersionInfoSizeW, DWORD, LPCWSTR, LPDWORD );
    __typedef_func( GetFileVersionInfoW, BOOL, LPCWSTR, DWORD, DWORD, LPVOID );
    __typedef_func( VerFindFileA, DWORD, DWORD, LPCSTR, LPCSTR, LPCSTR, LPSTR, PUINT, LPSTR, PUINT );
    __typedef_func( VerFindFileW, DWORD, DWORD, LPCWSTR, LPCWSTR, LPCWSTR, LPWSTR, PUINT, LPWSTR, PUINT );
    __typedef_func( VerInstallFileA, DWORD, DWORD, LPCSTR, LPCSTR, LPCSTR, LPCSTR, LPCSTR, LPSTR, PUINT );
    __typedef_func( VerInstallFileW, DWORD, DWORD, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPCWSTR, LPWSTR, PUINT );
    __typedef_func( VerLanguageNameA, DWORD, DWORD, LPSTR, DWORD );
    __typedef_func( VerLanguageNameW, DWORD, DWORD, LPWSTR, DWORD );
    __typedef_func( VerQueryValueA, BOOL, LPCVOID, LPCSTR, LPVOID*, PUINT );
    __typedef_func( VerQueryValueW, BOOL, LPCVOID, LPCWSTR, LPVOID*, PUINT );


    // 'd3d8.dll'
    __typedef_func( Direct3D8EnableMaximizedWindowedModeShim, int, BOOL mEnable );
    __typedef_func( ValidatePixelShader, HRESULT, const DWORD* pShader, void* pCaps, BOOL mFlag, char** pDest );
    __typedef_func( ValidateVertexShader, HRESULT, const DWORD* pShader, const DWORD* pUnknown1, void* pCaps, BOOL mFlag, char** pDest );
    __typedef_func( Direct3DCreate8, void*, UINT SDKVersion );


    // 'd3d9.dll'
    __typedef_func( Direct3DCreate9, void*, UINT nSDKVersion );
    __typedef_func( Direct3DCreate9Ex, HRESULT, UINT nSDKVersion, void** ppDirect3D9Ex );
    __typedef_func( D3DPERF_BeginEvent, int, DWORD col, LPCWSTR wszName );
    __typedef_func( D3DPERF_EndEvent, int );
    __typedef_func( D3DPERF_SetMarker, void, DWORD col, LPCWSTR wszName );
    __typedef_func( D3DPERF_SetRegion, void, DWORD col, LPCWSTR wszName );
    __typedef_func( D3DPERF_QueryRepeatFrame, BOOL );
    __typedef_func( D3DPERF_SetOptions, void, DWORD dwOptions );
    __typedef_func( D3DPERF_GetStatus, DWORD );
    __typedef_func( DebugSetMute, void ); // also valid for 'd3d8.dll'
    __typedef_func( DebugSetLevel, int );
    __typedef_func( PSGPError, void, void* pProcessVertices, int errorId, UINT unknownParam1 );
    __typedef_func( PSGPSampleTexture, void, void* pProcessVertices, UINT unknownParam1, float( * const unknownParam2 )[4], UINT unknownParam3, float( * const unknownParam4 )[4] );
    __typedef_func( Direct3DShaderValidatorCreate9, void* );
    __typedef_func( Direct3D9EnableMaximizedWindowedModeShim, int, UINT unknownParam );

    /// <summary>
    /// Loads an original system library and resolves all the function procs
    /// </summary>
    /// <returns>Returns "true" upon success, "false" otherwise</returns>
    bool resolve( const HMODULE& mod )
    {
        wchar_t proxy_path[4096]{};
        GetModuleFileNameW( mod, proxy_path, (sizeof( proxy_path )) );
        m_proxy_path = fs::path( proxy_path ).parent_path();

        auto proxy_name = fs::path( proxy_path ).filename();

        // Check if our proxy library name is supported
        bool proxy_supported{ false };
        for (auto const& proxy : m_supported_proxies)
        {
            // Case insensitive compare
            if (_wcsnicmp( proxy_name.c_str(), proxy.c_str(), proxy.size()) == 0)
            {
                proxy_supported = true;
                break;
            }
        }

        if (!proxy_supported)
            return false;

        wchar_t sys_path[MAX_PATH]{};
        GetSystemDirectoryW( sys_path, MAX_PATH );

        // A full path to the original system library
        auto system_dll_path = fs::path( sys_path ) / proxy_name;

        // Try loading an original system library
        auto proxy_dll = LoadLibraryExW( system_dll_path.c_str(), nullptr, LOAD_LIBRARY_SEARCH_SYSTEM32 );

        if (proxy_dll == nullptr)
            return false;

        // 'version.dll'
        __setup_proc( GetFileVersionInfoA, proxy_dll );
        __setup_proc( GetFileVersionInfoByHandle, proxy_dll );
        __setup_proc( GetFileVersionInfoExA, proxy_dll );
        __setup_proc( GetFileVersionInfoExW, proxy_dll );
        __setup_proc( GetFileVersionInfoSizeA, proxy_dll );
        __setup_proc( GetFileVersionInfoSizeExA, proxy_dll );
        __setup_proc( GetFileVersionInfoSizeExW, proxy_dll );
        __setup_proc( GetFileVersionInfoSizeW, proxy_dll );
        __setup_proc( GetFileVersionInfoW, proxy_dll );
        __setup_proc( VerFindFileA, proxy_dll );
        __setup_proc( VerFindFileW, proxy_dll );
        __setup_proc( VerInstallFileA, proxy_dll );
        __setup_proc( VerInstallFileW, proxy_dll );
        __setup_proc( VerLanguageNameA, proxy_dll );
        __setup_proc( VerLanguageNameW, proxy_dll );
        __setup_proc( VerQueryValueA, proxy_dll );
        __setup_proc( VerQueryValueW, proxy_dll );


        // 'd3d8.dll'
        __setup_proc( Direct3D8EnableMaximizedWindowedModeShim, proxy_dll );
        __setup_proc( ValidatePixelShader, proxy_dll );
        __setup_proc( ValidateVertexShader, proxy_dll );
        __setup_proc( Direct3DCreate8, proxy_dll );


        // 'd3d9.dll'
        __setup_proc( Direct3DCreate9, proxy_dll );
        __setup_proc( Direct3DCreate9Ex, proxy_dll );
        __setup_proc( D3DPERF_BeginEvent, proxy_dll );
        __setup_proc( D3DPERF_EndEvent, proxy_dll );
        __setup_proc( D3DPERF_SetMarker, proxy_dll );
        __setup_proc( D3DPERF_SetRegion, proxy_dll );
        __setup_proc( D3DPERF_QueryRepeatFrame, proxy_dll );
        __setup_proc( D3DPERF_SetOptions, proxy_dll );
        __setup_proc( D3DPERF_GetStatus, proxy_dll );
        __setup_proc( DebugSetMute, proxy_dll );
        __setup_proc( DebugSetLevel, proxy_dll );
        __setup_proc( PSGPError, proxy_dll );
        __setup_proc( PSGPSampleTexture, proxy_dll );
        __setup_proc( Direct3DShaderValidatorCreate9, proxy_dll );
        __setup_proc( Direct3D9EnableMaximizedWindowedModeShim, proxy_dll );

        return true;
    }
};