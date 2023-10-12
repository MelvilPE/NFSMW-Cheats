#pragma once

#include "../../Includes.h"

class Hooks {
public:
	static bool Hook(void* hookPos, void* hookedFuncPos, int len);
	static intptr_t TrampHook(char* hookPos, char* hookedFuncPos, const intptr_t len);
};

