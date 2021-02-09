#pragma once

#include "SVector4.h"

class SInterpolatingParameter
{
public:
    SVector4 m_oldValue;
    SVector4 m_newValue;
    float m_fTimeTotal;
    float m_fTimeCurrent;
};
