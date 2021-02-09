#pragma once

#include "ZNPCMorphemeNetworkController.h"
#include "EOrderCompletionStatus.h"

class ZAnimProgramBase
{
public:
    ZNPCMorphemeNetworkController* m_pController;
    ZAnimatedActor* m_pAnimatedActor;
    __int8 m_bPreventAiming : 1;
    __int8 m_bWillingToAim : 1;
    float m_timeOutOfAimingCone;

    virtual ~ZAnimProgramBase();
    virtual bool Update(float);
    virtual bool RequestTermination(bool);
    virtual void NotifyTermination();
    virtual EOrderCompletionStatus CompletionStatus();
    virtual void UpdateCollisionInfo();
    virtual void OnAnimationEvent(unsigned int, float);
};
