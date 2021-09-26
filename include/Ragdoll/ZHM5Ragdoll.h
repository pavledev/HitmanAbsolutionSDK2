#pragma once

#include "ZBipedRagdoll.h"
#include "SPowerSettings.h"
#include "TEntityRef.h"

class ZHM5BaseCharacter;
class ZLinkedEntity;

class ZHM5Ragdoll : public ZBipedRagdoll
{
public:
	enum
	{
		NUM_ROOT_POS_SAMLES = 10
	};

	bool m_bPowered;
	bool m_bDrivesEnabled;
	float m_fPoweredTime;
	float m_fPoweredSyncTime;
	float m_fLastTM;
	TArray<SMatrix43> m_TargetPose;
	TArray<SMatrix43> m_PreviousTargetPose;
	SPowerSettings m_powerSettings;
	int m_nRootBodyLowVelFrames;
	float4 m_aRootPosSamples[10];
	float m_aSimEndTimes[10];
	unsigned short m_nCurRootPosIndex;

	~ZHM5Ragdoll() override = default;
	void FrameUpdate() override;

	ZHM5Ragdoll() = default;
	ZHM5Ragdoll(const SRagdollRuntimeParams& Params);
	bool Initialize(ZLinkedEntity* pOwner, const float& fMass, const unsigned short nCollisionLayer);
	bool Initialize(const TEntityRef<ZHM5BaseCharacter>& pOwner, const float& fMass, const unsigned short nCollisionLayer);
	bool ActivateInMotion(const TArrayRef<SQV> LastPose, float fPoseDeltaTime);
	void SetPowerSettings(SPowerSettings powerSettings);
	void FeedPoweredRagdoll(const TArrayRef<SMatrix43> aPose);
	bool StartPoweredRagdoll();
	void StopPoweredRagdoll(bool bPutToSleep);
	bool IsPoweredRagdollActive() const;
	void UpdatePowerSettings(const SPowerSettings& powerSettings);
	bool HasDrivesEnabled();
	void EnableDrives();
	void DisableDrives();
	void PoweredRagdollUpdate();
	void FilteredVelocitySleepControl();
};
