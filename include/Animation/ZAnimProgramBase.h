#pragma once

#include "ZNPCMorphemeNetworkController.h"
#include "EOrderCompletionStatus.h"

class __declspec(novtable) ZAnimProgramBase
{
public:
	ZNPCMorphemeNetworkController* m_pController;
	ZAnimatedActor* m_pAnimatedActor;
	bool m_bPreventAiming : 1;
	bool m_bWillingToAim : 1;
	float m_timeOutOfAimingCone;

	virtual ~ZAnimProgramBase() = default;
	virtual bool Update(float param1) = 0;
	virtual bool RequestTermination(bool param1) = 0;
	virtual void NotifyTermination() = 0;
	virtual EOrderCompletionStatus CompletionStatus() const;
	virtual void UpdateCollisionInfo() const;
	virtual void OnAnimationEvent(unsigned int nEventId, float fWeight);

	ZAnimProgramBase() = default;
	ZAnimProgramBase(ZNPCMorphemeNetworkController* pController, ZAnimatedActor* pAnimatedActor, bool bLockOnNavMesh);
	void UpdateAim(float timeDelta, const bool bShouldAim, const bool bRightHand, const float4& wsAimTargetPosition);
	void UpdateActAim(float timeDelta, const bool bShouldAim, const bool bRightHand, const float4& wsAimTargetPosition);
	void UpdateLookAt(const ZPositionTarget& lookAtTarget, const ZPositionTarget& aimTarget);
	void StartUpperbodyAct(const SActOrderParams& params);
	void DecideLookAtTarget(const ZPositionTarget& orderlookAtTarget, const ZPositionTarget& orderAimTarget, bool& bShouldLook, float4& wsLookAtPoint, bool& bEyesOnly);
};
