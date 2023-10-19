#include "Main.h"

void Main::Run()
{
    AppliedHooksRegistrator::ApplyRegisteredHooks();

    Flyhack flyhack = Flyhack();
    Teleport teleport = Teleport();
    AntiKB antiKB = AntiKB();
    while (true)
    {
        FlyhackBlock(&flyhack);
        TeleportBlock(&teleport);
        AntiKBBlock(&antiKB);

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

void Main::AntiKBBlock(AntiKB* antiKB)
{
    int VK_J = 0x4A;
    if (GetAsyncKeyState(VK_J))
    {
        antiKB->EnableOrDisable();
    }
}