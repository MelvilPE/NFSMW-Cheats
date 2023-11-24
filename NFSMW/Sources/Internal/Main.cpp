#include "Main.h"

void Main::Run()
{
    AppliedHooksRegistrator::ApplyRegisteredHooks();

    Flyhack flyhack = Flyhack();
    Teleport teleport = Teleport();
    AntiKB antiKB = AntiKB();
    Boost boost = Boost();
    Wheeling wheeling = Wheeling();

    while (true)
    {
        FlyhackBlock(&flyhack);
        TeleportBlock(&teleport);
        AntiKBBlock(&antiKB);
        BoostBlock(&boost);
        WheelingBlock(&wheeling);

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

void Main::BoostBlock(Boost* boost)
{
    int VK_S = 0x53;
    if (GetAsyncKeyState(VK_S))
    {
        boost->ApplyEffectPlayer(2.0f);
    }
}

void Main::WheelingBlock(Wheeling* wheeling)
{
    int VK_W = 0x57;
    if (GetAsyncKeyState(VK_W))
    {
        wheeling->ApplyEffectPlayer();
    }
}