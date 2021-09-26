#pragma once

#include "TEntityRef.h"
#include "ZActor.h"
#include "ECCNodeType.h"
#include "ECCTargetPos.h"

struct SHM5CCTarget
{
	TEntityRef<ZActor> m_rActor;
	bool m_bAtPos;
	bool m_bValidPos;
	ECCNodeType m_eStartState;
	ECCTargetPos m_eTargetPos;
	float4 m_vPos;
	float4 m_vRunInPos;
	bool m_bSelected;
	bool m_bPassified;
	float m_fTimeToAttack;
	bool m_bDisabled;
	bool m_bMainTarget;
	bool m_bBeenMainTarget;
	float m_fDamageReceived;
	float m_fPendingDamage;
	float m_fTimeInQueue;
	unsigned int m_nNormalAttacksReceived;
	bool m_bFirstAttack;

	SHM5CCTarget(const SHM5CCTarget& __that);
	SHM5CCTarget() = default;
	void Reserve(const TEntityRef<ZActor>& rActor, ECCNodeType eStartState);
	bool IsReserved() const;
	void SetMainTarget(bool bMainTarget);
	void UpdateDamageReceived();
	void Release();
	bool IsAtPos(const float4& vPos) const;
	bool IsMainTarget() const;
	bool IsBossTarget() const;
	bool NPCStartedFight() const;
	bool IsHitTarget() const;
	void AddDamage(bool bSpecial);
	bool DamageTakeDown() const;
	void AddNormalAttack();
	float GetAttackFraction() const;
	bool FightIdle() const;
	void UpdateAttackTime(float fDeltaTime, bool allowAttack);
	void ResetTimeInQueue();
	bool IsRunInActive() const;
	bool IsCloseCombatActive() const;
	bool CanAttackHitman() const;
	float GetHitmanDamage() const;
	float GetTakeDownWindowTime() const;
	float GetTakeDownIncFraction() const;
	float GetDecayTime() const;
	int GetMashNum() const;
	int GetSnapNeckMashNum() const;
	void ClearFirstAttack();
	bool IsFirstAttack() const;
	ZHM5CCProfile* GetCCProfile() const;
	bool WaitingToAttack() const;
	bool IsReadyToAttack() const;
	void ResetTimeToAttack();
	void ResetTimeToAttackPacified();
	float TimeLeftToAttack() const;
	bool IsSelected() const;
	~SHM5CCTarget() = default;
};
