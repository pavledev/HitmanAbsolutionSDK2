#pragma once

#include "IComponentInterface.h"
#include "ZSharedPointerTarget.h"
#include "EActorAnimationStatusUpdate.h"

class ZActorAnimationState;

class ZActorAnimationProgram : public IComponentInterface, public ZSharedPointerTarget
{
public:
    ZActorAnimationState* m_pState;
    bool m_bCompleted;
    float m_fLogTimer;
    ZMorphemeNetworkInstance* m_pNetwork;
    unsigned int nodeControlled;
    unsigned int nodeHumanShield;
    unsigned int nodeHumanShieldMove;
    unsigned int nodeHumanShieldMoveForward;
    unsigned int nodeHumanShieldMoveBackward;
    unsigned int nodeHumanShieldMoveLeft;
    unsigned int nodeHumanShieldMoveRight;
    unsigned int nodeHumanShieldIdle;
    unsigned int nodeCarryCivilian;
    unsigned int nodeCarryCivilianMove;
    unsigned int nodeCarryCivilianMoveForward;
    unsigned int nodeCarryCivilianMoveBackward;
    unsigned int nodeCarryCivilianMoveLeft;
    unsigned int nodeCarryCivilianMoveRight;
    unsigned int nodeCarryCivilianIdle;
    unsigned int nodeHumanShieldExit;
    unsigned int nodeHumanShieldExitKill;
    unsigned int paramAnimPrct;
    unsigned int paramCloseCombatBlend;
    unsigned int paramCloseCombatBossBlend;
    unsigned int paramCloseCombatFraction1;
    unsigned int paramCloseCombatFraction2;
    unsigned int paramControlled;
    unsigned int requestHumanShieldMove;
    unsigned int requestHumanShieldStop;
    unsigned int requestHumanShieldForward;
    unsigned int requestHumanShieldBackward;
    unsigned int requestHumanShieldLeft;
    unsigned int requestHumanShieldRight;
    unsigned int requestHumanShieldKnockOutVictim;
    unsigned int requestHumanShieldKillVictim;
    unsigned int requestCarryCivilianMove;
    unsigned int requestCarryCivilianIdle;
    unsigned int requestCarryCivilianForward;
    unsigned int requestCarryCivilianBackward;
    unsigned int requestCarryCivilianLeft;
    unsigned int requestCarryCivilianRight;

    virtual void OnComplete();
    virtual void OnAnimationEvents(const MR::TriggeredEventsBuffer*);
    virtual EActorAnimationStatusUpdate Update(float);
    virtual ZString* GetDebugName(ZString* result);
};
