#pragma once

#include "ZAnimationClipBaseEntity.h"
#include "TResourcePtr.h"
#include "ZAnimationResource.h"
#include "EGait.h"
#include "ESpeed.h"
#include "EAnimBlendMode.h"

class ZAnimationClipEntity : public ZAnimationClipBaseEntity
{
public:
    float m_fDuration;
    float m_fSampleFrequency;
    float m_fLinearVelocity;
    float m_fAngularVelocity;
    unsigned __int16 m_clipIndex;
    ZString m_sAnimName;
    TResourcePtr<ZAnimationResource> m_pAnimationResource;
    EGait m_gait;
    ESpeed m_speed;
    EAnimBlendMode m_eAnimBlendMode;
    bool m_bIsEnabled;
    unsigned __int8 m_nOverrideStageFlags;
    bool m_bStartFromBeginning;
    bool m_bMirrored;

    virtual void OnAnimationResourceChanged();
};
