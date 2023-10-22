#include "CheatsBase.h"

uintptr_t CheatBase::GetModuleHandleAlias()
{
	return this->moduleHandle;
}

VehicleEntity* CheatBase::GetPlayerEntity()
{
	return reinterpret_cast<VehicleEntity*>(moduleHandle + 0x5386C8);
}
