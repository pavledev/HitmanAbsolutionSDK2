#pragma once

#include "eItemType.h"
#include "STokenID.h"
#include "ZResourcePtr.h"
#include "TFixedArray.h"
#include "SInventoryChangeInfoMKB.h"
#include "ZString.h"
#include "eAmmoType.h"
#include "TArray.h"

class ZHM5BaseInventory;

namespace UserFBInventoryInfoNamesp
{
    enum EOperationMode
    {
        WEAPON_MODE_SEMI_AUTO = 0,
        WEAPON_MODE_FULL_AUTO = 1,
        WEAPON_MODE_SILENCED_SEMI_AUTO = 2,
        WEAPON_MODE_BURST_FIRE = 3,
        WEAPON_MODE_CLOSECOMBAT = 4,
        WEAPON_MODE_INVALID = 5
    };

    struct SHUDWeaponInfo
    {
        enum
        {
            OPERATION_MODES = 2
        };

        eItemType m_eItemType;
        STokenID m_pTokenID;
        ZResourcePtr m_pIcon;
        ZResourcePtr m_pSilencerIcon;
        unsigned short m_nClipSize;
        unsigned short m_nClipAmmo;
        unsigned short m_nTotalAmmo;
        float m_fSilencerPosX;
        float m_fSilencerPosY;
        bool m_bDualWield;
        EOperationMode m_eCurrentOperationMode;
        TFixedArray<EOperationMode, 2> m_eAvailableOperationModes;

        SHUDWeaponInfo(const SHUDWeaponInfo& __that);
        SHUDWeaponInfo() = default;
        ~SHUDWeaponInfo() = default;
        SHUDWeaponInfo& operator=(const SHUDWeaponInfo& __that);
    };

    struct SHUDWeaponGroup
    {
        enum
        {
            WEAPONS_PERGROUP = 5
        };

        TFixedArray<SHUDWeaponInfo, 5> m_aWeaponInfos;
        unsigned short n_selectedWeaponIndex;

        SHUDWeaponGroup() = default;
        ~SHUDWeaponGroup() = default;
    };

    struct SHUDInventoryInfo
    {
        TFixedArray<SHUDWeaponGroup, 4> m_aWeaponGroups;
        unsigned short n_selectedGroupIndex;
        bool m_bDirty;
        bool m_bNoneSelected;
        bool m_bHolsterSelected;

        SHUDInventoryInfo() = default;
        void Reset();
        ~SHUDInventoryInfo() = default;
    };

    struct HUDInventoryInfoMKB
    {
        TArray<SHUDWeaponInfo> m_Slots[7];
        unsigned int m_nActiveSlot[7];
        SInventoryChangeInfoMKB m_InventoryChangeInfo;
        bool m_bDirty;

        HUDInventoryInfoMKB() = default;
        void Sync(const SHUDInventoryInfo& weaponInventory, const SInventoryChangeInfoMKB* pInventoryChangeInfo, ZHM5BaseInventory* pInventory);
        unsigned int GetActiveSlotIdx(unsigned int nHolderIdx) const;
        unsigned int GetSlotCount(unsigned int nHolderIdx) const;
        SHUDWeaponInfo GetWeaponInfo(unsigned int nHolderIdx, unsigned int nSlotIdx) const;
        ~HUDInventoryInfoMKB() = default;
    };

    struct SHUDAmmoPickup
    {
        ZString m_sAmmoName;
        eAmmoType m_eAmmoType;
        unsigned short m_iAmmoPicked;
        bool m_bNew;

        SHUDAmmoPickup(const SHUDAmmoPickup& __that);
        SHUDAmmoPickup() = default;
        void Reset();
        ~SHUDAmmoPickup() = default;
        SHUDAmmoPickup& operator=(const SHUDAmmoPickup& __that);
    };
}
