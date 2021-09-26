#pragma once

#include "ZBipedRagdoll.h"
#include "ZCrowdActor.h"
#include "TComponentPtr.h"
#include "TDCBZArray.h"

class ZCrowdRagdoll : public ZBipedRagdoll
{
public:
	ZCrowdActor* m_pActor;
	TComponentPtr<ZAnimationBonePose> m_pBoneCache;

	~ZCrowdRagdoll() override = default;
	void FrameUpdate() override;

	ZCrowdRagdoll() = default;
	ZCrowdRagdoll(const SRagdollRuntimeParams& Params);
	bool Initialize(ZCrowdActor* pCrowdActor, const ZAnimationBoneData* pBoneData, const ZAnimationBonePose* pBonePose, const unsigned short nCollisionLayer);
	void ReleaseToRagdollPool();
	void UpdateBoneCacheFromRagdollPose();
	ZCrowdActor* GetActor() const;
	void ShootRagdoll(const SHitInfo& HitInfo);
	bool GetAnimationPose(const ZAnimationBoneData** pBoneData, const ZAnimationBonePose** pBonePose);
	void SetRagdollPoseFromStaticPose(const TDCBZArray<SMatrix43>& aStaticPose);
};
