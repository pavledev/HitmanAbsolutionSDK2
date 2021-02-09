#pragma once

#include "ZSpatialEntity.h"
#include "DifficultyLevelEnum.h"
#include "EGuardPointType.h"
#include "TMaxArray.h"
#include "ZHM5CoverPlane.h"
#include "ZGameTime.h"

class ZGuardPointEntity : public ZSpatialEntity
{
public:
    bool m_bEnabled;
    DifficultyLevelEnum m_eMinDifficulty;
    EGuardPointType m_eType;
    unsigned int m_nMaxNumberOfGuards;
    float m_fRadius;
    float m_fHeight;
    TEntityRef<ZSpatialEntity> m_rHoldTowardPos;
    bool m_bAllowActorGroupA;
    bool m_bAllowActorGroupB;
    bool m_bAllowActorGroupC;
    bool m_bAllowActorGroupD;
    TMaxArray<ZHM5CoverPlane*, 64> m_covers;
    bool m_bHoldValid;
    bool m_bStreamedIn;
    ZGameTime m_tEnableChangeTime;
};
