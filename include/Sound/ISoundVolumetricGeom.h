#pragma once

#include "IComponentInterface.h"

class __declspec(novtable) ISoundVolumetricGeom : public IComponentInterface
{
public:
	~ISoundVolumetricGeom() override = default;
	virtual void SetOwner(ZSoundVolumetricAspect* soundVolumetricAspect) = 0;
	virtual void InitVolumetricGeom() = 0;
	virtual void SetEarPosition(const float4& param1) = 0;
	virtual int GetNumPrimarySurfacePoints() const = 0;
	virtual int GetNumSecondarySurfacePoints() const = 0;
	virtual const float4 GetPrimarySurfacePointLocal(const int param1) = 0;
	virtual const float4 GetPrimarySurfacePointWorld(const int param1) = 0;
	virtual const float4 GetSecondarySurfacePointLocal(const int param1) = 0;
	virtual const float4 GetSecondarySurfacePointWorld(const int param1) = 0;
	virtual void PreparePrimaryHitTest() = 0;
	virtual void PrepareSecondaryHitTest() = 0;
	virtual bool UpdateTime(float param1) = 0;
	virtual const float4 GetDopplerPoint() const = 0;
	virtual const float GetVolumetricGain() const = 0;
	virtual const float GetInsideness() const = 0;

	static void RegisterType();
	ISoundVolumetricGeom() = default;
};
