#pragma once

#include "ZMenuSystem.h"
#include "EMenuId.h"
#include "ZPCOptionsHelper.h"
#include "TSet.h"
#include "STokenID.h"
#include "EMenuActionId.h"
#include "ZGameWideUI.h"
#include "ELevelIndex.h"
#include "EUIDialog.h"
#include "TMap.h"
#include "ZString.h"

class IScaleformExternalInterfaceArguments;
class ZMenuItem;
class ZMenuSpinnerItem;
class ZVariant;

class ZHUDMenuSystem : public ZMenuSystem
{
public:
	EMenuId m_eCurrentMenuId;
	int m_nPreviousDifficulty;
	bool m_bEditedContractTitle;
	bool m_bEditedContractDescription;
	ZString m_sContractCompetitionFriends;
	int m_iContractCompetitionAllow;
	int m_iContractCompetitionDuration;
	ZPCOptionsHelper m_PCOptionsHelper;
	bool m_bChangesDialogActive;
	bool m_bPCRetail;
	bool m_bButtonMappingSubmenu;
	ZMenuSpinnerItem* m_pWeaponSelectionSpinner;
	TSet<STokenID> m_aInitialItems;

	~ZHUDMenuSystem() override = default;
	void Setup() override;
	void Shutdown() override;
	void OnAction(IScaleformExternalInterfaceArguments& params) override;
	TMap<ZString, ZVariant> GetMenuInfoMap(IScaleformExternalInterfaceArguments& params) override;
	virtual void OnPCEvent(IScaleformExternalInterfaceArguments& params);
	virtual ZPCOptionsHelper& GetPCOptionsHelper();

	ZHUDMenuSystem() = default;
	void OnWaitForAsyncSaveStateComplete(EMenuActionId eAction);
	void CollectPauseMenuItems(TMap<ZString, ZVariant>& pInfo);
	void CollectObjectiveItems(TMap<ZString, ZVariant>& pInfo);
	void CollectContractBriefing(TMap<ZString, ZVariant>& pInfo);
	void CollectInventoryItems(TMap<ZString, ZVariant>& pInfo);
	void CollectContractItems(TMap<ZString, ZVariant>& pInfo);
	void CollectRatingItems(TMap<ZString, ZVariant>& pInfo);
	void CollectScoreForCheckpoint(ELevelIndex lvl, int cp, TMap<ZString, ZVariant>& pInfo, bool loadImages);
	void CollectScoreItems(TMap<ZString, ZVariant>& pInfo);
	void CollectChallengeItems(TMap<ZString, ZVariant>& pInfo);
	void CollectContractCreatorItems(TMap<ZString, ZVariant>& pInfo);
	void CollectContractCreatorEditItems(TMap<ZString, ZVariant>& pInfo);
	void CollectContractPlayerItems(TMap<ZString, ZVariant>& pInfo);
	void CollectContractLeaderboardItems(TMap<ZString, ZVariant>& pInfo);
	void CollectLevelEndItems(TMap<ZString, ZVariant>& pInfo);
	void CollectLevelEndLeaderboardItems(TMap<ZString, ZVariant>& pInfo);
	void CollectLevelEndUnlockItems(TMap<ZString, ZVariant>& pInfo);
	void DialogCallback(ZGameWideUI::EDialogContext eContext, EUIDialog eDialog, ZGameWideUI::EDialogResult eResult);
	EMenuId GetCurrentMenuId() const;
	void AddInitialItem(const STokenID& tokenID);
	void RemoveInitialItem(const STokenID& tokenID);
	bool IsInitialItem(const STokenID& tokenID) const;
	void ClearInitialItems();
	void SetPreviousDifficulty(int nPreviousDifficulty);
	void CollectInventoryUnlocks(TMap<ZString, ZVariant>& pInfo, int eLevelIndex, int cp);
	void CollectLevelEndScreenUnlocks(TMap<ZString, ZVariant>& pInfo, int eLevelIndex, int cp, int* count_pickedup, int* count_total);
	void TitleCallback(bool bSuccess, const ZString& sTitle, void* pData);
	void DescriptionCallback(bool bSuccess, const ZString& sDescription, void* pData);
	void TagScoreItem(ZMenuItem* pItem, TMap<ZString, ZVariant>& pInfo);
	void TagChallengesItem(ZMenuItem* pItem, TMap<ZString, ZVariant>& pInfo);
	void InitializeMenuItems();
};
