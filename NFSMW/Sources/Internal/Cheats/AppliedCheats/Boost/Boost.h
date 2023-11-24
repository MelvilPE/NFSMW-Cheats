#pragma once

#include "../../../Includes.h"

#include "../CheatsBase.h"
#include "../../GameClasses/VehicleEntity.h"

#include "../../AppliedHooks/HooksList/VehiclesCollector.h"

class Boost : public CheatBase
{
public:
	void ApplyEffectPlayer(float boostForce);
};