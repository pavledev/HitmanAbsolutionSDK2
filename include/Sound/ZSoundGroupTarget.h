#pragma once

#include "float4.h"
#include "ZGameTime.h"
#include "ZString.h"

class ZSoundGroupTarget
{
public:
    struct ZSoundGroupInternal* m_pSoundGroupInternal;
    bool m_bMutedBySoundGroup;
    float m_fSoundGroupFadeLevel;
    float m_fSoundGroupFadeDelta;

    virtual ~ZSoundGroupTarget();
    virtual int GetPriority();
    virtual float GetAudibility(bool);
    virtual float GetSquaredDistanceToListener(const float4*);
    virtual ZGameTime* GetTimestamp(ZGameTime* result);
    virtual void StopTarget();
    virtual ZString* GetSoundGroupTargetName(ZString* result);
    virtual bool UpdateSoundGroupFade(bool, float, float);
};
