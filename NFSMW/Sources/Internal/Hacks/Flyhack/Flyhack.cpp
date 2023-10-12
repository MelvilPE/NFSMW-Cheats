#include "Flyhack.h"

void Flyhack::ApplyEffect(uintptr_t* targetAdressY, uintptr_t flyhackForce)
{
	if (targetAdressY == nullptr)
	{
		MessageBox(NULL, "Flyhack::ApplyEffect failed to activate flyhack, targetAdressY pointer can't be nullptr!", "NFSMW", 16);
		return;
	}

	DWORD curProtection;
	VirtualProtect(targetAdressY, sizeof(uintptr_t), PAGE_EXECUTE_READWRITE, &curProtection);

	*targetAdressY += flyhackForce;

	DWORD temp;
	VirtualProtect(targetAdressY, sizeof(uintptr_t), curProtection, &temp);
}

void Flyhack::ApplyEffectPlayer(uintptr_t flyhackForce)
{
	if (playerAdressY == nullptr)
	{
		MessageBox(NULL, "Flyhack::ApplyEffectPlayer failed to activate flyhack, playerAdressY pointer can't be nullptr!", "NFSMW", 16);
		return;
	}

	ApplyEffect(playerAdressY, flyhackForce);

	/* When we need to add more force to beat gravity! */
	while (*playerAdressY <= lastPlayerPositionY)
	{
		flyhackForce = flyhackForce - flyhackForce / 2;
		ApplyEffect(playerAdressY, flyhackForce);
	}
	/* We beat the gravity force here! */
	lastPlayerPositionY = *playerAdressY;
}

void Flyhack::ApplyEffectAllOtherVehicles(uintptr_t flyhackForce)
{
	std::vector<uintptr_t*> vehiclesPointersY = VehiclesCollector::GetAllInitializedVehicles();
	if (vehiclesPointersY.size() == NULL)
	{
		MessageBox(NULL, "Flyhack::ApplyEffectAllOtherVehicles failed to receive any vehicles entities position Y!", "NFSMW", 16);
		return;
	}

	/* We want to apply force to each vehicles in the received vector */
	for (uintptr_t vehiclesIndex = 0; vehiclesIndex < vehiclesPointersY.size(); vehiclesIndex++)
	{
		uintptr_t* currentVehiclePointerY = vehiclesPointersY[vehiclesIndex];
		if (currentVehiclePointerY == nullptr)
		{
			MessageBox(NULL, "Flyhack::ApplyEffectAllOtherVehicles failed to activate flyhack, currentVehiclePointerY pointer can't be nullptr!", "NFSMW", 16);
			return;
		}

		/* We can apply to all vehicles except us */
		if (currentVehiclePointerY != playerAdressY)
		{
			ApplyEffect(currentVehiclePointerY, flyhackForce);
		}
	}
}

void Flyhack::ResetEffect()
{
	lastPlayerPositionY = NULL;
}