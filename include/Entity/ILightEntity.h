#pragma once

#include "IComponentInterface.h"

struct SColorRGB;
struct SVector2;

class __declspec(novtable) ILightEntity : public IComponentInterface
{
public:
	enum ELightType
	{
		LT_DIRECTIONAL = 0,
		LT_ENVIRONMENT = 1,
		LT_OMNI = 2,
		LT_SPOT = 3,
		LT_SQUARESPOT = 4,
		LT_CAPSULE = 5
	};

	enum EFrameIndexStrategy
	{
		WRAP = 0,
		CLAMP = 1
	};

	enum ERoomLightFlow
	{
		ROOM_LOCAL = 0,
		THROUGH_GATES = 1,
		ALL_ROOMS = 2
	};

	~ILightEntity() override = default;
	virtual const SColorRGB& GetDiffuseColor() const = 0;
	virtual ELightType GetLightType() const = 0;
	virtual float GetCapsuleHeight() const = 0;
	virtual const SVector2& GetNearAttenuation() const = 0;
	virtual const SVector2& GetFarAttenuation() const = 0;
	virtual bool GetCastOmniShadows() const = 0;
	virtual const SVector2& GetAngularAttenuation() const = 0;
	virtual void SetDiffusePower(const float param1) = 0;
	virtual void SetDiffuseColor(const SColorRGB& colorRGB) = 0;

	static void RegisterType();
	ILightEntity() = default;
};
