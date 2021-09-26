#pragma once

#include "TArray.h"

class ZCrowdRagdoll;
class SQV;
class ZCrowdActor;
class ZAnimationBoneData;
class ZAnimationBonePose;

class ZCrowdRagdollManager
{
public:
	TArray<ZCrowdRagdoll*> m_aRagdolls;
	unsigned int m_nNextStaticPoseSlot;
	TArray<SQV> m_aStaticPoses[128];
	unsigned int m_nFramesSinceLastRagdollAdded;

	static const unsigned char INVALID_RAGDOLL_INDEX;
	static const unsigned int INVALID_STATICPOSE_INDEX;
	static const unsigned int nRagdollMinLifeTimeSec;
	static const unsigned int nRagdollPoolSize;
	static const unsigned int nStaticPosePoolSize;

	virtual ~ZCrowdRagdollManager() = default;

	ZCrowdRagdollManager(const ZCrowdRagdollManager& __that);
	ZCrowdRagdollManager() = default;
	static unsigned int GetRagdollPoolSize();
	unsigned int GetMaxNumAvailableRagdolls() const;
	void UpdateRagdolls();
	unsigned char EnableRagdoll(ZCrowdActor* pActor, bool bCriticalDeath);
	unsigned int ConvertToStaticPose(ZCrowdActor* pActor, const ZAnimationBoneData* pBoneData, const ZAnimationBonePose* pBonePose);
	unsigned int ConvertToStaticPose(ZCrowdRagdoll* pRagdoll);
	ZCrowdRagdoll* GetRagdoll(unsigned char nRagdollIndex);
	bool GetRagdollPose(unsigned char nRagdollIndex, const ZAnimationBoneData** pBoneData, const ZAnimationBonePose** pBonePose);
	void InitializeStaticPoses(unsigned int nBoneCacheSize);
	unsigned int GetStaticPosePoolSize() const;
	const TArray<SQV>& GetStaticPose(unsigned int nIndex) const;
	ZCrowdRagdollManager& operator=(const ZCrowdRagdollManager& __that);
};
