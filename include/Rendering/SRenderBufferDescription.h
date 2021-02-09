#pragma once

#include "ERenderResourceUsage.h"

struct SRenderBufferDescription
{
    unsigned int nSize;
    unsigned int nBindingFlags;
    ERenderResourceUsage eUsage;
    unsigned int nCPUAccessFlags;
    unsigned int nStride;
};
