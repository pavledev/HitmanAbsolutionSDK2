#pragma once

#include "TArray.h"
#include "TEntityRef.h"
#include "IHM5Item.h"
#include "SInventoryChangeInfoMKB.h"
#include "ZInventorySlot.h"
#include "ZHM5WeaponSet.h"
#include "TFixedArray.h"
#include "ZEvent.h"

class ZHitman5;
class IHM5ItemAmmo;
class IHM5ItemWeapon;
class ZEventNull;

class ZHM5BaseInventory
{
public:
	enum EWeaponGroupType
	{
		WEAPON_GROUP_CLOSE_COMBAT = 0,
		WEAPON_GROUP_SHORT_RANGE = 1,
		WEAPON_GROUP_HOLSTER = 2,
		WEAPON_GROUP_LONG_RANGE = 3,
		WEAPON_GROUP_NUM = 4,
		WEAPON_GROUP_SILVERBALLERS = 5,
		WEAPON_GROUP_FIBREWIRE = 6,
		WEAPON_GROUP_IMPROVISED = 7,
		WEAPON_GROUP_HEAVY = 8,
		WEAPON_GROUP_HANDGUNS = 9,
		WEAPON_GROUP_REMOTE = 10,
		WEAPON_GROUP_SNIPER = 11
	};

	enum EStoreItemsReason
	{
		eStoreItem_PlayerHolster = 1,
		eStoreItem_MovementContext = 2,
		eStoreItem_LevelSetup = 4
	};

	struct SInventorySlotPref
	{
		ZInventorySlot::EInventorySlotType m_eSlotType;
		bool m_bDualWielded;

		SInventorySlotPref(ZInventorySlot::EInventorySlotType type, bool bdual);
		SInventorySlotPref() = default;
		void Set(ZInventorySlot::EInventorySlotType type, bool bdual);
	};

	struct SStoredSlotData
	{
		ZInventorySlot* m_pStoredInventorySlot;
		unsigned char m_iStoreReason;

		union 
		{
			unsigned char unionInt;

			struct 
			{
				bool m_bItemsStored : 1;
				bool m_bRestoreItems : 1;
				bool m_bSignalWeaponSoundManager : 1;
				bool m_bPlayEquipAnimation : 1;
			};
		};

		void Reset();
	};

	TArray<TEntityRef<IHM5Item>> m_Items;
	TArray<TEntityRef<IHM5Item>> m_RemoteControlledItems;
	unsigned int m_nAmmoInPocket[8];
	SStoredSlotData m_StoredSlot;
	ZInventorySlot m_WeaponSlots[10];
	ZInventorySlot* m_pEquippedInventorySlot;
	ZInventorySlot* m_pShootingBalletCandidateSlot;
	SInventorySlotPref m_SelectedSlot;
	ZInventorySlot::EInventorySlotType m_eLastEquippedSlot;
	ZInventorySlot::EInventorySlotType m_eDualSlotWhenDisabled;
	ZInventorySlot::EInventorySlotType m_eSlotBonusWeapon;

	union 
	{
		unsigned short unionInt;

		struct 
		{
			bool m_bItemSelect : 1;
			bool m_bLoadOutChanged : 1;
			bool m_bActivatingHolster : 1;
			bool m_bDisableHolsterInput : 1;
			bool m_bDualWieldingEnabled : 1;
			bool m_bHolsterSelected : 1;
			bool m_bCheckBonusWeapon : 1;
			bool m_bFirstWeaponSelected : 1;
			bool m_bItemHandlingSet : 1;
		};
	};

	bool m_bUseSelectionConfirmation;
	TEntityRef<ZHitman5> m_pHitman;
	ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_EquipedInventorySlotChangedEvent;
	bool m_bPCRetail;
	bool m_bPCWeaponSelectorEnabled;
	SInventoryChangeInfoMKB m_InventoryChangeInfoMKB;
	bool m_bUnholsteringStoredSlot;
	unsigned int m_nSelectedHolderSlot[7];

