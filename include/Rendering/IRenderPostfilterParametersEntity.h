#pragma once

#include "IComponentInterface.h"
#include "SVector2.h"
#include "SVector3.h"

class ZRenderPostfilterControllerEntity;
class ZEvent0;
struct SRenderPostfilterParameters;
template <class T> class TEntityRef;

class __declspec(novtable) IRenderPostfilterParametersEntity : public IComponentInterface
{
public:
	~IRenderPostfilterParametersEntity() override = default;
	virtual void UpdateParameters(SRenderPostfilterParameters& renderPostfilterParameters, bool param2) = 0;
	virtual void SetController(const TEntityRef<ZRenderPostfilterControllerEntity>& entityRef) = 0;
	virtual bool GaussianBlurEnabled() const = 0;
	virtual bool ColorCorrectionGetEnabled() const = 0;
	virtual bool ColorCorrectionGetDepthRemapEnabled() const = 0;
	virtual void ColorCorrectionSetDepthRemapEnabled(bool param1) = 0;
	virtual float ColorCorrectionGetDepthRemapNearRange() const = 0;
	virtual void ColorCorrectionSetDepthRemapNearRange(float param1) = 0;
	virtual float ColorCorrectionGetDepthRemapFarRange() const = 0;
	virtual void ColorCorrectionSetDepthRemapFarRange(float param1) = 0;
	virtual bool DepthOfFieldGetEnabled() const = 0;
	virtual void DepthOfFieldSetEnabled(bool param1) = 0;
	virtual float DepthOfFieldGetBlurriness() const = 0;
	virtual void DepthOfFieldSetBlurriness(float param1) = 0;
	virtual bool RadialBlurGetEnabled() const = 0;
	virtual void RadialBlurSetEnabled(bool param1) = 0;
	virtual float RadialBlurGetBlurriness() const = 0;
	virtual void RadialBlurSetBlurriness(float param1) = 0;
	virtual SVector2 RadialBlurGetCenter() const = 0;
	virtual void RadialBlurSetCenter(const SVector2& vector2) = 0;
	virtual float RadialBlurGetStart() const = 0;
	virtual void RadialBlurSetStart(float param1) = 0;
	virtual bool SpatialBlurGetEnabled() const = 0;
	virtual void SpatialBlurSetEnabled(bool param1) = 0;
	virtual float SpatialBlurGetBlurriness() const = 0;
	virtual void SpatialBlurSetBlurriness(float param1) = 0;
	virtual SVector3 SpatialBlurGetCenter() const = 0;
	virtual void SpatialBlurSetCenter(const SVector3& vector3) = 0;
	virtual float SpatialBlurGetStart() const = 0;
	virtual void SpatialBlurSetStart(float param1) = 0;
	virtual float SpatialBlurGetFade() const = 0;
	virtual void SpatialBlurSetFade(float param1) = 0;
	virtual bool DistortionWobbleGetEnabled() const = 0;
	virtual void DistortionWobbleSetEnabled(bool param1) = 0;
	virtual float DistortionWobbleGetScale() const = 0;
	virtual void DistortionWobbleSetScale(float param1) = 0;
	virtual SVector2 DistortionWobbleGetWaveLength() const = 0;
	virtual void DistortionWobbleSetWaveLength(const SVector2& vector2) = 0;
	virtual SVector2 DistortionWobbleGetSpeed() const = 0;
	virtual void DistortionWobbleSetSpeed(const SVector2& vector2) = 0;
	virtual bool DistortionWobbleGetUseRealTime() const = 0;
	virtual void DistortionWobbleSetUseRealTime(bool param1) = 0;
	virtual void SetModified(unsigned int param1) = 0;
	virtual unsigned int GetModified() const = 0;
	virtual ZEvent0& GetParametersChangedEvent() = 0;

	IRenderPostfilterParametersEntity(const IRenderPostfilterParametersEntity& __that);
	IRenderPostfilterParametersEntity() = default;
	IRenderPostfilterParametersEntity& operator=(const IRenderPostfilterParametersEntity& __that);
};
