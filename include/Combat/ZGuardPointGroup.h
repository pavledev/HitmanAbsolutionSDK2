#pragma once

#include "ZSituationGroup.h"
#include "ZCombatZoneEntity.h"

class ZGuardPointGroup : public ZSituationGroup
{
public:
	bool m_bGroupEngaged;
	TEntityRef<ZCombatZoneEntity> m_combatZone;
	TEntityRef<ZGuardPointEntity> m_guardPointEntity;
	ZGameTime m_tGroupTime;

	~ZGuardPointGroup() override = default;
	void OnMemberDeactivated(TRefCountPtrArg<ZSituationMember> rMember) override;

	ZGuardPointGroup() = default;
	ZGuardPointGroup(const TEntityRef<ZSituationBase>& rSituation, TRefCountPtrArg<ZSituationMember> pGuard, const TEntityRef<ZCombatZoneEntity>& combatZone, const TEntityRef<ZGuardPointEntity>& guardPointEntity);
	void AddGuard(TRefCountPtrArg<ZSituationMember> pGuard);
	void RemoveGuard(TRefCountPtrArg<ZSituationMember> pGuard);
	TEntityRef<ZGuardPointEntity> GetGuardPointEntity();
	float GetAge() const;
	bool Update(const float4& vLastLOSPosition);
};
