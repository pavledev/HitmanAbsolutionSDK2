#pragma once

#include "SMatrix.h"

class alignas(16) sPelvisOffsetElement
{
public:
    SMatrix m_mvOffset;
    void* m_pClassPtr;
};
