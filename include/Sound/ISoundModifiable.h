#pragma once

#include "IComponentInterface.h"

class ISoundModifiable : public IComponentInterface
{
public:
    virtual float GetAttenuation();
    virtual void SetAttenuationGain(float);
    virtual float GetPitchShift();
    virtual void SetPitchShift(float);
};
