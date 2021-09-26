#pragma once

#include "IComponentInterface.h"
#include "float4.h"

class ZSpatialEntity;

class __declspec(novtable) IHM5CoverPlane : public IComponentInterface
{
public:
	~IHM5CoverPlane() override = default;
	virtual float GetCoverDepth() const = 0;
	virtual bool IsHighCover() const = 0;
	virtual bool IsMediumCover() const = 0;
	virtual bool IsLowCover() const = 0;
	virtual float GetCoverLength() const = 0;
	virtual ZSpatialEntity* GetNeighborCoverPlane(const float4& param1, float4& param2) const = 0;
	virtual float GetCoverHeight() const = 0;
	virtual float4 GetCoverDir() const = 0;
	virtual bool IsWindowCover() const = 0;

	static void RegisterType();
	IHM5CoverPlane() = default;
};
