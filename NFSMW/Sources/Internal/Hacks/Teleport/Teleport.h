#pragma once

#include "../../Includes.h"

#include "../GameClasses/VehicleEntity.h"

#include "../../AppliedHooks/HooksList/VehiclesCollector.h"

class Teleport
{
public:
	Teleport()
	{
		uintptr_t moduleHandle = reinterpret_cast<uintptr_t>(GetModuleHandle(NULL));
		this->playerEntity = reinterpret_cast<VehicleEntity*>(moduleHandle + 0x5386C8);
	}

	void TeleportLocation(VehicleEntity* targetEntity, Vector3* targetLocation);
	void TeleportHighestLocation(VehicleEntity* targetEntity);
	void TeleportPlayerToHighestLocation();
private:
	VehicleEntity* playerEntity;
};