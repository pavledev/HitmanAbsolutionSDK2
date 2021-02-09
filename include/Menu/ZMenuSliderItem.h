#pragma once

#include "ZMenuItem.h"

class alignas(8) ZMenuSliderItem : public ZMenuItem
{
public:
    unsigned __int16 m_nOptionKey;
    float m_fMinValue;
    float m_fMaxValue;
    float m_fStepSize;
    float m_fValue;
    ZString m_sText;
};
