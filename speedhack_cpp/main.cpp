#include "pch.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
        {
            auto result = CProxyStub::instance().resolve( hModule );

            if (!result)
                return FALSE;

            result = CSpeedHack::instance().setup_hooks();

            if (!result)
                return FALSE;

            break;
        }

        case DLL_PROCESS_DETACH:
        {
            CSpeedHack::instance().remove_hooks();
            break;
        }
    }

    return TRUE;
}