#pragma once

#include "SVector4.h"

class SWigglerParams
{
public:
    float m_fWigglerPct;
    float m_fWigglerTimeLeft;
    float m_fWigglerRelease;
    float m_fWigglerFrequency;
    SVector4 m_vWigglerRange;
    float m_fWigglerDelay;
    bool m_bLoop;
    void* m_pWigglerId;
    float m_fMinFov;
    float m_fMaxFov;
};
