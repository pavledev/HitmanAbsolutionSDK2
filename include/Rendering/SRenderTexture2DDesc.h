#pragma once

#include "ERenderFormat.h"
#include "SRenderSampleDesc.h"
#include "ERenderResourceUsage.h"
#include "ERenderResourcePriority.h"
#include "ERenderResourceMipInterpolation.h"

struct SRenderTexture2DDesc
{
	unsigned long long nResourceMemoryScopeID;
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

	SRenderTexture2DDesc() = default;
	~SRenderTexture2DDesc() = default;
};
