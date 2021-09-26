#pragma once

#include "float4.h"
#include "SHM5CCTarget.h"
#include "ZHitman5.h"
#include "ZPF5Location.h"

class ZHM5CCTargetController
{
public:
	struct STargetPositions
	{
		ECCTargetPos m_eFirstPos;
		ECCTargetPos m_eSecondPos;
	};

	bool m_bAllowAttacks;
	float4 m_vMainDir;
	float4 m_vMainPos;
	SHM5CCTarget m_TargetPos[4];
	SHM5CCTarget m_RunInTargetInfo[3];
	TEntityRef<ZHitman5> m_pHitman;
	ZPF5Location m_StartLocation;
	bool m_bLock;

	ZHM5CCTargetController() = default;
	ZHM5CCTargetController(const TEntityRef<ZHitman5>& pHitman);
	bool ReservePosition(const TEntityRef<ZActor>& rActor, ECCNodeType eStartState);
	void ForcePosition(const TEntityRef<ZActor>& rActor, ECCNodeType eStartState);
	const SHM5CCTarget& GetTarget(unsigned int nIndex) const;
	SHM5CCTarget* GetTarget();
	void ResetTimers();
	void ResetTimeToAttack(const TEntityRef<ZActor>& rActor, bool pacified);
	void Update();
	const SHM5CCTarget* GetTargetInfo(const TEntityRef<ZActor>& rActor) const;
	void ReleaseTargets();
	void ReleaseRunInTargets();
	void ReleaseTarget(const TEntityRef<ZActor>& rActor);
	void ReleaseCrowdActors();
	void ReleaseAllExcept(const TEntityRef<ZActor>& rActor);
	float4 GetMainPosition() const;
	unsigned int GetNumTargets() const;
	const ZPF5Location& GetStartLocation() const;
	void Lock(bool bLock);
	SHM5CCTarget* ChangeTarget();
	bool ReserveRunIn(const TEntityRef<ZActor>& rActor);
	float4 GetHitmanPos() const;
	ZPF5Location GetHitmanMappedPos() const;
	ZPF5Location GetMappedPos(const float4& vPos) const;
	unsigned int GetNumActiveReservations() const;
	unsigned int GetNumRunInReservations() const;
	unsigned int GetMaxReservations() const;
	void UpdateTimeToAttack();
	SHM5CCTarget* GetFirstReadyTarget();
	SHM5CCTarget* GetFirstWaitingTarget();
	SHM5CCTarget* GetAvaliableTarget(const TEntityRef<ZActor>& rActor);
	SHM5CCTarget* GetAvaliableTarget(unsigned int idx);
	SHM5CCTarget* GetAvaliableTarget();
	void AllowTargetsToAttack(bool allow);
	void ForceWaitingTarget(unsigned int iNumTargets);
	SHM5CCTarget* GetSelectedTarget();
	void ResetTargetSelection();
	void SelectTarget(const float4& selectDir, bool ignoreWaitingTargets);
	void SelectTarget(const TEntityRef<ZActor>& rActor);
	bool CanReservePosition(const float4& vHitmanPos, const float4& vActorPos) const;
	bool CanReservePosition(const TEntityRef<ZActor>& rActor) const;
	bool ReserveSecondaryPos(const TEntityRef<ZActor>& rActor, ECCNodeType eStartState);
	bool OppositePos(ECCTargetPos eTargetPos, ECCTargetPos eTargetPos2) const;
	STargetPositions GetTargetPositions(const TEntityRef<ZActor>& rActor) const;
	~ZHM5CCTargetController() = default;
};
