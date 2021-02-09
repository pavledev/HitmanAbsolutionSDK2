#pragma once

#include "ZSpatialEntity.h"
#include "ZLinkedEntity.h"

class ZHM5WeaponHandPosBox : public ZSpatialEntity
{
public:
    TEntityRef<ZLinkedEntity> m_linkedEntity;
    ZString m_BoneName;
    float m_fSwivelAngle;
    float m_fSwivelContribution;
};
