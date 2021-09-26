#pragma once

#include "ZBaseRagdoll.h"
#include "ZAnimationBoneData.h"

class ZBipedRagdoll
{
public:
	struct SPhysBone
	{
		int m_nBoneId;
		float m_fWeight;

		SPhysBone() = default;
	};

	ZBaseRagdoll* m_pRagdoll;
	const ZAnimationBoneData* m_pBoneData;
	TArray<SPhysBone> m_aBoneMapping;
	unsigned int m_iRootId;
	bool m_bResetHead;
	unsigned int m_nForceMovingFrames;

	virtual ~ZBipedRagdoll() = default;
	virtual void FrameUpdate();

	ZBipedRagdoll() = default;
	ZBipedRagdoll(const ZBipedRagdoll& __that);
	ZBipedRagdoll(const SRagdollRuntimeParams& Params);
	ZBaseRagdoll* GetBaseRagdoll() const;
	unsigned int GetRootBoneId() const;
	bool UpdateBones(ZAnimationBonePose& boneCache, const SMatrix& mvWorldTransform) const;
	bool UpdateBonesPowered(ZAnimationBonePose& boneCache, const SMatrix& mvWorldTransform) const;
	bool Initialize(const ZAnimationBoneData* pBoneData, const ZAnimationBonePose* pBonePose, const SMatrix& mOwnerWorldMatrix, const float nRagdollMass, const unsigned short nCollisionLayer);
	bool ReInitialize(const ZAnimationBoneData* pBoneData);
	bool SetPose(const ZAnimationBonePose* pBonePose, const SMatrix& mOwnerWorldMat);
	bool Activate();
	bool Deactivate();
	void SetMass(const float fMass, const bool bUnify);
	float GetMass() const;
	void SetHeaviness(const float& fFactor);
	void SetResetHead(bool bVal);
	bool IsActive() const;
	bool IsSleeping() const;
	bool IsMoving() const;
	void WakeUp(const float& fTime);
	void PutToSleep();
	void Hit(const float4& wsPointOfImpact, const float4& wsImpulse);
	void HitBodyPart(unsigned int nBoneID, const float4& wsPointOfImpact, const float4& wsImpulse);
	float GetDefaultHeaviness() const;
	float GetDragHeaviness() const;
	bool InitializePhysBones(const ZAnimationBoneData* pBoneData);
	SQV GetLocalBoneByIndex(int iBoneIndex, const TArrayRef<SQV const> aBones, const TArrayRef<int>& aHierarchy) const;
	SQV GetLocalBoneByID(int iBoneId, const TArrayRef<SQV const> aBones, const TArrayRef<int>& aHierarchy) const;
	bool GetIsForcedMoving() const;
	ZBipedRagdoll& operator=(const ZBipedRagdoll& __that);
};
