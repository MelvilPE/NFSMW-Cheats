#include "windows.h"
#include "Sources/Internal/Hacks/Flyhack.h"

DWORD WINAPI MainThread(LPVOID param)
{
    while (true)
    {
        /* This part is for flyhack! */
        int VK_M = 0x4D;
        if (GetAsyncKeyState(VK_M))
        {
            Flyhack::ApplyGravity(0xFFFF);
        }

        Sleep(30);
    }

    FreeLibraryAndExitThread((HMODULE)param, 0);
    return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, MainThread, hModule, 0, 0);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

