#include "Boost.h"

void Boost::ApplyEffectPlayer()
{
	VehicleEntity* playerEntity = GetPlayerEntity();
	if (playerEntity == nullptr)
	{
		MessageBox(NULL, "Boost::ApplyEffectPlayer failed to activate boost, playerEntity pointer can't be nullptr!", "NFSMW", 16);
		return;
	}

	DWORD curProtection;
	VirtualProtect(playerEntity, sizeof(VehicleEntity), PAGE_EXECUTE_READWRITE, &curProtection);

	Vector3 playerAppliedForces = playerEntity->GetAppliedForces();
	if (playerAppliedForces.HasSameValues(0.0f, 0.0f, 0.0f))
	{
		MessageBox(NULL, "Boost::ApplyEffectPlayer failed to activate boost, playerEntity must be in movement!", "NFSMW", 16);
		return;
	}

	playerAppliedForces.SetAxisX(playerAppliedForces.GetAxisX() * 10);
	playerAppliedForces.SetAxisY(playerAppliedForces.GetAxisY() * 10);
	playerAppliedForces.SetAxisZ(playerAppliedForces.GetAxisZ() * 10);

	playerEntity->SetAppliedForces(playerAppliedForces);

	DWORD temp;
	VirtualProtect(playerEntity, sizeof(VehicleEntity), curProtection, &temp);
}
