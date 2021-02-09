#pragma once

#include "IComponentInterface.h"
#include "IScaleformExternalInterfaceHandler.h"
#include "ZHUDManagerEntity.h"
#include "IScaleformPlayer.h"
#include "ZHUDMenuSystem.h"
#include "EMenuActionId.h"
#include "TFixedArray.h"
#include "HUDButtonDisplay.h"
#include "ECrossHairType.h"
#include "ZAttentionHUD.h"
#include "SShootinBalletStatus.h"
#include "ZHM5HUDFadeHandler.h"
#include "SActorInfo.h"
#include "SWeaponStatus.h"
#include "SIconInfo.h"
#include "TQueue.h"
#include "SPushNotification.h"
#include "ZDynamicResourceLibrary.h"
#include "ZNotebookEntity.h"
#include "ZHintMessageEntity.h"
#include "SValueTween.h"
#include "SBreadcrumb.h"
#include "ZUIButtonMapper_Windows.h"
#include "EHUDFadeReason.h"
#include "ECommunicationBarState.h"
#include "EMeBarState.h"
#include "EScreenAnchor.h"
#include "ETextAlignment.h"
#include "EButtonPressType.h"
#include "SRatingProgress.h"
#include "IHM5Item.h"
#include "IHM5ItemWeapon.h"
#include "ZHitman5.h"
#include "ZScoreComparisonData.h"
#include "SComponentMapEntry.h"

