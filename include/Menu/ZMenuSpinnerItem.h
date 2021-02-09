#pragma once

#include "ZMenuItem.h"

class alignas(8) ZMenuSpinnerItem : public ZMenuItem
{
public:
    unsigned __int16 m_nOptionKey;
    unsigned int m_nCurrentIdx;
    TArray<ZString> m_sEntry;
};
