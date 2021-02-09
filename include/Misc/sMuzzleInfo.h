#pragma once

#include "SMatrix.h"

class alignas(16) sMuzzleInfo
{
public:
    SMatrix m_mvMuzzleMatPos;
    bool m_bValid;
};
