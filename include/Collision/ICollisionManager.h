#pragma once

#include "IComponentInterface.h"
#include "EDefaultCollidableLayer.h"
#include "ECharacterCollidableLayer.h"
#include "ETrayCatchType.h"
#include "ZFilterGroupMask.h"
#include "EFilterMaskBit.h"
#include "ECollidablesType.h"
#include "TEntityRef.h"
#include "ZEntityRef.h"
#include "ZString.h"

class ICollisionShape;
class IAsyncRayHandle;
class IPhysicsAccessor;
class IPhysicsObject;
class ZAsyncRayCaster;
class ZRayQueryInput;
class ZRayQueryOutput;
class ZSpatialEntity;
struct SBox;
struct SCapsule;
struct SCapsuleSweepInput;
struct SCapsuleSweepOutput;
struct SCollisionInfo;
struct SGameSpecificCollisionFilterCallbacks;
struct SHitInfo;
struct SSphere;
struct SSphereSweepInput;
struct SSphereSweepOutput;
struct SVector3;
struct float4;
template <class A, class B> class TPair;
template <class T> class TArray;
template <class T> class TArrayRef;
template <class T> class alignas(8) ZDelegate;

class __declspec(novtable) ICollisionManager : public IComponentInterface
{
public:
	~ICollisionManager() override = default;
	virtual void SuspendAsyncRayCast() = 0;
	virtual void ResumeAsyncRayCast() = 0;
	virtual bool IsAsyncRayCastSuspended() = 0;
	virtual void ResetScene() = 0;
	virtual void PostCheckpointActivate() = 0;
	virtual ZAsyncRayCaster* GetAsyncRayCaster() const = 0;
	virtual ICollisionShape* CreateCollisionSphere(float param1) const = 0;
	virtual ICollisionShape* CreateCollisionCapsule(const SVector3& vector3, const SVector3& vector32, float param3) const = 0;
	virtual ICollisionShape* CreateCollisionBox(const SVector3& vector3) const = 0;
	virtual void SetSpatialFilterFunc(const ZDelegate<TEntityRef<ZSpatialEntity> __cdecl(ZEntityRef)>& delegate) = 0;
	virtual TEntityRef<ZSpatialEntity> ResolveSpatialFromFilterFunc(const ZEntityRef& entityRef) = 0;
	virtual bool RayCastClosestHit(const ZRayQueryInput& rayQueryInput, ZRayQueryOutput* rayQueryOutput) const = 0;
	virtual bool RayCastAgainstEntity(const ZRayQueryInput& rayQueryInput, ZRayQueryOutput* rayQueryOutput, ZEntityRef entityRef) const = 0;
	virtual unsigned int RayCastAgainstShapes(const ZRayQueryInput& rayQueryInput, ZRayQueryOutput* rayQueryOutput, const IPhysicsObject* physicsObject) const = 0;
	virtual IAsyncRayHandle* AsyncRayCastClosestHit(const ZRayQueryInput& rayQueryInput) = 0;
	virtual bool BoxCollisionQuery(TArray<TPair<IPhysicsObject*, ZEntityRef>>& array, const SBox& box, ECollidablesType collidablesType, unsigned int param4, bool param5, bool param6) const = 0;
	virtual unsigned int CapsuleCollisionQuery(TArray<TPair<IPhysicsObject*, ZEntityRef>>& array, const SCapsule& capsule, ECollidablesType collidablesType, unsigned int param4, bool param5, bool param6) const = 0;
	virtual unsigned int GetNextFreeCollisionGroup() = 0;
	virtual unsigned int GetCollisionFilter(unsigned short param1, unsigned short param2) const = 0;
	virtual unsigned short GetCollisionGroup(unsigned int param1) const = 0;
	virtual unsigned short GetCollisionLayer(unsigned int param1) const = 0;
	virtual unsigned int GetCollisionLayerDebugColor(unsigned short param1) const = 0;
	virtual void SetCollisionLayerDebugColor(unsigned short param1, unsigned int param2) = 0;
	virtual void EnableMutualCollisionsBetween(unsigned short param1, unsigned short param2) = 0;
	virtual void DisableMutualCollisionsBetween(unsigned short param1, unsigned short param2) = 0;
	virtual void EnableRayCollisionWith(unsigned short param1, unsigned short param2) = 0;
	virtual void DisableRayCollisionWith(unsigned short param1, unsigned short param2) = 0;
	virtual void DisableCollisionBetween(const ZEntityRef& entityRef, const ZEntityRef& entityRef2) = 0;
	virtual void DisableCollisionBetween(IPhysicsObject* physicsObject, IPhysicsObject* physicsObject2) = 0;
	virtual void ResetCollisionBetween(const ZEntityRef& entityRef, const ZEntityRef& entityRef2) = 0;
	virtual void ResetCollisionBetween(IPhysicsObject* physicsObject, IPhysicsObject* physicsObject2) = 0;
	virtual void RegisterDefaultCollisionLayer(EDefaultCollidableLayer defaultCollidableLayer, unsigned short param2) = 0;
	virtual unsigned short GetDefaultCollisionLayer(EDefaultCollidableLayer defaultCollidableLayer) const = 0;
	virtual EDefaultCollidableLayer FindDefaultLayer(const unsigned short param1) const = 0;
	virtual EDefaultCollidableLayer SwitchKinematicDynamicDefaultLayers(EDefaultCollidableLayer defaultCollidableLayer) const = 0;
	virtual bool IsDefaultCollisionLayerKinematic(EDefaultCollidableLayer defaultCollidableLayer) const = 0;
	virtual bool IsDefaultCollisionLayerDynamic(EDefaultCollidableLayer defaultCollidableLayer) const = 0;
	virtual void RegisterCharacterCollidableLayer(ECharacterCollidableLayer characterCollidableLayer, unsigned short param2) = 0;
	virtual unsigned short GetCharacterCollisionLayer(ECharacterCollidableLayer characterCollidableLayer) const = 0;
	virtual ECharacterCollidableLayer FindCharacterCollidableLayer(const unsigned short param1) const = 0;
	virtual ECharacterCollidableLayer SwitchCharacterCollidableLayers(ECharacterCollidableLayer characterCollidableLayer) const = 0;
	virtual bool HasCharacterCollidableLayerCollision(ECharacterCollidableLayer characterCollidableLayer) const = 0;
	virtual void SetCrowdRagdollCollisionLayer(unsigned short param1) = 0;
	virtual unsigned short GetCrowdRagdollCollisionLayer() const = 0;
	virtual unsigned int GetCollidableMaskFromLayer(unsigned short param1) const = 0;
	virtual void SetSceneBounds(const float4& param1, const float4& param2) = 0;
	virtual void SetSceneTray(bool param1, bool param2) = 0;
	virtual void ReportTrayCatch(ETrayCatchType trayCatchType, ZEntityRef entityRef) = 0;
	virtual void OutputTrayCatch() const = 0;
	virtual ZFilterGroupMask GetCollisionFilterMaskBit(const EFilterMaskBit filterMaskBit) const = 0;
	virtual void InitializeSweepCache() = 0;
	virtual void DeInitializeSweepCache() = 0;
	virtual void* GetSweepCache() = 0;
	virtual void RegisterForCollisionListening(IPhysicsObject* physicsObject) = 0;
	virtual void RegisterForCollisionListening(IPhysicsObject* physicsObject, const ZDelegate<void __cdecl(SCollisionInfo const&)>& param2) = 0;
	virtual void UnregisterForCollisionListening(IPhysicsObject* physicsObject) = 0;
	virtual void UnregisterForCollisionListening(IPhysicsObject* physicsObject, const ZDelegate<void __cdecl(SCollisionInfo const&)>& param2) = 0;
	virtual bool IsRegisteredForCollisionListening(const IPhysicsObject* physicsObject, const ZDelegate<void __cdecl(SCollisionInfo const&)>& param2) const = 0;
	virtual bool IsRegisteredForCollisionListening(const IPhysicsObject* physicsObject) const = 0;
	virtual void RegisterEntityForCollisionListening(IPhysicsAccessor* physicsAccessor) = 0;
	virtual void UnregisterEntityForCollisionListening(IPhysicsAccessor* physicsAccessor) = 0;
	virtual void RegisterForShotListening(const IPhysicsObject* physicsObject, const ZDelegate<void __cdecl(SHitInfo const&)>& param2) = 0;
	virtual void UnregisterForShotListening(const IPhysicsObject* physicsObject, const ZDelegate<void __cdecl(SHitInfo const&)>& param2) = 0;
	virtual void UnregisterForShotListening(const IPhysicsObject* physicsObject) = 0;
	virtual bool IsRegisteredForShotListening(const IPhysicsObject* physicsObject, const ZDelegate<void __cdecl(SHitInfo const&)>& param2) const = 0;
	virtual bool IsRegisteredForShotListening(const IPhysicsObject* physicsObject) const = 0;
	virtual bool NotifyShotListeners(const SHitInfo& hitInfo) = 0;
	virtual void RegisterForCollisionEvents(const ZDelegate<void __cdecl(TArrayRef<SCollisionInfo>)>& delegate) = 0;
	virtual void UnregisterForCollisionEvents(const ZDelegate<void __cdecl(TArrayRef<SCollisionInfo>)>& delegate) = 0;
	virtual bool IsRegisteredForCollisionEvents(const ZDelegate<void __cdecl(TArrayRef<SCollisionInfo>)>& delegate) const = 0;
	virtual bool ShapeOverlapsCapsule(const IPhysicsObject* physicsObject, const SCapsule& capsule) = 0;
	virtual bool BoxOverlapAnyShape(const SBox& box, ECollidablesType collidablesType, unsigned int param3) const = 0;
	virtual bool CapsuleOverlapAnyShape(const SCapsule& capsule, ECollidablesType collidablesType, unsigned int param3) const = 0;
	virtual bool PointOverlapAnyShape(const float4& param1, const unsigned int param2) const = 0;
	virtual bool LinearSphereSweepClosest(SSphereSweepOutput& sphereSweepOutput, const SSphereSweepInput& sphereSweepInput) = 0;
	virtual bool CachedLinearSphereSweepClosest(SSphereSweepOutput& sphereSweepOutput, const SSphereSweepInput& sphereSweepInput, IPhysicsObject* physicsObject) = 0;
	virtual unsigned int GetTrianglesIntersectSphere(const SSphere& sphere, ECollidablesType collidablesType, unsigned int param3, TArray<float4>& array) = 0;
	virtual bool LinearCapsuleSweepClosest(SCapsuleSweepOutput& capsuleSweepOutput, const SCapsuleSweepInput& capsuleSweepInput) = 0;
	virtual void ShowActiveContactDebug(const bool param1, const bool param2) = 0;
	virtual ZString GetDebugLevelAndCheckpointName() const = 0;
	virtual void SetGameSpecificCollisionFilterCallbacks(const SGameSpecificCollisionFilterCallbacks& gameSpecificCollisionFilterCallbacks) = 0;

	static void RegisterType();
	ICollisionManager() = default;
};
