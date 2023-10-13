#include "Main.h"

void Main::Run()
{
    AppliedHooksRegistrator::ApplyRegisteredHooks();

    uintptr_t moduleHandle = reinterpret_cast<uintptr_t>(GetModuleHandle(NULL));
    uintptr_t* playerPositionY = reinterpret_cast<uintptr_t*>(moduleHandle + 0x5386DC);

    Flyhack instance = Flyhack(playerPositionY);
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
}