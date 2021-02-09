#pragma once

#include "SHM5WeaponConfig.h"
#include "TSet.h"
#include "ZString.h"
#include "TEntityRef.h"
#include "ZHM5WeaponBasicConfigEntity.h"
#include "ZFireArmKitEntity.h"
#include "EWeaponUpgConfig.h"

class ZHM5WeaponConfigurator
{
public:
    SHM5WeaponConfig m_Configs[3];
    TSet<ZString> m_VisibleBones[3];
    TEntityRef<ZHM5WeaponBasicConfigEntity> m_rBasicConfig;
    TEntityRef<ZFireArmKitEntity> m_rFireArmKit;
    EWeaponUpgConfig m_eCurrentConfig;
    unsigned __int8 m_iPossibleUpgrades;
    bool m_bInitialized;
    bool m_bSavegameAuthority;
    bool m_bDirty;
};
