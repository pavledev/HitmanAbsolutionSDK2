#pragma once

#include "ZSoundPlayableBase.h"
#include "ISoundBlendContainer.h"

class ZSoundBlendEvent;

class ZSoundBlendContainerBase : public ZSoundPlayableBase, public ISoundBlendContainer
{
public:
    bool m_bUseGameTime;
    bool m_bDebugShowParameters;
    float m_fCooldownTime;
    int m_nPriority;
    TArray<ZEntityRef> m_Tracks;
    TArray<ZSoundBlendEvent*> m_pEvents;
    unsigned int m_nEventID;
    TArray<ZSoundPlayerChannel*> m_ActiveChannels;
    ZGameTime m_lastPlayTime;

    virtual bool IsPhysics();
    virtual void SetupAndStartEvent(bool, const float4*);
    virtual float GetAbsoluteFromNormal(int, float);
    virtual float GetNormalizedParameter(int, float);
};
