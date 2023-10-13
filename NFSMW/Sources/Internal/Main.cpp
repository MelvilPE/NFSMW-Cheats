#include "Main.h"

void Main::Run()
{
    AppliedHooksRegistrator::ApplyRegisteredHooks();

    Flyhack flyhack = Flyhack();
    while (true)
    {
        FlyhackBlock(&flyhack);

        Sleep(30);
    }
}

void Main::FlyhackBlock(Flyhack* flyhack)
{
    float flyhackForce = 2.5f;
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