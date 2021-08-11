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
        __clear_proc( DirectDrawCreate );
        __clear_proc( DirectDrawCreateEx );
        __clear_proc( DirectDrawCreateClipper );
        __clear_proc( DirectDrawEnumerateA );
        __clear_proc( DirectDrawEnumerateW );
        __clear_proc( DirectDrawEnumerateExA );
        __clear_proc( DirectDrawEnumerateExW );
        __clear_proc( AcquireDDThreadLock );
        __clear_proc( ReleaseDDThreadLock );
        __clear_proc( D3DParseUnknownCommand );
        __clear_proc( DllCanUnloadNow );
        __clear_proc( DllGetClassObject );
        __clear_proc( GetSurfaceFromDC );
        __clear_proc( CompleteCreateSysmemSurface );
        __clear_proc( DDGetAttachedSurfaceLcl );
        __clear_proc( DDInternalLock );
        __clear_proc( DDInternalUnlock );
        __clear_proc( Direct3D8EnableMaximizedWindowedModeShim );
        __clear_proc( ValidatePixelShader );
        __clear_proc( ValidateVertexShader );
        __clear_proc( Direct3DCreate8 );
        __clear_proc( Direct3DCreate9 );
        __clear_proc( Direct3DCreate9 );
        __clear_proc( Direct3DCreate9Ex );
        __clear_proc( D3DPERF_BeginEvent );
        __clear_proc( D3DPERF_EndEvent );
        __clear_proc( D3DPERF_SetMarker );
        __clear_proc( D3DPERF_SetRegion );
        __clear_proc( D3DPERF_QueryRepeatFrame );
        __clear_proc( D3DPERF_SetOptions );
        __clear_proc( D3DPERF_GetStatus );
        __clear_proc( DebugSetMute );
        __clear_proc( DebugSetLevel );
        __clear_proc( PSGPError );
        __clear_proc( PSGPSampleTexture );
        __clear_proc( Direct3DShaderValidatorCreate9 );
        __clear_proc( Direct3D9EnableMaximizedWindowedModeShim );
    }

private:

    // A list of supported proxy libraries
    std::vector<std::wstring> m_supported_proxies
    {
        L"version.dll",
        L"ddraw.dll",
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


    // 'ddraw.dll'
    __typedef_func( DirectDrawCreate, HRESULT, GUID* lpGUID, void* lplpDD, void* pUnkOuter );
    __typedef_func( DirectDrawCreateEx, HRESULT, GUID* lpGuid, LPVOID* lplpDD, REFIID iid, void* pUnkOuter );
    __typedef_func( DirectDrawCreateClipper, HRESULT, DWORD dwFlags, void* FAR* lplpDDClipper, void* pUnkOuter );
    __typedef_func( DirectDrawEnumerateA, HRESULT, void* lpCallback, LPVOID lpContext );
    __typedef_func( DirectDrawEnumerateW, HRESULT, void* lpCallback, LPVOID lpContext );
    __typedef_func( DirectDrawEnumerateExA, HRESULT, void* lpCallback, LPVOID lpContext, DWORD dwFlags );
    __typedef_func( DirectDrawEnumerateExW, HRESULT, void* lpCallback, LPVOID lpContext, DWORD dwFlags );
    __typedef_func( AcquireDDThreadLock, void );
    __typedef_func( ReleaseDDThreadLock, void );
    __typedef_func( D3DParseUnknownCommand, DWORD, LPVOID lpCmd, LPVOID* lpRetCmd );
    __typedef_func( DllCanUnloadNow, HRESULT );
    __typedef_func( DllGetClassObject, HRESULT, const CLSID& rclsid, const IID& riid, void** ppv );
    __typedef_func( GetSurfaceFromDC, size_t, size_t aUnknown1, size_t aUnknown2, size_t aUnknown3 );
    __typedef_func( CompleteCreateSysmemSurface, size_t, size_t aUnknown1 );
    __typedef_func( DDGetAttachedSurfaceLcl, size_t, size_t aUnknown1, int* pUnknown2, void* pUnknown3 );
    __typedef_func( DDInternalLock, size_t, void* pDrawSurface );
    __typedef_func( DDInternalUnlock, size_t, size_t aUnknown1 );


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


        // 'ddraw.dll'
        __setup_proc( DirectDrawCreate, proxy_dll );
        __setup_proc( DirectDrawCreateEx, proxy_dll );
        __setup_proc( DirectDrawCreateClipper, proxy_dll );
        __setup_proc( DirectDrawEnumerateA, proxy_dll );
        __setup_proc( DirectDrawEnumerateW, proxy_dll );
        __setup_proc( DirectDrawEnumerateExA, proxy_dll );
        __setup_proc( DirectDrawEnumerateExW, proxy_dll );
        __setup_proc( AcquireDDThreadLock, proxy_dll );
        __setup_proc( ReleaseDDThreadLock, proxy_dll );
        __setup_proc( D3DParseUnknownCommand, proxy_dll );
        __setup_proc( DllCanUnloadNow, proxy_dll );
        __setup_proc( DllGetClassObject, proxy_dll );
        __setup_proc( GetSurfaceFromDC, proxy_dll );
        __setup_proc( CompleteCreateSysmemSurface, proxy_dll );
        __setup_proc( DDGetAttachedSurfaceLcl, proxy_dll );
        __setup_proc( DDInternalLock, proxy_dll );
        __setup_proc( DDInternalUnlock, proxy_dll );


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