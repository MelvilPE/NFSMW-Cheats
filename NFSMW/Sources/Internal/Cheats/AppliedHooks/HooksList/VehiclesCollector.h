#pragma once
#include "../../../Includes.h"

#include "../../../Cheats/GameClasses/VehicleEntity.h"

#include "../../../Modules/Hooks/Hooks.h"

class VehiclesCollector 
{
public:
	static void SetHookCreateVehicleEntity();
	static std::vector<VehicleEntity*> GetAllVehiclesEntities();
};