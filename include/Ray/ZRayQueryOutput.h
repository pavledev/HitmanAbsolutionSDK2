#pragma once

#include "ZRayQueryOutputBase.h"
#include "ZEntityRef.h"
#include "ZPhysicsObjectRef.h"
#include "TEntityRef.h"
#include "ZSpatialEntity.h"
#include "ZRenderPrimitiveResource.h"
#include "SBoneCollision.h"

class alignas(16) ZRayQueryOutput : public ZRayQueryOutputBase
{
public:
    ZEntityRef m_BlockingEntity;
    ZPhysicsObjectRef m_pBlockingPhysicsObject;
    TEntityRef<ZSpatialEntity> m_pBlockingSpatialEntity;
    TResourcePtr<ZRenderPrimitiveResource> m_pBlockingPrimitive;
    float4 m_vDecalPosition;
    float4 m_vDecalNormal;
    TArray<SBoneCollision> m_aAllIntersectedBones;
};
