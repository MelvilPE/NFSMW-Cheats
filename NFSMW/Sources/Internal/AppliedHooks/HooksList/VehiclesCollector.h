#pragma once
#include "../../Includes.h"
#include "../../Modules/Hooks/Hooks.h"

class VehiclesCollector 
{
public:
	static void SetHookInitializeVehicles();
	static std::vector<uintptr_t*> GetAllInitializedVehicles();
};