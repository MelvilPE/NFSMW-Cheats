#include "AntiKB.h"

void AntiKB::EnableOrDisable()
{
	VehicleEntity* playerEntity = GetPlayerEntity();
	float vehicleWeight = playerEntity->GetWeight();

	enabled = !enabled;
	if (enabled)
		vehicleWeight = vehicleWeight * 3;
	else
		vehicleWeight = vehicleWeight / 3;

	playerEntity->SetWeight(vehicleWeight);
}