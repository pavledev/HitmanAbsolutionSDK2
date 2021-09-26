#pragma once

#include "ECCDUsage.h"
#include "IPhysicsSystem.h"
#include "IRagdollDesc.h"
#include "TMap.h"
#include "IFixedConstraint.h"
#include "SRagdollRuntimeParams.h"

struct SExplodeInfo;

class ZBaseRagdoll
{
public:
	bool m_bIsActivated;
	ECCDUsage m_eCCDUsage;
	ECollisionPriority m_eSolverPriority;
	IPhysicsSystem* m_pSystem;
	IRagdollDesc* m_pRagdollDesc;
	float m_fAge;
	TMap<unsigned int, unsigned int> m_BodyPartMapper;
	TMap<unsigned int, IBaseConstraint*> m_LockMapper;
	TArray<IFixedConstraint*> m_apPhantomConstraints;
	unsigned int m_nBodyPartActivationRoot;
	bool m_bHasPhantomBodyParts;
	TArray<unsigned int> m_anLocalCBM;
	TArray<unsigned int> m_anParentBeginIndices;
	TArray<unsigned int> m_anChildIndices;
	SRagdollRuntimeParams m_Params;

	virtual ~ZBaseRagdoll() = default;

	ZBaseRagdoll() = default;
	IPhysicsObject* CreateBodyPart(const SBodyPartDesc& Part, const float4& vCreateOffset);
	IBaseConstraint* CreateBodyJoint(const SBodyJointDesc& JointDesc);
	void SetupBodyJoint(IBaseConstraint* pConstraint, const SBodyJointDesc& JointDesc, const SMatrix& tParent, const SMatrix& tParentT, const SMatrix& tChild);
	void AddConstraintsToPhysicsWorld();
	void AddToPhysicsWorld();
	IRagdollDesc* GetRagdollDesc();
	bool Activate();
	bool Deactivate();
	void DisableWorldInteraction();
	void RestoreWorldInteraction();
	void HitBodyPart(unsigned int nID, const float4& vPointOfImpact, const float4& vImpulse);
	void HitBodyPart(unsigned int nID, const float4& vImpulse);
	void Explode(const SExplodeInfo& explodeInfo, const float4& vOrigin);
	void Explode(const SHitInfo& Hit);
	bool LockBodyPart(unsigned int nID, IPhysicsObject* pExternal);
	bool UnlockBodyPart(unsigned int nID);
	bool IsLocked(unsigned int nID) const;
	void Displace(unsigned int nID, const float4& vDirection);
	const IPhysicsObject* GetBodyPart(unsigned int nID) const;
	IPhysicsObject* GetBodyPart(unsigned int nID);
	unsigned int GetBodyPartID(IPhysicsObject* pBody) const;
	bool IsActive() const;
	bool IsSleeping() const;
	void WakeUp(float fSeconds);
	void PutToSleep();
	void SetCollisionLayer(unsigned short iCollisionLayer);
	unsigned short GetCollisionLayer() const;
	void SetEntity(const ZEntityRef& entity);
	ZEntityRef GetEntity() const;
	void SetIsDeadRagdollBodyParts(const bool bIsDead);
	void SetSleepingEnergyThreshold(const float fEnergy);
	float GetAge() const;
	void SetAge(const float fAge);
	const IPhysicsSystem* GetPhysicsSystem() const;
	bool SetPose(const ZAnimationBonePose* pBonePose, const ZAnimationRig* pRig, const SMatrix& mOwnerWorldMat);
	bool SetPose(const THashMap<int, int, TDefaultHashMapPolicy<int, int>>& aBoneMap, const TArrayRef<SQV const> aBoneCache, const TArrayRef<int> aBoneHierarchy, const SMatrix& mOwnerWorldMat);
	void SetMass(const float fMass, const bool bUnify);
	void ScaleVelocity(const float1& fScale);
	void ActivatePhantomParts();
	void Phantomize();
	void UnPhantomize();
	void BuildActivationGraph();
	IBaseConstraint* CreateLockConstraint(IPhysicsObject* pExternal, IPhysicsObject* pPart);
	void AddTwistTorqueAroundSpine(IPhysicsObject* pPart, const float4& vPointOfImpact, const float4& vImpulse);
	ZBaseRagdoll(const ZBaseRagdoll& __that);
	ZBaseRagdoll(IRagdollDesc* pRagdollDesc, const SRagdollRuntimeParams& Params);
	ZBaseRagdoll& operator=(const ZBaseRagdoll& __that);
};
