#pragma once

#include "ZHM5IngamePromptsManager.h"
#include "ZHM5IngameMessageBarManager.h"
#include "ZHM5TimerToOSDManager.h"
#include "ZHM5IngameIconsManager.h"
#include "UserFBInventoryInfoNamesp.h"
#include "TQueue.h"
#include "SGameStateForUserFeedback.h"
#include "SVector3.h"
#include "TArray.h"
#include "TBlockArray.h"
#include "TEntityRef.h"
#include "UserFBIcons.h"
#include "ZGameTime.h"
#include "eAmmoType.h"

class ZHM5Action;
class ZAIGameState;
class ZHitman5;
class ZString;
struct SGameUpdateEvent;
struct SGameplayInputControlBind;
struct SInventoryChangeInfoMKB;
struct SPromptToDisplay;
struct float4;

class ZUserFeedbackManager
{
public:
	class ZHintMessageEntity
	{
	};

	ZHM5IngamePromptsManager m_PromptsManager;
	ZHM5IngameMessageBarManager m_MessageBarManager;
	ZHM5TimerToOSDManager m_TimerToOSDManager;
	ZHM5IngameIconsManager m_IconsManager;
	TArray<SGameplayInputControlBind> m_GameplayInputControlBinds;
	UserFBInventoryInfoNamesp::SHUDInventoryInfo m_HUDInventoryInfo;
	UserFBInventoryInfoNamesp::HUDInventoryInfoMKB m_HUDInventoryInfoMKB;
	bool m_bPCRetail;
	bool m_bPCWeaponSelectorEnabled;
	TQueue<UserFBInventoryInfoNamesp::SHUDAmmoPickup, TBlockArray<UserFBInventoryInfoNamesp::SHUDAmmoPickup>> m_HUDAmmoPickups;
	ZGameTime m_tDisplayAmmoPickup;
	SGameStateForUserFeedback m_GameState;
	TEntityRef<ZHitman5> m_pHitman;
	ZGameTime m_tDisplaySkipPromptTimer;
	ZGameTime m_tLastDisplayWeaponGroupInfo;
	bool m_bLastDisplayWeaponGroupUseTimer : 1;
	bool m_bGameplayInputControlBindsChanged : 1;

	static const UserFBInventoryInfoNamesp::SHUDWeaponInfo s_EmptyWeapon;
	static const float s_fHoldsTimer;

	ZUserFeedbackManager() = default;
	~ZUserFeedbackManager() = default;
	void OnStart(const TEntityRef<ZHitman5>& pHitman);
	void OnStop();
	void Initialize();
	void Reset();
	void ClearIcons();
	void Update(const SGameUpdateEvent& updateEvent);
	const SGameStateForUserFeedback& GetGameStateForUserFB() const;
	void ChangeBindings(const TArray<SGameplayInputControlBind>& bindingsToUpdate);
	bool GameplayInputControlBindsChanged() const;
	void ClearGameplayInputControlBindsChanged();
	const TArray<SGameplayInputControlBind>& GetGameplayInputControlBinds() const;
	void ChangeHitmanInventoryInfo(bool bShowNoneSelected, bool bHolsterSelected, SInventoryChangeInfoMKB* pInventoryChangeInfoMKB);
	void UpdateWeaponDisplay(unsigned short nNumLoadedAmmoLeft, unsigned short nNumLoadedAmmoRight, unsigned short nNumReserveAmmo);
	bool GetHUDInventoryInfo_IsDirty() const;
	const ZGameTime& GetLastDisplayWeaponGroupInfo() const;
	const UserFBInventoryInfoNamesp::SHUDWeaponInfo& GetCurrentWeaponInfo() const;
	const UserFBInventoryInfoNamesp::SHUDInventoryInfo& GetHUDInventoryInfo();
	const UserFBInventoryInfoNamesp::HUDInventoryInfoMKB& GetHUDInventoryInfoMKB();
	bool GetHUDInventoryInfoMKB_IsDirty() const;
	void AddActivatedAction(ZHM5Action* const pAction, bool bAlternativeActivated);
	void UpdateActiveActions(int nActionCount, ZHM5Action** const pActionList);
	void GetActivePrompts(unsigned char& iCount, const SPromptToDisplay*& pActivePrompts);
	const float GetHoldsTimer() const;
	void UpdateAIState(const ZAIGameState* const pOldState, const ZAIGameState* const pNewState);
	const ZHM5TimerToOSDManager& GetTimerToOSDManager() const;
	void TimerToOSD_Register(TEntityRef<UserFBIcons::IHM5TimerToOSD>& obj, ZHM5TimerToOSDManager::ETimerToOSDManager_Command eComm);
	SVector3 ConvToScreenSpace(const float4& vWorldTrans, float fCamSpaceOffsetX, float fCamSpaceOffsetY, bool& bReject) const;
	void PushAmmoPickup(eAmmoType ammotype, const ZString& sName, unsigned short iAmmoPicked);
	ZHM5IngameMessageBarManager& GetMessageBarManager();
	TEntityRef<ZHitman5> Hitman() const;
	void ShowTopAmmoPickup();
	void HideAmmoPickup();
};
