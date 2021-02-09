#pragma once

#include "SRenderTempTexture2DAccess.h"

class alignas(4) SRenderMixedResolutionBuffers
{
public:
    SRenderTempTexture2DAccess m_RGB565[1];
    SRenderTempTexture2DAccess m_2x2RGBA5551[2];
    SRenderTempTexture2DAccess m_RGBA8[2];
    SRenderTempTexture2DAccess m_R2x2RGBA8[3];
    SRenderTempTexture2DAccess m_R2x2RGBA8_NONSRGB[3];
    SRenderTexture2DAccess m_R4x4RGBA8[3];
    SRenderTexture2DAccess m_R4x4RGBA8_NONSRGB[3];
    SRenderTexture2DAccess m_R8x8RGBA8[3];
    SRenderTexture2DAccess m_R16x16RGBA8[2];
    unsigned int m_nWidth;
    unsigned int m_nHeight;
    bool m_bBuffersAllocated;
};
