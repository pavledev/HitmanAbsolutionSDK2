#pragma once

#include "ZHM5BaseCharacter.h"
#include "ICharacterCollision.h"
#include "ZHM5CCProfile.h"
#include "ZHuntProfile.h"
#include "EActorType.h"
#include "EActorRank.h"
#include "EActorGroup.h"
#include "ZBehaviorEntityBase.h"
#include "ZPointOfInterestEntity.h"
#include "ISoundDefinition.h"
#include "ZActorInstanceEntity.h"
#include "ZCompiledBehaviorTree.h"
#include "ZCharacterTemplateAspect.h"
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
#include "ZHM5ItemCCWeapon.h"
#include "ZHM5ItemWeapon.h"
#include "ZControlledAnimLocomotion.h"
#include "ZKnowledge.h"

class ZHumanShieldLocomotion;
class ZCarryCivilianLocomotion;
class ZAnimatedActor;

class alignas(16) ZActor : public ZHM5BaseCharacter, public ICharacterCollision
{
public:
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
    alignas(4) TEntityRef<ZActor> m_pThis;
    TEntityRef<ZCharacterTemplateAspect> m_pCharacterTemplate;
    TMap<ZString, bool> m_Breakpoints;
    TSharedPointer<ZKnowledge> m_pKnowledge;
    TSharedPointer<ZHumanShieldLocomotion> m_pCurrentHumanShield;
    TSharedPointer<ZCarryCivilianLocomotion> m_pCurrentCarryCivilian;
    ZAnimatedActor* m_pAnimatedActor;
    unsigned int m_nLipSyncAnimationID;
    unsigned int m_nStreamedLipSyncUID;
    ISoundPlayerChannel* m_pSubtitleSoundChannel;
    unsigned __int16 m_nImpactCount;
    unsigned __int16 m_nCachedRoomID;
    __int8 m_bForceUpdate : 1;
    __int8 m_bIsBeingDragged : 1;
    __int8 m_bActorActivated : 1;
    __int8 m_bEnabled : 1;
    __int8 m_bStreamedIn : 1;
    __int8 m_bInSequence : 1;
    __int8 m_bIgnoreLOF : 1;
    __int8 m_bHasLOF : 1;
    __int8 m_bBlindfire : 1;
    __int8 m_bShootingRequested : 1;
    __int8 m_bBodyHidden : 1;
    __int8 m_bIsInCutsequence : 1;
    __int8 m_bDeathAnimationEnabled : 1;
    __int8 m_bDisabledByForwardSpawn : 1;
    __int8 m_bAboutToDie : 1;
    __int8 m_bMuted : 1;
    __int8 m_bSpeaking : 1;
    __int8 m_bSpeakPlaying : 1;
    __int8 m_bDefaultSpeakPlaying : 1;
    __int8 m_bChangingGeometryInProgress : 1;
    __int8 m_bSBKillTagged : 1;
    __int8 m_bTransformChangeCallbackRegistered : 1;
    __int8 m_bGreetedHM : 1;
    __int8 m_bAloneHumanShieldVictim : 1;
    __int8 m_bHasBeenPacified : 1;
    __int8 m_bBodyWaterSplashed : 1;
    __int8 m_bWasSeenDying : 1;
    SActorSoundDefs::EDefinition m_eActiveSpeak;
    SActorSoundDefs::EDefinition m_eDeathSpeak;
    ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_SpeakInterruptedEvent;
    ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_SpeakEndEvent;
    ZGameTime m_tSpeakEndTime;
    ZGameTime m_tSequenceEndTime;
    ZGameTime m_nReleaseRagdollAfterHiddenTime;
    EActorDeathType m_eDeathType;
    EActorDeathType m_eRegisteredDeathType;

    enum EActorState : __int32
    {
        AS_UNDEFINED = 0x0,
        AS_ALIVE = 0x1,
        AS_DEAD = 0x2
    } m_nActorState;

    TArray<SHitInfo> m_HitInfoList;
    int m_nLookAroundActs[3];
    int m_nLookAroundActShuffleIndex;
    bool m_bDeadTarget;
    bool m_bDiedFromHeadshot;
    bool m_bDeathVisible;
    ZShootTargetInfo m_ShootTargetInfo;
    float m_fAimingStartTime;

