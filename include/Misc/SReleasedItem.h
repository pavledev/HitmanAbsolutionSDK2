#pragma once

#include "TEntityRef.h"
#include "IHM5Item.h"
#include "EThrowType.h"
#include "ZActor.h"

class alignas(16) SReleasedItem
{
public:
    TEntityRef<IHM5Item> m_rItem;
    ZGameTime m_ReleaseTime;
    EThrowType m_eThrowType;
    bool m_bStuckInTarget;
    bool m_bImpactForceApplied;
    float m_fCollisionDisableTime;
    float m_fRotation;
    float m_fRotationSign;
    float m_fVelocity;
    SMatrix m_mvLastAlignedMatPos;
    SMatrix m_mvTargetBoneOffset;
    TEntityRef<ZActor> m_pTarget;
};
