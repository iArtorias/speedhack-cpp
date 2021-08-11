#include "pch.h"

#pragma region VERSION_DLL

EXTERN_API BOOL WINAPI GetFileVersionInfoA(
     LPCSTR lptstrFilename,
     DWORD dwHandle,
     DWORD dwLen,
     LPVOID lpData
)
{
    return CProxyStub::instance().m_GetFileVersionInfoA( lptstrFilename, dwHandle, dwLen, lpData );
}


EXTERN_API BOOL WINAPI GetFileVersionInfoByHandle(
    size_t aUnkn1,
    HANDLE hFile,
    size_t aUnkn3,
    size_t aUnkn4 )
{
    return CProxyStub::instance().m_GetFileVersionInfoByHandle( aUnkn1, hFile, aUnkn3, aUnkn4 );
}


EXTERN_API BOOL WINAPI GetFileVersionInfoExA(
  DWORD dwFlags,
  LPCSTR lpwstrFilename,
  DWORD dwHandle,
  DWORD dwLen,
  LPVOID lpData
)
{
    return CProxyStub::instance().m_GetFileVersionInfoExA( dwFlags, lpwstrFilename, dwHandle, dwLen, lpData );
}


EXTERN_API BOOL WINAPI GetFileVersionInfoExW(
    DWORD dwFlags,
    LPCWSTR lpwstrFilename,
    DWORD dwHandle,
    DWORD dwLen,
    LPVOID lpData )
{
    return CProxyStub::instance().m_GetFileVersionInfoExW( dwFlags, lpwstrFilename, dwHandle, dwLen, lpData );
}


EXTERN_API DWORD WINAPI GetFileVersionInfoSizeA(
    LPCSTR lptstrFilename,
    LPDWORD lpdwHandle )
{
    return CProxyStub::instance().m_GetFileVersionInfoSizeA( lptstrFilename, lpdwHandle );
}


EXTERN_API DWORD WINAPI GetFileVersionInfoSizeExA(
    DWORD dwFlags,
    LPCSTR lpwstrFilename,
    LPDWORD lpdwHandle )
{
    return CProxyStub::instance().m_GetFileVersionInfoSizeExA( dwFlags, lpwstrFilename, lpdwHandle );
}


EXTERN_API DWORD WINAPI GetFileVersionInfoSizeExW(
    DWORD dwFlags,
    LPCWSTR lpwstrFilename,
    LPDWORD lpdwHandle )
{
    return CProxyStub::instance().m_GetFileVersionInfoSizeExW( dwFlags, lpwstrFilename, lpdwHandle );
}


EXTERN_API DWORD WINAPI GetFileVersionInfoSizeW(
    LPCWSTR lptstrFilename,
    LPDWORD lpdwHandle )
{
    return CProxyStub::instance().m_GetFileVersionInfoSizeW( lptstrFilename, lpdwHandle );
}


EXTERN_API BOOL WINAPI GetFileVersionInfoW(
    LPCWSTR lptstrFilename,
    DWORD dwHandle,
    DWORD dwLen,
    LPVOID lpData )
{
    return CProxyStub::instance().m_GetFileVersionInfoW( lptstrFilename, dwHandle, dwLen, lpData );
}


EXTERN_API DWORD WINAPI VerFindFileA(
    DWORD uFlags,
    LPCSTR szFileName,
    LPCSTR szWinDir,
    LPCSTR szAppDir,
    LPSTR szCurDir,
    PUINT lpuCurDirLen,
    LPSTR szDestDir,
    PUINT lpuDestDirLen )
{
    return CProxyStub::instance().m_VerFindFileA( uFlags, szFileName, szWinDir, szAppDir, szCurDir, lpuCurDirLen,
        szDestDir, lpuDestDirLen );
}


EXTERN_API DWORD WINAPI VerFindFileW(
    DWORD uFlags,
    LPCWSTR szFileName,
    LPCWSTR szWinDir,
    LPCWSTR szAppDir,
    LPWSTR szCurDir,
    PUINT lpuCurDirLen,
    LPWSTR szDestDir,
    PUINT lpuDestDirLen )
{
    return CProxyStub::instance().m_VerFindFileW( uFlags, szFileName, szWinDir, szAppDir, szCurDir, lpuCurDirLen,
        szDestDir, lpuDestDirLen );
}


EXTERN_API DWORD WINAPI VerInstallFileA(
    DWORD uFlags,
    LPCSTR szSrcFileName,
    LPCSTR szDestFileName,
    LPCSTR szSrcDir,
    LPCSTR szDestDir,
    LPCSTR szCurDir,
    LPSTR szTmpFile,
    PUINT lpuTmpFileLen )
{
    return CProxyStub::instance().m_VerInstallFileA( uFlags, szSrcFileName, szDestFileName, szSrcDir, szDestDir,
        szCurDir, szTmpFile, lpuTmpFileLen );
}


