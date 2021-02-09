#pragma once

#include "ZBoundedEntity.h"

class ZAISoundModifierVolume : public ZBoundedEntity
{
public:
    SVector3 m_vGlobalSize;
    float m_fDampening;
};
