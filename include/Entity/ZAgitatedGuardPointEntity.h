#pragma once

#include "ZSpatialEntity.h"
#include "DifficultyLevelEnum.h"

class ZAgitatedGuardPointEntity : public ZSpatialEntity
{
public:
    bool m_bEnabled;
    DifficultyLevelEnum m_eMinDifficulty;
    bool m_bAllowActorGroupA;
    bool m_bAllowActorGroupB;
    bool m_bAllowActorGroupC;
    bool m_bAllowActorGroupD;
};