EXTERN_API DWORD WINAPI VerInstallFileW(
    DWORD uFlags,
    LPCWSTR szSrcFileName,
    LPCWSTR szDestFileName,
    LPCWSTR szSrcDir,
    LPCWSTR szDestDir,
    LPCWSTR szCurDir,
    LPWSTR szTmpFile,
    PUINT lpuTmpFileLen )
{
    return CProxyStub::instance().m_VerInstallFileW( uFlags, szSrcFileName, szDestFileName, szSrcDir, szDestDir,
        szCurDir, szTmpFile, lpuTmpFileLen );
}


EXTERN_API DWORD WINAPI VerLanguageNameA(
    DWORD wLang,
    LPSTR szLang,
    DWORD cchLang )
{
    return CProxyStub::instance().m_VerLanguageNameA( wLang, szLang, cchLang );
}


EXTERN_API DWORD WINAPI VerLanguageNameW(
    DWORD wLang,
    LPWSTR szLang,
    DWORD cchLang )
{
    return CProxyStub::instance().m_VerLanguageNameW( wLang, szLang, cchLang );
}


EXTERN_API BOOL WINAPI VerQueryValueA(
    LPCVOID pBlock,
    LPCSTR lpSubBlock,
    LPVOID* lplpBuffer,
    PUINT puLen )
{
    return CProxyStub::instance().m_VerQueryValueA( pBlock, lpSubBlock, lplpBuffer, puLen );
}


EXTERN_API BOOL WINAPI VerQueryValueW(
    LPCVOID pBlock,
    LPCWSTR lpSubBlock,
    LPVOID* lplpBuffer,
    PUINT puLen )
{
    return CProxyStub::instance().m_VerQueryValueW( pBlock, lpSubBlock, lplpBuffer, puLen );
}

#pragma endregion


#pragma region DDRAW_DLL

EXTERN_API HRESULT WINAPI DirectDrawCreate(
    GUID* lpGUID,
    void* lplpDD,
    void* pUnkOuter )
{
    return CProxyStub::instance().m_DirectDrawCreate( lpGUID, lplpDD, pUnkOuter );
}


EXTERN_API HRESULT WINAPI DirectDrawCreateEx(
    GUID* lpGuid,
    LPVOID* lplpDD,
    REFIID iid,
    void* pUnkOuter )
{
    return CProxyStub::instance().m_DirectDrawCreateEx( lpGuid, lplpDD, iid, pUnkOuter );
}


EXTERN_API HRESULT WINAPI DirectDrawCreateClipper(
    DWORD dwFlags,
    void* FAR* lplpDDClipper,
    void* pUnkOuter )
{
    return CProxyStub::instance().m_DirectDrawCreateClipper( dwFlags, lplpDDClipper, pUnkOuter );
}


EXTERN_API HRESULT WINAPI DirectDrawEnumerateA(
    void* lpCallback,
    LPVOID lpContext )
{
    return CProxyStub::instance().m_DirectDrawEnumerateA( lpCallback, lpContext );
}


EXTERN_API HRESULT WINAPI DirectDrawEnumerateW(
    void* lpCallback,
    LPVOID lpContext )
{
    return CProxyStub::instance().m_DirectDrawEnumerateW( lpCallback, lpContext );
}


EXTERN_API HRESULT WINAPI DirectDrawEnumerateExA(
    void* lpCallback,
    LPVOID lpContext, 
    DWORD dwFlags )
{
    return CProxyStub::instance().m_DirectDrawEnumerateExA( lpCallback, lpContext, dwFlags );
}


EXTERN_API HRESULT WINAPI DirectDrawEnumerateExW(
    void* lpCallback,
    LPVOID lpContext,
    DWORD dwFlags )
{
    return CProxyStub::instance().m_DirectDrawEnumerateExW( lpCallback, lpContext, dwFlags );
}


EXTERN_API void WINAPI AcquireDDThreadLock()
{
    return CProxyStub::instance().m_AcquireDDThreadLock();
}


EXTERN_API void WINAPI ReleaseDDThreadLock()
{
    return CProxyStub::instance().m_ReleaseDDThreadLock();
}


EXTERN_API DWORD WINAPI D3DParseUnknownCommand( 
    LPVOID lpCmd,
    LPVOID* lpRetCmd )
{
    return CProxyStub::instance().m_D3DParseUnknownCommand( lpCmd, lpRetCmd );
}


EXTERN_API HRESULT WINAPI DllCanUnloadNow()
{
    return CProxyStub::instance().m_DllCanUnloadNow();
}


EXTERN_API HRESULT WINAPI DllGetClassObject(
    const CLSID& rclsid,
    const IID& riid,
    void** ppv )
{
    return CProxyStub::instance().m_DllGetClassObject( rclsid, riid, ppv );
}


EXTERN_API size_t WINAPI GetSurfaceFromDC(
    size_t aUnknown1,
    size_t aUnknown2,
    size_t aUnknown3 )
{
    return CProxyStub::instance().m_GetSurfaceFromDC( aUnknown1, aUnknown2, aUnknown3 );
}


