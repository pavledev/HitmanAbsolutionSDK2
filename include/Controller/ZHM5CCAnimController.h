#pragma once

#include "ZHM5CCAnimDatabase.h"
#include "ZActor.h"
#include "ZFindAnimPositions.h"
#include "ZFindAnimPositionsStairs.h"
#include "SAnimTime.h"
#include "ZHM5CCTargetController.h"
#include "HM5Utils.h"
#include "ZHM5CCEffects.h"

class ZHM5CCAnimController
{
    ZHM5CCAnimDatabase* m_pAnimDatabase;
    ZMorphemeNetworkInstance* m_pNetWork;
    unsigned int m_nNetworkIndex;
    TEntityRef<ZHitman5> m_pHitman;
    TEntityRef<ZActor> m_rActor;
    bool m_bAlignHitman;
    SMatrix m_mAlignStart;
    SMatrix m_mAlignEnd;
    SMatrix m_mAlignStartNPC;
    SMatrix m_mAlignEndNPC;
    const SAnimNodeHitman* m_pCurrentNode;
    alignas(16) ZFindAnimPositions m_FindAnimPositions;
    ZFindAnimPositions m_FindAnimPositionsRunTime;
    ZFindAnimPositionsStairs m_FindAnimPositionsStairs;
    SAnimTime m_aAnimTime[2];
    bool m_bFightOnStairs;
    ECCNodeSubtype m_eNodeSubtype;
    ZHM5CCTargetController* m_pTargetController;
    ZPathfinder2* m_pPathfinder;
    ZPF5Location m_StairLocation;
    bool m_bFirstAttack;
    bool m_bFakeAttack;
    float m_fBlendFraction;
    HM5Utils::SAnimBlend m_AnimBlendHitman;
    HM5Utils::SAnimBlend m_AnimBlendNPC;
    ZMapPoly m_MapPoly;
    ECCNodeType m_ePropBackNodeType;
    TEntityRef<ZHM5CCEffects> m_rEffects;
    bool m_bForceAlign;
    bool m_bCoverCornerTakeDown;
    SMatrix m_aBlendMats[6];
    HM5Utils::SAnimBlend m_aAnimBlends[6];
    bool m_bUseEarlyEndRagdoll;
    unsigned __int16 m_nAllowMask;
};
