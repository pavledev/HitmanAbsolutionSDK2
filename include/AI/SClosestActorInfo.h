#pragma once

#include "TEntityRef.h"

class ZActor;

struct SClosestActorInfo
{
	TEntityRef<ZActor> m_pMaxFacingAlertableActor;
	TEntityRef<ZActor> m_pClosestAlertableActor;
	TEntityRef<ZActor> m_pClosestAlertableGuard;
	TEntityRef<ZActor> m_pClosestEngagedActor;
	float m_fMaxFacingAlertableActor;
	float m_fClosestAlertableActor;
	float m_fClosestAlertableGuard;
	float m_fClosestEngagedActor;
	float m_fMaxFacingAlertablePan;
	float m_fClosestAlertablePan;
	float m_fClosestAlertableGuardPan;
	float m_fClosestEngangedPan;

	SClosestActorInfo() = default;
	~SClosestActorInfo() = default;
	SClosestActorInfo& operator=(const SClosestActorInfo& __that);
};
