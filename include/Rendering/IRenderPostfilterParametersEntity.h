#pragma once

#include "IComponentInterface.h"
#include "SRenderPostfilterParameters.h"
#include "TEntityRef.h"
#include "ZEvent0.h"

class ZRenderPostfilterControllerEntity;

class IRenderPostfilterParametersEntity : public IComponentInterface
{
public:
    virtual void UpdateParameters(SRenderPostfilterParameters*, bool);
    virtual void SetController(const TEntityRef<ZRenderPostfilterControllerEntity>*);
    virtual bool GaussianBlurEnabled();
    virtual bool ColorCorrectionGetEnabled();
    virtual bool ColorCorrectionGetDepthRemapEnabled();
    virtual void ColorCorrectionSetDepthRemapEnabled(bool);
    virtual float ColorCorrectionGetDepthRemapNearRange();
    virtual void ColorCorrectionSetDepthRemapNearRange(float);
    virtual float ColorCorrectionGetDepthRemapFarRange();
    virtual void ColorCorrectionSetDepthRemapFarRange(float);
    virtual bool DepthOfFieldGetEnabled();
    virtual void DepthOfFieldSetEnabled(bool);
    virtual float DepthOfFieldGetBlurriness();
    virtual void DepthOfFieldSetBlurriness(float);
    virtual bool RadialBlurGetEnabled();
    virtual void RadialBlurSetEnabled(bool);
    virtual float RadialBlurGetBlurriness();
    virtual void RadialBlurSetBlurriness(float);
    virtual SVector2 RadialBlurGetCenter();
    virtual void RadialBlurSetCenter(const SVector2*);
    virtual float RadialBlurGetStart();
    virtual void RadialBlurSetStart(float);
    virtual bool SpatialBlurGetEnabled();
    virtual void SpatialBlurSetEnabled(bool);
    virtual float SpatialBlurGetBlurriness();
    virtual void SpatialBlurSetBlurriness(float);
    virtual SVector3* SpatialBlurGetCenter(SVector3* result);
    virtual void SpatialBlurSetCenter(const SVector3*);
    virtual float SpatialBlurGetStart();
    virtual void SpatialBlurSetStart(float);
    virtual float SpatialBlurGetFade();
    virtual void SpatialBlurSetFade(float);
    virtual bool DistortionWobbleGetEnabled();
    virtual void DistortionWobbleSetEnabled(bool);
    virtual float DistortionWobbleGetScale();
    virtual void DistortionWobbleSetScale(float);
    virtual SVector2 DistortionWobbleGetWaveLength();
    virtual void DistortionWobbleSetWaveLength(const SVector2*);
    virtual SVector2 DistortionWobbleGetSpeed();
    virtual void DistortionWobbleSetSpeed(const SVector2*);
    virtual bool DistortionWobbleGetUseRealTime();
    virtual void DistortionWobbleSetUseRealTime(bool);
    virtual void SetModified(unsigned int);
    virtual unsigned int GetModified();
    virtual ZEvent0* GetParametersChangedEvent();
};
