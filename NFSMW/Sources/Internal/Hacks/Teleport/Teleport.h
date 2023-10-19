#pragma once

#include "../../Includes.h"
#include "../../Classes/Math/Vector3.h"
#include "../../AppliedHooks/HooksList/VehiclesCollector.h"

class Teleport
{
public:
	Teleport()
	{
		uintptr_t moduleHandle = reinterpret_cast<uintptr_t>(GetModuleHandle(NULL));
		this->playerPosition = reinterpret_cast<Vector3*>(moduleHandle + 0x5386D8);
	}

	void TeleportLocation(Vector3* targetPosition, Vector3* targetLocation);
	void TeleportHighestLocation(Vector3* targetPosition);
	void TeleportPlayerToHighestLocation();
private:
	Vector3* playerPosition;
};