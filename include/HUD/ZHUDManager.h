#pragma once

#include "IComponentInterface.h"
#include "IScaleformExternalInterfaceHandler.h"
#include "EMenuActionId.h"
#include "TFixedArray.h"
#include "HUDButtonDisplay.h"
#include "ECrossHairType.h"
#include "ZAttentionHUD.h"
#include "ZHM5HUDFadeHandler.h"
#include "TQueue.h"
#include "ZUIButtonMapper_Windows.h"
#include "EHUDFadeReason.h"
#include "ECommunicationBarState.h"
#include "EMeBarState.h"
#include "EScreenAnchor.h"
#include "ETextAlignment.h"
#include "EButtonPressType.h"
#include "UserFBInventoryInfoNamesp.h"
#include "EPushNotificationType.h"
#include "SHUDIconInfo.h"
#include "EControllerButton.h"
#include "EMenuId.h"
#include "EUIDialog.h"
#include "EUIText.h"
#include "GFxValue.h"
#include "STokenID.h"
#include "TArray.h"
#include "TBlockArray.h"
#include "TEntityRef.h"
#include "TMap.h"
#include "ZGameTime.h"
#include "ZGameWideUI.h"
#include "ZResourcePtr.h"
#include "ZRuntimeResourceID.h"
#include "ZString.h"
#include "ZVariant.h"
#include "ZVariantRef.h"
#include "eItemType.h"

class ZShowBreadcrumbIcon;
class IHM5Item;
class IHM5ItemWeapon;
class IScaleformExternalInterfaceArguments;
class IScaleformPlayer;
class ZDynamicResourceLibrary;
class ZHUDManagerEntity;
class ZHUDMenuSystem;
class ZHintMessageEntity;
class ZHitman5;
class ZNotebookEntity;
class ZScoreComparisonData;
struct SComponentMapEntry;
struct SGameUpdateEvent;
struct SPromptToDisplay;
struct SRatingProgress;
struct STypeID;

