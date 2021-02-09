#pragma once

#include "TArray.h"
#include "Bin.h"

class ZRenderDevice;

class ZSubRenderBufferManager
{
public:
    ZRenderDevice* m_pRenderDevice;
    TArray<Bin*> m_bins;

    struct Block
    {
        ZRenderBuffer* pBuffer;
        unsigned int nOffset;
        unsigned int nBindFlags;
        RangeAllocator::Block* pBlock;
    };
};
