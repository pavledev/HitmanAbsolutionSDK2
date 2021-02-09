#pragma once

#include "TFixedArray.h"

class ZHM5HUDFadeHandler
{
public:
    TFixedArray<unsigned int, 6> m_iFadeFlags;
    unsigned int m_iVisible;
};
