#pragma once

#include "NMP.h"

class ZJobQueue
{
public:
    unsigned __int16 m_numJobs;
    unsigned __int16 m_nextFreeByteIndex;
    NMP::Memory::Resource m_data;
    NMP::Memory::Format m_bufferFormat;
};
