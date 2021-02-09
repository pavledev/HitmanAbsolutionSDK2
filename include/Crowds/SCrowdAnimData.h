#pragma once

#include "SMatrix.h"

class SCrowdAnimData
{
public:
    unsigned int m_nSource;
    unsigned int m_nIndex;
    unsigned __int8 m_nLODFlags;
    SMatrix m_mMatrix;
};
