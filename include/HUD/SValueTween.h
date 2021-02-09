#pragma once

#include "State.h"

class SValueTween
{
public:
    int m_iTotalScore;
    int m_iNewShownValue;
    int m_iLastShownValue;
    float m_fAnimRunningTime;
    float m_fAnimTotalTime;
    int m_iAnimStartValue;
    State m_eState;
};
