#pragma once

#include "SRenderTempTexture2DAccess.h"
#include "SRenderTexture2DAccess.h"

struct SRenderMixedResolutionBuffers
{
	enum
	{
		NUM_TEMP_BUFFERS_RGB565 = 1
	};

	enum
	{
		NUM_TEMP_BUFFERS_2X2_RGBA5551 = 2
	};

	enum
	{
		NUM_TEMP_BUFFERS_RGBA8 = 2
	};

	enum
	{
		NUM_TEMP_BUFFERS_2X2_RGBA8 = 3
	};

	enum
	{
		NUM_TEMP_BUFFERS_4X4_RGBA8 = 3
	};

	enum
	{
		NUM_TEMP_BUFFERS_8X8_RGBA8 = 3
	};

	enum
	{
		NUM_TEMP_BUFFERS_16X16_RGBA8 = 2
	};

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

	SRenderMixedResolutionBuffers() = default;
	~SRenderMixedResolutionBuffers() = default;
	void Allocate(unsigned int nWidth, unsigned int nHeight);
	void Free();
};
