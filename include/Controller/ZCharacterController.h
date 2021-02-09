#pragma once

#include "ZCharacterControllerBlender.h"

class alignas(16) ZCharacterController
{
public:
    ZCharacterControllerBlender m_blender;
    unsigned __int16 m_nTransitionToIndex;
    unsigned __int16 m_nPreferredClipIndex;
    ZCharacterControllerClip m_partialAnimationClip;
    float m_nPartialAnimBlendTime;
    float m_nPartialAnimationPlayWeight;
    SQV m_trajectoryDelta;
    MR::EventSeqPosition m_footstepEvent;
    float m_fSequenceFraction;
    float m_fCutSequenceWeight;
    float m_fTimeModifier;
    float m_fTimeToFirstOverride;
    SVector4 m_vLookAtIKTarget;
    unsigned int m_nOverrideClipFlags;
    unsigned __int8 m_nOverrideStage;
    bool m_bAllowOverrides;
    unsigned __int16 m_nSequenceClipIndex;
    SVector3 m_desiredHeading;
    SVector3 m_desiredFacing;
    unsigned __int8 m_desiredGait : 3;
    unsigned __int8 m_desiredSpeed : 3;
    unsigned __int8 m_bUseCutSequenceData : 1;
};
