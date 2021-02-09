#pragma once

#include "TArray.h"
#include "TEntityRef.h"
#include "ZHM5Action.h"
#include "IHM5ItemWeapon.h"
#include "ZHM5ActionClientRayCaster.h"

class ZHitman5;

class alignas(4) ZHM5ActionClient
{
public:
    TArray<TEntityRef<ZHM5Action>> m_aCreatedActions;
    TArray<TEntityRef<IHM5ItemWeapon>> m_AmmoCollectorWeapons;
    ZHM5ActionClientRayCaster m_RayCaster;
    ZHM5Action* m_pActiveActions[5];
    ZHM5Action* m_pPersistentActions[3];
    ZHM5Action* m_pFarActions[8];
    TEntityRef<ZHitman5> m_pHitman;
    unsigned int m_nActionFilter[3];
    unsigned int m_iFarFeedbackPrompts;
    unsigned int m_iActiveActionsCount;
    bool m_bUseablePropAvailable;

    enum eActionGroup : __int32
    {
        eAG_General = 0x0,
        eAG_Pickup = 0x1,
        eAG_DeadBody = 0x2,
        eAG_Disguise = 0x3,
        eAG_Automatic = 0x4,
        eAG_NUM = 0x5
    };

    enum ePersistentActions : __int32
    {
        ePersAct_DisguiseFromActor = 0x0,
        ePersAct_ContextSensitive = 0x1,
        ePersAct_DragBody = 0x2,
        ePersAct_NUM = 0x3
    };

    enum UnkEnum : __int32
    {
        MAX_NON_PICKUPS = 0x20,
        MAX_PICKUPS = 0x20,
        MAX_FAR_ACTIONS = 0x8
    };

    enum EActionFilterReason : __int32
    {
        eAFR_Movement = 0x0,
        eAFR_Instinct = 0x1,
        eAFR_ItemHandling = 0x2,
        eAFR_NUM = 0x3
    };
};
