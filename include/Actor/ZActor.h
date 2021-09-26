#pragma once

#include "ZHM5BaseCharacter.h"
#include "ICharacterCollision.h"
#include "EActorType.h"
#include "EActorRank.h"
#include "EActorGroup.h"
#include "SActorSoundDefs.h"
#include "ZShootTargetInfo.h"
#include "ZPositionTarget.h"
#include "EActorDeathType.h"
#include "EActorPerceptionSensitivity.h"
#include "EGameTension.h"
#include "EAttachLocation.h"
#include "EActorInteractionFlag.h"
#include "EAISharedEventType.h"
#include "ECCActorEvent.h"
#include "ECCActorEventDir.h"
#include "SActorHSState.h"
#include "EActorCCPreset.h"
#include "ERenderGlowTypes.h"
#include "SComponentMapEntry.h"
#include "SMatrix.h"
#include "SMatrix43.h"
#include "STokenID.h"
#include "TArray.h"
#include "TArrayRef.h"
#include "TEntityRef.h"
#include "TMap.h"
#include "TResourcePtr.h"
#include "TSharedPointer.h"
#include "ZEntityRef.h"
#include "ZEvent.h"
#include "ZGameTime.h"
#include "ZResourcePtr.h"
#include "ZRuntimeResourceID.h"
#include "ZString.h"
#include "ZVariantRef.h"
#include "float4.h"

class ZHumanShieldLocomotion;
class ZCarryCivilianLocomotion;
class ZAnimatedActor;
class IHM5Item;
class IHM5ItemWeapon;
class ISoundDefinition;
class ISoundPlayable;
class ISoundPlayerChannel;
class IWaveBankData;
class ZActorAnimationState;
class ZActorInstanceEntity;
class ZAnimationRig;
class ZBehaviorEntityBase;
class ZCharacterTemplateAspect;
class ZCompiledBehaviorTree;
class ZComponentCreateInfo;
class ZControlledAnimLocomotion;
class ZEventNull;
class ZHM5CCProfile;
class ZHM5ItemCCWeapon;
class ZHM5ItemWeapon;
class ZHM5Ragdoll;
class ZHuntProfile;
class ZKnowledge;
class ZPointOfInterestEntity;
class ZSoundPlayerCallbackExtraData;
class ZSpatialEntity;
class ZVolumeTriggerEntity;
struct SGameUpdateEvent;
struct SHitInfo;
struct STypeID;
template <class A, class B> class THashSet;
template <class T> class TDefaultHashSetPolicy;
template <class T> class TRefCountPtr;

