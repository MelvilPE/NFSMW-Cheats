#include "Teleport.h"

void Teleport::TeleportLocation(Vector3* targetPosition, Vector3* targetLocation)
{
	if (targetPosition == nullptr)
	{
		MessageBox(NULL, "Teleport::TeleportLocation failed to teleport, targetPosition pointer can't be nullptr!", "NFSMW", 16);
		return;
	}

	DWORD curProtection;
	VirtualProtect(targetPosition, sizeof(Vector3), PAGE_EXECUTE_READWRITE, &curProtection);

	targetPosition->SetAxisXYZ(*targetLocation);

	DWORD temp;
	VirtualProtect(targetPosition, sizeof(Vector3), curProtection, &temp);
}

void Teleport::TeleportHighestLocation(Vector3* targetPosition)
{
	std::vector<Vector3*> allVehiclesPosition = VehiclesCollector::GetAllInitializedVehiclesPosition();
	if (allVehiclesPosition.size() == NULL)
	{
		MessageBox(NULL, "Teleport::TeleportHelicopter failed to receive any vehicles entities position!", "NFSMW", 16);
		return;
	}

	/* We want to find the highest vehicle, which in most cases is the helicopter */
	Vector3 highestVehiclePosition = Vector3(0.0f, 0.0f, 0.0f);
	for (uintptr_t vehiclesIndex = 0; vehiclesIndex < allVehiclesPosition.size(); vehiclesIndex++)
	{
		Vector3* currentVehiclePosition = allVehiclesPosition[vehiclesIndex];
		if (currentVehiclePosition == nullptr)
		{
			MessageBox(NULL, "Teleport::TeleportHelicopter failed to teleport on helicopter, currentVehiclePosition pointer can't be nullptr!", "NFSMW", 16);
			return;
		}

		/* We check there each vehicle and get the highest position */
		if (currentVehiclePosition != playerPosition)
			if (highestVehiclePosition.GetAxisY() < currentVehiclePosition->GetAxisY())
				highestVehiclePosition = *currentVehiclePosition;
	}

	if (highestVehiclePosition.IsSameLocation(0.0f, 0.0f, 0.0f))
	{
		MessageBox(NULL, "Teleport::TeleportHelicopter failed to teleport on helicopter, failed to receive highest entity position!", "NFSMW", 16);
		return;
	}

	highestVehiclePosition.SetAxisY(highestVehiclePosition.GetAxisY() + 2.5f);
	TeleportLocation(targetPosition, &highestVehiclePosition);
}

void Teleport::TeleportPlayerToHighestLocation()
{
	TeleportHighestLocation(playerPosition);
}