    class alignas(4) SRandomToggle
    {
    public:
        float m_fEnabledTimeMin;
        float m_fEnabledTimeMax;
        float m_fDisabledTimeMin;
        float m_fDisabledTimeMax;
        float m_TimeToChangeState;
        bool m_bEnabled;
    } m_ShootingToggle;

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

    enum EShootIntensity : __int32
    {
        SHOOT_INTENSITY_LOW = 0x0,
        SHOOT_INTENSITY_MEDIUM = 0x1,
        SHOOT_INTENSITY_HIGH = 0x2
    };

    virtual ~ZActor();
    virtual ZVariantRef* GetVariantRef(ZVariantRef* result);
    virtual int AddRef();
    virtual int Release();
    virtual void* QueryInterface(STypeID* iid);
    virtual void Activate(ZString* sSubset);
    virtual void Deactivate(ZString* sSubset);
    virtual void StreamIn();
    virtual void StreamOut();
    virtual bool IsStreamedIn();
    virtual void GetStreamableIncludes(THashSet<ZEntityRef, TDefaultHashSetPolicy<ZEntityRef> >* streamableIncludes);
    virtual void OnEnterEditMode();
    virtual void OnExitEditMode();
    virtual void Init();
    virtual bool AddItemToInventory(TEntityRef<IHM5Item>* pItem);
    virtual void RemoveItemFromInventory(TEntityRef<IHM5Item>* rItem);
    virtual void ReleaseRagdoll();
    virtual bool IsWearingOutfit();
    virtual bool IsDead();
    virtual bool CanBeDragged();
    virtual void ResetCharacter();
    virtual bool CreateBodyCollision();
    virtual void UpdateBodyCollisionPoses(bool bMoveTransform);
    virtual void OnAnimatorChanged();
    virtual void SetSequenceWeight(float fFeatherWeight, unsigned int track);
    virtual void SetSequenceFeatherWeight(float fFeatherWeight, unsigned int track);
    virtual void BlendOutSequenceWeights();
    virtual void OnOutfitEntityChanged();
    virtual ZHM5Ragdoll* AcquireRagdollInstance(float4* vSearchPos);
    virtual void Enable();
    virtual void Disable();
    virtual bool IsEnabled();
    virtual bool IsActivated();
    virtual bool CanBeAgitated();
    virtual void HealthUpdate(SGameUpdateEvent* updateEvent);
    virtual void FrameUpdate(SGameUpdateEvent* updateEvent);
    virtual void YouGotHit(SHitInfo* hitInfo);
    virtual void CutSequenceSetWorldTransform(SMatrix43* mNewWorldTransform);
    virtual SMatrix* GetCollisionCheckedMatPos(SMatrix* result, SMatrix* MatPos);

