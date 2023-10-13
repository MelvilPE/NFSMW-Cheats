#include "VehiclesCollector.h"

bool IsInitializeVehiclesPositionHooked = false;
uintptr_t InitializeVehiclesPositionHookJump = NULL;

std::vector<Vector3*> initializedVehiclesPosition;
Vector3* currentInitializedVehiclePosition = nullptr;

/* Short function to add a position address retrieved from the hook
 * Check if it is not nullptr and already present in the list
 */
void PushInitializedVehiclePosition()
{
	if (currentInitializedVehiclePosition == nullptr)
		return;

	auto it = std::find(initializedVehiclesPosition.begin(), initializedVehiclesPosition.end(), currentInitializedVehiclePosition);
	if (it == initializedVehiclesPosition.end())
	{
		initializedVehiclesPosition.push_back(currentInitializedVehiclePosition);
	}
}

void __declspec(naked) HookInitializeVehiclesPosition()
{
	/* Get the address of entity position */
	_asm
	{
		push ebx
		mov ebx, ecx
		mov currentInitializedVehiclePosition, ebx
		pop ebx
	}
	/* Prepare registers for function call */
	_asm
	{
		pushad
		pushfd
	}
	PushInitializedVehiclePosition();
	_asm
	{
		popfd
		popad
	}
	/* Execution of overwritten instructions and normal execution */
	_asm
	{
		mov[ecx + 0x04], eax
		mov edx, [edx + 0x08]
		jmp[InitializeVehiclesPositionHookJump]
	}
}

void VehiclesCollector::SetHookInitializeVehiclesPosition()
{
	uintptr_t hookAdress = reinterpret_cast<uintptr_t>(GetModuleHandle(NULL)) + 0x2A6FFF;
	uintptr_t hookLenght = 6;

	if (!IsInitializeVehiclesPositionHooked)
	{
		if (!hookAdress)
		{
			MessageBox(NULL, "VehiclesCollector::SetHookInitializeVehiclesPosition failed to find pattern.", "NFSMW", 16);
			return;
		}

		InitializeVehiclesPositionHookJump = hookAdress + hookLenght;
		Hooks::Hook((char*)hookAdress, (char*)HookInitializeVehiclesPosition, hookLenght);
		IsInitializeVehiclesPositionHooked = true;
	}
}

std::vector<Vector3*> VehiclesCollector::GetAllInitializedVehiclesPosition()
{
	return initializedVehiclesPosition;
}