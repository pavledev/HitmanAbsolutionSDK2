#pragma once

#include "TFixedArray.h"
#include "UserFBIcons.h"

class ZUserFeedbackManager;

class alignas(8) ZHM5TimerToOSDManager
{
public:
    TFixedArray<UserFBIcons::STimerToOSDElement, 6> m_rTimers;
    ZUserFeedbackManager* m_pUserFBManager;
};
