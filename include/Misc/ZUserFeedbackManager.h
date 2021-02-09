#pragma once

#include "ZHM5IngamePromptsManager.h"
#include "ZHM5IngameMessageBarManager.h"
#include "ZHM5TimerToOSDManager.h"
#include "ZHM5IngameIconsManager.h"
#include "SGameplayInputControlBind.h"
#include "UserFBInventoryInfoNamesp.h"
#include "TQueue.h"
#include "SGameStateForUserFeedback.h"
#include "ZAIGameState.h"

class alignas(16) ZUserFeedbackManager
{
public:
    ZHM5IngamePromptsManager m_PromptsManager;
    ZHM5IngameMessageBarManager m_MessageBarManager;
    ZHM5TimerToOSDManager m_TimerToOSDManager;
    ZHM5IngameIconsManager m_IconsManager;
    TArray<SGameplayInputControlBind> m_GameplayInputControlBinds;
    UserFBInventoryInfoNamesp::SHUDInventoryInfo m_HUDInventoryInfo;
    UserFBInventoryInfoNamesp::HUDInventoryInfoMKB m_HUDInventoryInfoMKB;
    bool m_bPCRetail;
    bool m_bPCWeaponSelectorEnabled;
    TQueue<UserFBInventoryInfoNamesp::SHUDAmmoPickup, TBlockArray<UserFBInventoryInfoNamesp::SHUDAmmoPickup> > m_HUDAmmoPickups;
    ZGameTime m_tDisplayAmmoPickup;
    SGameStateForUserFeedback m_GameState;
    TEntityRef<ZHitman5> m_pHitman;
    ZGameTime m_tDisplaySkipPromptTimer;
    ZGameTime m_tLastDisplayWeaponGroupInfo;
    __int8 m_bLastDisplayWeaponGroupUseTimer : 1;
    __int8 m_bGameplayInputControlBindsChanged : 1;

    ZHM5IngameMessageBarManager* GetMessageBarManager();
    const SGameStateForUserFeedback* GetGameStateForUserFB();
    const ZGameTime* GetLastDisplayWeaponGroupInfo();
    const ZHM5TimerToOSDManager* GetTimerToOSDManager();
    const TArray<SGameplayInputControlBind>* GetGameplayInputControlBinds();
    TEntityRef<ZHitman5>* Hitman(TEntityRef<ZHitman5> * result);
    bool GameplayInputControlBindsChanged();
    void ClearGameplayInputControlBindsChanged();
    float GetHoldsTimer();
    bool GetHUDInventoryInfo_IsDirty();
    bool GetHUDInventoryInfoMKB_IsDirty();
    const UserFBInventoryInfoNamesp::SHUDInventoryInfo* GetHUDInventoryInfo();
    const UserFBInventoryInfoNamesp::HUDInventoryInfoMKB* GetHUDInventoryInfoMKB();
    //~ZUserFeedbackManager();
    void OnStop();
    void AddActivatedAction(ZHM5Action* const pAction, bool bAlternativeActivated);
    void UpdateActiveActions(int nActionCount, ZHM5Action** const pActionList);
    void GetActivePrompts(unsigned __int8* iCount, SPromptToDisplay * *pActivePrompts);
    void UpdateAIState(ZAIGameState* const pOldState, ZAIGameState* const pNewState);
    void HideAmmoPickup();
    void ChangeBindings(TArray<SGameplayInputControlBind> * bindingsToUpdate);
    void ClearIcons();
    const UserFBInventoryInfoNamesp::SHUDWeaponInfo* GetCurrentWeaponInfo();
    SVector3* ConvToScreenSpace(SVector3 * result, float4 * vWorldTrans, float fCamSpaceOffsetX, float fCamSpaceOffsetY, bool* bReject);
    void UpdateWeaponDisplay(unsigned __int16 nNumLoadedAmmoLeft, unsigned __int16 nNumLoadedAmmoRight, unsigned __int16 nNumReserveAmmo);
    void Initialize();
    void ShowTopAmmoPickup();
    void PushAmmoPickup(eAmmoType ammotype, ZString * sName, unsigned __int16 iAmmoPicked);
    void Update(SGameUpdateEvent * updateEvent);
    void ChangeHitmanInventoryInfo(bool bShowNoneSelected, bool bHolsterSelected, SInventoryChangeInfoMKB * pInventoryChangeInfoMKB);
    //ZUserFeedbackManager();
    void Reset();
    void OnStart(TEntityRef<ZHitman5> * pHitman);
};
