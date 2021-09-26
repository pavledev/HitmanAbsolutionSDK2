#pragma once

#include "ZHM5BaseController.h"
#include "SAimCandidate.h"
#include "EAimAssistMode.h"
#include "EHM5BaseControllerType.h"
#include "EHM5ResetReason.h"
#include "SMatrix.h"
#include "TArray.h"
#include "TEntityRef.h"
#include "float4.h"

class ZActor;
class ZHitman5;
class ZSpatialEntity;
struct SGameUpdateEvent;
struct SHM5ControllerUpdateEvent;

class ZHM5AimAssist : public ZHM5BaseController
{
public:
	float4 m_vClipPlanes[6];
	float4 m_vSlowDownClipPlanes[6];
	TArray<SAimCandidate> m_TargetCandidates;
	SMatrix m_mvInvFrustumBase;
	SAimCandidate m_BestCandidate;
	SAimCandidate m_BestSlowDownCandidate;
	float m_fSlowDownFactor;
	TEntityRef<ZHitman5> m_pHitman;
	bool m_bActorNearbyCrosshair;
	bool m_AAEnabled;
	EAimAssistMode m_eAimAssistMode;

	~ZHM5AimAssist() override = default;
	void Update(const SHM5ControllerUpdateEvent& HM5ControllerUpdateEvent) override;
	void Reset(EHM5ResetReason eResetReason) override;

	ZHM5AimAssist() = default;
	ZHM5AimAssist(const TEntityRef<ZHitman5>& pHitman, EHM5BaseControllerType eType);
	float GetAACamSlowDownFactor() const;
	const SAimCandidate& GetBestAimCandidate() const;
	void Enable(bool enable);
	TEntityRef<ZHitman5> Hitman() const;
	void SelectAimAssistMode();
	void CreatePlanes(const SHM5ControllerUpdateEvent& HM5ControllerUpdateEvent);
	void CollectCandidateBones();
	void CollectCandidateProps();
	void CollectShootingBalletCandidateProps();
	void CheckPropAimAssistCandidacy(const TEntityRef<ZSpatialEntity> rSpatial, bool bExcludeFromSlowdown);
	void FilterCandidates();
	bool IgnoreActor(TEntityRef<ZActor> actor);
	void CastRays();
	bool ShouldUpdate();
	void UpdateSlowDownFactor(const SGameUpdateEvent& updateEvent);
	void SelectBestCandidate();
	bool UseAimAssist() const;
};
