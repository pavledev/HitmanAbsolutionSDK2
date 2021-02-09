#pragma once

#include "IComponentInterface.h"
#include "ZAsyncRayCaster.h"
#include "IPhysicsObject.h"
#include "SBox.h"
#include "SCapsule.h"
#include "EDefaultCollidableLayer.h"
#include "ECharacterCollidableLayer.h"
#include "ETrayCatchType.h"
#include "ZFilterGroupMask.h"
#include "EFilterMaskBit.h"
#include "SCollisionInfo.h"
#include "IPhysicsAccessor.h"
#include "SHitInfo.h"
#include "SSphereSweepOutput.h"
#include "SSphereSweepInput.h"
#include "SSphere.h"
#include "SCapsuleSweepOutput.h"
#include "SCapsuleSweepInput.h"
#include "SGameSpecificCollisionFilterCallbacks.h"

class ICollisionShape;

class ICollisionManager : public IComponentInterface
{
public:
    virtual void SuspendAsyncRayCast();
    virtual void ResumeAsyncRayCast();
    virtual bool IsAsyncRayCastSuspended();
    virtual void ResetScene();
    virtual void PostCheckpointActivate();
    virtual ZAsyncRayCaster* GetAsyncRayCaster();
    virtual ICollisionShape* CreateCollisionSphere(float);
    virtual ICollisionShape* CreateCollisionCapsule(const SVector3*, const SVector3*, float);
    virtual ICollisionShape* CreateCollisionBox(const SVector3*);
    virtual void SetSpatialFilterFunc(const ZDelegate<TEntityRef<ZSpatialEntity> __cdecl(ZEntityRef)>*);
    virtual TEntityRef<ZSpatialEntity>* ResolveSpatialFromFilterFunc(TEntityRef<ZSpatialEntity>* result, const ZEntityRef*);
    virtual bool RayCastClosestHit(const ZRayQueryInput*, ZRayQueryOutput*);
    virtual bool RayCastAgainstEntity(const ZRayQueryInput*, ZRayQueryOutput*, ZEntityRef);
    virtual unsigned int RayCastAgainstShapes(const ZRayQueryInput*, ZRayQueryOutput*, const IPhysicsObject*);
    virtual IAsyncRayHandle* AsyncRayCastClosestHit(const ZRayQueryInput*);
    virtual bool BoxCollisionQuery(TArray<TPair<IPhysicsObject*, ZEntityRef> >*, const SBox*, ECollidablesType, unsigned int, bool, bool);
    virtual unsigned int CapsuleCollisionQuery(TArray<TPair<IPhysicsObject*, ZEntityRef> >*, const SCapsule*, ECollidablesType, unsigned int, bool, bool);
    virtual unsigned int GetNextFreeCollisionGroup();
    virtual unsigned int GetCollisionFilter(unsigned __int16, unsigned __int16);
    virtual unsigned __int16 GetCollisionGroup(unsigned int);
    virtual unsigned __int16 GetCollisionLayer(unsigned int);
    virtual unsigned int GetCollisionLayerDebugColor(unsigned __int16);
    virtual void SetCollisionLayerDebugColor(unsigned __int16, unsigned int);
    virtual void EnableMutualCollisionsBetween(unsigned __int16, unsigned __int16);
    virtual void DisableMutualCollisionsBetween(unsigned __int16, unsigned __int16);
    virtual void EnableRayCollisionWith(unsigned __int16, unsigned __int16);
    virtual void DisableRayCollisionWith(unsigned __int16, unsigned __int16);
    virtual void DisableCollisionBetween(const ZEntityRef*, const ZEntityRef*);
    virtual void DisableCollisionBetween(IPhysicsObject*, IPhysicsObject*);
    virtual void ResetCollisionBetween(const ZEntityRef*, const ZEntityRef*);
    virtual void ResetCollisionBetween(IPhysicsObject*, IPhysicsObject*);
    virtual void RegisterDefaultCollisionLayer(EDefaultCollidableLayer, unsigned __int16);
    virtual unsigned __int16 GetDefaultCollisionLayer(EDefaultCollidableLayer);
    virtual EDefaultCollidableLayer FindDefaultLayer(const unsigned __int16);
    virtual EDefaultCollidableLayer SwitchKinematicDynamicDefaultLayers(EDefaultCollidableLayer);
    virtual bool IsDefaultCollisionLayerKinematic(EDefaultCollidableLayer);
    virtual bool IsDefaultCollisionLayerDynamic(EDefaultCollidableLayer);
    virtual void RegisterCharacterCollidableLayer(ECharacterCollidableLayer, unsigned __int16);
    virtual unsigned __int16 GetCharacterCollisionLayer(ECharacterCollidableLayer);
    virtual ECharacterCollidableLayer FindCharacterCollidableLayer(const unsigned __int16);
    virtual ECharacterCollidableLayer SwitchCharacterCollidableLayers(ECharacterCollidableLayer);
    virtual bool HasCharacterCollidableLayerCollision(ECharacterCollidableLayer);
    virtual void SetCrowdRagdollCollisionLayer(unsigned __int16);
    virtual unsigned __int16 GetCrowdRagdollCollisionLayer();
    virtual unsigned int GetCollidableMaskFromLayer(unsigned __int16);
    virtual void SetSceneBounds(const float4*, const float4*);
    virtual void SetSceneTray(bool, bool);
    virtual void ReportTrayCatch(ETrayCatchType, ZEntityRef);
    virtual void OutputTrayCatch();
    virtual ZFilterGroupMask* GetCollisionFilterMaskBit(ZFilterGroupMask* result, const EFilterMaskBit);
    virtual void InitializeSweepCache();
    virtual void DeInitializeSweepCache();
    virtual void* GetSweepCache();
    virtual void RegisterForCollisionListening(IPhysicsObject*);
    virtual void RegisterForCollisionListening(IPhysicsObject*, const ZDelegate<void __cdecl(SCollisionInfo const&)>*);
    virtual void UnregisterForCollisionListening(IPhysicsObject*);
    virtual void UnregisterForCollisionListening(IPhysicsObject*, const ZDelegate<void __cdecl(SCollisionInfo const&)>*);
    virtual bool IsRegisteredForCollisionListening(const IPhysicsObject*, const ZDelegate<void __cdecl(SCollisionInfo const&)>*);
    virtual bool IsRegisteredForCollisionListening(const IPhysicsObject*);
    virtual void RegisterEntityForCollisionListening(IPhysicsAccessor*);
    virtual void UnregisterEntityForCollisionListening(IPhysicsAccessor*);
    virtual void RegisterForShotListening(const IPhysicsObject*, const ZDelegate<void __cdecl(SHitInfo const&)>*);
    virtual void UnregisterForShotListening(const IPhysicsObject*, const ZDelegate<void __cdecl(SHitInfo const&)>*);
    virtual void UnregisterForShotListening(const IPhysicsObject*);
    virtual bool IsRegisteredForShotListening(const IPhysicsObject*, const ZDelegate<void __cdecl(SHitInfo const&)>*);
    virtual bool IsRegisteredForShotListening(const IPhysicsObject*);
    virtual bool NotifyShotListeners(const SHitInfo*);
    virtual void RegisterForCollisionEvents(const ZDelegate<void __cdecl(TArrayRef<SCollisionInfo>)>*);
    virtual void UnregisterForCollisionEvents(const ZDelegate<void __cdecl(TArrayRef<SCollisionInfo>)>*);
    virtual bool IsRegisteredForCollisionEvents(const ZDelegate<void __cdecl(TArrayRef<SCollisionInfo>)>*);
    virtual bool ShapeOverlapsCapsule(const IPhysicsObject*, const SCapsule*);
    virtual bool BoxOverlapAnyShape(const SBox*, ECollidablesType, unsigned int);
    virtual bool CapsuleOverlapAnyShape(const SCapsule*, ECollidablesType, unsigned int);
    virtual bool PointOverlapAnyShape(const float4*, const unsigned int);
    virtual bool LinearSphereSweepClosest(SSphereSweepOutput*, const SSphereSweepInput*);
    virtual bool CachedLinearSphereSweepClosest(SSphereSweepOutput*, const SSphereSweepInput*, IPhysicsObject*);
    virtual unsigned int GetTrianglesIntersectSphere(const SSphere*, ECollidablesType, unsigned int, TArray<float4>*);
    virtual bool LinearCapsuleSweepClosest(SCapsuleSweepOutput*, const SCapsuleSweepInput*);
    virtual void ShowActiveContactDebug(const bool, const bool);
    virtual ZString* GetDebugLevelAndCheckpointName(ZString* result);
    virtual void SetGameSpecificCollisionFilterCallbacks(const SGameSpecificCollisionFilterCallbacks*);
};
