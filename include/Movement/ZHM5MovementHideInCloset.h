#pragma once

#include "ZHM5BaseMovement.h"
#include "ZMovementAnimNode.h"
#include "ZHM5Closet.h"
#include "EClosetType.h"
#include "ZMovementAnimTransition.h"

class alignas(16) ZHM5MovementHideInCloset : public ZHM5BaseMovement
{
public:
    enum EState : __int32
    {
        eStateNone = 0x0,
        eStateStart = 0x1,
        eStateEntering = 0x2,
        eStateInside = 0x3,
        eStateExitingPending = 0x4,
        eStateExitingNormal = 0x5,
    } m_eState;

    ZMovementAnimNode* m_pCurrentAnim;
    TEntityRef<ZHM5Closet> m_rCloset;
    float m_fCameraPeekPrc;
    float m_fEarlyExitFraction;
    EClosetType m_eCurrentClosetType;
    unsigned int m_nClosetRootNodeID[3];
    ZMovementAnimNode m_AnimEnter[3];
    ZMovementAnimNode m_AnimInside[3];
    ZMovementAnimNode m_AnimExit[3];
    ZMovementAnimTransition m_TransEnter[3];
    ZMovementAnimTransition m_TransExit[3];
    __int8 m_bExitAlignmentStarted : 1;
    __int8 m_bForceResetCamera : 1;
    SMatrix m_mvStartPos;
    SMatrix m_mvDestPos;
    SMatrix m_mvHitmanInside;
    HM5Utils::SAnimBlend m_sAnimBlend;
    SCameraUpdateEvent m_StartCameraEvent;
    ZGameTime m_TimeSpentInCloset;
};
