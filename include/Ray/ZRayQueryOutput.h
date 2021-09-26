#pragma once

#include "ZRayQueryOutputBase.h"
#include "ZEntityRef.h"
#include "ZPhysicsObjectRef.h"
#include "TEntityRef.h"
#include "TArray.h"
#include "TArrayRef.h"
#include "TResourcePtr.h"
#include "float4.h"

class ZRenderPrimitiveResource;
class ZSpatialEntity;
struct SBoneCollision;

class ZRayQueryOutput : public ZRayQueryOutputBase
{
public:
	ZEntityRef m_BlockingEntity;
	ZPhysicsObjectRef m_pBlockingPhysicsObject;
	TEntityRef<ZSpatialEntity> m_pBlockingSpatialEntity;
	TResourcePtr<ZRenderPrimitiveResource> m_pBlockingPrimitive;
	float4 m_vDecalPosition;
	float4 m_vDecalNormal;
	TArray<SBoneCollision> m_aAllIntersectedBones;

	ZRayQueryOutput() = default;
	void Clear();
	void ClearHit();
	const TArrayRef<SBoneCollision> GetAllBoneHits() const;
	void AddBoneHit(unsigned char nBone, float nT);
	~ZRayQueryOutput() = default;
	ZRayQueryOutput& operator=(const ZRayQueryOutput& __that);
};
