#pragma once

#include "ZSoundAmbienceBase.h"
#include "SVector3.h"
#include "TEntityRef.h"
#include "ZSoundPlayableBase.h"
#include "ESoundAmbiencePlayState.h"

class ZSoundAmbienceElement : ZSoundAmbienceBase
{
    bool m_bIsTempSpatial;
    bool m_bAmbienceActivated;
    bool m_bTriggerByAmbience;
    bool m_bUseTimer;
    float m_fMinTime;
    float m_fMaxTime;
    float m_fTimeMultiplier;
    float m_fProbability;
    int m_nMaxPlayCount;
    bool m_bUseAmbienceAttenuation;
    SVector3 m_vTempSpatialPos;
    float m_fTempSpatialWeight;
    TEntityRef<ZSoundPlayableBase> m_parentEntity;
    ESoundAmbiencePlayState m_eCurrPlayState;
    ESoundAmbiencePlayState m_eNextPlayState;
    ESoundAmbiencePlayState m_eSavedPlayState;
    float m_fMinTimeInterpolated;
    float m_fMaxTimeInterpolated;
    float m_fTimeMultiplierInterpolated;
    float m_fProbabilityInterpolated;
    float m_fLowpassCutoffInterpolated;
    float m_fRemaining;
    bool m_bTriggeredByPin;
    bool m_bPaused;
    bool m_bPlaying;
    bool m_bSingleSoundStarted;
    unsigned int m_nIncrementAddCount;
    int m_nCurrentPlayCount;
};
