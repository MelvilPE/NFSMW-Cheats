#pragma once
#include "Includes.h"

#include "AppliedHooks/AppliedHooksRegistrator.h"
#include "Hacks/Flyhack/Flyhack.h"
#include "Hacks/Teleport/Teleport.h"

class Main
{
public:
	static void Run();
	static void FlyhackBlock(Flyhack* flyhack);
	static void TeleportBlock(Teleport* teleport);
};