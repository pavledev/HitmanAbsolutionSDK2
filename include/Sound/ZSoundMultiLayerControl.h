#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ZSoundPlayableBase.h"
#include "ZSoundMultiLayerMixer.h"

class ZSoundMultiLayerControl : public ZEntityImpl
{
public:
    TEntityRef<ZSoundPlayableBase> m_parentEntity;
    int m_nLFEChannel;
    TArray<TEntityRef<ZSoundMultiLayerMixer>> m_aChannel0;
    TArray<TEntityRef<ZSoundMultiLayerMixer>> m_aChannel1;
    TArray<TEntityRef<ZSoundMultiLayerMixer>> m_aChannel2;
    TArray<TEntityRef<ZSoundMultiLayerMixer>> m_aChannel3;
    TArray<TEntityRef<ZSoundMultiLayerMixer>> m_aChannel4;
    TArray<TEntityRef<ZSoundMultiLayerMixer>> m_aChannel5;
    TArray<TEntityRef<ZSoundMultiLayerMixer>> m_aChannel6;
    TArray<TEntityRef<ZSoundMultiLayerMixer>> m_aChannel7;
    float m_fReverbLevel;
    bool m_bAlignListener;
    float m_fChannelVolume[8];
    float4 m_vSpeakerDir[8];
    float4 m_vSpeakerPos[8];
    float4 m_vSpeakerDirTransformed[8];
    float4 m_vSpeakerPosTransformed[8];
    float4 m_vLastListenerPos;
    float4 m_vLastOcclusionPos;
    bool m_bIsLFE[8];
    bool m_bIsUpdated;
    unsigned __int64 m_nFrameUpdateTag;
    SMatrix m_mListenerMatrix;
};