class ZActor : public ZHM5BaseCharacter, public ICharacterCollision
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum EShootIntensity
	{
		SHOOT_INTENSITY_LOW = 0,
		SHOOT_INTENSITY_MEDIUM = 1,
		SHOOT_INTENSITY_HIGH = 2
	};

	enum EActorState
	{
		AS_UNDEFINED = 0,
		AS_ALIVE = 1,
		AS_DEAD = 2
	};

	struct SRandomToggle
	{
		float m_fEnabledTimeMin;
		float m_fEnabledTimeMax;
		float m_fDisabledTimeMin;
		float m_fDisabledTimeMax;
		float m_TimeToChangeState;
		bool m_bEnabled;

		SRandomToggle() = default;
		void Reset(bool bEnabled);
		void SetIntervals(float fEnabledMin, float fEnabledMax, float fDisabledMin, float fDisabledMax);
		float GetTimeToChangeState();
		void Update(float fTimeDelta);
		bool IsEnabled();
	};

	TEntityRef<ZHM5CCProfile> m_rCCProfile;
	TEntityRef<ZHuntProfile> m_pHuntProfile;
	bool m_bStartEnabled;
	bool m_bPreferredInvestigator;
	bool m_bStartAgitated;
	bool m_bAllowAgitatedAmbient;
	bool m_bCanCallForHelp;
	bool m_bDropWeapons;
	bool m_bPreferredAccidentInvestigator;
	bool m_bAccidentShy;
	ZString m_sActorName;
	EActorType m_eActorType;
	EActorRank m_eActorRank;
	EActorGroup m_eActorGroup;
	bool m_bContractsEligible;
	bool m_eDifficulty_Level1;
	bool m_eDifficulty_Level2;
	bool m_eDifficulty_Level3;
	bool m_eDifficulty_Level4;
	TArray<TEntityRef<ZBehaviorEntityBase>> m_behaviors;
	TArray<TEntityRef<IHM5Item>> m_inventory;
	TEntityRef<IHM5Item> m_leftHandItem;
	TEntityRef<IHM5Item> m_rightHandItem;
	TEntityRef<ZSpatialEntity> m_pHelpPoint;
	TArray<TEntityRef<ZPointOfInterestEntity>> m_PointOfInterestArray;
	TEntityRef<ZVolumeTriggerEntity> m_pVolumeTrigger;
	TEntityRef<ISoundDefinition> m_pSoundDefinition;
	TEntityRef<ISoundPlayable> m_pDefaultDialogueEmitter;
	TEntityRef<ZActorInstanceEntity> m_pActorInstance;
	TResourcePtr<ZCompiledBehaviorTree> m_pCompiledBehaviorTree;
	ERenderGlowTypes m_eInstinctGlow;
	TArray<ZString> m_StatLabelList;
	bool m_bEnableFaceMoodInSequence;
	bool m_bNoticedWhenKilled;
	TEntityRef<ZActor> m_pThis;
	TEntityRef<ZCharacterTemplateAspect> m_pCharacterTemplate;
	TMap<ZString, bool> m_Breakpoints;
	TSharedPointer<ZKnowledge> m_pKnowledge;
	TSharedPointer<ZHumanShieldLocomotion> m_pCurrentHumanShield;
	TSharedPointer<ZCarryCivilianLocomotion> m_pCurrentCarryCivilian;
	ZAnimatedActor* m_pAnimatedActor;
	unsigned int m_nLipSyncAnimationID;
	unsigned int m_nStreamedLipSyncUID;
	ISoundPlayerChannel* m_pSubtitleSoundChannel;
	unsigned short m_nImpactCount;
	unsigned short m_nCachedRoomID;
	bool m_bForceUpdate : 1;
	bool m_bIsBeingDragged : 1;
	bool m_bActorActivated : 1;
	bool m_bEnabled : 1;
	bool m_bStreamedIn : 1;
	bool m_bInSequence : 1;
	bool m_bIgnoreLOF : 1;
	bool m_bHasLOF : 1;
	bool m_bBlindfire : 1;
	bool m_bShootingRequested : 1;
	bool m_bBodyHidden : 1;
	bool m_bIsInCutsequence : 1;
	bool m_bDeathAnimationEnabled : 1;
	bool m_bDisabledByForwardSpawn : 1;
	bool m_bAboutToDie : 1;
	bool m_bMuted : 1;
	bool m_bSpeaking : 1;
	bool m_bSpeakPlaying : 1;
	bool m_bDefaultSpeakPlaying : 1;
	bool m_bChangingGeometryInProgress : 1;
	bool m_bSBKillTagged : 1;
	bool m_bTransformChangeCallbackRegistered : 1;
	bool m_bGreetedHM : 1;
	bool m_bAloneHumanShieldVictim : 1;
	bool m_bHasBeenPacified : 1;
	bool m_bBodyWaterSplashed : 1;
	bool m_bWasSeenDying : 1;
	SActorSoundDefs::EDefinition m_eActiveSpeak;
	SActorSoundDefs::EDefinition m_eDeathSpeak;
	ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_SpeakInterruptedEvent;
	ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_SpeakEndEvent;
	ZGameTime m_tSpeakEndTime;
	ZGameTime m_tSequenceEndTime;
	ZGameTime m_nReleaseRagdollAfterHiddenTime;
	EActorDeathType m_eDeathType;
	EActorDeathType m_eRegisteredDeathType;
	EActorState m_nActorState;
	TArray<SHitInfo> m_HitInfoList;
	int m_nLookAroundActs[3];
	int m_nLookAroundActShuffleIndex;
	bool m_bDeadTarget;
	bool m_bDiedFromHeadshot;
	bool m_bDeathVisible;
	ZShootTargetInfo m_ShootTargetInfo;
	float m_fAimingStartTime;
	SRandomToggle m_ShootingToggle;
	ZPositionTarget m_rShootTarget;
	TArray<TEntityRef<IHM5Item>> m_runtimeInventory;
	const char* m_sCurrentMood;
	float m_nCrowdTimer;
	unsigned int m_iDisableInteractionFlags;
	STokenID m_TokenID;
	TEntityRef<ZHM5BaseCharacter> m_rAmbientLookAtCharacter;
	TEntityRef<ZPointOfInterestEntity> m_rCurrentPOI;
	bool m_bAllowAmbientLookAt;
	ZGameTime m_timeCurrentPOIwasSet;
	ZEntityRef m_pBrokenActorEntity;

	static SComponentMapEntry s_componentMap[0];
	static const int LOOK_AROUND_ACT_COUNT;
	static unsigned int m_snOnAccidentDeath;
	static unsigned int m_snOnMurdered;
	static unsigned int m_snOnPacified;
	static unsigned int m_snOnUnnoticableKill;
	static unsigned int m_snInvisibleOnNude;

	~ZActor() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void StreamIn() override;
	void StreamOut() override;
	bool IsStreamedIn() override;
	void GetStreamableIncludes(THashSet<ZEntityRef, TDefaultHashSetPolicy<ZEntityRef>>& streamableIncludes) const override;
	void OnEnterEditMode() override;
	void OnExitEditMode() override;
	void Init() override;
	bool AddItemToInventory(const TEntityRef<IHM5Item>& pItem) override;
	void RemoveItemFromInventory(const TEntityRef<IHM5Item>& rItem) override;
	void ReleaseRagdoll() override;
	bool IsWearingOutfit() const override;
	bool IsDead() const override;
	bool CanBeDragged() const override;
	void ResetCharacter() override;
	bool CreateBodyCollision() override;
	void UpdateBodyCollisionPoses(bool bMoveTransform) override;
	void OnAnimatorChanged() override;
	void SetSequenceWeight(float fFeatherWeight, unsigned int track) override;
	void SetSequenceFeatherWeight(float fFeatherWeight, unsigned int track) override;
	void BlendOutSequenceWeights() override;
	void OnOutfitEntityChanged() override;
	ZHM5Ragdoll* AcquireRagdollInstance(const float4& vSearchPos) override;
	virtual void Enable();
	virtual void Disable();
	virtual bool IsEnabled();
	virtual bool IsActivated();
	virtual bool CanBeAgitated() const;
	virtual void HealthUpdate(const SGameUpdateEvent& updateEvent);
	virtual void FrameUpdate(const SGameUpdateEvent& updateEvent);

	void YouGotHit(const SHitInfo& hitInfo) override;

	void CutSequenceSetWorldTransform(const SMatrix43& mNewWorldTransform) override;

	SMatrix GetCollisionCheckedMatPos(const SMatrix& MatPos) override;

	ZActor() = default;
	static void RegisterType();
	ZActor(ZComponentCreateInfo& info);
	bool IsFullyEnabled() const;
	bool IsAlive() const;
	bool IsPacified() const;
	EActorDeathType GetDeathType() const;
	bool HasBeenPacified() const;
	EActorDeathType GetRegisteredDeathType() const;
	void SetRegisteredDeathType(EActorDeathType eDeathType);
	void SetIsDeadTarget(bool dt);
	bool IsDeadTarget() const;
	static bool TestAllTargetsKilled(bool& bHaveTargets);
	bool IsBodyHidden() const;
	void BodyHidden(bool b);
	void BodyWaterSplashed(bool b);
	bool IsSharedEventCurrent(EAISharedEventType eventType) const;
	void RenewSharedEvent(EAISharedEventType eventType, float fDuration);
	void ExpireSharedEvent(EAISharedEventType eventType);
	void OnSpawned();
	EActorType GetActorType() const;
	EActorRank GetActorRank() const;
	EActorGroup GetActorGroup() const;
	void SetActorGroup(EActorGroup group);
	bool IsRadioActAllowed() const;
	EActorPerceptionSensitivity GetPerceptionSensitivity(const EGameTension eTension) const;
	EActorPerceptionSensitivity GetPerceptionSensitivity() const;
	unsigned int ForceUpdate();
	const TResourcePtr<ZCompiledBehaviorTree>& GetBehaviorTree() const;
	bool IsUpdateForced() const;
	void SetForceUpdate(bool bForced);
	float4 GetBoneWorldPosition(unsigned int iBoneId) const;
	SMatrix43 GetBoneWorldTransform(unsigned int iBoneId) const;
	SMatrix43 GetBoneTransform(unsigned int iBoneId) const;
	void SetAboutToDie();
	bool IsAboutToDie() const;
	void KillActor(EActorDeathType eDeathType, bool bDeathVisible);
	void DeadlyThrowKill(TEntityRef<IHM5Item> rItem, bool bIsThrowFromBehind);
	void SignalKillSoundManager(bool bCheckForSilencedKill) const;
	void ChangeToNude();
	bool IsFemale() const;
	bool IsHitTarget() const;
	ZRuntimeResourceID GetHMAsResourceID() const;
	bool IsNude() const;
	bool IsBoss() const;
	void StartBeingDragged();
	void StopBeingDragged();
	bool IsBeingDragged() const;
	void StartPull(bool bWindow);
	void StartPush();
	bool CanCallForHelp() const;
	bool IsPreferredAccidentInvestigator() const;
	bool IsAccidentShy() const;
	void SetSBKillTagged(bool bTagged);
	bool GetSBKillTagged() const;
	bool AttachItem(EAttachLocation eLocation, const TEntityRef<IHM5Item>& rItem);
	TEntityRef<IHM5Item> DetachItem(EAttachLocation eLocation, bool bAddToPhysicsWorld, bool bRemoveFromInventory);
	EAttachLocation GetItemLocation(const TEntityRef<IHM5Item>& rItem);
	void DropAllItems();
	void DropKeycardNoPhysics();
	void HideAttachedNonWeapons();
	void ShowAttachedNonWeapons();
	TEntityRef<IHM5Item> GetAttachedItem(EAttachLocation eLocation) const;
	void DropAttachedItems(bool bDropWeapon);
	bool GetAttachLocation(TEntityRef<IHM5Item> pItem, EAttachLocation& loc);
	TEntityRef<IHM5Item> GetInitialRightHandItem();
	void EnterHumanShield(SActorHSState::EHSEnterAnimation eEnterAnimation);
	void ReleaseHumanShield();
	bool EnterCarryCivilian(bool bDirectToStandIdle);
	void ReleaseCarryCivilian();
	void UpdateHumanShieldMovement(const ZString& sRequest);
	void SetDefaultHumansShieldState(const unsigned int nStrafeID);
	void UpdateCarryCivilianMovement(const ZString& sRequest);
	void SetDefaultCarryCivilianState(const unsigned int nStrafeID);
	TSharedPointer<ZControlledAnimLocomotion> StartControlledAnim(const ZString& sAnimSMName, const ZString& sAnimName, bool bSetAnimProgram, bool bBlendToControlledState);
	TSharedPointer<ZControlledAnimLocomotion> CreateControlledProgram(const ZString& sAnimSMName, const ZString& sAnimName);
	ZAnimatedActor* GetAnimatedActor() const;
	ZActorAnimationState* GetAnimationState() const;
	TArrayRef<SHitInfo> GetHitInfoList() const;
	void SetAssert(const ZString& sBreakpointName, bool bEnable);
	const TSharedPointer<ZKnowledge>& GetKnowledge() const;
	const ZKnowledge& Knowledge() const;
	ZKnowledge& Knowledge();
	bool IsMuted() const;
	bool IsSpeaking() const;
	bool IsSpeakPlaying() const;
	SActorSoundDefs::EDefinition GetActiveSpeak() const;
	void SetMuted(bool bMuted);
	bool Speak(SActorSoundDefs::EDefinition eSoundDefinition);
	bool Speak(ZResourcePtr pWavebank);
	void StopSpeak();
	ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull>& GetSpeakInterruptedEvent();
	ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull>& GetSpeakEndEvent();
	void StartSubtitles(ISoundPlayerChannel* pChannel);
	void StopSubtitles(ISoundPlayerChannel* pChannel);
	void StartLipSync(ISoundPlayerChannel* pChannel, const TRefCountPtr<ZSoundPlayerCallbackExtraData> pExtraData);
	void StopLipSync(ISoundPlayerChannel* pChannel);
	bool IsDisabledByForwardSpawn() const;
	TArray<TEntityRef<ZBehaviorEntityBase>>& GetBehaviors();
	void RemoveBehavior(TEntityRef<ZBehaviorEntityBase> rBehavior);
	void PromoteBehavior(TEntityRef<ZBehaviorEntityBase> rBehavior);
	bool IsBehaviorPromoted(TEntityRef<ZBehaviorEntityBase> rBehavior);
	bool IsLeaningAtWindow() const;
	bool IsFacingPosition(const float4& vPos, float fAngleToleranceDegrees) const;
	bool IsFacingDirection(const float4& vDir, float fAngleToleranceDegrees) const;
	void OnSpeakFailed(ISoundPlayerChannel* pChannel, IWaveBankData* pWaveBankData, int nSubSoundIndex, void* pUserData);
	void OnSpeakBeginPlay(ISoundPlayerChannel* pChannel, IWaveBankData* pWaveBankData, int nSubSoundIndex, void* pUserData, const TRefCountPtr<ZSoundPlayerCallbackExtraData> pExtraData);
	void OnSpeakEndPlay(ISoundPlayerChannel* pChannel, IWaveBankData* pWaveBankData, int nSubSoundIndex, void* pUserData);
	void OnDefaultEmitterSpeakFailed(ISoundPlayerChannel* pChannel, IWaveBankData* pWaveBankData, int nSubSoundIndex, void* pUserData);
	void OnDefaultEmitterSpeakBeginPlay(ISoundPlayerChannel* pChannel, IWaveBankData* pWaveBankData, int nSubSoundIndex, void* pUserData, const TRefCountPtr<ZSoundPlayerCallbackExtraData> pExtraData);
	void OnDefaultEmitterSpeakEndPlay(ISoundPlayerChannel* pChannel, IWaveBankData* pWaveBankData, int nSubSoundIndex, void* pUserData);
	void SetActorMultiplier(float fTimeMultiplier);
	void ReleaseRagdollAfterBodyHidden(const ZGameTime& curGameTime);
	bool IsReleaseRagdollAfterBodyHiddenTriggered() const;
	void SetInSequence(bool b);
	bool IsInSequence() const;
	const STokenID& GetTokenID() const;
	ZShootTargetInfo& GetShootTargetInfo();
	TEntityRef<IHM5ItemWeapon> GetCurrentWeapon() const;
	void SwitchWeaponHand(bool bSwitchToLeftHand);
	void UnholsterWeapon(const TEntityRef<IHM5ItemWeapon>& rWeapon);
	bool UnholsterWeapon();
	void HolsterWeapon();
	TEntityRef<IHM5ItemWeapon> GetDisarmWeapon();
	bool HasHandGun() const;
	EActorCCPreset GetCCPreset() const;
	bool IsWeaponFiring() const;
	bool HasFullClip() const;
	bool NeedReload() const;
	ZString GetWeaponName() const;
	bool CalculateShot(const ZEntityRef& target, const float4& vShotOrigin, float4& vShotHitPosition) const;
	bool CheckLOF(const float4& vShotOrigin, const float4& vShotHitPosition, float4& vCollision) const;
	bool IsEnemyInFrontArc(float fArcHalfangleInDeg) const;
	void ShootEnemy();
	void EndShootEnemy();
	bool IsShootingRequested() const;
	void SetShootIntensity(EShootIntensity intensity);
	void UpdateShooting(const SGameUpdateEvent& updateEvent);
	void Reload();
	void CloseCombatEvent(ECCActorEvent eEvent, ECCActorEventDir eDir, const TEntityRef<ZHM5ItemCCWeapon>& rWeapon);
	float CalcGetBoneDamageMultiplier(unsigned int nHitBoneIndex);
	float GetInitHitPoints() const;
	unsigned short UpdateRoomID();
	ZString GetActorName() const;
	bool GetContractsEligible() const;
	void SetContractsEligible(bool bEligible);
	TArray<ZString>& GetStatLabels();
	void OnWeaponFireProjectile(const TEntityRef<ZHM5ItemWeapon>& rWeapon);
	void OnEnable();
	void ForceEnable();
	void OnDisable();
	void ForceDisable();
	void OnForceUnholster();
	void OnForceHolster();
	void OnKillUnnoticed();
	void OnKillByAccident();
	void OnKillByUnnoticedAccident();
	void OnKillByPacify();
	void OnPacifyByAccident();
	void OnKillActor();
	void OnAccidentStart();
	void OnAccidentEnd();
	void OnAboutToDie();
	void OnEnableUnnoticableKill();
	void OnDisableUnnoticableKill();
	bool IsUnnoticableKillEnabled() const;
	void OnFallImpact(TEntityRef<ZActor> pActor);
	void SetInteractionAllowed(EActorInteractionFlag eInteraction, bool bAllowed);
	bool GetInteractionAllowed(EActorInteractionFlag eInteraction) const;
	float GetSpeakEndTime();
	float GetSequenceEndTime();
	void SetHasGreetedHM(bool bGreetedHM);
	bool GetHasGreetedHM() const;
	void SetSeenDying(bool b);
	void SetAloneAsHumanShieldVictim(bool bAlone);
	int LookAroundAct_GetCount();
	ZString LookAroundAct_Select(int nIndex);
	ZString LookAroundAct_SelectRandom();
	void LookAroundAct_Shuffle();
	void OnDisableDeathAnimation();
	void StartShooting(const ZPositionTarget& rTarget, bool bIgnoreLOF, bool bBlindFire);
	void StopShooting();
	void SetShootTarget(const ZPositionTarget& rTarget);
	void ClearShootTarget();
	void RemoveGlow();
	void OnAnimationRigChanged(const ZAnimationRig* pRig, const SMatrix* pMatrix);
	void TryInitAnimatedActor();
	void TryUninitAnimatedActor();
	void OnTestUnrecoverableError();
	void UpdateFaceFX();
	void FlagDeathAsAccident();
	void FlagDeathAsMurder();
	void FlagDeathAsPacify(bool bByAccident);
	void FlagDeathAsUnnoticed();
	void SetDeathType(EActorDeathType eDeathType);
	void UpdateReleaseRagdollAfterBodyHidden(const ZGameTime& curGameTime);
	void SetActorState(EActorState state);
	EActorState GetActorState() const;
	void ImmediateInitialize();
	void ImmediateDeinitialize();
	bool ImmediateEnable();
	void ImmediateDisable();
	void Die(SActorSoundDefs::EDefinition eDeathSpeak);
	TEntityRef<IHM5ItemWeapon> GetPistolInInventory();
	TEntityRef<IHM5ItemWeapon> GetRifleInInventory();
	void SetHitPointsDirect(float fHitpoints);
	void UpdateHasWeapon();
	void InitializeKnowledge();
	void ReleaseKnowledge();
	void OnHelpPointChanged();
	void OnCompiledBehaviorTreeChanged();
	void OnInventoryChanged(const TArray<TEntityRef<IHM5Item>>& old);
	void SelectBehavior(const SGameUpdateEvent& updateEvent);
	void HandleHealth();
	bool IsAvailableOnDifficultyLevel(int iDifficultyLevel) const;
	void AttachWeaponsToHolsters();
	void AttachWeaponToHolster(TEntityRef<IHM5ItemWeapon> pWeapon, const ZString& sBoneName);
	void RegisterTransformChangeCallback();
	void UnregisterTransformChangeCallback();
	void GeomTransformChangeCallback(const ZEntityRef& entity, const SMatrix43& mNewValue);
	bool HasLocomotionControlledBySequence();
	bool IsInFullBodySequence();
	bool GetAmbientLookAt(float4& wsLookAt, bool& bEyesOnly);
	void EnableAmbientLookAt();
	void DisableAmbientLookAt();
	void SetAmbientLookAtCharacter(const TEntityRef<ZHM5BaseCharacter>& rCharacter);
	TEntityRef<ZPointOfInterestEntity> GetRandomStaticPointOfInterest() const;
	void OnUnrecoverableError(const ZString& reason);
	void RemoveActorBroken();
};
