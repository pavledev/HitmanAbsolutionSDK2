#pragma once

#include "ZHM5BaseMovement.h"
#include "ZActor.h"
#include "ECCLeeState.h"

class ZHM5MovementCarryCivilian : public ZHM5BaseMovement
{
public:
    TEntityRef<ZActor> m_pCarryCivilianVictim;
    TEntityRef<ZCrowdActor> m_pCrowdActorTarget;
    unsigned int m_nStrafeStateIDs[4];
    unsigned int m_nCarryCivilianStateMachineID;
    ECCLeeState m_eCarryCivilianState;
    float m_fRawInputX;
    float m_fRawInputY;
    float m_fInputX;
    float m_fInputY;
    float m_fInputVelocity;
    SInputRestriction m_InputRestriction;
};
