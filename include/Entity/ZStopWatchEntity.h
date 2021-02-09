#pragma once

#include "ZEntityImpl.h"

class alignas(4) ZStopWatchEntity : public ZEntityImpl
{
public:
    bool m_bEnabled;
    float m_fSeconds;
    float m_fDuration;
    bool m_bSendTotalSecondsOnChanged;
};
