#pragma once

#include "ZString.h"

class IAnimPlayerEntity
{
public:
    virtual bool ContainsAnimation(const ZString*);
    virtual bool RequestAnimationByName(const ZString*);
    virtual void SetIsPlaying(bool);
    virtual void SetTrajectoryFlag(bool);
    virtual void SetTime(float);
    virtual float GetDuration();
    virtual void ResetTime();
    virtual ~IAnimPlayerEntity();
};
