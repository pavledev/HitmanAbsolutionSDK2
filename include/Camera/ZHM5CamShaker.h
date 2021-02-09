#pragma once

#include "SVector4.h"
#include "SWigglerParams.h"

class ZHM5CamShaker
{
public:
    SVector4 m_vWigglerPrevPos;
    SVector4 m_vWigglerNextPos;
    float m_fWigglerPct;
    float m_fWigglerTimeLeft;
    float m_fWigglerRelease;
    float m_fWigglerFrequency;
    SVector4 m_vWigglerRange;
    float m_fWigglerDelay;
    bool m_bWigglerPostfilter;
    bool m_bActive;
    SVector4 m_vFocalOffset;
    float m_fRollOffset;
    float m_fFovOffset;
    float m_fMinFov;
    float m_fMaxFov;
    bool m_bLoop;
    SWigglerParams m_sOverridenWiggler;
    bool m_bEnabled;
    void* m_pWigglerId;
};