class alignas(16) ZHUDManager : public IComponentInterface, public IScaleformExternalInterfaceHandler
{
public:
    ZHUDManagerEntity* m_pHUDManagerEntity;
    IScaleformPlayer* m_mcHUD;
    IScaleformPlayer* m_mcMenu;
    ZHUDMenuSystem* m_pMenu;
    bool m_bPCRetail;
    bool m_bPCWeaponSelectorEnabled;
    bool m_bLeavePauseMenu;
    bool m_bDisabledRightMouseButton;
    float m_fCrossHairDepth;
    bool m_bAlwaysShowWeaponSelection;
    float m_fWeaponSelectionTimer;
    TMap<ZString, ZVariant> m_nextScreenInfo;
    EMenuActionId m_eMenuActionToActivateAfterAsyncSave;
    TFixedArray<int, 14> m_aVisible;
    bool m_bHUDVisibleOnGameStart;
    bool m_bDisplayHUD;
    bool m_bCutscenePaused;
    bool m_bPauseMode;
    bool m_bPauseMenuActive;
    bool m_bNotebookActive;
    bool m_bNotebookBlocked;
    bool m_bLevelCompleteScreenActive;
    bool m_bCutscenePlaying;
    bool m_bGameModeActive;
    bool m_bGameStarted;
    bool m_bBlendInActive;
    bool m_bPointShootingExecuting;
    int m_nFocusBarState;
    int m_nDifficulty;
    ZString m_sNextLevelPath;
    bool m_bCommunicationBarAnimating;
    bool m_bMeBarAnimating;
    bool m_bExternalInterfacesRegistered;
    bool m_bCutsceneShouldStop;
    TArray<ZString> m_aObjectives;
    bool m_bDisguiseLevelChanged;
    float m_fDisguiseLevel;
    bool m_bAnimatingDisguiseIndicator;
    float m_fFocusBarValue;
    ZResourcePtr m_pDisguiseMovie;
    bool m_bDisguiseChanged;
    HUDButtonDisplay m_buttonDisplay;
    GFxValue m_currentSelectedWeaponBG;
    TArray<GFxValue> m_aWeaponIcons;
    bool m_bShowingWeaponSelection;
    bool m_bShowingWeaponSelectionMKB;
    ECrossHairType m_eScaleformCrossHair;
    ECrossHairType m_eCrossHair;
    int m_nCrossHairTargetFrame;
    float m_fCrossHairScale;
    float m_fCrossHairScaleAnimate;
    float m_fCrosshairShootAnimate;
    float m_fCrosshairFocusAnimate;
    float m_fCrosshairHitIndicatorAnimate;
    bool m_bCrossHairFocused;
    bool m_bCrossHairAnimating;
    bool m_bUpdateCrossHair;
    float m_fHealthPercentage;
    float m_fScaleformHealthPercentage;
    float m_fBossHealth;
    float m_fBossTimer;
    ZAttentionHUD m_AttentionHUD;
    SShootinBalletStatus m_ShootingBalletStatus;
    unsigned int m_nNumShootingBalletSlotTimers;
    ZHM5HUDFadeHandler m_FadeHandler;
    TFixedArray<GFxValue, 32> m_aRadarBlips;
    TFixedArray<GFxValue, 32> m_aRadarIcons;
    TFixedArray<SActorInfo, 32> m_aActorInfo;
    int m_nNumBlips;
    bool m_bScaleformShowRadar;
    alignas(4) SWeaponStatus m_NewWeaponStatus;
    SWeaponStatus m_WeaponStatus;
    bool m_bPlayingReloadAnimation;
    const float m_cfReloadAnimationTimeTotal;
    float m_fReloadAnimationTimeCurrent;
    bool m_bLowReserveAmmo;
    float m_fCachedDeltaTime;
    bool m_bCurrentAmmoDirtyFlag;
    ZString m_sCurrentAmmoName;
    unsigned __int16 m_iCurrentAmmoPicked;
    TMap<ZString, float> m_Calls;
    TFixedArray<SIconInfo, 16> m_aIcons;
    TQueue<SPushNotification, TBlockArray<SPushNotification>> m_qPushNotifications;
    EMenuId m_eNotebookScreen;
    EMenuId m_eUserNotebookPage;
    EMenuId m_eNotebookPage;
    int m_nNotebookItem;
    unsigned __int16 m_eNotebookState;
    ZRuntimeResourceID m_notebookResourceID;
    ZRuntimeResourceID m_contractResourceID;
    ZRuntimeResourceID m_techniqueIconResourceID;
    ZDynamicResourceLibrary* m_pNotebookLibrary;
    TEntityRef<ZNotebookEntity> m_pNotebookEntity;
    TEntityRef<IScaleformPlayer> m_pNotebookPlayerEntity;
    ZDynamicResourceLibrary* m_pNotebookPortraitLibrary;
    __int16 m_nSceneOverlayQuad;
    unsigned int m_nSceneOverlayQuadFrameCounter;
    TArray<TEntityRef<ZHintMessageEntity>> m_HintQueue;
    ZGameTime m_HintActivationTime;
    TEntityRef<ZHintMessageEntity> m_pCurrentHint;
    bool m_bCurrentHintRefresh;
    bool m_bTutorialPause;
    bool m_bEndTutorialMessage;
    bool m_bTutorialNotebookPrompt;
    ZString m_sPortraitResource;
    SValueTween m_RatingScore;
    SValueTween m_ContractsScore;
    ZGameTime m_tWaitForBlackNotebook;
    TMap<unsigned int, SBreadcrumb> m_BreadcrumbIcons;
    bool m_bObjectiveFailedPause;
    ZGameTime m_ObjectiveFailedTime;
    ZString m_LastOutfitTitle;
    ZString m_LastOutfitDescription;
    ZRuntimeResourceID m_LastOutfitImage;
    bool m_bTrespassing;
    float m_fScoreComparisonTimer;
    bool m_bShowScoreComparison;
    bool m_bShowScoreComparisonDelay;
    ZString m_sShowScoreComparisonLeaderboardId;
    ZGameTime m_tShowScoreComparisonDelay;
    bool m_bCheckpointLoadscreenActive;
    ZUIButtonMapper_Windows m_ButtonMapper;
    bool m_bScheduleEyefinityHUDPositionUpdate;
    bool m_bDialogActive;

