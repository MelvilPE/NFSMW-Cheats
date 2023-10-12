#include "VehiclesCollector.h"

bool IsInitializeVehiclesHooked = false;
uintptr_t InitializeVehiclesHookJump = NULL;

std::vector<uintptr_t*> initializedVehicles;
uintptr_t* currentInitializedVehicle = nullptr;

/* Short function to add a Y position address retrieved from the hook
 * Check if it is not nullptr and already present in the list
 */
void PushInitializedVehicle()
{
	if (currentInitializedVehicle == nullptr)
		return;

	auto it = std::find(initializedVehicles.begin(), initializedVehicles.end(), currentInitializedVehicle);
	if (it == initializedVehicles.end())
	{
		initializedVehicles.push_back(currentInitializedVehicle);
	}
}

void __declspec(naked) HookInitializeVehicles()
{
	/* Get the address of position Y */
	_asm
	{
		push ebx
		mov ebx, ecx
		add ebx, 0x04
		mov currentInitializedVehicle, ebx
		pop ebx
	}
	/* Prepare registers for function call */
	_asm
	{
		pushad
		pushfd
	}
	PushInitializedVehicle();
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
		jmp[InitializeVehiclesHookJump]
	}
}

void VehiclesCollector::SetHookInitializeVehicles()
{
	uintptr_t hookAdress = reinterpret_cast<uintptr_t>(GetModuleHandle(NULL)) + 0x2A6FFF;
	uintptr_t hookLenght = 6;

	if (!IsInitializeVehiclesHooked)
	{
		uintptr_t InitializeVehiclesHookAddr = (uintptr_t)GetModuleHandle(NULL);
		if (!InitializeVehiclesHookAddr)
		{
			MessageBox(NULL, "VehiclesCollector::SetHookInitializeVehicles failed to find pattern.", "wotblitz-dlc.dll", 16);
			return;
		}

		InitializeVehiclesHookJump = InitializeVehiclesHookAddr + hookLenght;
		Hooks::Hook((char*)InitializeVehiclesHookAddr, (char*)HookInitializeVehicles, hookLenght);
		IsInitializeVehiclesHooked = true;
	}
}

std::vector<uintptr_t*> VehiclesCollector::GetAllInitializedVehicles()
{
	return initializedVehicles;
}