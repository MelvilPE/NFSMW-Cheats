#pragma once

#include "../Includes.h"

#include "GameClasses/VehicleEntity.h"

class CheatBase
{
public:
	uintptr_t GetModuleHandleAlias();
	VehicleEntity* GetPlayerEntity();
private:
	uintptr_t moduleHandle = reinterpret_cast<uintptr_t>(GetModuleHandle(NULL));
};