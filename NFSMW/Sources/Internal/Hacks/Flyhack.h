#pragma once

#include "windows.h"
#include <vector>

class Flyhack
{
public:
	Flyhack(uintptr_t* playerAdressY, uintptr_t* startVehiclesAdressY)
	{
		this->playerAdressY = playerAdressY;
		this->startVehiclesAdressY = startVehiclesAdressY;
		this->minimumPositionY = 0.1f;
		this->maximumPositionY = 350.0f;

		/* We find each Y position of cops after 0x80 bytes */
		this->entityLenght = 0xB0; 
		this->lastPlayerPositionY = NULL;
	}

	void ApplyEffect(uintptr_t* targetAdressY, uintptr_t flyhackForce);
	void ApplyEffectPlayer(uintptr_t flyhackForce);
	void ApplyEffectAllOtherVehicles(uintptr_t flyhackForce);
	void ResetEffect();

private:
	float minimumPositionY;
	float maximumPositionY;
	uintptr_t* playerAdressY;
	uintptr_t* startVehiclesAdressY;

	uintptr_t lastPlayerPositionY;
	uintptr_t entityLenght;
	std::vector<uintptr_t*> FindAllVehiclesPointersY();
};