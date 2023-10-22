#pragma once
#include "Includes.h"

#include "Cheats/AppliedHooks/AppliedHooksRegistrator.h"
#include "Cheats/AppliedCheats/Flyhack/Flyhack.h"
#include "Cheats/AppliedCheats/Teleport/Teleport.h"
#include "Cheats/AppliedCheats/AntiKB/AntiKB.h"

class Main
{
public:
	static void Run();
	static void FlyhackBlock(Flyhack* flyhack);
	static void TeleportBlock(Teleport* teleport);
	static void AntiKBBlock(AntiKB* antiKB);
};