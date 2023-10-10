#include "Flyhack.h"
// 009386DC
void Flyhack::ApplyGravity(uintptr_t flyhackForce)
{
	uintptr_t calculatePositionY = reinterpret_cast<uintptr_t>(GetModuleHandle(NULL));
	calculatePositionY += 0x5386DC; // static offset corresponding to Y axis position
	uintptr_t* positionY = reinterpret_cast<uintptr_t*>(calculatePositionY);

	DWORD curProtection;
	VirtualProtect(positionY, sizeof(uintptr_t), PAGE_EXECUTE_READWRITE, &curProtection);
	
	*positionY = *positionY + flyhackForce;

	DWORD temp;
	VirtualProtect(positionY, sizeof(uintptr_t), curProtection, &temp);
}