#pragma once

#include "SRenderPostfilterParametersBase.h"
#include "SVector4.h"
#include "SVector2.h"

class SRenderPostfilterParametersFog : public SRenderPostfilterParametersBase
{
public:
    bool m_bUseQuarterRes;
    bool m_bFogBeforePostEffects;
    bool m_bGlobal;
    float m_fDensity;
    SVector4 m_vColor;
    SVector4 m_vTurbulenceOctaveVelocity[4];
    SVector4 m_vFogTurbulenceData;
    SVector2 m_vFogNearDistance;
};
