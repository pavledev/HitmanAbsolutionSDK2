#pragma once

#include "ZString.h"

class QualitySetting
{
public:
    ZString m_sName;
    ZString m_sApplicationOption;
    ZString m_sConfigCommand;
    int m_nMinValue;
    int m_nMaxValue;
    int m_nDesiredValue;
    int m_nCurrentValue;
};