class ZHUDManager : public IComponentInterface, public IScaleformExternalInterfaceHandler
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum WeaponSelectionMode
	{
		eShowWeaponSelectionOnUse = 0,
		eShowWeaponSelection = 1,
		eHideWeaponSelection = 2,
		eNumSelectionModes = 3
	};

	struct SWeaponStatus
	{
		eItemType eRightHandItemType;
		STokenID pTokenID;
		ZResourcePtr pIcon;
		ZResourcePtr pSilencerIcon;
		short nLoadedAmmoLeft;
		short nLoadedAmmoRight;
		short nReserveAmmo;
		short nClipSize;
		float m_fSilencerPosX;
		float m_fSilencerPosY;
		UserFBInventoryInfoNamesp::EOperationMode eOperationMode;
		bool bHolstered;
		bool bDualWield;
		bool bSwitchedWeapon;

		SWeaponStatus() = default;
		~SWeaponStatus() = default;
		SWeaponStatus& operator=(const SWeaponStatus& __that);
	};

	struct SValueTween
	{
		enum State
		{
			ST_IDLE = 0,
			ST_DELAY = 1,
			ST_ANIM = 2
		};

		int m_iTotalScore;
		int m_iNewShownValue;
		int m_iLastShownValue;
		float m_fAnimRunningTime;
		float m_fAnimTotalTime;
		int m_iAnimStartValue;
		State m_eState;

		SValueTween() = default;
		void StartDelay(int iTarget, float fDelay);
		void StartAnim(float fAnimTime);
		void Idle();
		void Update(float fAnimTime);
	};

	struct SShootinBalletStatus
	{
		int nShootingBalletMode;
		int nTagSlots;
		int nNumTags;
		int nNumTagsShot;
		int nKillingShot;
	};

	struct SActorInfo
	{
		float fAlpha;
		float fDistance;
		float fDegrees;
		float fFacingDirection;
		int nHeight;
		int eIndicator;
	};

	struct SIconInfo
	{
		GFxValue mc;
		bool bActive;

		SIconInfo() = default;
		~SIconInfo() = default;
	};

	struct SPushNotification
	{
		bool bShown;
		TMap<ZString, ZVariant> info;
		float fDisplayTime;
		EPushNotificationType ePushNotificationType;
		EMenuId eMenuID;
		int nItemID;

		SPushNotification(const SPushNotification& __that);
		SPushNotification() = default;
		~SPushNotification() = default;
		SPushNotification& operator=(const SPushNotification& __that);
	};

	struct SBreadcrumb
	{
		TEntityRef<ZShowBreadcrumbIcon> ent;
		SHUDIconInfo icon;

		SBreadcrumb(const SBreadcrumb& __that);
		SBreadcrumb() = default;
		~SBreadcrumb() = default;
		SBreadcrumb& operator=(const SBreadcrumb& __that);
	};

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
	SWeaponStatus m_NewWeaponStatus;
	SWeaponStatus m_WeaponStatus;
	bool m_bPlayingReloadAnimation;
	const float m_cfReloadAnimationTimeTotal;
	float m_fReloadAnimationTimeCurrent;
	bool m_bLowReserveAmmo;
	float m_fCachedDeltaTime;
	bool m_bCurrentAmmoDirtyFlag;
	ZString m_sCurrentAmmoName;
	unsigned short m_iCurrentAmmoPicked;
	TMap<ZString, float> m_Calls;
	TFixedArray<SIconInfo, 16> m_aIcons;
	TQueue<SPushNotification, TBlockArray<SPushNotification>> m_qPushNotifications;
	EMenuId m_eNotebookScreen;
	EMenuId m_eUserNotebookPage;
	EMenuId m_eNotebookPage;
	int m_nNotebookItem;
	unsigned short m_eNotebookState;
	ZRuntimeResourceID m_notebookResourceID;
	ZRuntimeResourceID m_contractResourceID;
	ZRuntimeResourceID m_techniqueIconResourceID;
	ZDynamicResourceLibrary* m_pNotebookLibrary;
	TEntityRef<ZNotebookEntity> m_pNotebookEntity;
	TEntityRef<IScaleformPlayer> m_pNotebookPlayerEntity;
	ZDynamicResourceLibrary* m_pNotebookPortraitLibrary;
	short m_nSceneOverlayQuad;
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

	static const float m_fWeaponSelectionDuration;

	~ZHUDManager() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZHUDManager() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	void RenderThreadUpdate();
	void ScaleformUpdateEyefinityHUDPosition();
	void UpdateWeaponDisplay(const SWeaponStatus& newStatus);
	void ItemPickedUp(const TEntityRef<IHM5Item>& rItem);
	void AmmoSuckedUp(const TEntityRef<IHM5ItemWeapon>& rWeapon, int nBullets);
	void ItemUnlocked(const ZString& sItemName);
	void OutfitUnlocked(const ZString& sOutfitName);
	void TechniqueUnlocked(const ZString& sTechniqueName);
	void SpecialRatingUnlocked(const ZString& sTitle);
	void ContractPickedUp(const ZString& sTitle);
	void SetFocusTargetCrossHair(bool bOnTarget);
	void UpdateCrossHair();
	void HideCrossHair();
	void ShowCrossHair();
	void SetCrossHair(ECrossHairType eCrossHair);
	void FocusCrossHair();
	void UnfocusCrossHair();
	void ShootCrossHair();
	void ScaleformUpdateCrossHair();
	void ScaleformUpdateFocusBar();
	void SetFocusBarValue(float fFocusFraction, bool bIsBurning);
	void ShowFocusBar(bool bShow);
	void ShowThreatRadar(bool bShow);
	void ScaleformUpdateAttentionHUD();
	ZAttentionHUD& GetAttentionHUD();
	void DisguiseChanged(const ZResourcePtr& pDisguiseMovie, bool bDisguiseIsBroken);
	void SetDisguiseHealth(float fDisguiseLevel);
	void ClearDisguise();
	void UpdatePrompts(unsigned char iCount, const SPromptToDisplay* const pActivePrompts);
	void DisplayCustomButton(EControllerButton nButton, const ZString& sButtonText, bool bShow);
	void ShowObjective(const ZString& sText, bool bTertiaryObjective, bool bObjectiveUpdated);
	void ShowScoreUpdate();
	void ShowCommunicationBar(const ZString& sHeadline, const ZString& sSubline, ECommunicationBarState eState);
	void HideCommunicationBar();
	void ShowMeBar(const ZString& sHeadline, const ZString& sSubline, EMeBarState eState);
	void HideMeBar();
	void ShowPushNotification(EPushNotificationType ePushNotificationType, float fDisplayTime, const TMap<ZString, ZVariant>& data, int nItemID);
	void UpdatePushNotifications();
	void ResetScorePreviewPushNotifications();
	short AddQuad(int nOffsetX, int nOffsetY, int nWidth, int nHeight, EScreenAnchor eScreenAnchor, unsigned int nColor, unsigned short nAlpha, float nDuration);
	void SetQuadPositionAndSize(short nQuadID, int nOffsetX, int nOffsetY, int nWidth, int nHeight);
	void SetQuadSize(short nQuadID, int nWidth, int nHeight);
	void RemoveQuad(short nQuadID);
	void SetSceneOverlayVisible(bool bVisible);
	short AddText(const ZString& sText, int nOffsetX, int nOffsetY, EScreenAnchor eScreenAnchor, float nSize, unsigned int nColor, ETextAlignment eTextAlign, float nDuration, bool bForce);
	void SetText(short nTextID, const ZString& sText, bool bForce);
	void SetTextPosition(short nTextID, int nOffsetX, int nOffsetY, bool bForce);
	void SetTextScale(short nTextID, float fScale, bool bForce);
	void SetTextAlpha(short nTextID, short nAlpha, bool bForce);
	void RemoveText(short nTextID);
	void OnFontChanged();
	void GetLocalizedText(IScaleformExternalInterfaceArguments& params);
	void ShowHint(const ZString& text, int iType, int iFirstButton, int iSecondButton, const ZString& buttonText);
	void HideHint();
	void HideHintAndTutorialAndReset();
	void PushHintEntity(TEntityRef<ZHintMessageEntity> pEntity);
	void CancelHintEntity(TEntityRef<ZHintMessageEntity> pEntity);
	void UpdateHints();
	void ControlLayoutChanged();
	ZString GetButtonTag(EControllerButton eButton, EButtonPressType ePressType);
	void ShowTutorial(const ZString& headline, const ZString& text, const ZString& resourcePath, int iButton, const ZString& buttonText, const ZString& keyText);
	void HideTutorial();
	void BaconShot(const ZString& sText);
	void ShowTrespassingIcon(bool bShow);
	void ShowAIStateIcon(int nState);
	void AddIcon(SHUDIconInfo& iconInfo);
	void UpdateIcon(SHUDIconInfo& iconInfo, unsigned int changedFlags);
	void RemoveIcon(SHUDIconInfo& iconInfo);
	ZString GetIconPathForResourceID(ZRuntimeResourceID rID, ZDynamicResourceLibrary*& lib, bool bWait);
	void GetIconPathForResourceID_Async(ZRuntimeResourceID rID, ZDynamicResourceLibrary*& lib);
	void ContractCreatorEnded(bool bSuccess);
	void ContractPlayerEnded(bool bSuccess);
	void ShowContractTargets(const TArray<ZVariant> aTargets);
	void ShowContractExitPoints(const TArray<ZVariant> aTargets);
	void HideContractInfo();
	void ShowContractNotification(const ZString& sUser, const ZString& sText, unsigned short nIcon, float fDuration);
	void ResetContractScoring();
	void SetContractsScore(int iScore);
	void ExpandContractScoringCountdown();
	void ContractScoreUpdate(int iScore, const ZString& sScoreReason);
	void ContractUpdateTimerScore(const TMap<ZString, ZVariant>& info);
	void ContractSetTitleText(ZString sTitle);
	void ContractSetDescriptionText(ZString sDescription);
	void ContractsSetTargetRestriction(TMap<ZString, ZVariant> info);
	bool InitTargetTrackerCampaign(const TMap<ZString, ZVariant>& info);
	bool InitTargetTrackerContractPlayer(const TMap<ZString, ZVariant>& info);
	bool InitTargetTrackerContractCreator(const TMap<ZString, ZVariant>& info);
	void UpdateTargetTrackerState(const TMap<ZString, ZVariant>& info);
	bool InitTargetTrackerTimer();
	void UpdateTargetTrackerTime(const TMap<ZString, ZVariant>& info);
	void ClearTargetTracker();
	void ShowRatingProgress(const SRatingProgress& actionProgress, const SRatingProgress& stealthProgress);
	void ShowFinalCheckPointRating(float fActionRatingFraction, float fStealthRatingFraction, float fDuration);
	void HideRatingProgress();
	ZString GetRatingPortraitImage(int titleIndex);
	ZRuntimeResourceID GetRatingPortraitImageRID(int titleIndex);
	void ShowAchievementNotification(const ZString& sTitle, const ZString& sDescription);
	void SetupMenu();
	void ShutdownMenu();
	void SetMenuConstants();
	void SetGlobalTexts();
	void SetHUDConstants();
	void RestoreDifficultySelection(int nIndex);
	bool DoShowLoadSaveIndicator(bool bShow);
	bool ShouldCutsceneStop();
	void ShowLevelIntroScreen(const ZString& sLevelName, const ZString& sSubString);
	void HideLevelIntroScreen();
	void ShowAmmoPickup(const ZString& ammoName, unsigned short iAmmoPicked);
	void HideAmmoPickup();
	static void MenuAction(IScaleformExternalInterfaceArguments& params);
	static void PCEvent(IScaleformExternalInterfaceArguments& params);
	static void SoundEvent(IScaleformExternalInterfaceArguments& params);
	static void HUDEvent(IScaleformExternalInterfaceArguments& params);
	static void GetFriendsList(IScaleformExternalInterfaceArguments& params);
	static void GetUserWalletAmount(IScaleformExternalInterfaceArguments& params);
	static void GetImageFromResourceID(IScaleformExternalInterfaceArguments& params);
	static void GetChallengeIcon(IScaleformExternalInterfaceArguments& params);
	static void GetObjectiveImage(IScaleformExternalInterfaceArguments& params);
	static void GetLikeDislikeInfo(IScaleformExternalInterfaceArguments& params);
	static void UpdateLikesDislikes(IScaleformExternalInterfaceArguments& params);
	static void FetchNotificationMessages(IScaleformExternalInterfaceArguments& params);
	static void LeaderboardGetScores(IScaleformExternalInterfaceArguments& params);
	static void LeaderboardGetAverageScores(IScaleformExternalInterfaceArguments& params);
	static void GetChallengeInfo(IScaleformExternalInterfaceArguments& params);
	static void GetChallengeSentInfo(IScaleformExternalInterfaceArguments& params);
	static void IsContractsTutorial(IScaleformExternalInterfaceArguments& params);
	static void SetContractTargetWeapon(IScaleformExternalInterfaceArguments& params);
	static void SetContractTargetOutfit(IScaleformExternalInterfaceArguments& params);
	static void SetContractRestriction(IScaleformExternalInterfaceArguments& params);
	static void GetControllerLayout(IScaleformExternalInterfaceArguments& params);
	static void ShowGamerCard(IScaleformExternalInterfaceArguments& params);
	static void StartButtonMapCallback(IScaleformExternalInterfaceArguments& params);
	static void QueryButtonMapCallback(IScaleformExternalInterfaceArguments& params);
	static void CancelButtonMapCallback(IScaleformExternalInterfaceArguments& params);
	static void RequestButtonMapCallback(IScaleformExternalInterfaceArguments& params);
	static void ResetButtonMapCallback(IScaleformExternalInterfaceArguments& params);
	void HideTutorialFromScaleform();
	static void HideTutorialCallback(IScaleformExternalInterfaceArguments& params);
	void FadeHUDElements(unsigned int nElements, EHUDFadeReason eReason, bool bFadeIn, float fTime);
	void SetDifficultyLevelHUDElementMask(unsigned int nElements);
	void ShowScoreComparison(ZString sId);
	void UpdateScoreComparison();
	void ShowContractFailed();
	void StopRumble();
	void CompetitionClearSelectedFriends();
	void Reset();
	void ShowNotebook(bool bShow);
	void ShowNotebookScreen(EMenuId nNotebookScreenID);
	void LevelEnded(const ZString& sNextLevelPath);
	void ShowLevelCompleteScreen();
	void HideLevelCompleteScreen();
	void SetHUDManagerEntity(ZHUDManagerEntity* pHUDManagerEntity);
	void SetHUDMovieClip(IScaleformPlayer* pFlashMovie);
	void SetPauseMenuMovieClip(IScaleformPlayer* pFlashMovie);
	void InitMenuMovieClip();
	void SetNotebookLibID(const ZRuntimeResourceID& notebookLibID);
	void SetContractLibID(const ZRuntimeResourceID& contractLibID);
	TEntityRef<ZNotebookEntity>& GetNotebook();
	bool IsNotebookOff() const;
	bool IsNotebookWaitingForDisguiseRelease();
	unsigned short GetNotbookState() const;
	void CallHUD(const ZString& sFunction, const ZVariant& arg0);
	void TriggerSoundEvent(const ZString& sPin, const ZVariantRef& data);
	ZString GetText(EUIText nTextId);
	void OnContinueAction();
	void ShowNextScreen();
	void OnDisplayScreen(EMenuId nMenuId, TMap<ZString, ZVariant> info);
	bool IsNotebookActive();
	bool IsPauseMenuActive();
	void SetNotebookBlocked(bool bVal);
	void LeaderboardDisplayScores(const TMap<ZString, ZVariant>& info);
	void LeaderboardDisplayAverageScores(const TMap<ZString, ZVariant>& info);
	void SetWaitForAsyncSaveState(EMenuActionId eAction);
	void CheckpointLoadingStarted();
	void CheckpointLoadingFinished();
	ZHUDMenuSystem* GetMenuSystem() const;
	void UpdateRatingTracker(const ZString& title, const ZString& portrait, int totalscore, bool titlechanged, bool totalscorechanged);
	void ResetRatingTracker(const ZString& portrait);
	void RatingScoreAdded(int score, const ZString& scoreReason);
	void HideRatingTracker();
	void ScaleformUpdateRatingTracker();
	void UpdateAnimatedScoreForRatingTracker();
	void ScaleformUpdateScoreTrackers(SValueTween& value, const char* pszMovieClip);
	void ScaleformUpdateContractsTracker();
	void ScaleformUpdateContractsReportEnabled(bool bState);
	void ScaleformUpdateContractTargets();
	void ScaleformUpdateContractExits();
	void ScaleformGetStageScale(float& fScaleX, float& fScaleY);
	void AddBreadcrumbIcon(const TEntityRef<ZShowBreadcrumbIcon>& ent);
	void RemoveBreadcrumbIcon(const TEntityRef<ZShowBreadcrumbIcon>& ent);
	void UpdateBreadcrumbIcons();
	bool UpdateBreadcrumbIcon(const TEntityRef<ZShowBreadcrumbIcon>& ent, SHUDIconInfo& info);
	void ScaleformUpdateIcon(const SHUDIconInfo& iconInfo);
	void ScaleformUpdateBreadcrumbIcons();
	void LevelFailed(const ZString& sReason);
	void SetDialogActive(bool bActive);
	void OnClosedDisplayOptionsMenu();
	bool OnClosedGraphicsOptionsMenu();
	ZUIButtonMapper_Windows& GetButtonMapper();
	void UpdateWaitForAsyncSaveState();
	void DialogCallback(ZGameWideUI::EDialogContext eContext, EUIDialog eDialog, ZGameWideUI::EDialogResult eResult);
	void OnFrameUpdate(const SGameUpdateEvent& updateEvent);
	void OnPauseUpdate(const SGameUpdateEvent& updateEvent);
	void OnGameStart(const ZString& sEvent, const ZVariantRef& val);
	void OnGameStop(const ZString& sEvent, const ZVariantRef& val);
	void ShowHUD(bool bShow);
	void TogglePauseMenu();
	void ToggleNotebook();
	void ReleaseNotebook();
	void ResumeGame();
	void StartPauseMode();
	void FadePauseMenuToBlack(EMenuActionId eAction);
	void ScaleformUpdateDisguiseLevel();
	void ScaleformUpdateHealth();
	void UpdateHealth();
	void ScaleformUpdateWeaponSelection();
	void ScaleformUpdateWeaponDisplay();
	void ScaleformShowWeaponDisplay(bool bShow);
	void ScaleformShowWeaponAndAmmo(const SWeaponStatus& newStatus);
	void ScaleformUpdateReserveAmmo(const SWeaponStatus& newStatus);
	void ScaleformUpdateBullets(const SWeaponStatus& newStatus);
	void ScaleformUpdateWeaponDisplayAnimations();
	void ScaleformShowAmmoPickup();
	void ShowPauseMenu(bool bShow);
	void UpdateThreatRadar();
	void ScaleformUpdateThreatRadar();
	TEntityRef<ZHitman5> Hitman() const;
	bool HitmanExists() const;
	void StoreLastOutfitParameters();
	const ZString& GetLastOutfitTitle() const;
	const ZString& GetLastOutfitDescription() const;
	ZRuntimeResourceID GetLastOutfitImage() const;
	void SetPauseMenuActive(bool bActive);
	void ScaleformWeaponSelectionChanged(const UserFBInventoryInfoNamesp::SHUDInventoryInfo& weaponInventory, bool bShow);
	void SetupWeaponIcons(GFxValue& mcWeaponSelectionMain, GFxValue& mcHolder, const ZString& sName, const ZString& sIconPath, const ZString& sSilencerIconPath, const UserFBInventoryInfoNamesp::SHUDWeaponInfo& weaponInfo);
	void ScaleformShowWeaponSelection(const UserFBInventoryInfoNamesp::SHUDInventoryInfo& weaponInventory, bool bShow);
	void InitWeaponSelectionMKB();
	void ScaleformShowWeaponSelectionMKB(const UserFBInventoryInfoNamesp::HUDInventoryInfoMKB& weaponInventory, bool bShow);
	void SetupWeaponIconsMKB(const UserFBInventoryInfoNamesp::HUDInventoryInfoMKB& weaponInventory, GFxValue& mcWeaponSelectionMain);
	void UpdateAmmoCountsMKB();
	void DeSelectCurrentWeapon();
	void SetSelectedWeapon(unsigned int nDirection, unsigned int nSlot, GFxValue& mcMain, GFxValue& mcWeapon);
	void InitRadarBlips();
	void ReleaseRadarBlips();
	void UpdateRadarBlip(SActorInfo* pInfo, short nBlipIndex);
	void AnimateCrosshair();
	void InitIcons();
	void ReleaseIcons();
	void ReleaseWeapons();
	void InitMovieClips();
	void ReleaseMovieClips();
	void HandleNotebookTransition();
	void SetNotebookPage(EMenuId ePageId, int nItemId);
	void SetUserNotebookPage(EMenuId ePageId);
	void ShowScoreComparisonCallback(bool bSuccess, const ZScoreComparisonData& data);
	void UpdatePcInput();
};
