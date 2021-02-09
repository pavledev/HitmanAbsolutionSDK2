#pragma once

#include "eItemType.h"
#include "STokenID.h"
#include "ZResourcePtr.h"
#include "UserFBInventoryInfoNamesp.h"

class alignas(4) SWeaponStatus
{
public:
    eItemType eRightHandItemType;
    STokenID pTokenID;
    ZResourcePtr pIcon;
    ZResourcePtr pSilencerIcon;
    __int16 nLoadedAmmoLeft;
    __int16 nLoadedAmmoRight;
    __int16 nReserveAmmo;
    __int16 nClipSize;
    float m_fSilencerPosX;
    float m_fSilencerPosY;
    UserFBInventoryInfoNamesp::EOperationMode eOperationMode;
    bool bHolstered;
    bool bDualWield;
    bool bSwitchedWeapon;
};
