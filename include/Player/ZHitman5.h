#pragma once

#include "ZHM5BaseCharacter.h"
#include "IFutureCameraState.h"
#include "ICharacterCollision.h"
#include "IHM5ActionEntityListener.h"
#include "ZHM5MorphemeNodeIds.h"
#include "IHM5ItemWeapon.h"
#include "IVariationResourceEntity.h"
#include "ZFabricColliderBaseEntity.h"
#include "ZDynamicResourceLibrary.h"
#include "SHitmanGameplayState.h"
#include "ZHitman5PermissionHandler.h"
#include "ZHM5BaseMovement.h"
#include "ZHM5BaseController.h"
#include "ZHitmanMorphemePostProcessor.h"
#include "ZHM5InputControlScheme.h"
#include "ZHM5ActorControl.h"
#include "ZHM5AimAssist.h"
#include "SOutfitData.h"
#include "SLoadingOutfit.h"
#include "IHM5ClothBundlePool.h"
#include "ZHM5PostfilterController.h"
#include "sPelvisOffsetElement.h"
#include "ZHM5LooseTargetEncounter.h"
#include "sQueuedReset.h"
#include "ZTargetTracker.h"
#include "ZTargetTrackerGUI.h"
#include "SMetricState.h"
#include "ZHM5CoverPlane.h"
#include "ZHM5BodyContainer.h"
#include "sAimFlags.h"
#include "ZHM5BaseGuide.h"
#include "eMorphemeRequests.h"
#include "SCameraState.h"
#include "ZHM5MovementLocomotion.h"
#include "ZHM5WeaponRecoil.h"
#include "EHM5SoundFootwearType.h"
#include "ZHM5DisguiseSafeZoneEntity.h"
#include "ZHM5MovementDragBody.h"
#include "ZHM5MovementDead.h"
#include "ZOutfitKitEntity.h"
#include "ZHM5MovementKickVictim.h"
#include "ZHM5MovementOperateCPDoor.h"
#include "ZHM5MovementLedgeHang.h"
#include "ZHM5GuideVentilatorShaft.h"
#include "ZHM5MovementSurrender.h"
#include "ZHM5EquipController.h"
#include "SRecoilAnimInfo.h"
#include "ZHM5ItemWeapon.h"
#include "EHitmanGState.h"
#include "ZHM5AimController.h"
#include "ENetworkMoveStatus.h"
#include "ZHM5MovementPushVictim.h"
#include "ZHM5DisguiseSafeZoneMovement.h"
#include "ZHM5MovementHideInCloset.h"
#include "ZHM5MovementHumanShield.h"
#include "ECustomFlags.h"
#include "ZHM5MovementCarryCivilian.h"
#include "ZHM5MovementFiberWireKill.h"
#include "ZHM5MovementPullVictimThroughWindow.h"
#include "ZHM5MovementLadder.h"
#include "ZHM5MovementCover.h"
#include "ZMovementAnimTransition.h"
#include "ZHM5MovementToss.h"
#include "ZHM5Health.h"
#include "ZHM5BaseInventory.h"
#include "ZHM5MainCamera.h"
#include "ZHM5SneakController.h"
#include "ZHM5ActionClient.h"

class ZHM5InputControl;
class ZHM5WeaponControl;
class ZHM5ReloadController;
class ZHM5GuideController;
class ZHM5FocusController;
class IHM5ForceMovementCallBack;
class ZHM5SniperController;
class ZHM5MovementLedgeWalk;
class ZHM5MovementShootingBallet;
class ZHM5MovementCloseCombat;
class ZHM5TossController;
class ZHM5MovementVentilatorShaft;
class ZHM5CCTargetController;
class ZHM5MovementHideInCloset;

