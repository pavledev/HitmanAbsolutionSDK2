#pragma once

#include "ERenderFormat.h"
#include "SRenderSampleDesc.h"
#include "ERenderResourceUsage.h"
#include "ERenderResourcePriority.h"
#include "ERenderResourceMipInterpolation.h"

class alignas(8) SRenderTexture2DDesc
{
public:
    unsigned __int64 nResourceMemoryScopeID;
    unsigned int nWidth;
    unsigned int nHeight;
    unsigned int nMipLevels;
    unsigned int nArraySize;
    ERenderFormat eFormat;
    SRenderSampleDesc sampleDesc;
    unsigned int nBindFlags;
    unsigned int nMiscFlags;
    unsigned int nCPUAccessFlags;
    ERenderResourceUsage eUsage;
    ERenderResourcePriority ePriority;
    ERenderResourceMipInterpolation eMipInterpolation;
};
