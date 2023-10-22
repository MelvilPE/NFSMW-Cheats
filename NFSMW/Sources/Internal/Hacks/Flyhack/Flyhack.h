#pragma once

#include "../../Includes.h"

#include "../CheatBase.h"
#include "../GameClasses/VehicleEntity.h"

#include "../../AppliedHooks/HooksList/VehiclesCollector.h"

class Flyhack: public CheatBase
{
public:
	Flyhack()
	{
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
	float lastPlayerPositionY;
};