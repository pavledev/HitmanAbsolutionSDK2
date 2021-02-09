#pragma once

#include "SHUDIconInfo.h"

class alignas(4) SIconElement
{
public:
    unsigned int m_iHandle;
    SHUDIconInfo m_iconInfo;
    unsigned __int8 m_iChangedFlags;
    bool m_bUpdated;
};