	static SInventorySlotPref s_eWeaponGroupShortRange[0];
	static SInventorySlotPref s_eWeaponGroupCloseCombat[0];
	static SInventorySlotPref s_eWeaponGroupLongRange[0];
	static SInventorySlotPref s_eWeaponGroupSilverBallers[0];
	static SInventorySlotPref s_eWeaponGroupFibrewire[0];
	static SInventorySlotPref s_eWeaponGroupImprovised[0];
	static SInventorySlotPref s_eWeaponGroupHeavy[0];
	static SInventorySlotPref s_eWeaponGroupHandguns[0];
	static SInventorySlotPref s_eWeaponGroupRemote[0];
	static SInventorySlotPref s_eWeaponGroupSniper[0];
	static SInventorySlotPref s_eQuickSwapPreferences[0];
	static SInventorySlotPref s_eShootingBalletPreferences[0];
	static SInventorySlotPref s_eCommonAmmoPistols[0];
	static ZHM5WeaponSet s_EmptyWeaponSet;

	ZHM5BaseInventory() = default;
	ZHM5BaseInventory(const TEntityRef<ZHitman5>& pHitman);
	~ZHM5BaseInventory() = default;
	const unsigned int* GetSelectedHolderSlots() const;
	bool IsSelectingWeapon() const;
	ZInventorySlot::EInventorySlotType GetActiveSlotType(bool& bInDualWieldMode) const;
	bool IsWaitingForSelectionConfirmation() const;
	static const void GetWeaponGroup(const EWeaponGroupType type, const SInventorySlotPref*& pResult, int& iResultSize);
	bool IsWeaponSlotEmpty(ZInventorySlot::EInventorySlotType eSlotType) const;
	bool IsWeaponSlotEmpty(const TEntityRef<IHM5ItemWeapon>& rWeapon) const;
	TEntityRef<IHM5Item> GetSwapForItem(const TEntityRef<IHM5Item>& rItemToCheck, bool bNoDualWieldCheck) const;
	ZInventorySlot* AddItemToInventory(const TEntityRef<IHM5Item>& rItem, bool bAddInitialBullets, bool bDisableHUD);
	void AddItemToInventorySlot(const TEntityRef<IHM5Item>& rItem, ZInventorySlot::EInventorySlotType eSlot);
	void EnableItemSelect(bool bItemSelect);
	void SetCanDualWield(bool bVal);
	void DisableHolsterInput(bool bDisableHolsterInput);
	TEntityRef<IHM5Item> GetItemFromInventory(eItemType eType);
	bool IsThereRoomInInventoryForItem(const TEntityRef<IHM5Item>& rCandidateItem);
	void TransferAmmoToWeapon(const TEntityRef<IHM5ItemWeapon>& rWeapon, unsigned int iMaxToTransfer);
	void TransferAmmoToWeapons(const TEntityRef<IHM5ItemWeapon>& rRHWeapon, const TEntityRef<IHM5ItemWeapon>& rLHWeapon, unsigned int iMaxToTransfer);
	unsigned int GetTotalAmmoForWeapon(const TEntityRef<IHM5ItemWeapon>& rWeapon);
	unsigned int GetTotalAmmoForSlot(const ZInventorySlot* pSlot);
	void TransferAmmoFromItem(const TEntityRef<IHM5Item>& rItem, bool bSignalHUD);
	void DistributeDualAmmo(const TEntityRef<IHM5ItemWeapon>& rRHWeapon, const TEntityRef<IHM5ItemWeapon>& rLHWeapon);
	void SetNumOfAmmoForWeapon(const TEntityRef<IHM5ItemWeapon>& rWeapon, unsigned int nNumAmmo);
	void UpdateInitialBullets(const TEntityRef<IHM5ItemWeapon>& rWeapon);
	void GetAllInventoryItems(TArray<TEntityRef<IHM5Item>>& arrResults);
	void GetAmmoInPocket(TFixedArray<unsigned int, 8>& nAmmoInPocket);
	void SetAmmoInPocket(TFixedArray<unsigned int, 8>& nAmmoInPocket);
	void StoreItems(EStoreItemsReason eReason);
	void RestoreItems(EStoreItemsReason eReason);
	ZInventorySlot::EInventorySlotType GetInventorySlotTypeFromWeapon(const TEntityRef<IHM5ItemWeapon>& rWeapon) const;
	const ZInventorySlot* GetInventorySlotFromType(ZInventorySlot::EInventorySlotType eType) const;
	ZInventorySlot* GetInventorySlotFromType(ZInventorySlot::EInventorySlotType eType);
	const ZInventorySlot* GetInventorySlotFromWeapon(const TEntityRef<IHM5ItemWeapon>& rWeapon) const;
	ZInventorySlot* GetInventorySlotFromWeapon(const TEntityRef<IHM5ItemWeapon>& rWeapon);
	bool OnPickupItem(const TEntityRef<IHM5Item>& rItem);
	TEntityRef<IHM5Item> GetEquippedItem() const;
	const ZHM5WeaponSet& GetEquippedWeaponSet() const;
	const ZHM5WeaponSet& GetSelectedWeaponSet(bool& bSelectedInDualMode) const;
	void OnDropItem(const TEntityRef<IHM5Item> rItem, bool bDestroyed);
	void OnThrowItem(const TEntityRef<IHM5Item> rItem);
	void InitInventory();
	void Update();
	void UpdateHUD();
	void DeactivateCheckPoint();
	void CheckpointRestore(int iSelectedSlot, bool bWasDual, bool bUnholster);
	void RemoveItemFromInventory(const TEntityRef<IHM5Item>& rItem);
	void DropItemsInInventorySlot(ZInventorySlot& Slot, bool bHideItems);
	void DropItemsInInventorySlot(ZInventorySlot::EInventorySlotType eType);
	void DropItemsFromBonusInventorySlot();
	bool AttemptUnHolster(ZInventorySlot::EInventorySlotType eSlotType, bool bAttemptDual, bool bSignalWeaponSoundManager);
	void UnHolster(ZInventorySlot* pSlot, bool bSignalWeaponSoundManager, bool bPlayEquipAnimation);
	void HolsterCurrentSlot(bool bSignalWeaponSoundManager);
	void SetSelectedHolderSlot(ZInventorySlot* pSlot);
	bool HasStoredItem() const;
	bool IsReadyForShootingBallet();
	void UnHolsterForShootingBallet();
	void RestoreAfterShootingBallet();
	bool IsHitmanArmed() const;
	void UpdateShootingBalletCandidate();
	bool CurrentHasAmmoInClip() const;
	ZInventorySlot::EInventorySlotType GetSelectedSlotType() const;
	ZInventorySlot::EInventorySlotType GetSelectedSlotType(bool& bInDualWieldMode) const;
	ZInventorySlot* GetSelectedSlot();
	ZInventorySlot::EInventorySlotType GetSlotTypeForHUD(bool& bInDualWieldMode) const;
	void UpdateEquippedInventorySlot();
	bool IsActivatingHolster() const;
	bool CurrentCanBeDropped() const;
	void AddRemoteControlledProp(const TEntityRef<IHM5Item>& rItem);
	void RemoveFromRemoteControlledProps(const TEntityRef<IHM5Item>& rItem);
	bool ValidPickOrSwap(const TEntityRef<IHM5Item>& rItem) const;
	bool QuickSwap(bool bFirearmsOnly);
	bool ShouldDisplayGreyPickup() const;
	void SetBonusInventorySlotFromWeapon(const TEntityRef<IHM5ItemWeapon>& rWeapon);
	void CheckBonusWeapon();
	ZInventorySlot::EInventorySlotType GetBonusWeaponSlotType() const;
	ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull>& GetEquipedInventorySlotChangedEvent();
	void InventoryLoadOutChanged();
	void AttemptAmmoShareOnCurrentSlot();
	TEntityRef<ZHitman5> Hitman() const;
	void AmmoShare(ZInventorySlot* pSlot);
	void ActivateDetonatorEffects(bool bTurnOn);
	void DetonatorPlace();
	void DetonatorRemove();
	void TakeAmmoFromPistols(unsigned int iMaxAmmoToTake);
	void DualWieldingEnabledChanged();
	bool IsDropItemAllowed(ZInventorySlot* pInventorySlot) const;
	ZInventorySlot* FindQuickSwapCandidate(bool bFirearmsOnly);
	bool FindQuickSwapCandidate_Validate(ZInventorySlot* pSlot, bool bFirearmsOnly) const;
	void SetEquippedInventorySlot(ZInventorySlot* const pNewSlot);
	void SetSelectedInventorySlot(ZInventorySlot::EInventorySlotType type, bool bDualWield);
	void SendAmmoPickupMetrics(const TEntityRef<IHM5ItemAmmo>& rItemAmmo);
	void HandleEquipCommand(const EWeaponGroupType eEquiptToggleType);
	void HandleEquipCycleCommand(bool bForward);
	void HandleEquipCommand_Store(ZInventorySlot* pInventorySlot, bool bDualWield);
	ZInventorySlot* EquipCommandEvaluateSlot(ZInventorySlot::EInventorySlotType eCandidateType, ZInventorySlot::EInventorySlotType eOldSelectedSlot, bool bDualWield);
};
