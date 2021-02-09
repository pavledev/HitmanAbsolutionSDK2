#pragma once

#include "ZSoundGroupTarget.h"
#include "TMap.h"
#include "ESustainPointState.h"
#include "ZSoundBlendContainerBase.h"
#include <fmod.hpp>
#include "ESoundCollisionType.h"

class ZSoundBlendTrackInstance;

class alignas(16) ZSoundBlendEvent : public ZSoundGroupTarget
{
public:
    TMap<int, ESustainPointState> m_SustainPointStates;
    bool m_bTimerRunning;
    ZSoundBlendContainerBase* m_pContainerOwner;
    TArray<ZSoundBlendTrackInstance*> m_pBlendTrackInstances;
    unsigned int m_nUniqueID;
    ESoundCollisionType m_eCollisionSupport;
    float4 m_vPosition;
    TArray<float> m_fSourceParameters;
    int m_nNumTrackInstances;
    int m_nRegisterIndex;
    int m_nPriority;
    bool m_bAllowChannelCreation;
    bool m_bDisposable;
    bool m_bSourceParametersDirty;
    bool m_bAutoDestruct;
    bool m_bMemorizeAutoDestruct;
    bool m_bIs3D;
    bool m_bSustainPointReleasedPrematurely;
    bool m_bIsLoudPhysicsEvent;
    ZGameTime m_timestamp;
    float m_fBaseAttenuation;
    FMOD::ChannelGroup* m_pMasterEffectsGroup;
    ZSoundBlendEvent* m_pPrev;
    ZSoundBlendEvent* m_pNext;

    virtual void AttachEffectInstance(FMOD::DSP*, void*);
    virtual bool IsSilent();
};
