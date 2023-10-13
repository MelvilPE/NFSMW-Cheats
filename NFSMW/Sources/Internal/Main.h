#pragma once
#include "Includes.h"

#include "AppliedHooks/AppliedHooksRegistrator.h"
#include "Hacks/Flyhack/Flyhack.h"

class Main
{
public:
	static void Run();
	static void FlyhackBlock(Flyhack* flyhack);
};