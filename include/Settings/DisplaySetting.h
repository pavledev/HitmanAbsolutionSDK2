#pragma once

#include "ZString.h"

class DisplaySetting
{
public:
    ZString m_sName;
    ZString m_sApplicationOption;

    union
    {
        int m_nDesiredValue;
        float m_fDesiredValue;
    };

    union
    {
        int m_nCurrentValue;
        float m_fCurrentValue;
    };

    union
    {
        int m_nSavedValue;
        float m_fSavedValue;
    };
};
