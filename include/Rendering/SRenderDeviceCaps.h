#pragma once

#include "ZString.h"
#include "SVector2.h"
#include "ERenderFormat.h"

struct SRenderDeviceCaps
{
	ZString sPlatform;
	ZString sEffectProfile;
	ZString sVertexShaderProfile;
	ZString sMaterialPlatform;
	SVector2 vSafeZoneScale;
	SVector2 vDebugTextOffset;
	unsigned int nMaxGPUMemoryAvailable;
	unsigned int nMaxCPUMemoryAvailable;
	ERenderFormat eDepthTextureFormat;
	bool bDepthBufferReadable : 1;
	bool bSupportsTimeStampQueries : 1;
	bool bSupportsQuadLists : 1;
	bool bSupportsRectLists : 1;

	SRenderDeviceCaps(const SRenderDeviceCaps& __that);
	SRenderDeviceCaps() = default;
	~SRenderDeviceCaps() = default;
	SRenderDeviceCaps& operator=(const SRenderDeviceCaps& __that);
};
