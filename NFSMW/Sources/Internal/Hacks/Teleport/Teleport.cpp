#include "Teleport.h"

void Teleport::TeleportLocation(VehicleEntity* targetEntity, Vector3* targetLocation)
{
	if (targetEntity == nullptr)
	{
		MessageBox(NULL, "Teleport::TeleportLocation failed to teleport, targetEntity pointer can't be nullptr!", "NFSMW", 16);
		return;
	}

	DWORD curProtection;
	VirtualProtect(targetEntity, sizeof(VehicleEntity), PAGE_EXECUTE_READWRITE, &curProtection);

	targetEntity->SetPosition(*targetLocation);

	DWORD temp;
	VirtualProtect(targetEntity, sizeof(VehicleEntity), curProtection, &temp);
}

void Teleport::TeleportHighestLocation(VehicleEntity* targetEntity)
{
	VehicleEntity* playerEntity = GetPlayerEntity();
	std::vector<VehicleEntity*> allVehiclesEntities = VehiclesCollector::GetAllVehiclesEntities();
	if (allVehiclesEntities.size() == NULL)
	{
		MessageBox(NULL, "Teleport::TeleportHelicopter failed to receive any vehicles entities position!", "NFSMW", 16);
		return;
	}

	/* We want to find the highest vehicle, which in most cases is the helicopter */
	Vector3 highestVehiclePosition = Vector3(0.0f, 0.0f, 0.0f);
	for (uintptr_t vehicleIndex = 0; vehicleIndex < allVehiclesEntities.size(); vehicleIndex++)
	{
		VehicleEntity* currentVehicleEntity = allVehiclesEntities[vehicleIndex];
		if (currentVehicleEntity == nullptr)
		{
			MessageBox(NULL, "Teleport::TeleportHelicopter failed to teleport on helicopter, currentVehicleEntity pointer can't be nullptr!", "NFSMW", 16);
			return;
		}

		/* We check there each vehicle and get the highest position */
		if (currentVehicleEntity != playerEntity)
			if (highestVehiclePosition.GetAxisY() < currentVehicleEntity->GetPosition().GetAxisY())
				highestVehiclePosition = currentVehicleEntity->GetPosition();
	}

	if (highestVehiclePosition.HasSameValues(0.0f, 0.0f, 0.0f))
	{
		MessageBox(NULL, "Teleport::TeleportHelicopter failed to teleport on helicopter, failed to receive highest entity position!", "NFSMW", 16);
		return;
	}

	highestVehiclePosition.SetAxisY(highestVehiclePosition.GetAxisY() + 2.5f);
	TeleportLocation(targetEntity, &highestVehiclePosition);
}

void Teleport::TeleportPlayerToHighestLocation()
{
	VehicleEntity* playerEntity = GetPlayerEntity();
	TeleportHighestLocation(playerEntity);
}