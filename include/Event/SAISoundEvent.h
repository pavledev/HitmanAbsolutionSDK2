#pragma once

#include "ZEntityRef.h"
#include "TEntityRef.h"
#include "ZSpatialEntity.h"
#include "EAIEventType.h"

class alignas(16) SAISoundEvent
{
public:
    ZEntityRef m_pSender;
    TEntityRef<ZSpatialEntity> m_pSpatial;
    float4 m_vPosition;
    unsigned __int16 m_nRoomID;
    EAIEventType m_eType;
    float m_fRange;
};
