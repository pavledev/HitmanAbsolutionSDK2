#pragma once

#include "ZSituationMember.h"

class ZCombatSituationMember : public ZSituationMember
{
public:
	float m_fDistanceToTarget;
	float m_fDistanceFieldValue;
	bool m_bIsPreferredToFire;
	bool m_bIsReinforcing;
	bool m_bCanRequestCoverFire;
	bool m_bDialogPreventShooting;
	bool m_bCanFlee;
	bool m_bCantFleeNoPath;

	~ZCombatSituationMember() override = default;
	void OnOrderAssigned() override;

	ZCombatSituationMember() = default;
	ZCombatSituationMember(const TEntityRef<ZSituationBase>& rSituation, const TEntityRef<ZActor>& rActor);
};
