#pragma once

#include "EBlendNodeStatus.h"
#include "TEntityRef.h"
#include "ZHM5GameCamProfileEntity.h"

class SBlendNode
{
public:
    EBlendNodeStatus m_eStatus;
    float m_fBlendTime;
    float m_fBlendDuration;
    TEntityRef<ZHM5GameCamProfileEntity> m_rGameGamProfile;
};