EXTERN_API size_t WINAPI CompleteCreateSysmemSurface(
    size_t aUnknown1 )
{
    return CProxyStub::instance().m_CompleteCreateSysmemSurface( aUnknown1 );
}


EXTERN_API size_t WINAPI DDGetAttachedSurfaceLcl(
    size_t aUnknown1,
    int* pUnknown2,
    void* pUnknown3 )
{
    return CProxyStub::instance().m_DDGetAttachedSurfaceLcl( aUnknown1, pUnknown2, pUnknown3 );
}


EXTERN_API size_t WINAPI DDInternalLock(
    void* pDrawSurface )
{
    return CProxyStub::instance().m_DDInternalLock( pDrawSurface );
}


EXTERN_API size_t WINAPI DDInternalUnlock(
    size_t aUnknown1 )
{
    return CProxyStub::instance().m_DDInternalUnlock( aUnknown1 );
}

#pragma endregion


#pragma region D3D8_DLL

EXTERN_API int WINAPI Direct3D8EnableMaximizedWindowedModeShim( 
    BOOL mEnable )
{
    return CProxyStub::instance().m_Direct3D8EnableMaximizedWindowedModeShim( mEnable );
}


EXTERN_API HRESULT WINAPI ValidatePixelShader( 
    const DWORD* pShader,
    void* pCaps,
    BOOL mFlag,
    char** pDest )
{
    return CProxyStub::instance().m_ValidatePixelShader( pShader, pCaps, mFlag, pDest );
}


EXTERN_API HRESULT WINAPI ValidateVertexShader( 
    const DWORD* pShader, 
    const DWORD* pUnknown1,
    void* pCaps,
    BOOL mFlag,
    char** pDest )
{
    return CProxyStub::instance().m_ValidateVertexShader( pShader, pUnknown1, pCaps, mFlag, pDest );
}


EXTERN_API void* WINAPI Direct3DCreate8( 
    UINT SDKVersion )
{
    return CProxyStub::instance().m_Direct3DCreate8( SDKVersion );
}

#pragma endregion


#pragma region D3D9_DLL

EXTERN_API void* WINAPI Direct3DCreate9(
    UINT nSDKVersion )
{
    return CProxyStub::instance().m_Direct3DCreate9( nSDKVersion );
}


EXTERN_API HRESULT WINAPI Direct3DCreate9Ex(
    UINT nSDKVersion,
    void** ppDirect3D9Ex )
{
    return CProxyStub::instance().m_Direct3DCreate9Ex( nSDKVersion, ppDirect3D9Ex );
}


EXTERN_API int WINAPI D3DPERF_BeginEvent(
    DWORD col,
    LPCWSTR wszName )
{
    return CProxyStub::instance().m_D3DPERF_BeginEvent( col, wszName );
}


EXTERN_API int WINAPI D3DPERF_EndEvent()
{
    return CProxyStub::instance().m_D3DPERF_EndEvent();
}


EXTERN_API void WINAPI D3DPERF_SetMarker(
    DWORD col, 
    LPCWSTR wszName )
{
    return CProxyStub::instance().m_D3DPERF_SetMarker( col, wszName );
}


EXTERN_API void WINAPI D3DPERF_SetRegion(
    DWORD col, 
    LPCWSTR wszName )
{
    return CProxyStub::instance().m_D3DPERF_SetRegion( col, wszName );
}


EXTERN_API BOOL WINAPI D3DPERF_QueryRepeatFrame()
{
    return CProxyStub::instance().m_D3DPERF_QueryRepeatFrame();
}


EXTERN_API void WINAPI D3DPERF_SetOptions(
    DWORD dwOptions )
{
    return CProxyStub::instance().m_D3DPERF_SetOptions( dwOptions );
}


EXTERN_API DWORD WINAPI D3DPERF_GetStatus()
{
    return CProxyStub::instance().m_D3DPERF_GetStatus();
}


EXTERN_API void WINAPI DebugSetMute()
{
    return CProxyStub::instance().m_DebugSetMute();
}


EXTERN_API int WINAPI DebugSetLevel()
{
    return CProxyStub::instance().m_DebugSetLevel();
}


EXTERN_API void WINAPI PSGPError(
    void* pProcessVertices,
    int errorId,
    UINT unknownParam1 )
{
    return CProxyStub::instance().m_PSGPError( pProcessVertices, errorId, unknownParam1 );
}


EXTERN_API void WINAPI PSGPSampleTexture(
    void* pProcessVertices, 
    UINT unknownParam1,
    float( * const unknownParam2 )[4],
    UINT unknownParam3,
    float( * const unknownParam4 )[4] )
{}


EXTERN_API void* WINAPI Direct3DShaderValidatorCreate9()
{
    return CProxyStub::instance().m_Direct3DShaderValidatorCreate9();
}


EXTERN_API int WINAPI Direct3D9EnableMaximizedWindowedModeShim(
    UINT unknownParam )
{
    return CProxyStub::instance().m_Direct3D9EnableMaximizedWindowedModeShim( unknownParam );
}

#pragma endregion