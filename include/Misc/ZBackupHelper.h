#pragma once

#include "ZGameTime.h"

class ZBackupHelper
{
public:
    bool m_bCombatZonesReset;
    bool m_bSpawnMessageShown;
    int m_nActorsSpawned;
    ZGameTime m_lastBackupTime;
};
