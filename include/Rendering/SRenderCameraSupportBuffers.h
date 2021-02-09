#pragma once

#include "SRenderTempTexture2DAccess.h"

class SRenderCameraSupportBuffers
{
public:
    SRenderTempTexture2DAccess m_Depth2x2;
    SRenderTempTexture2DAccess m_Depth4x4;
    SRenderTempTexture2DAccess m_Normals2x2;
    SRenderTempTexture2DAccess m_CoC2x2;
    SRenderTempTexture2DAccess m_SSAO;
};