class alignas(16) ZHitman5 : public ZHM5BaseCharacter, public IFutureCameraState, public ICharacterCollision, public IHM5ActionEntityListener, public ZHM5MorphemeNodeIds
{
public:
    TArray<ZEntityRef> m_InitialInventoryItems;
    TEntityRef<IHM5ItemWeapon> m_FiberWire;
    bool m_bStoryModeFiberWire;
    ZRuntimeResourceID m_StreamableWeaponID;
    TEntityRef<IVariationResourceEntity> m_DefaultWeaponVariationResource;
    bool m_bStreamableWeaponGive;
    bool m_bStreamableWeaponDualWield;
    bool m_bStreamableDisguiseGive;
    ZRuntimeResourceID m_InitialOutfitID;
    TArray<TEntityRef<ZFabricColliderBaseEntity>> m_EnvironmentClothColliders;
    ZDynamicResourceLibrary* m_CurrentBonusWeapon;
    ZDynamicResourceLibrary* m_CurrentWeaponMaterial;
    TEntityRef<IHM5Item> m_rCurrentlyLoadingItem;
    TEntityRef<IHM5Item> m_rItemsHolstered[2];
    ICharacterController* m_pCharacterController;
    bool m_bPlayerCollisionEnabled;
    bool m_bPlayerNPCCollisionEnabled;
    bool m_bGravityEnabled;
    bool m_bFalling;
    float m_fFallVelocity;
    SHitmanGameplayState m_GameplayState;
    ZHitman5PermissionHandler m_PermissionHandler;
    ZHM5BaseMovement* m_pCurrentMovement;
    ZHM5BaseMovement* m_pCurrentMovement_PrevState;
    ZHM5BaseMovement* m_pMovements[32];
    ZHM5BaseController* m_pBaseControllers[5];
    ZGameTime m_tBlendInCommandStarted;
    ZGameTime m_tBlendInCommandStopped;
    ZGameTime m_tLastHardToSee;
    bool m_bBlendInEnding;
    ZHitmanMorphemePostProcessor* m_pMrPostProcessor;
    unsigned int m_nMrRequests[75];
    unsigned int m_nMrControlParams[76];
    ZHM5Health* m_pHealth;
    ZHM5InputControl* m_pInputControl;
    ZHM5InputControlScheme* m_pControlScheme;
    ZHM5WeaponControl* m_pWeaponControl;
    ZHM5ActorControl* m_pActorControl;
    ZHM5ReloadController* m_pReloadController;
    ZHM5BaseInventory* m_pBaseInventory;
    ZHM5ActionClient* m_pActionClient;
    ZHM5AimAssist* m_pAimAssist;
    ZHM5GuideController* m_pGuideController;
    ZHM5SneakController* m_pSneakController;
    ZHM5FocusController* m_pFocusController;
    EBaseMovementType m_eForceMovementType;
    IHM5ForceMovementCallBack* m_pForceMovementCallBack;
    ZMapPoly m_Mapper;
    float m_fUpperBodyOverrideWeight;
    unsigned int m_nLastSentRequest[5];
    bool m_bMorphemeIdsInitialized;
    SOutfitData m_CurrentOutfitData;
    ZRuntimeResourceID m_UnloadedOutfitResourceID;
    ZDynamicResourceLibrary* m_pCurrentOutfitLibrary;
    bool m_bOwnCurrentOutfitLibrary;
    SLoadingOutfit m_EquipOutfitAsyncParams;
    SLoadingOutfit m_UnloadedOutfitParams;
    TEntityRef<IHM5ClothBundlePool> m_ClothBundlePool;
    ZHM5PostfilterController* m_pHM5PostfilterController;
    sAimFlags m_AimFlags;
    ZHM5BaseGuide* m_pGuidesHMStandsOn[10];
    float m_fTechnRunSpeedFactor;
    bool m_bFirstColiDetected;
    float m_fTimeMultiplier;
    bool m_bFastTargetSelectionQueued;
    ZHM5CoverPlane* m_pNearestRail;
    TEntityRef<ZHM5BodyContainer> m_pNearestContainer;
    SMatrix m_mvCurrentPelvisOffset;
    TList<sPelvisOffsetElement> m_PelvisOffsets;
    bool m_bInterpolateTargetPelvisOffset;
    TEntityRef<ZHM5LooseTargetEncounter> m_rLooseTargetEncounter;
    ZEntityRef m_pRenderDestination;
    int m_nMaxGunAmmo;
    int m_nMaxRevolverAmmo;
    int m_nMaxSMGAmmo;
    int m_nMaxRifleAmmo;
    int m_nMaxSniperAmmo;
    int m_nMaxMGAmmo;
    int m_nMaxRPGAmmo;
    int m_nMaxShotgunAmmo;
    ZEntityRef m_rFailSafeDisarmWeapon;
    sQueuedReset m_Reset;
    float m_fRestartTime;
    float m_fBlendInStartFocus;
    unsigned __int64 m_nMovementFlags;
    unsigned int m_nLocomotionFlag;
    unsigned __int64 m_nCustomFlags;
    bool m_bDecriminalizedShooting;
    bool m_bDecriminalizedWeapons;
    bool m_bDecriminalizedAiming;
    bool m_bDecriminalizedCloseCombat;
    bool m_bDecriminalizedCrossdressing;
    bool m_bMinigame;
    ZGameTime m_tIllegalPushButtonTimer;
    SGameUpdateEvent m_currentUpdateEvent;
    __int16 m_iQuadFocusID;
    __int16 m_iQuadBackgrounID;
    __int16 m_iQuadBurnID;
    __int16 m_iQuadFocusSBID;
    __int16 m_iTextID;
    ISequenceEntity* m_pPendingSequence;
    ZString m_sPendingSlotName;
    float m_fMoveLength;
    float m_fVelocity;
    float m_fPulse;
    ZHM5SniperController* m_pSniperController;
    __int8 m_bActivated : 1;
    __int8 m_bActivatingHitman : 1;
    __int8 m_bInEditMode : 1;
    TEntityRef<ZHM5MainCamera> m_rMainCamera;
    ZTargetTracker* m_pTargetTracker;
    ZTargetTrackerGUI* m_pTargetTrackerGUI;
    unsigned int m_paramCutSequenceFullBody;
    bool m_bLevelEnded;
    ZGameTime m_LastMetricsUpdateTime;
    SMetricState m_MetricState;
    float m_fCameraDeltaTime;
    bool m_bActiveCheckPoint;

