#pragma once

#include "../../Includes.h"
#include "../../Classes/Math/Vector3.h"
#include "../../AppliedHooks/HooksList/VehiclesCollector.h"

class Flyhack
{
public:
	Flyhack()
	{
		uintptr_t moduleHandle = reinterpret_cast<uintptr_t>(GetModuleHandle(NULL));
		this->playerPosition = reinterpret_cast<Vector3*>(moduleHandle + 0x5386D8);
		this->minimumPositionY = 0.1f;
		this->maximumPositionY = 350.0f;
		this->lastPlayerPositionY = NULL;
	}

	void ApplyEffect(Vector3* targetPosition, float flyhackForce);
	void ApplyEffectPlayer(float flyhackForce);
	void ApplyEffectAllOtherVehicles(float flyhackForce);
	void ResetEffect();

private:
	float minimumPositionY;
	float maximumPositionY;
	Vector3* playerPosition;
	float lastPlayerPositionY;
};