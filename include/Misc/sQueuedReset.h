#pragma once

#include "SMatrix.h"

class alignas(16) sQueuedReset
{
public:
    bool m_bResetQueued;
    SMatrix m_mvResetPoint;
};
