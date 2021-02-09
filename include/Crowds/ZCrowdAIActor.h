#pragma once

#include "TArray.h"
#include "ZLinkedEntity.h"

class ZCrowdAIActor
{
public:
    bool m_bInUse;
    TEntityRef<ZLinkedEntity> m_pLinked;
    ZAnimationBonePose* m_pPose;
    ZAnimationBonePose* m_pOrgPose;
    float m_fBlendTime;
    float m_fTimer;
};
