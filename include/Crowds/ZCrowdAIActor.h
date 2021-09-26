#pragma once

#include "TEntityRef.h"

class ZAnimationBoneData;
class ZAnimationBonePose;
class ZLinkedEntity;

class ZCrowdAIActor
{
public:
	bool m_bInUse;
	TEntityRef<ZLinkedEntity> m_pLinked;
	ZAnimationBonePose* m_pPose;
	ZAnimationBonePose* m_pOrgPose;
	float m_fBlendTime;
	float m_fTimer;

	ZCrowdAIActor(const ZCrowdAIActor& __that);
	ZCrowdAIActor() = default;
	~ZCrowdAIActor() = default;
	bool IsFree() const;
	bool IsInUse() const;
	void EnableAI(const ZAnimationBoneData* pBoneData);
	void StopAI();
	void UpdateAnimation(float nDeltaTime);
	void SetOrgPose(const ZAnimationBonePose* pOrgPose, float fBlendTime);
	void SetBlendOut(float fBlendTime);
	ZAnimationBonePose* GetPose();
	const TEntityRef<ZLinkedEntity>& GetLinkedEntity() const;
	ZCrowdAIActor& operator=(const ZCrowdAIActor& __that);
};
