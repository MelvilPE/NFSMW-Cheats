#include "Flyhack.h"

void Flyhack::ApplyEffect(VehicleEntity* targetEntity, float flyhackForce)
{
	if (targetEntity == nullptr)
	{
		MessageBox(NULL, "Flyhack::ApplyEffect failed to activate flyhack, targetEntity pointer can't be nullptr!", "NFSMW", 16);
		return;
	}

	DWORD curProtection;
	VirtualProtect(targetEntity, sizeof(VehicleEntity), PAGE_EXECUTE_READWRITE, &curProtection);

	Vector3 targetPosition = targetEntity->GetPosition();
	targetPosition.SetAxisY(targetPosition.GetAxisY() + flyhackForce);
	targetEntity->SetPosition(targetPosition);

	DWORD temp;
	VirtualProtect(targetEntity, sizeof(VehicleEntity), curProtection, &temp);
}

void Flyhack::ApplyEffectPlayer(float flyhackForce)
{
	if (playerEntity == nullptr)
	{
		MessageBox(NULL, "Flyhack::ApplyEffectPlayer failed to activate flyhack, playerEntity pointer can't be nullptr!", "NFSMW", 16);
		return;
	}


	ApplyEffect(playerEntity, flyhackForce);

	/* When we need to add more force to beat gravity! */
	while (playerEntity->GetPosition().GetAxisY() <= lastPlayerPositionY)
	{
		//flyhackForce = flyhackForce - flyhackForce / 2;
		flyhackForce += flyhackForce;
		ApplyEffect(playerEntity, flyhackForce);
	}
	/* We beat the gravity force here! */
	lastPlayerPositionY = playerEntity->GetPosition().GetAxisY();
}

void Flyhack::ApplyEffectAllOtherVehicles(float flyhackForce)
{
	std::vector<VehicleEntity*> allVehiclesEntities = VehiclesCollector::GetAllVehiclesEntities();
	if (allVehiclesEntities.size() == NULL)
	{
		MessageBox(NULL, "Flyhack::ApplyEffectAllOtherVehicles failed to receive any vehicles entities position!", "NFSMW", 16);
		return;
	}

	/* We want to apply force to each vehicles in the received vector */
	for (uintptr_t vehicleIndex = 0; vehicleIndex < allVehiclesEntities.size(); vehicleIndex++)
	{
		VehicleEntity* currentVehicleEntity = allVehiclesEntities[vehicleIndex];
		if (currentVehicleEntity == nullptr)
		{
			MessageBox(NULL, "Flyhack::ApplyEffectAllOtherVehicles failed to activate flyhack, currentVehicleEntity pointer can't be nullptr!", "NFSMW", 16);
			return;
		}

		/* We can apply to all vehicles except us */
		if (currentVehicleEntity != playerEntity)
		{
			ApplyEffect(currentVehicleEntity, flyhackForce);
		}
	}
}

void Flyhack::ResetEffect()
{
	lastPlayerPositionY = 0.0f;
}