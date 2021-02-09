#pragma once

#include "ISoundModifiable.h"
#include "ISoundEffectAttachable.h"

class ISoundChannelGroup : public ISoundModifiable, public ISoundEffectAttachable
{
public:
    virtual FMOD::ChannelGroup* GetFMODChannelGroup();
    virtual const ZString* GetGroupName();
    virtual void SetConfigAttenuation(float);
    virtual void SetAudibilityWeight(float);
};
