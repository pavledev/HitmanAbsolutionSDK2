#pragma once

#include "ZHM5LocomotionState.h"
#include "ETurnToMoveDataState.h"
#include "STurnToMoveData.h"
#include "ZString.h"

class alignas(8) ZHM5LocomotionTurnToMoveState : public ZHM5LocomotionState
{
public:
    ETurnToMoveDataState m_eSelectedState;
    float m_fAnimFraction;
    float m_fRotationScale;
    STurnToMoveData m_TurnToMoveData;

    virtual void FindTurnOnSpotData(const ZString*);
};
