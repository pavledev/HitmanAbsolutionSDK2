#pragma once

#include "ZString.h"
#include "ERenderFormat.h"
#include "ERenderResourceUsage.h"
#include "ERenderResourceMipInterpolation.h"

class SRenderTexture3DDesc
{
public:
    unsigned __int64 nResourceMemoryScopeID;
    ZString sName;
    unsigned int nWidth;
    unsigned int nHeight;
    unsigned int nDepth;
    unsigned int nMipLevels;
    unsigned int nBindFlags;
    unsigned int nMiscFlags;
    unsigned int nCPUAccessFlags;
    ERenderFormat eFormat;
    ERenderResourceUsage eUsage;
    ERenderResourceMipInterpolation eMipInterpolation;
};
