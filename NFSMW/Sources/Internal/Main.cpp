#include "Main.h"

void Main::Run()
{
    AppliedHooksRegistrator::ApplyRegisteredHooks();

    Flyhack flyhack = Flyhack();
    Teleport teleport = Teleport();
    while (true)
    {
        FlyhackBlock(&flyhack);
        TeleportBlock(&teleport);

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

void Main::TeleportBlock(Teleport* teleport)
{
    int VK_K = 0x4B;
    if (GetAsyncKeyState(VK_K))
    {
        teleport->TeleportPlayerToHighestLocation();
    }
}