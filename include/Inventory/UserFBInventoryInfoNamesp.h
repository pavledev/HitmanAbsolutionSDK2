#pragma once

#include "eItemType.h"
#include "STokenID.h"
#include "ZResourcePtr.h"
#include "TFixedArray.h"
#include "SInventoryChangeInfoMKB.h"
#include "ZString.h"
#include "eAmmoType.h"

namespace UserFBInventoryInfoNamesp
{
    enum EOperationMode : __int32
    {
        WEAPON_MODE_SEMI_AUTO = 0x0,
        WEAPON_MODE_FULL_AUTO = 0x1,
        WEAPON_MODE_SILENCED_SEMI_AUTO = 0x2,
        WEAPON_MODE_BURST_FIRE = 0x3,
        WEAPON_MODE_CLOSECOMBAT = 0x4,
        WEAPON_MODE_INVALID = 0x5
    };

    class SHUDWeaponInfo
    {
    public:
        eItemType m_eItemType;
        STokenID m_pTokenID;
        ZResourcePtr m_pIcon;
        ZResourcePtr m_pSilencerIcon;
        unsigned __int16 m_nClipSize;
        unsigned __int16 m_nClipAmmo;
        unsigned __int16 m_nTotalAmmo;
        float m_fSilencerPosX;
        float m_fSilencerPosY;
        bool m_bDualWield;
        UserFBInventoryInfoNamesp::EOperationMode m_eCurrentOperationMode;
        TFixedArray<enum UserFBInventoryInfoNamesp::EOperationMode, 2> m_eAvailableOperationModes;

        enum
        {
            OPERATION_MODES = 0x2
        };
    };

    class alignas(4) SHUDWeaponGroup
    {
    public:
        TFixedArray<SHUDWeaponInfo, 5> m_aWeaponInfos;
        unsigned __int16 n_selectedWeaponIndex;

        enum
        {
            WEAPONS_PERGROUP = 0x5
        };
    };

    class alignas(4) SHUDInventoryInfo
    {
    public:
        TFixedArray<SHUDWeaponGroup, 4> m_aWeaponGroups;
        unsigned __int16 n_selectedGroupIndex;
        bool m_bDirty;
        bool m_bNoneSelected;
        bool m_bHolsterSelected;
    };

    class HUDInventoryInfoMKB
    {
    public:
        TArray<SHUDWeaponInfo> m_Slots[7];
        unsigned int m_nActiveSlot[7];
        SInventoryChangeInfoMKB m_InventoryChangeInfo;
        bool m_bDirty;
    };

    class alignas(4) SHUDAmmoPickup
    {
    public:
        ZString m_sAmmoName;
        eAmmoType m_eAmmoType;
        unsigned __int16 m_iAmmoPicked;
        bool m_bNew;
    };
}
