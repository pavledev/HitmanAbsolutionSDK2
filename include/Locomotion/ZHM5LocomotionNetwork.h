#pragma once

#include "ZHM5LocomotionState.h"
#include "ZHM5LocomotionIdleState.h"
#include "ZHM5LocomotionToMoveState.h"
#include "ZHM5LocomotionTurnToMoveState.h"
#include "ZHM5LocomotionMoveState.h"
#include "ZHM5LocomotionTurnState.h"
#include "ZHM5LocomotionStrafeStandState.h"
#include "ZHM5LocomotionStrafeState.h"
#include "ZHM5LocomotionStandRootState.h"
#include "ZHM5LocomotionMoveRootState.h"
#include "ZHM5LocomotionRootState.h"
#include "ZHM5LocomotionStrafeRootState.h"
#include "ZVariant.h"

class ZHM5LocomotionNetwork
{
public:
    ZHM5LocomotionState* m_apnNetworkState[18];
    ZHM5LocomotionState* m_apnStatesToDeactivate[18];
    ZHM5LocomotionState* m_apnStatesToActivate[18];
    ZHM5LocomotionState* m_apnStatesToUpdate[18];
    unsigned int m_nStatesToDeactivate;
    unsigned int m_nStatesToActivate;
    unsigned int m_nStatesToUpdate;
    ZHM5LocomotionIdleState m_IdleState;
    ZHM5LocomotionToMoveState m_ToMoveState;
    ZHM5LocomotionTurnToMoveState m_TurnToMoveLeftState45;
    ZHM5LocomotionTurnToMoveState m_TurnToMoveRightState45;
    ZHM5LocomotionTurnToMoveState m_TurnToMoveLeftState135;
    ZHM5LocomotionTurnToMoveState m_TurnToMoveRightState135;
    ZHM5LocomotionMoveState m_NormalMoveState;
    ZHM5LocomotionState m_ToStandState;
    ZHM5LocomotionTurnState m_TurnState;
    ZHM5LocomotionTurnState m_TurnState1;
    ZHM5LocomotionState m_IdleAnimation;
    ZHM5LocomotionStrafeStandState m_StrafeStand;
    ZHM5LocomotionStrafeState m_StrafeFoward;
    ZHM5LocomotionStrafeState m_StrafeBackward;
    ZHM5LocomotionStandRootState m_StandRootState;
    ZHM5LocomotionMoveRootState m_MoveRootState;
    ZHM5LocomotionRootState m_LocomotionRoot;
    ZHM5LocomotionStrafeRootState m_LocomotionStrafeRoot;
    ZMorphemeNetworkInstance* m_pNetwork;
    ZString m_sLocomotionPath;
    unsigned int m_nNodeIdRoot;
    unsigned int m_nNodeIdLocomotionRoot;
    unsigned int m_nNodeIdStrafeRoot;
    unsigned int m_anRequest[18];
    unsigned int m_anControlParameters[32];
    bool m_bFootStepEventTriggered;
    float m_fCharAngle;
    float m_fDeltaAngle;
    float m_fHeadAngle;
    bool m_bIdleAnimationsAllowed;
    unsigned int m_nRequestsSend;
    ZVariant m_aInitialControlParamValues[32];
};
