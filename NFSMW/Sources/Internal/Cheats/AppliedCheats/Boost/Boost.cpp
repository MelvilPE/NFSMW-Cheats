#include "Boost.h"

void Boost::ApplyEffectPlayer(float boostForce)
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

	playerAppliedForces.SetAxisX(playerAppliedForces.GetAxisX() * boostForce);
	playerAppliedForces.SetAxisY(playerAppliedForces.GetAxisY() * boostForce);
	playerAppliedForces.SetAxisZ(playerAppliedForces.GetAxisZ() * boostForce);

	playerEntity->SetAppliedForces(playerAppliedForces);

	DWORD temp;
	VirtualProtect(playerEntity, sizeof(VehicleEntity), curProtection, &temp);
}
