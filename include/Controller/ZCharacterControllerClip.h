#pragma once

#include "MR.h"

class ZCharacterControllerClip
{
public:
    MR::EventsSequenceTimeStretch m_eventSequenceTimeStretch;
    float m_fPrevAnimationTime;
    float m_fPrevTimeFraction;
    float m_fCurTimeFraction;
    float m_fDeltaTimeFraction;
    float m_fDuration;
    unsigned __int16 m_clipIndex;
    bool m_bLoop;
    bool m_loopedOnLastUpdate;
};
