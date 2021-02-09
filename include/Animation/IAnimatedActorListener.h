#pragma once

class IAnimatedActorListener
{
public:
    virtual ~IAnimatedActorListener();
    virtual void OnMoveStart();
    virtual void OnMove();
    virtual void OnMoveStopping();
    virtual void OnStanding();
    virtual void OnActStart();
    virtual void OnActInFullbody();
    virtual void OnActEnteredLoop();
    virtual void OnActStopping();
    virtual void OnReactionStart();
    virtual void OnReactionStopping();
    virtual void OnOrderCompleted();
};
