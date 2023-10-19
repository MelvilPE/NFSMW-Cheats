#pragma once

#include "../../Includes.h"

#include "../GameClasses/VehicleEntity.h"

#include "../../AppliedHooks/HooksList/VehiclesCollector.h"

class Flyhack
{
public:
	Flyhack()
	{
		uintptr_t moduleHandle = reinterpret_cast<uintptr_t>(GetModuleHandle(NULL));
		this->playerEntity = reinterpret_cast<VehicleEntity*>(moduleHandle + 0x5386C8);
		this->minimumPositionY = 0.1f;
		this->maximumPositionY = 350.0f;
		this->lastPlayerPositionY = NULL;
	}

	void ApplyEffect(VehicleEntity* targetEntity, float flyhackForce);
	void ApplyEffectPlayer(float flyhackForce);
	void ApplyEffectAllOtherVehicles(float flyhackForce);
	void ResetEffect();

private:
	float minimumPositionY;
	float maximumPositionY;
	VehicleEntity* playerEntity;
	float lastPlayerPositionY;
};