#pragma once

#include "../../../Includes.h"

#include "../CheatsBase.h"
#include "../../GameClasses/VehicleEntity.h"

#include "../../AppliedHooks/HooksList/VehiclesCollector.h"

class Teleport : public CheatBase
{
public:
	void TeleportLocation(VehicleEntity* targetEntity, Vector3* targetLocation);
	void TeleportHighestLocation(VehicleEntity* targetEntity);
	void TeleportPlayerToHighestLocation();
};