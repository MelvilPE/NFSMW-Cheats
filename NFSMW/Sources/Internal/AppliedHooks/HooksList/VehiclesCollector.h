#pragma once
#include "../../Includes.h"

#include "../../Hacks/GameClasses/VehicleEntity.h"

#include "../../Modules/Hooks/Hooks.h"

class VehiclesCollector 
{
public:
	static void SetHookCreateVehicleEntity();
	static std::vector<VehicleEntity*> GetAllVehiclesEntities();
};