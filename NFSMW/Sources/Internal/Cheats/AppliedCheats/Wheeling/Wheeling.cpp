#include "Wheeling.h"

void Wheeling::ApplyEffectPlayer()
{
	VehicleEntity* playerEntity = GetPlayerEntity();
	if (playerEntity == nullptr)
	{
		MessageBox(NULL, "Wheeling:ApplyEffectPlayer failed to activate wheeling, playerEntity pointer can't be nullptr!", "NFSMW", 16);
		return;
	}
	
	DWORD curProtection;
	VirtualProtect(playerEntity, sizeof(VehicleEntity), PAGE_EXECUTE_READWRITE, &curProtection);

	playerEntity->SetWeight(-(playerEntity->GetWeight()));

	Sleep(2.5 * 1000);

	playerEntity->SetWeight(-(playerEntity->GetWeight()));

	DWORD temp;
	VirtualProtect(playerEntity, sizeof(VehicleEntity), curProtection, &temp);
}
