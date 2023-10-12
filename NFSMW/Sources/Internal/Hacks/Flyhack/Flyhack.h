#pragma once

#include "../../Includes.h"
#include "AppliedHooks/VehiclesCollector.h"

class Flyhack
{
public:
	Flyhack(uintptr_t* playerAdressY)
	{
		this->playerAdressY = playerAdressY;
		this->minimumPositionY = 0.1f;
		this->maximumPositionY = 350.0f;
		this->lastPlayerPositionY = NULL;

		VehiclesCollector::SetHookInitializeVehicles();
	}

	void ApplyEffect(uintptr_t* targetAdressY, uintptr_t flyhackForce);
	void ApplyEffectPlayer(uintptr_t flyhackForce);
	void ApplyEffectAllOtherVehicles(uintptr_t flyhackForce);
	void ResetEffect();

private:
	float minimumPositionY;
	float maximumPositionY;
	uintptr_t* playerAdressY;
	uintptr_t lastPlayerPositionY;
};