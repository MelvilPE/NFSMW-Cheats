#include "Hooks.h"

static const DWORD MINIMUM_SUPPORTED_JMP_HOOK_LEN = 5;
static const DWORD NOP_OPCODE = 0x90;
static const DWORD JMP_OPCODE = 0xE9;

bool Hooks::Hook(void* hookPos, void* hookedFuncPos, int len)
{
	if (len < (int)MINIMUM_SUPPORTED_JMP_HOOK_LEN)
	{
		return false;
	}

	DWORD curProtection;
	VirtualProtect(hookPos, len, PAGE_EXECUTE_READWRITE, &curProtection);
	memset(hookPos, NOP_OPCODE, len);

	DWORD relativeAddress = ((DWORD)hookedFuncPos - (DWORD)hookPos) - MINIMUM_SUPPORTED_JMP_HOOK_LEN;

	*(BYTE*)hookPos = (BYTE)JMP_OPCODE;
	*(DWORD*)((DWORD)hookPos + 1) = relativeAddress;

	DWORD temp;
	VirtualProtect(hookPos, len, curProtection, &temp);

	return true;
}

intptr_t Hooks::TrampHook(char* hookPos, char* hookedFuncPos, const intptr_t len)
{
	if (len < MINIMUM_SUPPORTED_JMP_HOOK_LEN)
	{
		return false;
	}

	void* gateway = VirtualAlloc(0, len + MINIMUM_SUPPORTED_JMP_HOOK_LEN, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

	memcpy_s(gateway, len, hookPos, len);

	intptr_t hookAfterPos = ((intptr_t)hookPos - (intptr_t)gateway) - MINIMUM_SUPPORTED_JMP_HOOK_LEN;
	*(char*)((intptr_t)gateway + len) = (intptr_t)JMP_OPCODE;
	*(intptr_t*)((intptr_t)gateway + len + 1) = hookAfterPos;

	Hook(hookPos, hookedFuncPos, len);

	return (intptr_t)gateway;
}