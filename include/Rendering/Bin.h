#pragma once

#include "RangeAllocator.h"

class ZRenderBuffer;

class Bin
{
public:
    unsigned int nBindFlags;
    ZRenderBuffer* pBuffer;
    RangeAllocator* pAllocator;
};
