#pragma once

#include "TArray.h"
#include "NMP.h"
#include "SAnimBufferPage.h"

class ZAnimationBufferPageManager
{
public:
    unsigned int m_pageByteSize;
    unsigned int m_numBuffersPerPage;
    unsigned int m_memoryPerPage;
    unsigned __int16 m_nextFreeIndex;
    TArray<NMP::DataBuffer*> m_poseBuffers;
    NMP::Memory::Format m_bufferFormat;
    unsigned int m_transformCount;
    TArray<SAnimBufferPage> m_pages;
};
