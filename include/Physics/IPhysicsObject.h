#pragma once

#include "SMatrix.h"
#include "float4.h"
#include "EPhysicsObjectType.h"
#include "ECollisionPriority.h"
#include "ECCDUsage.h"
#include "ECOMUsage.h"
#include "ECameraCollisionMode.h"
#include "ZEntityRef.h"
#include "SCapsule.h"

class ZPhysicsObjectProxy;
class ICollisionShape;
struct SCollisionInfo;
struct SHitInfo;

class __declspec(novtable) IPhysicsObject
{
public:
	virtual ~IPhysicsObject() = default;
	virtual SMatrix GetTransform() const = 0;
	virtual SMatrix GetTransformInterpolated() const = 0;
	virtual SMatrix GetPreviousTransform() const = 0;
	virtual void SetTransform(const SMatrix& matrix) = 0;
	virtual void MoveTransform(const SMatrix& matrix) = 0;
	virtual float4 GetPosition() const = 0;
	virtual float4 GetPositionInterpolated() const = 0;
	virtual void SetPosition(const float4& param1) = 0;
	virtual void MovePosition(const float4& param1) = 0;
	virtual void RestoreWorldInteraction() = 0;
	virtual void DisableWorldInteraction() = 0;
	virtual bool IsWorldInteractionEnabled() = 0;
	virtual void SetType(EPhysicsObjectType physicsObjectType) = 0;
	virtual EPhysicsObjectType GetType() const = 0;
	virtual void SetPriority(ECollisionPriority collisionPriority) = 0;
	virtual ECollisionPriority GetPriority() const = 0;
	virtual bool SetContinuousCollisionDetection(const ECCDUsage usage) = 0;
	virtual ECCDUsage GetContinuousCollisionDetection() const = 0;
	virtual void SetCenterOfMassUsage(const ECOMUsage usage) = 0;
	virtual ECOMUsage GetCenterOfMassUsage() const = 0;
	virtual void SetSkinWidth(const float param1) = 0;
	virtual float GetSkinWidth() const = 0;
	virtual void SetCameraCollisionMode(const ECameraCollisionMode cameraCollisionMode) = 0;
	virtual ECameraCollisionMode GetCameraCollisionMode() const = 0;
	virtual float GetMass() const = 0;
	virtual void SetMass(float param1) = 0;
	virtual float4 GetCenterOfMass() const = 0;
	virtual float4 GetCenterOfMassLocal() const = 0;
	virtual SMatrix GetInertiaTensor() const = 0;
	virtual void AffectedByGravity(const bool param1) = 0;
	virtual float GetLinearDamping() const = 0;
	virtual void SetLinearDamping(float param1) = 0;
	virtual float GetAngularDamping() const = 0;
	virtual void SetAngularDamping(float param1) = 0;
	virtual float GetFriction() const = 0;
	virtual void SetFriction(float param1) = 0;
	virtual float GetRestitution() const = 0;
	virtual void SetRestitution(float param1) = 0;
	virtual void SetEntity(const ZEntityRef& entityRef) = 0;
	virtual ZEntityRef GetEntity() const = 0;
	virtual ICollisionShape* GetCollisionShape() const = 0;
	virtual bool IsKinematic() const = 0;
	virtual void SetKinematic(bool param1) = 0;
	virtual bool IsDynamic() const = 0;
	virtual bool IsSleeping() const = 0;
	virtual bool WakeUp(float param1) = 0;
	virtual bool PutToSleep() = 0;
	virtual void ResetMotion() = 0;
	virtual void SetSleepEnergyThreshold(float param1) = 0;
	virtual void ApplyLinearVelocity(const float4& param1) = 0;
	virtual void ApplyLinearImpulse(const float4& param1) = 0;
	virtual void ApplyForce(const float4& param1) = 0;
	virtual void ApplyPointImpulse(const float4& param1, const float4& param2) = 0;
	virtual void ApplyPointForce(const float4& param1, const float4& param2) = 0;
	virtual void ApplyPointImpulseLocalPos(const float4& param1, const float4& param2) = 0;
	virtual void ApplyPointForceLocalPos(const float4& param1, const float4& param2) = 0;
	virtual void ApplyTorqueImpulse(const float4& param1) = 0;
	virtual void ApplyTorque(const float4& param1) = 0;
	virtual void ApplyLocalLinearVelocity(const float4& param1) = 0;
	virtual void ApplyLocalLinearImpulse(const float4& param1) = 0;
	virtual void ApplyLocalForce(const float4& param1) = 0;
	virtual void ApplyLocalPointImpulse(const float4& param1, const float4& param2) = 0;
	virtual void ApplyLocalPointForce(const float4& param1, const float4& param2) = 0;
	virtual void ApplyLocalTorqueImpulse(const float4& param1) = 0;
	virtual void ApplyLocalTorque(const float4& param1) = 0;
	virtual float GetKineticEnergy() const = 0;
	virtual float4 GetLinearVelocity() const = 0;
	virtual float4 GetAngularVelocity() const = 0;
	virtual void SetLinearVelocity(const float4& param1) = 0;
	virtual void SetLinearVelocityLocal(const float4& param1) = 0;
	virtual void SetAngularVelocity(const float4& param1) = 0;
	virtual void SetMaxAngularVelocity(const float param1) = 0;
	virtual bool IsObjectInPhysicsWorld() const = 0;
	virtual void SetCollisionActivity(bool param1, bool param2) = 0;
	virtual bool GetCollisionActivity(bool param1) const = 0;
	virtual void SetCollisionLayer(const unsigned short param1) = 0;
	virtual unsigned short GetCollisionLayer() const = 0;
	virtual void SetCollisionGroup(const unsigned short param1) = 0;
	virtual unsigned short GetCollisionGroup() const = 0;
	virtual void UpdateStaticCollisionLayers() = 0;
	virtual SCapsule GetG2Capsule() const = 0;
	virtual void ConditionalAdjustCapsule(const float4& param1, const float4& param2, const float param3, const float param4) = 0;
	virtual void SetGenerateSound(const bool param1) = 0;
	virtual bool GetGenerateSound() const = 0;
	virtual void SetGenerateSoundLoud(const bool param1) = 0;
	virtual bool GetGenerateSoundLoud() const = 0;
	virtual void SetIsRagdollPart(const bool param1) = 0;
	virtual bool GetIsRagdollPart() const = 0;
	virtual void SetIgnoringCharacters(const bool param1) = 0;
	virtual void OnCollision(const SCollisionInfo& collisionInfo) = 0;
	virtual void OnHit(const SHitInfo& hitInfo) = 0;
	virtual float GetCombinedRestitution(const float param1) const = 0;
	virtual ZPhysicsObjectProxy* GetProxy() const = 0;
	virtual void SetProxy(ZPhysicsObjectProxy* physicsObjectProxy) const = 0;

	IPhysicsObject() = default;
};
