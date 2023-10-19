#include "VehiclesCollector.h"

bool IsCreateVehicleEntityHooked = false;
uintptr_t CreateVehicleEntityHookJump = NULL;

std::vector<VehicleEntity*> createdVehiclesEntities;
VehicleEntity* currentVehicleEntity = nullptr;

/* Short function to add a vehicle entity address retrieved from the hook
 * Check if it is not nullptr and already present in the list
 */
void PushCreatedVehicleEntity()
{
	if (currentVehicleEntity == nullptr)
		return;

	auto it = std::find(createdVehiclesEntities.begin(), createdVehiclesEntities.end(), currentVehicleEntity);
	if (it == createdVehiclesEntities.end())
	{
		createdVehiclesEntities.push_back(currentVehicleEntity);
	}
}

void __declspec(naked) HookCreateVehicleEntity()
{
	/* Get the address of vehicle entity */
	_asm
	{
		mov currentVehicleEntity, edx
	}
	/* Prepare registers for function call */
	_asm
	{
		pushad
		pushfd
	}
	PushCreatedVehicleEntity();
	_asm
	{
		popfd
		popad
	}
	/* Execution of overwritten instructions and normal execution */
	_asm
	{
		mov eax, dword ptr[ebp + 0x34]
		push 0
		jmp[CreateVehicleEntityHookJump]
	}
}

void VehiclesCollector::SetHookCreateVehicleEntity()
{
	uintptr_t hookAdress = reinterpret_cast<uintptr_t>(GetModuleHandle(NULL)) + 0x2B5B0F;
	uintptr_t hookLenght = 5;

	if (!IsCreateVehicleEntityHooked)
	{
		if (!hookAdress)
		{
			MessageBox(NULL, "VehiclesCollector::SetHookCreateVehicleEntity failed to deduce function hooking adress.", "NFSMW", 16);
			return;
		}

		CreateVehicleEntityHookJump = hookAdress + hookLenght;
		Hooks::Hook((char*)hookAdress, (char*)HookCreateVehicleEntity, hookLenght);
		IsCreateVehicleEntityHooked = true;
	}
}

std::vector<VehicleEntity*> VehiclesCollector::GetAllVehiclesEntities()
{
	return createdVehiclesEntities;
}