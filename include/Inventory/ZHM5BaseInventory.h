#pragma once

#include "TArray.h"
#include "TEntityRef.h"
#include "IHM5Item.h"
#include "SStoredSlotData.h"
#include "SInventorySlotPref.h"
#include "EInventorySlotType.h"
#include "SInventoryChangeInfoMKB.h"

class ZHitman5;

class alignas(4) ZHM5BaseInventory
{
public:
    TArray<TEntityRef<IHM5Item>> m_Items;
    TArray<TEntityRef<IHM5Item>> m_RemoteControlledItems;
    unsigned int m_nAmmoInPocket[8];
    SStoredSlotData m_StoredSlot;
    ZInventorySlot m_WeaponSlots[10];
    ZInventorySlot* m_pEquippedInventorySlot;
    ZInventorySlot* m_pShootingBalletCandidateSlot;
    SInventorySlotPref m_SelectedSlot;
    EInventorySlotType m_eLastEquippedSlot;
    EInventorySlotType m_eDualSlotWhenDisabled;
    EInventorySlotType m_eSlotBonusWeapon;

    union
    {
        unsigned __int16 unionInt;
        
        struct
        {
            __int8 m_bItemSelect : 1;
            __int8 m_bLoadOutChanged : 1;
            __int8 m_bActivatingHolster : 1;
            __int8 m_bDisableHolsterInput : 1;
            __int8 m_bDualWieldingEnabled : 1;
            __int8 m_bHolsterSelected : 1;
            __int8 m_bCheckBonusWeapon : 1;
            __int8 m_bFirstWeaponSelected : 1;
            __int8 m_bItemHandlingSet : 1;
        };
    };

    bool m_bUseSelectionConfirmation;
    alignas(4) TEntityRef<ZHitman5> m_pHitman;
    ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_EquipedInventorySlotChangedEvent;
    bool m_bPCRetail;
    bool m_bPCWeaponSelectorEnabled;
    SInventoryChangeInfoMKB m_InventoryChangeInfoMKB;
    bool m_bUnholsteringStoredSlot;
    alignas(4) unsigned int m_nSelectedHolderSlot[7];

    enum EWeaponGroupType : __int32
    {
        WEAPON_GROUP_CLOSE_COMBAT = 0x0,
        WEAPON_GROUP_SHORT_RANGE = 0x1,
        WEAPON_GROUP_HOLSTER = 0x2,
        WEAPON_GROUP_LONG_RANGE = 0x3,
        WEAPON_GROUP_NUM = 0x4,
        WEAPON_GROUP_SILVERBALLERS = 0x5,
        WEAPON_GROUP_FIBREWIRE = 0x6,
        WEAPON_GROUP_IMPROVISED = 0x7,
        WEAPON_GROUP_HEAVY = 0x8,
        WEAPON_GROUP_HANDGUNS = 0x9,
        WEAPON_GROUP_REMOTE = 0xA,
        WEAPON_GROUP_SNIPER = 0xB
    };

    enum EStoreItemsReason : __int32
    {
        eStoreItem_PlayerHolster = 0x1,
        eStoreItem_MovementContext = 0x2,
        eStoreItem_LevelSetup = 0x4
    };
};
