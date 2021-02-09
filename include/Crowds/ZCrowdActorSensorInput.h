#pragma once

#include "SVector2.h"

class ZCrowdActorSensorInput
{
public:
    float m_nActorRadius;
    float m_nStaticProbeLength;
    SVector2 m_vStaticProbeDir;
    float m_nWantedNeighborhoodRadius;
    SVector2 m_vDynamicProbeDir;
    float m_nDynamicProbeOffset;
    float m_nDensityCheckRadius;
    SVector2 m_vDensityCheckDir;
    float m_nDensityCheckOffset;
    __int16 m_nIgnoreList[4];
    unsigned __int8 m_nNumActiveIgnoreSlots;
    unsigned __int8 m_bAllowPanicOnlyCells;
    unsigned __int8 m_bAllowTeleportOutCells;
    unsigned __int8 m_bIgnoreDeadBodies;
    unsigned __int8 m_bIgnorePanicedActors;
    unsigned __int8 __padding__[3];
};
