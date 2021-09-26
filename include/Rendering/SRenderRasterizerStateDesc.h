#pragma once

#include "ERenderFillMode.h"
#include "ERenderCullMode.h"

struct SRenderRasterizerStateDesc
{
	ERenderFillMode eFillMode;
	ERenderCullMode eCullMode;
	bool bFrontCounterClockWise;
	int nDepthBias;
	float fDepthBiasClamp;
	float fSlopeScaledDepthBias;
	bool bDepthClipEnable;
	bool bScissorEnable;
	bool bMultiSampleEnable;
	bool bAntialiasedLineEnable;

	SRenderRasterizerStateDesc() = default;
	~SRenderRasterizerStateDesc() = default;
};
