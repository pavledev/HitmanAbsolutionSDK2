#pragma once

#include "ZCrowdActorCore.h"
#include "CrowdRegionType.h"
#include "CrowdUtil.h"
#include "float4.h"
#include "float1.h"

class ZCrowdRegion
{
public:
    ZCrowdActorCore* m_pOwner;
    CrowdRegionType m_eType;
    CrowdUtil::ECrowdActorMood m_eActorMood;
    float4 m_vCenter;
    float m_nDirection;
    float m_nRadius;
    unsigned int m_nAngle;
    float m_nLifetime;
    float m_nAge;
    float m_nTimeSinceLastPulse;
    float1 m_vCosAng;
    float m_nReactionDelayNear;
    float m_nReactionDelayFar;
    bool m_bIsPointOfInterest;
    bool m_bTurnTowards;
    bool m_bRemoveNeverFlee;
    float m_nPOIHeightOffset;
};
