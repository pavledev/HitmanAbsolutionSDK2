#pragma once

#include "ZRenderPostfilterStarDefinition.h"
#include "SRenderPostfilterGlareDefinition.h"
#include "float4.h"
#include "ERenderPostfilterGlareType.h"

class ZRenderPostfilterGlareDefinition
{
public:
    ZRenderPostfilterStarDefinition* m_pStarDefinition;
    SRenderPostfilterGlareDefinition* m_pGlareDefinition;
    float4* m_pChromaticAberrationColor;
    ERenderPostfilterGlareType m_eGlareType;
};
