#pragma once

#include "NMP.h"

class SAnimBufferPage
{
public:
    NMP::Memory::Resource m_bufferResource;
    unsigned int m_numBuffersUsed;
};
