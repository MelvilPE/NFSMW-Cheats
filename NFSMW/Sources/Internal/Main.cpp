#include "Main.h"

void Main::Run()
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

	/* Since memory code caves are inside the DLL, we do not want to free library */
	while (true)
	{
		Sleep(100);
	}
}