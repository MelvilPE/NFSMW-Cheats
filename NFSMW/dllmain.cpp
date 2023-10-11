#include "windows.h"
#include "Sources/Internal/Hacks/Flyhack.h"

DWORD WINAPI MainThread(LPVOID param)
{
    Flyhack instance = Flyhack();
    while (true)
    {
        int VK_M = 0x4D;

        /* This part is for flyhack! */
        if (GetAsyncKeyState(VK_M))
        {
            instance.ApplyEffect(0xFFFF);
        }
        else
        {
            instance.ResetEffect();
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

