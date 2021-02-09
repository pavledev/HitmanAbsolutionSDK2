#pragma once

#include "ZContentKitMenuSetup.h"
#include "ZHM5WeaponConfigurator.h"

class ZFireArmKitMenuSetup : public ZContentKitMenuSetup
{
public:
    ZRuntimeResourceID m_WeaponResource;
    ZHM5WeaponConfigurator m_Configurator;
};