    virtual ~ZHUDManager();
    virtual ZVariantRef* GetVariantRef(ZVariantRef* result);
    virtual int AddRef();
    virtual int Release();
    virtual void* QueryInterface(STypeID* iid);
    ZAttentionHUD* GetAttentionHUD();
    bool ShouldCutsceneStop();
    ZHUDMenuSystem* GetMenuSystem();
    bool IsNotebookActive();
    bool IsPauseMenuActive();
    ZUIButtonMapper_Windows* GetButtonMapper();
    bool IsNotebookOff();
    bool IsNotebookWaitingForDisguiseRelease();
    unsigned __int16 GetNotbookState();
    void CallHUD(ZString* sFunction, ZVariant* arg0);
    void UpdateWaitForAsyncSaveState();
    void ShowScoreComparison(ZString sId);
    void InitMenuMovieClip();
    void DisplayCustomButton(EControllerButton nButton, ZString* sButtonText, bool bShow);
    void SetupMenu();
    void ShutdownMenu();
    static void MenuAction(IScaleformExternalInterfaceArguments* params);
    static void PCEvent(IScaleformExternalInterfaceArguments* params);
    void StopRumble();
    void HideLevelCompleteScreen();
    void SetNotebookPage(EMenuId ePageId, int nItemId);
    void SetCrossHair(ECrossHairType eCrossHair);
    void FocusCrossHair();
    void UnfocusCrossHair();
    void SetFocusTargetCrossHair(bool bOnTarget);
    void ShootCrossHair();
    void SetDisguiseHealth(float fDisguiseLevel);
    void ClearDisguise();
    ZString* GetText(ZString* result, EUIText nTextId);
    void TriggerSoundEvent(ZString* sPin, ZVariantRef* data);
    static void SoundEvent(IScaleformExternalInterfaceArguments* params);
    static void HUDEvent(IScaleformExternalInterfaceArguments* params);
    static void GetFriendsList(IScaleformExternalInterfaceArguments* params);
    static void GetUserWalletAmount(IScaleformExternalInterfaceArguments* params);
    static void UpdateLikesDislikes(IScaleformExternalInterfaceArguments* params);
    static void LeaderboardGetScores(IScaleformExternalInterfaceArguments* params);
    static void LeaderboardGetAverageScores(IScaleformExternalInterfaceArguments* params);
    static void FetchNotificationMessages(IScaleformExternalInterfaceArguments* params);
    static void GetChallengeInfo(IScaleformExternalInterfaceArguments* params);
    static void GetChallengeSentInfo(IScaleformExternalInterfaceArguments* params);
    static void SetContractTargetOutfit(IScaleformExternalInterfaceArguments* params);
    static void SetContractTargetWeapon(IScaleformExternalInterfaceArguments* params);
    static void SetContractRestriction(IScaleformExternalInterfaceArguments* params);
    static void ShowGamerCard(IScaleformExternalInterfaceArguments* params);
    void GetIconPathForResourceID_Async(ZRuntimeResourceID rID, ZDynamicResourceLibrary** lib);
    void ItemPickedUp(TEntityRef<IHM5Item>* rItem);
    void ItemUnlocked(ZString* sItemName);
    void AmmoSuckedUp(TEntityRef<IHM5ItemWeapon>* rWeapon, int nBullets);
    void SetWaitForAsyncSaveState(EMenuActionId eAction);
    void ShowAmmoPickup(ZString* ammoName, unsigned __int16 iAmmoPicked);
    void OnClosedDisplayOptionsMenu();
    static void QueryButtonMapCallback(IScaleformExternalInterfaceArguments* params);
    static void CancelButtonMapCallback(IScaleformExternalInterfaceArguments* params);
    static void StartButtonMapCallback(IScaleformExternalInterfaceArguments* params);
    static void RequestButtonMapCallback(IScaleformExternalInterfaceArguments* params);
    static void ResetButtonMapCallback(IScaleformExternalInterfaceArguments* params);
    void SetPauseMenuActive(bool bActive);
    void SetHUDManagerEntity(ZHUDManagerEntity* pHUDManagerEntity);
    void SetUserNotebookPage(EMenuId ePageId);
    void ScaleformShowWeaponDisplay(bool bShow);
    void ScaleformUpdateWeaponDisplayAnimations();
    void HideCrossHair();
    void ShowCrossHair();
    void AnimateCrosshair();
    void DisguiseChanged(ZResourcePtr* pDisguiseMovie, bool bDisguiseIsBroken);
    void RemoveIcon(SHUDIconInfo* iconInfo);
    void ShowTrespassingIcon(bool bShow);
    void ResetContractScoring();
    void SetContractsScore(int iScore);
    void ExpandContractScoringCountdown();
    void HideContractInfo();
    bool InitTargetTrackerTimer();
    void ClearTargetTracker();
    void HideRatingProgress();
    void ShowThreatRadar(bool bShow);
    void HideHint();
    void HideTutorial();
    TEntityRef<ZHitman5>* Hitman(TEntityRef<ZHitman5>* result);
    void HideLevelIntroScreen();
    void UpdateAnimatedScoreForRatingTracker();
    void ScaleformUpdateContractsTracker();
    void ScaleformUpdateRatingTracker();
    void HideRatingTracker();
    void HideAmmoPickup();
    void ScaleformGetStageScale(float* fScaleX, float* fScaleY);
    void CompetitionClearSelectedFriends();
    void ScaleformUpdateEyefinityHUDPosition();
    bool DoShowLoadSaveIndicator(bool bShow);
    void GetLocalizedText(IScaleformExternalInterfaceArguments* params);
    void FadeHUDElements(unsigned int nElements, EHUDFadeReason eReason, bool bFadeIn, float fTime);
    void SetDifficultyLevelHUDElementMask(unsigned int nElements);
    void StoreLastOutfitParameters();
    void FadePauseMenuToBlack(EMenuActionId eAction);
    void InitWeaponSelectionMKB();
    void UpdateAmmoCountsMKB();
    void DeSelectCurrentWeapon();
    void SetSelectedWeapon(unsigned int nDirection, unsigned int nSlot, GFxValue* mcMain, GFxValue* mcWeapon);
    void ScaleformUpdateCrossHair();
    void ScaleformUpdateFocusBar();
    void SetFocusBarValue(float fFocusFraction, bool bIsBurning);
    void ShowFocusBar(bool bShow);
    void ScaleformUpdateDisguiseLevel();
    void ScaleformUpdateIcon(SHUDIconInfo* iconInfo);
    void InitIcons();
    void ReleaseIcons();
    void ShowAIStateIcon(int nState);
    void ShowAchievementNotification(ZString* sTitle, ZString* sDescription);
    void ContractUpdateTimerScore(TMap<ZString, ZVariant>* info);
    bool InitTargetTrackerCampaign(TMap<ZString, ZVariant>* info);
    bool InitTargetTrackerContractPlayer(TMap<ZString, ZVariant>* info);
    bool InitTargetTrackerContractCreator(TMap<ZString, ZVariant>* info);
    void UpdateTargetTrackerState(TMap<ZString, ZVariant>* info);
    void UpdateTargetTrackerTime(TMap<ZString, ZVariant>* info);
    void InitRadarBlips();
    void ScaleformUpdateThreatRadar();
    void UpdateHealth();
    void ScaleformUpdateHealth();
    void ShowCommunicationBar(ZString* sHeadline, ZString* sSubline, ECommunicationBarState eState);
    void HideCommunicationBar();
    void ShowMeBar(ZString* sHeadline, ZString* sSubline, EMeBarState eState);
    void HideMeBar();
    __int16 AddText(ZString* sText, int nOffsetX, int nOffsetY, EScreenAnchor eScreenAnchor, float nSize, unsigned int nColor, ETextAlignment eTextAlign, float nDuration, bool bForce);
    void SetText(__int16 nTextID, ZString* sText, bool bForce);
    void SetTextPosition(__int16 nTextID, int nOffsetX, int nOffsetY, bool bForce);
    void SetTextScale(__int16 nTextID, float fScale, bool bForce);
    void SetTextAlpha(__int16 nTextID, __int16 nAlpha, bool bForce);
    void RemoveText(__int16 nTextID);
    void ShowHint(ZString* text, int iType, int iFirstButton, int iSecondButton, ZString* buttonText);
    void HideHintAndTutorialAndReset();
    void ControlLayoutChanged();
    void ShowTutorial(ZString* headline, ZString* text, ZString* resourcePath, int iButton, ZString* buttonText, ZString* keyText);
    void BaconShot(ZString* sText);
    __int16 AddQuad(int nOffsetX, int nOffsetY, int nWidth, int nHeight, EScreenAnchor eScreenAnchor, unsigned int nColor, unsigned __int16 nAlpha, float nDuration);
    void SetQuadSize(__int16 nQuadID, int nWidth, int nHeight);
    void SetQuadPositionAndSize(__int16 nQuadID, int nOffsetX, int nOffsetY, int nWidth, int nHeight);
    void RemoveQuad(__int16 nQuadID);
    void LeaderboardDisplayScores(TMap<ZString, ZVariant>* info);
    void LeaderboardDisplayAverageScores(TMap<ZString, ZVariant>* info);
    static void IsContractsTutorial(IScaleformExternalInterfaceArguments* params);
    static void GetImageFromResourceID(IScaleformExternalInterfaceArguments* params);
    bool HitmanExists();
    ZString* GetButtonTag(ZString* result, EControllerButton eButton, EButtonPressType ePressType);
    void SetSceneOverlayVisible(bool bVisible);
    void UpdatePcInput();
    void ShowLevelIntroScreen(ZString* sLevelName, ZString* sSubString);
    void ResetRatingTracker(ZString* portrait);
    void ScaleformShowAmmoPickup();
    void SetDialogActive(bool bActive);
    void HideTutorialFromScaleform();
    static void HideTutorialCallback(IScaleformExternalInterfaceArguments* params);
    void RestoreDifficultySelection(int nIndex);
    bool UpdateBreadcrumbIcon(TEntityRef<ZShowBreadcrumbIcon>* ent, SHUDIconInfo* info);
    void ScaleformUpdateContractsReportEnabled(bool bState);
    void CheckpointLoadingFinished();
    void ShowHUD(bool bShow);
    void InitMovieClips();
    void UpdatePrompts(unsigned __int8 iCount, SPromptToDisplay* const pActivePrompts);
    void ReleaseNotebook();
    void ScaleformUpdateWeaponDisplay();
    void AddIcon(SHUDIconInfo* iconInfo);
    void UpdateIcon(SHUDIconInfo* iconInfo, unsigned int changedFlags);
    void ShowContractTargets(TArray<ZVariant> aTargets);
    void ShowContractExitPoints(TArray<ZVariant> aTargets);
    void UpdateThreatRadar();
    void ScaleformUpdateAttentionHUD();
    static void GetControllerLayout(IScaleformExternalInterfaceArguments* params);
    ZString* GetIconPathForResourceID(ZString* result, ZRuntimeResourceID rID, ZDynamicResourceLibrary** lib, bool bWait);
    static void GetObjectiveImage(IScaleformExternalInterfaceArguments* params);
    ZString* GetRatingPortraitImage(ZString* result, int titleIndex);
    ZRuntimeResourceID* GetRatingPortraitImageRID(ZRuntimeResourceID* result, int titleIndex);
    void SetNotebookLibID(ZRuntimeResourceID* notebookLibID);
    void SetContractLibID(ZRuntimeResourceID* contractLibID);
    void UpdateBreadcrumbIcons();
    void ScaleformUpdateBreadcrumbIcons();
    void ShowNextScreen();
    void UpdateCrossHair();
    void ReleaseWeapons();
    void ReleaseRadarBlips();
    void CancelHintEntity(TEntityRef<ZHintMessageEntity> pEntity);
    static void GetChallengeIcon(IScaleformExternalInterfaceArguments* params);
    void ReleaseMovieClips();
    void RemoveBreadcrumbIcon(TEntityRef<ZShowBreadcrumbIcon>* ent);
    void OnDisplayScreen(EMenuId nMenuId, TMap<ZString, ZVariant> info);
    void ContractsSetTargetRestriction(TMap<ZString, ZVariant> info);
    void PushHintEntity(TEntityRef<ZHintMessageEntity> pEntity);
    void UpdateHints();
    void AddBreadcrumbIcon(TEntityRef<ZShowBreadcrumbIcon>* ent);
    void SetHUDMovieClip(IScaleformPlayer* pFlashMovie);
    void SetPauseMenuMovieClip(IScaleformPlayer* pFlashMovie);
    void StartPauseMode();
    void ResumeGame();
    void ContractScoreUpdate(int iScore, ZString* sScoreReason);
    void ContractSetTitleText(ZString sTitle);
    void ContractSetDescriptionText(ZString sDescription);
    void ShowRatingProgress(SRatingProgress* actionProgress, SRatingProgress* stealthProgress);
    void ShowFinalCheckPointRating(float fActionRatingFraction, float fStealthRatingFraction, float fDuration);
    static void GetLikeDislikeInfo(IScaleformExternalInterfaceArguments* params);
    void SetGlobalTexts();
    void SetHUDConstants();
    void UpdateRatingTracker(ZString* title, ZString* portrait, int totalscore, bool titlechanged, bool totalscorechanged);
    void RatingScoreAdded(int score, ZString* scoreReason);
    void LevelFailed(ZString* sReason);
    void ScaleformUpdateContractTargets();
    void ScaleformUpdateContractExits();
    void OnFontChanged();
    void ShowPauseMenu(bool bShow);
    void TogglePauseMenu();
    void ScaleformUpdateWeaponSelection();
    void SetMenuConstants();
    void RenderThreadUpdate();
    void Reset();
    void ShowContractFailed();
    void HandleNotebookTransition();
    void ShowNotebook(bool bShow);
    void OnContinueAction();
    void ShowNotebookScreen(EMenuId nNotebookScreenID);
    void ContractCreatorEnded(bool bSuccess);
    void ContractPlayerEnded(bool bSuccess);
    void ShowLevelCompleteScreen();
    void UpdatePushNotifications();
    void ResetScorePreviewPushNotifications();
    bool OnClosedGraphicsOptionsMenu();
    void ToggleNotebook();
    void LevelEnded(ZString* sNextLevelPath);
    void ShowPushNotification(EPushNotificationType ePushNotificationType, float fDisplayTime, TMap<ZString, ZVariant>* data, int nItemID);
    void ShowObjective(ZString* sText, bool bTertiaryObjective, bool bObjectiveUpdated);
    void ShowScoreUpdate();
    void OutfitUnlocked(ZString* sOutfitName);
    void TechniqueUnlocked(ZString* sTechniqueName);
    void SpecialRatingUnlocked(ZString* sTitle);
    void ContractPickedUp(ZString* sTitle);
    void CheckpointLoadingStarted();
    void OnPauseUpdate(SGameUpdateEvent* updateEvent);
    void ShowScoreComparisonCallback(bool bSuccess, ZScoreComparisonData* data);
    void ShowContractNotification(ZString* sUser, ZString* sText, unsigned __int16 nIcon, float fDuration);
    void UpdateScoreComparison();
    void OnFrameUpdate(SGameUpdateEvent* updateEvent);
    void OnGameStop(ZString* sEvent, ZVariantRef* val);
    void OnGameStart(ZString* sEvent, ZVariantRef* val);
    ZHUDManager();
    const SComponentMapEntry* GetComponentInterfacesInternal();
    TEntityRef<ZNotebookEntity>* GetNotebook();
    const ZString* GetLastOutfitTitle();
    const ZString* GetLastOutfitDescription();
    ZRuntimeResourceID* GetLastOutfitImage(ZRuntimeResourceID* result);
    void SetNotebookBlocked(bool bVal);
};
