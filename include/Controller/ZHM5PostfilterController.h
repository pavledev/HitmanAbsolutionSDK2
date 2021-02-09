#pragma once

#include "ZEntityImpl.h"
#include "IGamePostfilterControllerEntity.h"
#include "SColorRGB.h"
#include "TResourcePtr.h"
#include "ZRenderTextureResource.h"
#include "TEntityRef.h"
#include "IRenderPostfilterParametersEntity.h"

class alignas(4) ZHM5PostfilterController : public ZEntityImpl, public IGamePostfilterControllerEntity
{
public:
    float m_fSpatialBlurStart;
    SVector3 m_fSpatialBlurCenter;
    float m_fSpatialBlurFade;
    float m_fSpatialBlurriness;
    float m_fRadialBluriness;
    float m_fRadialBlurStart;
    SVector2 m_vRadialBlurCenter;
    float m_fRadialBlurFadeFactor;
    bool m_bScreenDecalsEnabled;
    float m_fScreenDecalsTTL;
    float m_fScreenDecalsSettleTime;
    float m_fScreenDecalsFadeTime;
    float m_fScreenDecalsScaleTime;
    float m_fScreenDecalsOpacity;
    float m_fScreenDecalsRefractionScale;
    float m_fScreenDecalsBlurrinessScale;
    float m_fScreenDecalsColorScale;
    SColorRGB m_ScreenDecalsColor;
    SVector2 m_vScreenDecalsTiles;
    float m_fScreenDecalsSizeDeviation;
    SVector3 m_vScreenDecalsSingleSize;
    ZResourcePtr m_pScreenDecalsSingleTex;
    SVector3 m_vScreenDecalsPairASize;
    ZResourcePtr m_pScreenDecalsPairATex;
    SVector3 m_vScreenDecalsPairBSize;
    ZResourcePtr m_pScreenDecalsPairBTex;
    TResourcePtr<ZRenderTextureResource> m_pScreenDecalsTexRPs[3];
    SRenderPostfilterPerScreenDecalParametersInternal m_ScreenDecals[4];
    unsigned int m_nScreenDecalsNumAdded;
    TEntityRef<IRenderPostfilterParametersEntity> m_rCurrentGameMode;
    bool m_bSpatialBlurEnabled;
    bool m_bSpatialBlurUpdate;
    bool m_bRadialBlurUpdate;
    bool m_bRadialBlurEnabled;
    bool m_bSniperUpdate;
    bool m_bSniperEnabled;
    bool m_bDepthBlurUpdate;
    float m_fDepthBlurValue;
    float m_fSniperBlur;
    ZEntityRef m_rPostfilterControllerEntity;
    bool m_bHitmanRegistered;
};
