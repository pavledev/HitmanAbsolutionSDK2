#pragma once

#include "ZHM5WeaponSet.h"
#include "TEntityRef.h"

class IHM5Item;

class ZInventorySlot
{
public:
	enum EInventorySlotType
	{
		eSilverBallerSlot = 0,
		eHandgunSlot = 1,
		eRevolverSlot = 2,
		eRifleSlot = 3,
		eSniperSlot = 4,
		eSmgSlot = 5,
		eShotgunSlot = 6,
		eFiberwireSlot = 7,
		eCCPropSlot = 8,
		eRemoteControlled = 9,
		eOther = 10
	};

	EInventorySlotType m_eSlotType;
	ZHM5WeaponSet m_WeaponSet;

	static void RegisterType();
	ZInventorySlot(const ZInventorySlot& __that);
	ZInventorySlot(EInventorySlotType eType);
	ZInventorySlot() = default;
	~ZInventorySlot() = default;
	void ClearSlot();
	void InsertItem(const TEntityRef<IHM5Item>& rItem, bool bIsBonusSlot);
	void RemoveItem(const TEntityRef<IHM5Item>& rItem);
	bool IsItemInSlot(const TEntityRef<IHM5Item>& rItem) const;
	void SetType(EInventorySlotType etype);
	bool IsEmpty() const;
	EInventorySlotType GetType() const;
	TEntityRef<IHM5Item> GetItem() const;
	ZHM5WeaponSet& GetWeaponSet();
	const ZHM5WeaponSet& GetWeaponSet() const;
	void GetItemsForStorage(TEntityRef<IHM5Item>& rRightHand, TEntityRef<IHM5Item>& rLeftHand);
	bool WeaponsHaveAmmoInClip() const;
	void SetSlotDualWieldMode(bool bVal);
	bool SlotInDualWieldMode() const;
	static bool IsCCRelated(EInventorySlotType type);
	bool IsCCRelated() const;
	ZInventorySlot& operator=(const ZInventorySlot& __that);
};
