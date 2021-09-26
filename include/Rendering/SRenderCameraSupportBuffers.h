#pragma once

#include "SRenderTempTexture2DAccess.h"

struct SRenderCameraSupportBuffers
{
	SRenderTempTexture2DAccess m_Depth2x2;
	SRenderTempTexture2DAccess m_Depth4x4;
	SRenderTempTexture2DAccess m_Normals2x2;
	SRenderTempTexture2DAccess m_CoC2x2;
	SRenderTempTexture2DAccess m_SSAO;

	SRenderCameraSupportBuffers() = default;
	~SRenderCameraSupportBuffers() = default;
};
