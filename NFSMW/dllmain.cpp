#include "windows.h"
#include "Sources/Internal/Hacks/Flyhack.h"

DWORD WINAPI MainThread(LPVOID param)
{
    uintptr_t moduleHandle = reinterpret_cast<uintptr_t>(GetModuleHandle(NULL));
    uintptr_t* playerPositionY = reinterpret_cast<uintptr_t*>(moduleHandle + 0x5386DC);
    uintptr_t* startVehiclesAdressY = reinterpret_cast<uintptr_t*>(moduleHandle + 0x53878C);

    Flyhack instance = Flyhack(playerPositionY, startVehiclesAdressY);
    while (true)
    {
        /* This part is for flyhack! */
        uintptr_t globalForce = 0xFFFF;
        int VK_M = 0x4D;
        if (GetAsyncKeyState(VK_M))
        {
            instance.ApplyEffectPlayer(globalForce);
        }
        else
        {
            instance.ResetEffect();
        }

        int VK_L = 0x4C;
        if (GetAsyncKeyState(VK_L))
        {
            instance.ApplyEffectAllOtherVehicles(globalForce);
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

