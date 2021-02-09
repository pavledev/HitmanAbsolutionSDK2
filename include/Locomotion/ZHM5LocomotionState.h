#pragma once

#include "ZGameTime.h"
#include "ENetworkState.h"

class ZHM5LocomotionState
{
public:
    alignas(8) unsigned int m_nStateNodeID;
    ZGameTime m_TimeInState;
    bool m_bTransitionIn;
    bool m_bTransitionOut;
    bool m_bActive;
    float m_fTransitFraction;
    bool m_bCanSendRequestsDuringTransitionIn;
    bool m_bCanSendRequestsDuringTransitionOut;
    ENetworkState m_eStateType;
    float m_fBankWeightTarget;
    float m_fBankWeight;
    float m_fRemappedBankWeight;

    virtual ~ZHM5LocomotionState();
    virtual void Init(ENetworkState);
    virtual void Activate();
    virtual void Update(float);
    virtual void Deactivate();
};
