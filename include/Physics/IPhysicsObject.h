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
class SCollisionInfo;
class SHitInfo;

class IPhysicsObject
{
public:
    virtual ~IPhysicsObject();
    virtual SMatrix* GetTransform(SMatrix* result);
    virtual SMatrix* GetTransformInterpolated(SMatrix* result);
    virtual SMatrix* GetPreviousTransform(SMatrix* result);
    virtual void SetTransform(const SMatrix*);
    virtual void MoveTransform(const SMatrix*);
    virtual float4* GetPosition(float4* result);
    virtual float4* GetPositionInterpolated(float4* result);
    virtual void SetPosition(const float4*);
    virtual void MovePosition(const float4*);
    virtual void RestoreWorldInteraction();
    virtual void DisableWorldInteraction();
    virtual bool IsWorldInteractionEnabled();
    virtual void SetType(EPhysicsObjectType);
    virtual EPhysicsObjectType GetType();
    virtual void SetPriority(ECollisionPriority);
    virtual ECollisionPriority GetPriority();
    virtual bool SetContinuousCollisionDetection(const ECCDUsage);
    virtual ECCDUsage GetContinuousCollisionDetection();
    virtual void SetCenterOfMassUsage(const ECOMUsage);
    virtual ECOMUsage GetCenterOfMassUsage();
    virtual void SetSkinWidth(const float);
    virtual float GetSkinWidth();
    virtual void SetCameraCollisionMode(const ECameraCollisionMode);
    virtual ECameraCollisionMode GetCameraCollisionMode();
    virtual float GetMass();
    virtual void SetMass(float);
    virtual float4* GetCenterOfMass(float4* result);
    virtual float4* GetCenterOfMassLocal(float4* result);
    virtual SMatrix* GetInertiaTensor(SMatrix* result);
    virtual void AffectedByGravity(const bool);
    virtual float GetLinearDamping();
    virtual void SetLinearDamping(float);
    virtual float GetAngularDamping();
    virtual void SetAngularDamping(float);
    virtual float GetFriction();
    virtual void SetFriction(float);
    virtual float GetRestitution();
    virtual void SetRestitution(float);
    virtual void SetEntity(const ZEntityRef*);
    virtual ZEntityRef* GetEntity(ZEntityRef* result);
    virtual ICollisionShape* GetCollisionShape();
    virtual bool IsKinematic();
    virtual void SetKinematic(bool);
    virtual bool IsDynamic();
    virtual bool IsSleeping();
    virtual bool WakeUp(float);
    virtual bool PutToSleep();
    virtual void ResetMotion();
    virtual void SetSleepEnergyThreshold(float);
    virtual void ApplyLinearVelocity(const float4*);
    virtual void ApplyLinearImpulse(const float4*);
    virtual void ApplyForce(const float4*);
    virtual void ApplyPointImpulse(const float4*, const float4*);
    virtual void ApplyPointForce(const float4*, const float4*);
    virtual void ApplyPointImpulseLocalPos(const float4*, const float4*);
    virtual void ApplyPointForceLocalPos(const float4*, const float4*);
    virtual void ApplyTorqueImpulse(const float4*);
    virtual void ApplyTorque(const float4*);
    virtual void ApplyLocalLinearVelocity(const float4*);
    virtual void ApplyLocalLinearImpulse(const float4*);
    virtual void ApplyLocalForce(const float4*);
    virtual void ApplyLocalPointImpulse(const float4*, const float4*);
    virtual void ApplyLocalPointForce(const float4*, const float4*);
    virtual void ApplyLocalTorqueImpulse(const float4*);
    virtual void ApplyLocalTorque(const float4*);
    virtual float GetKineticEnergy();
    virtual float4* GetLinearVelocity(float4* result);
    virtual float4* GetAngularVelocity(float4* result);
    virtual void SetLinearVelocity(const float4*);
    virtual void SetLinearVelocityLocal(const float4*);
    virtual void SetAngularVelocity(const float4*);
    virtual void SetMaxAngularVelocity(const float);
    virtual bool IsObjectInPhysicsWorld();
    virtual void SetCollisionActivity(bool, bool);
    virtual bool GetCollisionActivity(bool);
    virtual void SetCollisionLayer(const unsigned __int16);
    virtual unsigned __int16 GetCollisionLayer();
    virtual void SetCollisionGroup(const unsigned __int16);
    virtual unsigned __int16 GetCollisionGroup();
    virtual void UpdateStaticCollisionLayers();
    virtual SCapsule* GetG2Capsule(SCapsule* result);
    virtual void ConditionalAdjustCapsule(const float4*, const float4*, const float, const float);
    virtual void SetGenerateSound(const bool);
    virtual bool GetGenerateSound();
    virtual void SetGenerateSoundLoud(const bool);
    virtual bool GetGenerateSoundLoud();
    virtual void SetIsRagdollPart(const bool);
    virtual bool GetIsRagdollPart();
    virtual void SetIgnoringCharacters(const bool);
    virtual void OnCollision(const SCollisionInfo*);
    virtual void OnHit(const SHitInfo*);
    virtual float GetCombinedRestitution(const float);
    virtual ZPhysicsObjectProxy* GetProxy();
    virtual void SetProxy(ZPhysicsObjectProxy*);
};
