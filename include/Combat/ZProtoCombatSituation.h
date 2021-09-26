#pragma once

#include "ZSituationBase.h"
#include "ECombatState.h"
#include "ZCombatTacticalHelper.h"
#include "EActorGroup.h"
#include "ESituationJoinReason.h"
#include "SComponentMapEntry.h"
#include "THashMap.h"
#include "TMaxArray.h"
#include "TRefCountPtr.h"
#include "ZGameTime.h"
#include "ZGridJobRequest.h"
#include "ZGridNodeRef.h"
#include "ZSharedKnowledgeRef.h"
#include "ZVariantRef.h"
#include "float4.h"

class ZActor;
class ZActorDialog;
class ZCheckLastPositionGroup;
class ZCombatSituationMember;
class ZComponentCreateInfo;
class ZGridFloatField;
class ZGuardPointGroup;
class ZHM5CoverPlane;
class ZHandleClosetGroup;
class ZHandleVentGroup;
class ZHumanShieldGroup;
class ZSituationMember;
struct SDialogEvalParams;
struct SFindBestTacticalPositionOutput;
struct SGameUpdateEvent;
struct SKnownEntity;
struct STypeID;
struct float1;
template <class A, class B> class TDefaultHashMapPolicy;
template <class T> class TEntityRef;
template <class T> class TRefCountPtrArg;

