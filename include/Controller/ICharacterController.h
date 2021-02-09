#pragma once

#include "float4.h"
#include "SVector3.h"
#include "SCapsule.h"
#include "ZEntityRef.h"
#include "ZCollisionLayerColorGetter.h"

class ICharacterController
{
public:
    virtual ~ICharacterController();
    virtual void SetEntity(const ZEntityRef*);
    virtual float4* GetPosition(float4* result);
    virtual void RelocateTo(const float4*);
    virtual float4* SweepToPos(float4* result, const float4*, const float4*);
    virtual void Update(const float4*);
    virtual bool IsSupported();
    virtual bool IsSideBlocked();
    virtual SVector3* GetSideBlockedNormal(SVector3* result);
    virtual float4* GetSurfaceNormal(float4* result);
    virtual void ReportSceneChanged();
    virtual bool CheckOverlapAtPos(const float4*, unsigned int, unsigned int, bool, bool);
    virtual bool CheckOverlapWithEntityAtPos(const float4*, unsigned int, unsigned int, bool, bool, IPhysicsObject*);
    virtual void GetCapsulePropertiesInternal(float*, float*, float*);
    virtual SCapsule* GetG2Capsule(SCapsule* result);
    virtual void DrawShape(const ZCollisionLayerColorGetter*);
};