    virtual ~ZHitman5();
    virtual ZVariantRef* GetVariantRef(ZVariantRef* result);
    virtual int AddRef();
    virtual int Release();
    virtual void* QueryInterface(STypeID* iid);
    virtual void Activate(ZString* sSubset);
    virtual void Deactivate(ZString* sSubset);
    virtual void OnEnterEditMode();
    virtual void OnExitEditMode();
    virtual void Init();
    virtual bool PickupItem(TEntityRef<IHM5Item>* rItem);
    virtual bool SwapItem(TEntityRef<IHM5Item>* rNewItem, TEntityRef<IHM5Item>* rDisposedItem);
    virtual void RemoveItemFromInventory(TEntityRef<IHM5Item>* rItem);
    virtual void AttachItemToRHand(TEntityRef<IHM5Item>* rItem);
    virtual void AttachItemToLHand(TEntityRef<IHM5Item>* rItem);
    virtual TEntityRef<IHM5Item>* DetachItemFromRHand(TEntityRef<IHM5Item>* result, bool bAddToPhysicWorld);
    virtual TEntityRef<IHM5Item>* DetachItemFromLHand(TEntityRef<IHM5Item>* result, bool bAddToPhysicWorld);
    virtual void ItemDestoyed(TEntityRef<IHM5Item> pItem);
    virtual bool IsDead();
    virtual void GetCharacterOBB(SMatrix* m0, float4* vSize);
    virtual void ReinitializeMorphemeData();
    virtual void GetOBB(SMatrix* mvCen, float4* vHalfSize);
    virtual float4* GetOBBRadius(float4* result);
    virtual bool CreateBodyCollision();
    virtual void UpdateBodyCollisionPoses(bool bMoveTransform);
    virtual bool ShouldDoHardCrowdPushes();
    virtual void SetSequenceWeight(float weight, unsigned int track);
    virtual void BlendOutSequenceWeights();
    virtual void HandleMorphemeEntityIDChanged();
    virtual bool EnsureBaseCharacterInit();
    virtual bool WillRequestBeReceived(eMorphemeRequests nRequest);
    virtual void FrameUpdate(SGameUpdateEvent* updateEvent);
    virtual void FrameUpdate2(SGameUpdateEvent* updateEvent);
    virtual void PlayImpactAnim(float4* vDir);
    virtual bool HolsterCurrentWeapons();
    virtual float CalcGetBoneDamageMultiplier(unsigned int nHitBoneIndex);
    virtual void YouGotHit(SHitInfo* HitInfo);
    virtual bool CanProjectileHitCharacter(SHitInfo* HitInfo);
    virtual unsigned __int16 GetCollisionLayer();
    virtual void CutSequenceStarted(ISequenceEntity* pSequence, ZString* sSlotName, float fBodyPartSelector);
    virtual void CutSequenceUpdate(ISequenceEntity* pSequence, ZString sSlotName, float fWeight);
    virtual void CutSequenceEnded(ISequenceEntity* pSequence, ZString sSlotName);
    virtual void AbortCutSequence();
    virtual bool SetCutSequenceData(ISequenceEntity* pSequence, SCutSequenceData* cutSequenceData, ZString* sSlotName, float fBodyPartSelector);
    virtual ICharacterController* GetCharacterController();
    virtual SCameraState* GetFutureCameraState(SCameraState* result);
    virtual SCameraState* GetCurrentCameraState(SCameraState* result);
    virtual void DisableCameraControl();
    virtual void EnableCameraControl();
    virtual SMatrix* GetCollisionCheckedMatPos(SMatrix* result, SMatrix* MatPos);
    virtual bool IsActionValid(ZHM5Action* pAction, TEntityRef<ZHM5BaseCharacter>* pOperator);