class ZProtoCombatSituation : public ZSituationBase
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum EFleeRuleState
	{
		FRS_SELECT_CANDIDATE = 0,
		FRS_SELECT_GUARD_FOR_HELP = 1,
		FRS_SELECT_FLEE_LOCATION = 2
	};

	enum EHumanShieldCombatState
	{
		HSCS_None = 0,
		HSCS_Negotiate = 1,
		HSCS_Eliminate = 2
	};

	struct SCombatInformation
	{
		int m_nActiveFighting;
		int m_nActorsInHoldGuard;
		int m_nHumanShieldGroups;
		int m_nCheckLastPositionGroups;
		int m_nDeaths;
		int m_nGuardsShooting;
		int m_nPotentialCLPActorCount;
		bool m_bNoStanddown;
		EActorGroup m_actorGroupForCLP;

		SCombatInformation() = default;
	};

	struct SCombatHazardZone
	{
		float4 m_wsPosition;
		float m_fRadius;
		float m_fTime;

		SCombatHazardZone(const float4& wsPosition, float fRadius, float fTime);
	};

	struct SDialogInformation
	{
		unsigned int m_nFlanked;
		bool m_bAnyNPCFiring;
		bool m_bTargetHit;
		bool m_bWeaponReloading;
		bool m_bInCover;
		bool m_bEnteringCloset;
		bool m_bInCloset;
		bool m_bShooting;
		bool m_bCloseCombat;
		bool m_bWieldingCCWeapon;
		bool m_bDefensiveShout;
		bool m_bPlayCmbtLngLstRsp;
		bool m_bPlayCmbtCvrFirRsp;
		bool m_bHitmanDead;

		SDialogInformation() = default;
	};

	ECombatState m_combatState;
	TRefCountPtr<ZGridFloatField> m_dangerField;
	ZGridJobRequest<TRefCountPtr<ZGridFloatField>> m_dangerFieldRequest;
	TRefCountPtr<ZGridFloatField> m_fleeToGuardField;
	ZGridJobRequest<TRefCountPtr<ZGridFloatField>> m_fleeToGuardFieldRequest;
	TRefCountPtr<ZCombatSituationMember> m_pFleeCandidate;
	ZGridJobRequest<ZGridNodeRef> m_fleeNodeRequest;
	unsigned int m_nFleeIndex;
	EFleeRuleState m_eFleeRuleState;
	ZGameTime m_tNextFleeCandiate;
	TMaxArray<TEntityRef<ZActor>, 8> m_aHelpfulGuards;
	TRefCountPtr<ZHandleVentGroup> m_handleVentGroup;
	TRefCountPtr<ZHandleClosetGroup> m_handleClosetGroup;
	TRefCountPtr<ZCheckLastPositionGroup> m_checkLastPositionGroup;
	TRefCountPtr<ZHumanShieldGroup> m_humanShieldGroup;
	TMaxArray<SCombatHazardZone, 128> m_CombatHazardZones;
	THashMap<unsigned int, TRefCountPtr<ZGuardPointGroup>, TDefaultHashMapPolicy<unsigned int, TRefCountPtr<ZGuardPointGroup>>> m_guardPointToGroup;
	TMaxArray<TRefCountPtr<SKnownEntity>, 8> m_aExplosiveEntities;
	ZGameTime m_lastLOSTime;
	ZGameTime m_tTargetLostTime;
	ZGameTime m_tCombatStartTime;
	bool m_bCLPAttentionResetDone;
	float m_fCLPTargetOutOfSightTime;
	int m_nCLPCount;
	ZGridNodeRef m_rLastKnownTargetNode;
	ZHM5CoverPlane* m_pThreatCover;
	float4 m_vLastLOSPosition;
	bool m_bTargetLost;
	bool m_bSearchCompleted;
	bool m_bHandleClosetCompleted;
	ZGameTime m_tLastHandleClosetTime;
	bool m_bHandleVentCompleted;
	ZGameTime m_tLastHandleVentTime;
	ZGameTime m_tLastTacticalOrderIssued;
	ZGameTime m_tLastGuardShooting;
	EHumanShieldCombatState m_humanShieldState;
	bool m_bTargetKnownInCloset;
	bool m_bTargetKnownInVent;
	float m_fAggressionLevel;
	ZGameTime m_tLastWeaponFiredHandleTime;
	SCombatInformation m_combatInfo;
	SDialogInformation m_dialogInfo;
	TRefCountPtr<ZActorDialog> m_pSpottedDialog;
	ZCombatTacticalHelper m_TacticalInfo;
	unsigned int m_nUpdateTacticalInfoIndex;
	TRefCountPtr<ZCombatSituationMember> m_pMemberBeingUpdated;
	ZGridJobRequest<SFindBestTacticalPositionOutput> m_tacticalPositionRequest;
	ZGridJobRequest<TRefCountPtr<ZGridFloatField>> m_occupancyFieldRequest;

	static SComponentMapEntry s_componentMap[0];

	~ZProtoCombatSituation() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	bool CanJoin(const TEntityRef<ZActor>& pActor, const ZSharedKnowledgeRef& rTarget) const override;
	void OnSituationStarted() override;
	void OnSituationEnded() override;
	TRefCountPtr<ZSituationMember> OnActorJoin(const TEntityRef<ZActor>& pActor, const TRefCountPtr<SKnownEntity>& rTarget, ESituationJoinReason eReason) override;
	void OnActorLeave(TRefCountPtrArg<ZSituationMember> pMember) override;
	void OnUpdate(const SGameUpdateEvent& updateEvent) override;

	ZProtoCombatSituation() = default;
	static void RegisterType();
	ZProtoCombatSituation(ZComponentCreateInfo& info);
	bool IsInCheckLastPosition();
	bool IsInHumanShield();
	bool IsSearchCompleted();
	int GetGuardShootingCount();
	ZGridNodeRef GetLastKnownTargetNode();
	ZGameTime GetLastWeaponFiredHandleTime();
	float GetDistanceToKnownHitman(const ZGridNodeRef& node);
	void ReportNoLOS(const TRefCountPtr<ZCombatSituationMember>& rMember);
	bool HasDistanceFieldFromTarget();
	const TRefCountPtr<ZGridFloatField>& GetDistanceFieldFromTarget() const;
	bool IsInsideGuardPoint(const TRefCountPtr<ZCombatSituationMember>& rMember) const;
	bool StartBackupDialog();
	void UpdateTargetInformation();
	void UpdateCombatInformation();
	void UpdateCheckLastPositionGroup();
	void UpdateHandleClosetGroup();
	void UpdateHandleVentGroup();
	void UpdateHumanShieldGroups();
	void UpdateGuardPointGroups();
	bool IsWithinSlice(const float4& v1, const float4& v2, const float4& vCenter, const float1& vAngleDeg);
	void Rule_Propagate();
	void Rule_CreateCheckLastPositionGroup();
	void Rule_StandDown();
	void Rule_StandownCilivian();
	void Rule_CreateHandleClosetGroup();
	void Rule_CreateHandleVentGroup();
	void Rule_FillGuardPoints();
	void Rule_HumanShield();
	void Rule_Firepattern();
	void Rule_Fight();
	void Rule_Flee();
	float TimeSinceLastLOS();
	float TimeSinceTargetLost();
	void UpdateCheckLastPosition();
	void ResetCheckLastPosition();
	bool ShouldDoCheckLastPosition();
	bool IsTargetHidingInVent();
	bool IsTargetHidingInCloset();
	bool IsTargetKnownInVent();
	bool IsTargetKnownInCloset();
	bool IsTargetVisible(float fSlack);
	void IncreaseAggression(float fAmount);
	void Standdown();
	void AddExplosiveEntity(TRefCountPtr<SKnownEntity> entityRef);
	void UpdateExplosiveEntities();
	void AddHazardZone(const float4& wsHazardPosition, float fOverrideRadius, float fOverrideTime);
	void UpdateHazardZones(float fTimeDelta);
	void Flee_UpdateDangerField();
	bool Flee_SelectCandidate();
	bool Flee_SelectGuardForHelp();
	bool Flee_SelectFleeLocation();
	void Speak_OnHitmanKilledActor(TRefCountPtrArg<ZSituationMember> pMember);
	void DialogX_UpdateInfo();
	bool Eval_Default(SDialogEvalParams& evalParams);
	bool Eval_CmbtFire(SDialogEvalParams& evalParams);
	bool Eval_CmbtFireLdr(SDialogEvalParams& evalParams);
	bool Eval_CmbtHMKllCiv(SDialogEvalParams& evalParams);
	bool Eval_CmbtHMKll(SDialogEvalParams& evalParams);
	bool Eval_CmbtHMKllName(SDialogEvalParams& evalParams);
	bool Eval_CmbtHMKllPrpTss(SDialogEvalParams& evalParams);
	bool Eval_CmbtHMKllXplo(SDialogEvalParams& evalParams);
	bool Eval_CmbtHMHeadPopr(SDialogEvalParams& evalParams);
	bool Eval_CmbtGtHit(SDialogEvalParams& evalParams);
	bool Eval_CmbtBackupRsp(SDialogEvalParams& evalParams);
	bool Eval_CmbtHMFlnk(SDialogEvalParams& evalParams);
	bool Eval_CmbtHoldLdr(SDialogEvalParams& evalParams);
	bool Eval_CmbtHold(SDialogEvalParams& evalParams);
	bool Eval_CmbtStalemateHold(SDialogEvalParams& evalParams);
	bool Eval_CmbtStalemateTnt(SDialogEvalParams& evalParams);
	bool Eval_CmbtHMClsCmbtAck(SDialogEvalParams& evalParams);
	bool Eval_CmbtHitHM(SDialogEvalParams& evalParams);
	bool Eval_CmbtHMRelod(SDialogEvalParams& evalParams);
	bool Eval_CmbtHMCvr(SDialogEvalParams& evalParams);
	bool Eval_CmbtHMFire(SDialogEvalParams& evalParams);
	bool Eval_CmbtRelod(SDialogEvalParams& evalParams);
	bool Eval_CmbtNdrAttck(SDialogEvalParams& evalParams);
	bool Eval_CmbtHMSht2Blw(SDialogEvalParams& evalParams);
	bool Eval_CmbtLstMnStn(SDialogEvalParams& evalParams);
	bool Eval_CmbtLngLst(SDialogEvalParams& evalParams);
	bool Eval_CmbtLngLstRsp(SDialogEvalParams& evalParams);
	bool Eval_CmbtKllHM(SDialogEvalParams& evalParams);
	bool Eval_CmbtCvrFirLdr(SDialogEvalParams& evalParams);
	bool Eval_CmbtCvrFirRsp(SDialogEvalParams& evalParams);
	bool Eval_CmbtClsAck(SDialogEvalParams& evalParams);
	bool Eval_HMShrpShtr(SDialogEvalParams& evalParams);
	bool Eval_HMMssTnt(SDialogEvalParams& evalParams);
};
