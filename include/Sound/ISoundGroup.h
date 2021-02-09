#pragma once

#include "ZString.h"
#include "float4.h"

class ISoundGroup
{
public:
    virtual ~ISoundGroup();
    virtual const ZString* GetGroupName();
    virtual struct ZSoundGroupInternal* GetSoundGroupInternal();
    virtual bool AcceptsNewTarget(int, const float4*);
};
