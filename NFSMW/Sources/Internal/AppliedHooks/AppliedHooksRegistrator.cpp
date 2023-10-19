#include "AppliedHooksRegistrator.h"

void AppliedHooksRegistrator::ApplyRegisteredHooks()
{
	VehiclesCollector::SetHookCreateVehicleEntity();
}