#pragma once

#include "ZString.h"
#include "SVector2.h"
#include "ERenderFormat.h"

class alignas(4) SRenderDeviceCaps
{
public:
    ZString sPlatform;
    ZString sEffectProfile;
    ZString sVertexShaderProfile;
    ZString sMaterialPlatform;
    SVector2 vSafeZoneScale;
    SVector2 vDebugTextOffset;
    unsigned int nMaxGPUMemoryAvailable;
    unsigned int nMaxCPUMemoryAvailable;
    ERenderFormat eDepthTextureFormat;
    __int8 bDepthBufferReadable : 1;
    __int8 bSupportsTimeStampQueries : 1;
    __int8 bSupportsQuadLists : 1;
    __int8 bSupportsRectLists : 1;
};
