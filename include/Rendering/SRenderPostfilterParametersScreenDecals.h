#pragma once

#include "SRenderPostfilterParametersBase.h"
#include "SVector3.h"
#include "SVector2.h"
#include "ZResourcePtr.h"

class SRenderPostfilterParametersScreenDecals : public SRenderPostfilterParametersBase
{
public:
    float m_fTimeToLive;
    float m_fSettleTime;
    float m_fFadeTime;
    float m_fScaleTime;
    float m_fOpacity;
    float m_fRefractionScale;
    float m_fBlurrinessScale;
    float m_fColorScale;
    SVector3 m_vColor;
    SVector2 m_vTiles;
    SVector3 m_vSizes[3];
    ZResourcePtr m_pTextureResources[3];
};
