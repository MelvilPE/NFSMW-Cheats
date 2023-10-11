#pragma once
#include "windows.h"

class Flyhack
{
private:
	uintptr_t lastPositionY;
public:
	Flyhack()
	{
		lastPositionY = 0;
	}

	void ApplyEffect(uintptr_t flyhackForce);
	void ResetEffect();
};