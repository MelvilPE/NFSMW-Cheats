#include "Flyhack.h"

void Flyhack::ApplyEffect(uintptr_t flyhackForce)
{
	uintptr_t pCalculatePositionY = reinterpret_cast<uintptr_t>(GetModuleHandle(NULL));
	pCalculatePositionY += 0x5386DC; // static offset corresponding to Y axis position
	uintptr_t* positionY = reinterpret_cast<uintptr_t*>(pCalculatePositionY);

	DWORD curProtection;
	VirtualProtect(positionY, sizeof(uintptr_t), PAGE_EXECUTE_READWRITE, &curProtection);
	
	if (*positionY == NULL)
	{
		MessageBox(NULL, "Flyhack::ApplyEffect failed to activate flyhack, since car is not on the map!", "NFSMW", 16);
		return;
	}

	*positionY += flyhackForce;
	
	while (*positionY <= this->lastPositionY)
	{
		/* Too much force! */
		*positionY += flyhackForce - flyhackForce/2;
	}
	this->lastPositionY = *positionY;

	DWORD temp;
	VirtualProtect(positionY, sizeof(uintptr_t), curProtection, &temp);
}

void Flyhack::ResetEffect()
{
	this->lastPositionY = NULL;
}