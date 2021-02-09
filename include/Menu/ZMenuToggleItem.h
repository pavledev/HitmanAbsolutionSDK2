#pragma once

#include "ZMenuItem.h"

class alignas(8) ZMenuToggleItem : public ZMenuItem
{
public:
    unsigned __int16 m_nOptionKey;
    bool m_bValue;
    ZString m_sText;
};
