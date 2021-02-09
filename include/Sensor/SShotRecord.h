#pragma once

#include "ZGameTime.h"

class alignas(8) SShotRecord
{
public:
    ZGameTime m_time;
    bool m_bHit;
};
