#pragma once

#include "ZHM5BaseMovement.h"
#include "ZHM5DisguiseSafeZoneEntity.h"
#include "ZMapPoly.h"

class alignas(16) ZHM5DisguiseSafeZoneMovement : public ZHM5BaseMovement
{
public:
    TEntityRef<ZHM5DisguiseSafeZoneEntity> m_rSafeZone;
    unsigned int m_nSafeZoneNetworkId;
    unsigned int m_nNumActiveFrames;
    bool m_bWaitingForExitEvent;
    float m_fBlendInFraction;
    SMatrix m_mStart;
    SMatrix m_mEnd;
    ZMapPoly m_MapPoly;
    bool m_bForceNoEnterAnim;
};
