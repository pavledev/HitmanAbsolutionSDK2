#pragma once

#include "EActorPerceptionSensitivity.h"

struct SVisibilitySetting
{
    EActorPerceptionSensitivity m_eSensitivity;
    float m_fCloseRange;
    float m_fPeripheralRange;
    float m_fPeripheralAngle;
    float m_fPeripheralHigh;
    float m_fPeripheralLow;
    float m_fFocusConeWidthAngle;
    float m_fFocusConeHeightAngle;
    float m_fFocusConeRange;
};
