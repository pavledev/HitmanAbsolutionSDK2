#pragma once

#include "ZString.h"
#include "ERenderFormat.h"
#include "ERenderResourceUsage.h"
#include "ERenderResourceMipInterpolation.h"

struct SRenderTexture3DDesc
{
	unsigned long long nResourceMemoryScopeID;
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

	SRenderTexture3DDesc(const SRenderTexture3DDesc& __that);
	SRenderTexture3DDesc() = default;
	~SRenderTexture3DDesc() = default;
};
