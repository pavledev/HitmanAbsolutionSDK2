#pragma once

#include "ZBoundedEntity.h"
#include "ISoundListenerPositionReceiver.h"
#include "ISoundUpdateListener.h"
#include "ESoundGlobalReverb.h"
#include "ZResourcePtr.h"
#include "ZSoundPlayableBase.h"
#include "ZSoundChannelGroup.h"
#include "ISoundVolumetricGeom.h"
#include "SSoundVolumetricOcclusionData.h"
#include "ZSoundBlendContainerExternalParameters.h"

class __declspec(align(8)) ZSoundVolumetricAspect : public ZBoundedEntity, public ISoundListenerPositionReceiver, public ISoundUpdateListener
{
public:
    float m_fDistanceAttenuation;
    float m_fDirectionalAttenuation;
    float m_fDirectionalAttenuationCurve;
    float m_f3DWeight;
    float m_fReverbLevelNear;
    float m_fReverbLevelFar;
    float m_fReverbRadius;
    float m_fOcclusionAttenuation;
    float m_fDopplerLevel;
    float m_fOcclusionLowpassHigh;
    float m_fOcclusionLowpassLow;
    bool m_bAlignListener;
    bool m_bUseAllInputChannels;
    ESoundGlobalReverb m_eSoundGlobalReverbChannelGroup;
    float m_fGlobalReverb1AttenuationChannelGroup;
    ZResourcePtr m_pHelper;
    TArray<ZEntityRef> m_pVolumetricGeometry;
    TEntityRef<ZSoundPlayableBase> m_parentSoundEntity;
    TEntityRef<ZSoundChannelGroup> m_parentSoundChannelGroup;
    TEntityRef<ZSoundBlendContainerExternalParameters> m_pBlendContainer;
    TArray<FMOD::Channel*> m_TempFrameUpdateChannels;
    int m_nNumSpeakers;
    float m_fOcclusionLowpassFrequency;
    float m_fDopplerShiftFilter1;
    float m_fDopplerShiftFilter2;
    float m_fDopplerShiftFilter3;
    float m_fDopplerVelocity;
    float m_fInsideness;
    float m_fSpeakerLevelsTarget[8];
    float m_fSpeakerLevelsSmooth[64];
    float4 m_vListenerPosition;
    float4 m_vObjectPosition;
    bool m_bDrawDebugRays;
    bool m_bHasUnoccludedPath;
    SMatrix m_mListenerMatrix;
    float4 m_vOcclusionPosition;
    float4 m_vAverageCenter;
    int m_nMaxRayCastResults;
    int m_nNextMaxRayCastResults;
    int m_asyncRaycastHandleCleanupHelper;
    TArray<ISoundVolumetricGeom*> m_pGeoms;
    SSoundVolumetricOcclusionData* m_pOcclusionData;
};