    const TSharedPointer<ZKnowledge>* GetKnowledge();
    EActorState GetActorState();
    bool IsAlive();
    void StopShooting();
    bool IsShootingRequested();
    void SetShootTarget(ZPositionTarget* rTarget);
    void StartShooting(ZPositionTarget* rTarget, bool bIgnoreLOF, bool bBlindFire);
    void ClearShootTarget();
    TArrayRef<SHitInfo>* GetHitInfoList(TArrayRef<SHitInfo>* result);
    bool IsSpeaking();
    bool IsUnnoticableKillEnabled();
    bool IsPacified();
    bool IsFullyEnabled();
    ZShootTargetInfo* GetShootTargetInfo();
    void SetHasGreetedHM(bool bGreetedHM);
    bool GetHasGreetedHM();
    bool CanCallForHelp();
    bool IsFemale();
    void SetAloneAsHumanShieldVictim(bool bAlone);
    bool IsMuted();
    float4* GetBoneWorldPosition(float4* result, unsigned int iBoneId);
    bool IsBodyHidden();
    void BodyHidden(bool b);
    void SetIsDeadTarget(bool dt);
    void SetSBKillTagged(bool bTagged);
    ZString* GetActorName(ZString* result);
    SMatrix43* GetBoneWorldTransform(SMatrix43* result, unsigned int iBoneId);
    SMatrix43* GetBoneTransform(SMatrix43* result, unsigned int iBoneId);
    EActorDeathType GetDeathType();
    bool IsReleaseRagdollAfterBodyHiddenTriggered();
    bool IsDeadTarget();
    SActorSoundDefs::EDefinition GetActiveSpeak();
    bool IsAvailableOnDifficultyLevel(int iDifficultyLevel);
    void OnSpawned();
    EActorType GetActorType();
    EActorRank GetActorRank();
    EActorGroup GetActorGroup();
    void SetActorGroup(EActorGroup group);
    void SetAboutToDie();
    bool IsAboutToDie();
    void SetDeathType(EActorDeathType eDeathType);
    bool IsBeingDragged();
    void OnInventoryChanged(TArray<TEntityRef<IHM5Item> >* old);
    void StopSubtitles(ISoundPlayerChannel* pChannel);
    void OnWeaponFireProjectile(TEntityRef<ZHM5ItemWeapon>* rWeapon);
    unsigned int ForceUpdate();
    bool IsUpdateForced();
    void SetForceUpdate(bool bForced);
    void ReleaseRagdollAfterBodyHidden(ZGameTime* curGameTime);
    void SetInSequence(bool b);
    bool IsInSequence();
    void OnDisableDeathAnimation();
    void OnAboutToDie();
    void SetInteractionAllowed(EActorInteractionFlag eInteraction, bool bAllowed);
    bool GetInteractionAllowed(EActorInteractionFlag eInteraction);
    void SetActorMultiplier(float fTimeMultiplier);
    void OnEnableUnnoticableKill();
    void OnDisableUnnoticableKill();
    ZAnimatedActor* GetAnimatedActor();
    ZActorAnimationState* GetAnimationState();
    bool IsLeaningAtWindow();
    bool IsFacingDirection(float4* vDir, float fAngleToleranceDegrees);
    bool HasLocomotionControlledBySequence();
    bool IsInFullBodySequence();
    void OnUnrecoverableError(ZString* reason);
    void RemoveActorBroken();
    void DisableAmbientLookAt();
    void EnableAmbientLookAt();
    void RemoveGlow();
    int LookAroundAct_GetCount();
    void LookAroundAct_Shuffle();
    void BodyWaterSplashed(bool b);
    bool AttachItem(EAttachLocation eLocation, TEntityRef<IHM5Item>* rItem);
    EAttachLocation GetItemLocation(TEntityRef<IHM5Item>* rItem);
    TEntityRef<IHM5Item>* GetAttachedItem(TEntityRef<IHM5Item>* result, EAttachLocation eLocation);
    bool GetAttachLocation(TEntityRef<IHM5Item> pItem, EAttachLocation* loc);
    void UpdateHumanShieldMovement(ZString* sRequest);
    void SetDefaultHumansShieldState(unsigned int nStrafeID);
    void UpdateCarryCivilianMovement(ZString* sRequest);
    void SetDefaultCarryCivilianState(unsigned int nStrafeID);
    void OnCompiledBehaviorTreeChanged();
    bool IsBehaviorPromoted(TEntityRef<ZBehaviorEntityBase> rBehavior);
    float GetSpeakEndTime();
    float GetSequenceEndTime();
    bool IsEnemyInFrontArc(float fArcHalfangleInDeg);
    void OnHelpPointChanged();
    TEntityRef<IHM5Item>* GetInitialRightHandItem(TEntityRef<IHM5Item>* result);
    void FlagDeathAsUnnoticed();
    EActorPerceptionSensitivity GetPerceptionSensitivity(EGameTension eTension);
    void UpdateReleaseRagdollAfterBodyHidden(ZGameTime* curGameTime);
    void SetHitPointsDirect(float fHitpoints);
    bool IsFacingPosition(float4* vPos, float fAngleToleranceDegrees);
    ZKnowledge* Knowledge();
    const ZKnowledge* KnowledgeConst(); //original name is Knowledge
    void OnTestUnrecoverableError();
    void SetAmbientLookAtCharacter(TEntityRef<ZHM5BaseCharacter>* rCharacter);
    void GeomTransformChangeCallback(ZEntityRef* entity, SMatrix43* mNewValue);
    ZRuntimeResourceID* GetHMAsResourceID(ZRuntimeResourceID* result);
    bool IsNude();
    void ChangeToNude();
    void HideAttachedNonWeapons();
    void ShowAttachedNonWeapons();
    void StartSubtitles(ISoundPlayerChannel* pChannel);
    float CalcGetBoneDamageMultiplier(unsigned int nHitBoneIndex);
    float GetInitHitPoints();
    unsigned __int16 UpdateRoomID();
    ZString* LookAroundAct_Select(ZString* result, int nIndex);
    ZString* LookAroundAct_SelectRandom(ZString* result);
    void TryInitAnimatedActor();
    void TryUninitAnimatedActor();
    void SignalKillSoundManager(bool bCheckForSilencedKill);
    bool IsBoss();
    TEntityRef<IHM5ItemWeapon>* GetCurrentWeapon(TEntityRef<IHM5ItemWeapon>* result);
    void SwitchWeaponHand(bool bSwitchToLeftHand);
    TEntityRef<IHM5ItemWeapon>* GetPistolInInventory(TEntityRef<IHM5ItemWeapon>* result);
    TEntityRef<IHM5ItemWeapon>* GetRifleInInventory(TEntityRef<IHM5ItemWeapon>* result);
    void UnholsterWeapon(TEntityRef<IHM5ItemWeapon>* rWeapon);
    bool HasHandGun();
    void RemoveBehavior(TEntityRef<ZBehaviorEntityBase> rBehavior);
    void PromoteBehavior(TEntityRef<ZBehaviorEntityBase> rBehavior);
    void OnDefaultEmitterSpeakFailed(ISoundPlayerChannel* pChannel, IWaveBankData* pWaveBankData, int nSubSoundIndex, void* pUserData);
    void StartLipSync(ISoundPlayerChannel* pChannel, TRefCountPtr<ZSoundPlayerCallbackExtraData> pExtraData);
    void StopLipSync(ISoundPlayerChannel* pChannel);
    bool IsWeaponFiring();
    void EndShootEnemy();
    bool HasFullClip();
    bool NeedReload();
    void Reload();
    ZString* GetWeaponName(ZString* result);
    void UpdateHasWeapon();
    static bool TestAllTargetsKilled(bool* bHaveTargets);
    EActorPerceptionSensitivity GetPerceptionSensitivity();
    void ExpireSharedEvent(EAISharedEventType eventType);
    void AttachWeaponToHolster(TEntityRef<IHM5ItemWeapon> pWeapon, ZString* sBoneName);
    void UpdateFaceFX();
    void OnAnimationRigChanged(ZAnimationRig* pRig, SMatrix* pMatrix);
    void StopBeingDragged();
    TEntityRef<IHM5Item>* DetachItem(TEntityRef<IHM5Item>* result, EAttachLocation eLocation, bool bAddToPhysicsWorld, bool bRemoveFromInventory);
    void DropAttachedItems(bool bDropWeapon);
    void DropKeycardNoPhysics();
    void DropAllItems();
    bool UnholsterWeapon();
    TEntityRef<IHM5ItemWeapon>* GetDisarmWeapon(TEntityRef<IHM5ItemWeapon>* result);
    void ReleaseCarryCivilian();
    void StopSpeak();
    void OnSpeakFailed(ISoundPlayerChannel* pChannel, IWaveBankData* pWaveBankData, int nSubSoundIndex, void* pUserData);
    void OnSpeakBeginPlay(ISoundPlayerChannel* pChannel, IWaveBankData* pWaveBankData, int nSubSoundIndex, void* pUserData, TRefCountPtr<ZSoundPlayerCallbackExtraData> pExtraData);
    void OnSpeakEndPlay(ISoundPlayerChannel* pChannel, IWaveBankData* pWaveBankData, int nSubSoundIndex, void* pUserData);
    void OnDefaultEmitterSpeakBeginPlay(ISoundPlayerChannel* pChannel, IWaveBankData* pWaveBankData, int nSubSoundIndex, void* pUserData, TRefCountPtr<ZSoundPlayerCallbackExtraData> pExtraData);
    void OnDefaultEmitterSpeakEndPlay(ISoundPlayerChannel* pChannel, IWaveBankData* pWaveBankData, int nSubSoundIndex, void* pUserData);
    bool CheckLOF(float4* vShotOrigin, float4* vShotHitPosition, float4* vCollision);
    bool CalculateShot(ZEntityRef* target, float4* vShotOrigin, float4* vShotHitPosition);
    void ShootEnemy();
    void UpdateShooting(SGameUpdateEvent* updateEvent);
    void ReleaseKnowledge();
    void ImmediateDeinitialize();
    void ImmediateDisable();
    void FlagDeathAsMurder();
    void SetAssert(ZString* sBreakpointName, bool bEnable);
    bool IsSharedEventCurrent(EAISharedEventType eventType);
    void RenewSharedEvent(EAISharedEventType eventType, float fDuration);
    void OnForceUnholster();
    void AttachWeaponsToHolsters();
    TEntityRef<ZPointOfInterestEntity>* GetRandomStaticPointOfInterest(TEntityRef<ZPointOfInterestEntity>* result);
    bool GetAmbientLookAt(float4* wsLookAt, bool* bEyesOnly);
    void RegisterTransformChangeCallback();
    void UnregisterTransformChangeCallback();
    ZActor(ZComponentCreateInfo* info);
    bool IsHitTarget();
    void StartBeingDragged();
    void StartPull(bool bWindow);
    void StartPush();
    void HolsterWeapon();
    EActorCCPreset GetCCPreset();
    bool EnterCarryCivilian(bool bDirectToStandIdle);
    TSharedPointer<ZControlledAnimLocomotion>* CreateControlledProgram(TSharedPointer<ZControlledAnimLocomotion>* result, ZString* sAnimSMName, ZString* sAnimName);
    TSharedPointer<ZControlledAnimLocomotion>* StartControlledAnim(TSharedPointer<ZControlledAnimLocomotion>* result, ZString* sAnimSMName, ZString* sAnimName, bool bSetAnimProgram, bool bBlendToControlledState);
    void SetMuted(bool bMuted);
    bool Speak(ZResourcePtr pWavebank);
    void SelectBehavior(SGameUpdateEvent* updateEvent);
    void InitializeKnowledge();
    void OnEnable();
    void OnDisable();
    void ImmediateInitialize();
    void FlagDeathAsAccident();
    void FlagDeathAsPacify(bool bByAccident);
    void OnAccidentStart();
    void OnForceHolster();
    void KillActor(EActorDeathType eDeathType, bool bDeathVisible);
    void DeadlyThrowKill(TEntityRef<IHM5Item> rItem, bool bIsThrowFromBehind);
    void OnFallImpact(TEntityRef<ZActor> pActor);
    void ReleaseHumanShield();
    bool ImmediateEnable();
    void OnKillActor();
    void OnKillUnnoticed();
    void OnKillByPacify();
    void OnKillByAccident();
    void OnKillByUnnoticedAccident();
    void OnPacifyByAccident();
    void OnAccidentEnd();
    static void RegisterType();
    void HandleHealth();
    void CloseCombatEvent(ECCActorEvent eEvent, ECCActorEventDir eDir, TEntityRef<ZHM5ItemCCWeapon>* rWeapon);
    bool GetSBKillTagged();
    bool IsSpeakPlaying();
    const TResourcePtr<ZCompiledBehaviorTree>* GetBehaviorTree();
    bool IsRadioActAllowed();
    void SetSeenDying(bool b);
    bool IsPreferredAccidentInvestigator();
    bool IsAccidentShy();
    ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull>* GetSpeakInterruptedEvent();
    ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull>* GetSpeakEndEvent();
    TArray<TEntityRef<ZBehaviorEntityBase>>* GetBehaviors();
    void ForceEnable();
    void ForceDisable();
    void SetRegisteredDeathType(EActorDeathType eDeathType);
    bool GetContractsEligible();
    TArray<ZString>* GetStatLabels();
    bool HasBeenPacified();
    EActorDeathType GetRegisteredDeathType();
    void SetContractsEligible(bool bEligible);
    const STokenID* GetTokenID();
    bool IsDisabledByForwardSpawn();
};
