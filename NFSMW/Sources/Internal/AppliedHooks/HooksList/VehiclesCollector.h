#pragma once
#include "../../Includes.h"
#include "../../Classes/Math/Vector3.h"
#include "../../Modules/Hooks/Hooks.h"

class VehiclesCollector 
{
public:
	static void SetHookInitializeVehiclesPosition();
	static std::vector<Vector3*> GetAllInitializedVehiclesPosition();
};