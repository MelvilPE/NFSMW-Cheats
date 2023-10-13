#include "Main.h"

void Main::Run()
{
    AppliedHooksRegistrator::ApplyRegisteredHooks();

    uintptr_t moduleHandle = reinterpret_cast<uintptr_t>(GetModuleHandle(NULL));
    uintptr_t* playerPositionY = reinterpret_cast<uintptr_t*>(moduleHandle + 0x5386DC);

    Flyhack flyhack = Flyhack(playerPositionY);
    while (true)
    {
        FlyhackBlock(&flyhack);

        Sleep(30);
    }
}

void Main::FlyhackBlock(Flyhack* flyhack)
{
    uintptr_t flyhackForce = 0xFFFF;
    int VK_M = 0x4D;
    if (GetAsyncKeyState(VK_M))
    {
        flyhack->ApplyEffectPlayer(flyhackForce);
    }
    else
    {
        flyhack->ResetEffect();
    }

    int VK_L = 0x4C;
    if (GetAsyncKeyState(VK_L))
    {
        flyhack->ApplyEffectAllOtherVehicles(flyhackForce);
    }
}