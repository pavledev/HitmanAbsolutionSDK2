#pragma once

#include "float4.h"
#include "SVector3.h"
#include "SCapsule.h"
#include "ZEntityRef.h"
#include "ZCollisionLayerColorGetter.h"

class IPhysicsObject;

class __declspec(novtable) ICharacterController
{
public:
	virtual ~ICharacterController() = default;
	virtual void SetEntity(const ZEntityRef& entityRef) = 0;
	virtual float4 GetPosition() const = 0;
	virtual void RelocateTo(const float4& param1) = 0;
	virtual float4 SweepToPos(const float4& param1, const float4& param2) = 0;
	virtual void Update(const float4& param1) = 0;
	virtual bool IsSupported() const = 0;
	virtual bool IsSideBlocked() const = 0;
	virtual SVector3 GetSideBlockedNormal() const = 0;
	virtual float4 GetSurfaceNormal() const = 0;
	virtual void ReportSceneChanged() = 0;
	virtual bool CheckOverlapAtPos(const float4& param1, unsigned int param2, unsigned int param3, bool param4, bool param5) = 0;
	virtual bool CheckOverlapWithEntityAtPos(const float4& param1, unsigned int param2, unsigned int param3, bool param4, bool param5, IPhysicsObject* physicsObject) = 0;
	virtual void GetCapsulePropertiesInternal(float& param1, float& param2, float& param3) const = 0;
	virtual SCapsule GetG2Capsule() const = 0;
	virtual void DrawShape(const ZCollisionLayerColorGetter& collisionLayerColorGetter) const = 0;

	ICharacterController() = default;
};
