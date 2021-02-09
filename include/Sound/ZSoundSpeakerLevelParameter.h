#pragma once

#include "ZEntityImpl.h"
#include "TSharedValue.h"
#include "ZSpeakerLevels.h"
#include "TEntityRef.h"
#include "ZSoundPlayableBase.h"

class ZSoundSpeakerLevelParameter : ZEntityImpl
{
    bool m_bMatrixModified;
    TSharedValue<ZSpeakerLevels> m_SpeakerLevels;
    float m_fReverbLevel;
    bool m_bEnablePan;
    float m_fPanAngle;
    float m_fPanAngleRandomizer;
    float m_fPanSpread;
    float m_fPanSpreadRandomizer;
    float m_fPanLFELevel;
    float m_fApproximateLFEVolumeFor3D;
    TEntityRef<ZSoundPlayableBase> m_parentEntity;
};