    ZEntityRef* GetCurrentOutfitEntity(ZEntityRef* result);
    ZHM5MovementLocomotion* GetMovementLocomotion();
    void DeactivateCheckPoint(bool bSetCurrentMovement);
    ZRuntimeResourceID* GetEquipOutfitAsyncResourceID(ZRuntimeResourceID* result);
    float4* GetSkinWidthVectorZ(float4* result);
    ZHM5MovementLedgeWalk* GetMovementLedgeWalk();
    ZHM5WeaponRecoil* GetRecoilController();
    bool IsUsingKeyCardReader();
    ZHM5BaseInventory* GetBaseInventory();
    ZGameTime* CurrentGameTimeDelta(ZGameTime* result);
    bool IsEquipOutfitAsyncReady();
    bool DrawHitmanInFPSMode();
    void DestroyBaseMovements();
    void EnableAnchorCollision(bool bEnable);
    ZHM5ActionClient* GetActionClient();
    bool IsEnteringCloset();
    void DestroyCharacterController();
    SMatrix* CalcTorsoColiMatPos(SMatrix* result);
    void CutSequenceEnded();
    bool IsReloadingOutfitReady();
    bool IsInDisguise();
    void GetCapsulePropertiesInternal(float* fRadius, float* fHeight, float* fSkinWidth);
    bool IsTakingSecurityTape();
    bool IsFireArmEquipped();
    void QueueReset(SMatrix* mvNewPos);
    void EquipOutfitResourceAsync_ManualFinish(ZRuntimeResourceID ridNewOutfitLibrary);
    void HitmanFailedAnimationPackBugAnimators();
    ZHM5ActorControl* GetActorControl();
    bool IsPushVictimPossible();
    void EnablePlayerCollision(bool bEnable);
    EHM5SoundFootwearType GetOutfitFootwearType();
    bool IsGuidesListEmpty();
    bool IsMovementEnabled(EBaseMovementType eMovement);
    bool OverlapWithGuideAnchor(ZHM5BaseGuide* pGuide);
    bool IsInSBExecutionMode();
    bool IsInSafeZoneMovement();
    bool IsDisablingFuseBox();
    void SetIllegalPushButtonTimer(float fDuration);
    void UpdateMetrics();
    void ResetPelvisOffset(void* pClassPtr);
    void DestroyControllers();
    bool GetUseCrowdCameraProfile();
    ZGameTime* GetSBEndGameTime(ZGameTime* result);
    bool ActivateEnterSafeZone(TEntityRef<ZHM5DisguiseSafeZoneEntity> rSafeZone);
    ZHM5SneakController* GetSneakController();
    void GetAimWeaponCollisionExtends(float4* vShoulder, float4* vMuzzle, bool bRightSideAim);
    void UpdateBaseMovements();
    void DebugDisplayBones();
    bool SendRequestToActiveStateMachines(eMorphemeRequests nRequest);
    int GetMaxAmmoForAmmoType(eAmmoType ammoType);
    ZHM5MovementDragBody* GetMovementDragBody();
    void ReleaseCurrentOutfitInternal();
    void DebugDisplayMorphemeStatus();
    SGameInput* GetGameInput();
    bool IsInDisguiseSafeZone();
    bool IsChangingClothes();
    void SetDecriminalizedShooting(bool b);
    SMatrix* GetClosetMatrix(SMatrix* result);
    void SetWalkOnLedgeMovementGuide(ZHM5BaseGuide* pGuide);
    ZHM5MovementDead* GetMovementDead();
    bool CheckWeaponCollisionOTS(SMatrix* mvFrom, SMatrix* mvTo);
    ZHM5BaseMovement* GetCurrentMovement();
    bool GuideActionPerformSecondary();
    bool GetDecriminalizedWeapons();
    bool IsWalkingSlowly();
    ZHM5GuideController* GetGuideController();
    TEntityRef<ZOutfitKitEntity>* GetOutfitKit(TEntityRef<ZOutfitKitEntity>* result);
    void MoveToMatPos(SMatrix* mvMatPos, bool bResetLockPos, bool bTriggerChangerHandlers);
    void UpdateMovementRelatedCache();
    bool GetDecriminalizedShooting();
    bool ShouldCheckWeaponCollision();
    ZHM5MovementShootingBallet* GetMovementShootingBallet();
    void UpdateWeaponStreaming();
    void ExitOTSMode();
    bool IsRifleEquipped();
    bool IsItemsEnabled();
    void ActivateFrameUpdate();
    void CacheCCAnims(TEntityRef<ZActor>* rActor);
    TEntityRef<IHM5Outfit>* GetOutfitFromClothBundle(TEntityRef<IHM5Outfit>* result, ZEntityRef* rOwner);
    float4* MinimizeWeaponCorrection(float4* result, SSphereSweepInput* coliin, SSphereSweepOutput* coliout, float4* vOffset);
    ZHM5MovementKickVictim* GetMovementKickVictim();
    ZDynamicResourceLibrary* EquipOutfitFromClothBundle(ZEntityRef* rOwner, ZDynamicResourceLibrary* pNewOutfitLibrary);
    bool IsPullVictimPossible();
    ZHM5MainCamera* GetMainCamera();
    bool IsKnifeKilling();
    void GeomTransformChangeCallback(ZEntityRef* entity, SMatrix43* mNewValue);
    bool IsPerformingIllegalPushButton();
    ZHM5AimAssist* GetAimAssist();
    bool IsStrafing();
    float4* CheckPlayerCollision(float4* result, float4* vTo, bool bCollisionEnabled);
    void GetHitmanAABB(float4* vMin, float4* vMax);
    bool IsTakingKeycard();
    bool IsDoingCoverToCoverMove();
    float GetMorphemeBlindFireWeight();
    void ResetGuidesList();
    bool CheckWeaponCollision(SMatrix* mvFrom, SMatrix* mvTo);
    void SetBurningFocusFlag(bool b);
    bool GetDecriminalizedAiming();
    ZHM5MovementCloseCombat* GetMovementCloseCombat();
    ZHM5TossController* GetTossController();
    bool CanOperateObject(ZHM5Action* pAction, bool* bShouldDisplayFarFeedback);
    unsigned int* GetControlParams();
    ZTargetTracker* GetTargetTracker();
    void QueueFastTargetSelection();
    float4* GetCurrentFacing(float4* result);
    TEntityRef<ZHM5LooseTargetEncounter>* GetLooseTargetEncounter(TEntityRef<ZHM5LooseTargetEncounter>* result);
    void UpdateGameStateFromFocus();
    bool IsSurendering();
    bool HasFocus();
    ZEntityRef* GetRenderDestination(ZEntityRef* result);
    const TEntityRef<ZActor>* GetDragVictim(TEntityRef<ZActor>* result);
    SMatrix* GetTargetPelvisOffset(SMatrix* result);
    void Die(SHitInfo* HitInfo);
    bool IsEquipFiberWireReady();
    void SetIsInCloseCombat(bool bVal);
    bool IsInContextActionInteraction();
    void StopKillingMovements();
    void SetDrawAsPlayerRecursive(ZEntityRef rEntity, bool bState);
    bool IsMovingOnLedge();
    void StopDragBody();
    bool IsFiberWireEquipped();
    bool ReadyForArrest();
    void UpdatePelvisOffset();
    bool GetFreeCamPos(SMatrix43* mvPos);
    void SetIsInInstinctMode(bool bVal);
    SMatrix* CalcRightCalfColiMatPos(SMatrix* result);
    void Jump(SMatrix* mTo, bool bResetLockPos);
    ZEntityRef* GetInitialOutfitEntity(ZEntityRef* result);
    bool IsWalkingFast();
    ZHM5MovementOperateCPDoor* GetMovementOperateCPDoor();
    unsigned int* GetLastSentRequest();
    bool DropItem(TEntityRef<IHM5Item>* rItem);
    bool IsThrowingSomething();
    void UpdateNearestRail();
    bool IsInVentilatorShaft();
    bool IsCurrentOutfitReady();
    void RegisterClothBundlePool(TEntityRef<IHM5ClothBundlePool>* rPool);
    void PlayTargetEncounterCut();
    void GetHitmanAABB(SMatrix* m0, float4* s0);
    void InitInitialInventory();
    ZRuntimeResourceID* GetOutfitResourceFromClothBundle(ZRuntimeResourceID* result, ZEntityRef* rOwner);
    void SetOTSModeActive(bool bOTS);
    ZHM5MovementLedgeHang* GetMovementLedgeHang();
    bool IsGravityEnabled();
    void SetupAimAssists(float fBlendInTime, float fAimTime);
    void SetDecriminalizedAiming(bool b);
    EBaseMovementType GetCurrentMovementType();
    bool PickupItemDirect(TEntityRef<IHM5Item>* rItem);
    bool IsFiberWireKillPossible();
    void CreateBaseMovements();
    bool IsVentilatorShaftPeekPossible();
    bool Arrest(TEntityRef<ZActor>* rActor);
    IHM5ClothBundlePool* GetClothBundlePool();
    void InitMorphemeIDs();
    unsigned int* GetRequests();
    void DebugContactMaterial();
    void EquipOutfitResource(ZRuntimeResourceID ridNewOutfitLibrary, TEntityRef<IHM5Outfit> Outfit, bool bPlaceClothBundle, bool bForce);
    bool IsKillingByPush();
    bool IsStanding();
    float4* GetArrestPos(float4* result);
    void SetNearestContainer(ZHM5Action* pAction);
    bool IsEnteringVent();
    void PlayerCollision(SMatrix* mvFrom, SMatrix* mvTo, float fDeltaTime);
    bool IsGuideInGuidesList(ZHM5BaseGuide* pGuide);
    const ZEntityRef* GetMorphemeVariationResource();
    void ActivateEnterVentilatorShaft(TEntityRef<ZHM5GuideVentilatorShaft> rVentilatorShaft);
    bool IsNonFireArmEquipped();
    void ReloadCurrentOutfit();
    void GetPulse(float* fPulse, float* fWalkPulse);
    bool IsPlayerNPCCollisionEnabled();
    SMatrix* CalcLeftCalfColiMatPos(SMatrix* result);
    ZHM5CoverPlane* GetNearestRail();
    bool IsPerformingTakedown();
    bool RightSideAim();
    void DeactivateFrameUpdate();
    void SetMovementAndLocomotionFlagsDefault(unsigned __int64 nMovementFlags, unsigned int nLocomotionFlags, unsigned __int64 nCustomFlags);
    ZTargetTrackerGUI* GetTargetTrackerGUI();
    void ReleaseWeaponMaterial(TEntityRef<IHM5Item>* rItem);
    ZHM5ReloadController* GetReloadController();
    ZHM5MovementSurrender* GetMovementSurrender();
    ZHitman5PermissionHandler* GetPermissionHandler();
    void SetDecriminalizedCrossdressing(bool b);
    bool IsKnifingFromBehind();
    bool IsKillingByKick();
    ZHM5WeaponControl* GetWeaponControl();
    bool ActivateExitSafeZone();
    void LoadWeaponMaterial(TEntityRef<IHM5Item>* rItem);
    ZHM5EquipController* GetEquipController();
    float CurrentGameTimeMultiplier();
    SRecoilAnimInfo GetRecoilAnimInfo(TEntityRef<ZHM5ItemWeapon>* rWeapon, bool bDual);
    bool QueryHM5Flag(EHitmanGState queryFlag);
    ZHM5BaseMovement* GetMovementOfType(EBaseMovementType eType);
    bool IsOperatingCheckPointDoor();
    ZHM5AimController* GetAimController();
    void SetHitmanTimeMultiplier(float fTimeMultiplier, bool bFromManager);
    void UpdatePulse(float fDeltaTime);
    bool IsDisablingFusebox();
    bool IsLocomotionEnabled(ENetworkMoveStatus eNetworkMoveStatus);
    void SetCurrentMovement(ZHM5BaseMovement* pCurrentMovement);
    bool GetDecriminalizedCloseCombat();
    void SetInsideCloset(bool bValue);
    void ActivateCheckPoint();
    ZHM5MovementPushVictim* GetMovementPushVictim();
    void UpdateMovementPostCam(SMatrix* mvFrom, SMatrix* mvTo);
    ZHitman5* operator=(ZHitman5* __that);
    bool IsMountingLedge();
    void ForceQueuedMovement(EBaseMovementType eMovementType, IHM5ForceMovementCallBack* pForceMovementCallBack);
    ZHM5Health* GetHealth();
    bool IsThrowingExplosives();
    ZHM5CCTargetController* GetCloseCombatTargetController();
    void SignalAgilitySoundManager(ZHM5BaseMovement* pPrevMovement, ZHM5BaseMovement* pNextMovement);
    ZHM5DisguiseSafeZoneMovement* GetMovementDisguiseSafeZone();
    void SetPelvisOffset(SMatrix* mvOffset, void* pClassPtr);
    bool IsKickVictimPossible();
    bool GetDecriminalizedCrossdressing();
    void PrepareForCutSequence();
    void UpdateSniperMode();
    const SHitmanGameplayState* GetHitmanGameplayState();
    bool GuideActionPerform();
    bool IsInSequence();
    TEntityRef<ZHM5BodyContainer>* GetNearestContainer(TEntityRef<ZHM5BodyContainer>* result);
    void UpdateBlendIn(SGameUpdateEvent* updateEvent);
    ZHitman5(ZHitman5* __that);
    ZHM5MovementToss* GetMovementToss();
    float GetSneakWeight();
    ENetworkState GetLocomotionStartState();
    void OnSceneStopping();
    bool IsFiberWiring();
    bool IsShootingInCover();
    void SetItemHandling(bool bVal, unsigned int iActionClientFilter);
    bool EnterOTSMode();
    ZHM5SniperController* GetSniperController();
    int GetFramesPassed();
    bool IsExitingCloset();
    void EquipOutfitResourceAsync(bool bEquipWhenReady, ZRuntimeResourceID ridNewOutfitLibrary, TEntityRef<IHM5Outfit> Outfit, bool bPlaceClothBundle, bool bForce);
    void DeSelectOTSMode();
    void AddFocus(float fDelta);
    void DebugDisplayStatus();
    void EnableGravity(bool bEnable);
    void CreateCharacterController();
    bool IsInCarryCivilianMovement();
    void OnWeaponFireProjectile(TEntityRef<ZHM5ItemWeapon>* rWeapon);
    ZHM5InputControlScheme* GetControlScheme();
    bool HasQueuedForceMovementCallBack(IHM5ForceMovementCallBack* pForceMovementCallBack);
    SMatrix* CalcHeadColiMatPos(SMatrix* result);
    bool CanPickOrSwap(TEntityRef<IHM5Item>* rItem);
    bool IsEnteringWindow();
    void QueueForcedMovement(EBaseMovementType eMovementType, IHM5ForceMovementCallBack* pForceMovementCallBack);
    ZHM5MovementHideInCloset* GetMovementHideInCloset();
    void SetLoadScreenActive(bool bActive);
    void UpdateHandleReset();
    void RelocatePlayerCollision(float4* vPos);
    bool ActorIgnoreDamage(TEntityRef<ZActor> rActor);
    bool IsVentilatorShaftExitPossible();
    void SetMorphemeVariationResource(ZEntityRef pVariationResource);
    void UpdateCameraProfile(SHM5GameCamParams* CurrentProfile);
    bool CanStartCloseCombat();
    float CurrentGameTimeDeltaNormalized();
    static void RegisterType();
    TEntityRef<IHM5ItemWeapon>* GetFailSafeDisarmWeapon(TEntityRef<IHM5ItemWeapon>* result);
    ZHM5MovementHumanShield* GetMovementHumanShield();
    void ResetImmediate(SMatrix* mvNewPos);
    void SetMovementAndLocomotionFlags(unsigned __int64 nMovementFlags, unsigned int nLocomotionFlags, unsigned __int64 nCustomFlags);
    bool IsWalking();
    bool IsInInteractiveCutsequence();
    void UpdateMovementContext(ZHM5BaseMovement* pNextMovement);
    bool GetIsInInstinctMode();
    bool IsBlindFiring();
    void UpdateCameraEvent(SCameraUpdateEvent* CameraUpdateEvent);
    ZHM5CoverPlane* GetCurrentCoverPlane();
    float GetMoveLength();
    void SetInMinigame(bool bMiniGame);
    float GetVelocity();
    bool IsCustomFlagEnabled(ECustomFlags eCustomFlags);
    void UpdateInstinctMode();
    void LevelEnded();
    ZResourcePtr* GetOutfitMovie(ZResourcePtr* result);
    void InitSequenceRelatedFields();
    ZHM5MovementVentilatorShaft* GetMovementVentilatorShaft();
    bool IsDualEquipped();
    void CheckFirstColi();
    bool IsExitingVent();
    void UpdateOTSMode();
    ZHM5MovementCarryCivilian* GetMovementCarryCivilian();
    void HandleCustomFlagSequence(unsigned __int64 nCustomFlags);
    void DeactivateCheckPointBeforeSpawnDelete();
    ZGameTime* CurrentRealTimeDelta(ZGameTime* result);
    const SOutfitData* GetOutfitData();
    void UpdateGuidesList();
    bool CanSkipSequence();
    bool IsClosetPeekPossible();
    bool SelectOTSMode();
    bool IsPlayerCollisionEnabled();
    ZHitmanMorphemePostProcessor* GetPostProcessor();
    ZHM5PostfilterController* GetHitmanPostfilterController();
    SMatrix* GetCurrentPelvisOffset(SMatrix* result);
    void SetInterpolatePelvisOffset(bool bInterpolate);
    const ZHitman5PermissionHandler* GetPermissionHandlerConst(); //original name is GetPermissionHandler
    void SetDecriminalizedWeapons(bool b);
    void SetDecriminalizedCloseCombat(bool b);
    const SGameUpdateEvent* CurrentUpdateEvent();
    ZHM5InputControl* GetInputControl();
    ZHM5FocusController* GetFocusController();
    void SetCurrentControlScheme(ZHM5InputControlScheme* pNewControlScheme);
    void EnablePlayerNPCCollision(bool bEnable);
    ZRuntimeResourceID* GetCurrentOutfitResourceID(ZRuntimeResourceID* result);
    void SetHangOnLedgeMovementGuide(ZHM5BaseGuide* pGuide);
    int GetControllerId();
    bool IsInMinigame();
    ZHM5MovementFiberWireKill* GetMovementFiberWireKill();
    ZHM5MovementPullVictimThroughWindow* GetMovementPullVictimFromWindow();
    void ClearQueuedForceMovement();
    ZHM5MovementLadder* GetMovementLadder();
    ZHM5MovementCover* GetMovementCover();
    void SetHitmanPostfilterController(ZHM5PostfilterController* pHM5PostfilterController);
    void SetAvoidParams(float fLeftRight, float fBlend);
    bool CanBeArrested();
    bool IsRunning();
    void SetSneaking(bool bSet);
    void SetHoldsUtilityMode(bool bSet);
    bool IsDoingDeadlyThrow();
    bool IsKillingByPull();
    bool IsDumpingBody();
    bool IsInSBTagMode();
    void SetLooseTargetEncounterCutRef(TEntityRef<ZHM5LooseTargetEncounter> rLooseTargetEncounter);
    bool PrepareTargetEncounterCut();
    bool CanPlayLooseTargetEncounterCut();
    bool IsAiming();
    void UpdateAlternateFire();
    bool SwapItemDirect(TEntityRef<IHM5Item>* rNewItem, TEntityRef<IHM5Item>* rDisposedItem);
    bool UnHolster(ZHM5WeaponSet* weaponSet);
    void UnloadCurrentOutfit();
    void ExitSniperMode();
    bool BlockedByCrowd();
    void ResetBlendInState();
    void CreateControllers();
    ZHitman5(ZComponentCreateInfo* pInfo);
    void CheckHitmanNPCCollision(SMatrix* mvFrom, SMatrix* mvTo);
    void EquipOutfitInternal(ZDynamicResourceLibrary* pNewOutfitLibrary, TEntityRef<IHM5Outfit> Outfit, bool bPlaceClothBundle, TEntityRef<ZSpatialEntity> pClothBundlePosition, bool bForce);
    bool EnterSniperMode();
    ZDynamicResourceLibrary* EquipOutfitFromCharacter(TEntityRef<ZHM5BaseCharacter>* pCharacter, ZDynamicResourceLibrary* pNewOutfitLibrary);
    void OnLoadingOutfitStatusChanged(ZRuntimeResourceID* rid);
    void EquipOutfitResourceAsync_Abort(ZRuntimeResourceID ridNewOutfitLibrary);
    void CutSequenceStarted();
};
