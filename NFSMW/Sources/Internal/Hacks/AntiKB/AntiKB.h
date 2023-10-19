#pragma once

#include "../../Includes.h"

#include "../GameClasses/VehicleEntity.h"

class AntiKB
{
public:
    AntiKB()
    {
        uintptr_t moduleHandle = reinterpret_cast<uintptr_t>(GetModuleHandle(NULL));
        this->playerEntity = reinterpret_cast<VehicleEntity*>(moduleHandle + 0x5386C8);
        this->enabled = false;
    }

    void EnableOrDisable();

private:
    VehicleEntity* playerEntity;
    bool enabled;
};