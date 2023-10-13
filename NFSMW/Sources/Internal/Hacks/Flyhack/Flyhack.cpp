#include "Flyhack.h"

void Flyhack::ApplyEffect(Vector3* targetPosition, float flyhackForce)
{
	if (targetPosition == nullptr)
	{
		MessageBox(NULL, "Flyhack::ApplyEffect failed to activate flyhack, targetPosition pointer can't be nullptr!", "NFSMW", 16);
		return;
	}

	DWORD curProtection;
	VirtualProtect(targetPosition, sizeof(Vector3), PAGE_EXECUTE_READWRITE, &curProtection);

	targetPosition->SetAxisY(targetPosition->GetAxisY() + flyhackForce);

	DWORD temp;
	VirtualProtect(targetPosition, sizeof(Vector3), curProtection, &temp);
}

void Flyhack::ApplyEffectPlayer(float flyhackForce)
{
	if (playerPosition == nullptr)
	{
		MessageBox(NULL, "Flyhack::ApplyEffectPlayer failed to activate flyhack, playerPosition pointer can't be nullptr!", "NFSMW", 16);
		return;
	}

	ApplyEffect(playerPosition, flyhackForce);

	/* When we need to add more force to beat gravity! */
	while (playerPosition->GetAxisY() <= lastPlayerPositionY)
	{
		//flyhackForce = flyhackForce - flyhackForce / 2;
		flyhackForce += flyhackForce;
		ApplyEffect(playerPosition, flyhackForce);
	}
	/* We beat the gravity force here! */
	lastPlayerPositionY = playerPosition->GetAxisY();
}

void Flyhack::ApplyEffectAllOtherVehicles(float flyhackForce)
{
	std::vector<Vector3*> allVehiclesPosition = VehiclesCollector::GetAllInitializedVehiclesPosition();
	if (allVehiclesPosition.size() == NULL)
	{
		MessageBox(NULL, "Flyhack::ApplyEffectAllOtherVehicles failed to receive any vehicles entities position!", "NFSMW", 16);
		return;
	}

	/* We want to apply force to each vehicles in the received vector */
	for (uintptr_t vehiclesIndex = 0; vehiclesIndex < allVehiclesPosition.size(); vehiclesIndex++)
	{
		Vector3* currentVehiclePosition = allVehiclesPosition[vehiclesIndex];
		if (currentVehiclePosition == nullptr)
		{
			MessageBox(NULL, "Flyhack::ApplyEffectAllOtherVehicles failed to activate flyhack, currentVehiclePosition pointer can't be nullptr!", "NFSMW", 16);
			return;
		}

		/* We can apply to all vehicles except us */
		if (currentVehiclePosition != playerPosition)
		{
			ApplyEffect(currentVehiclePosition, flyhackForce);
		}
	}
}

void Flyhack::ResetEffect()
{
	lastPlayerPositionY = 0.0f;
}