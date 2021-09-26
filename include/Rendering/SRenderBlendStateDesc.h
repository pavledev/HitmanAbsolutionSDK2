#pragma once

#include "ERenderBlendMode.h"
#include "ERenderBlendOp.h"

struct SRenderBlendStateDesc
{
	bool bAlphaToCoverageEnable;
	bool bBlendEnable[8];
	ERenderBlendMode eSrcBlend;
	ERenderBlendMode eDestBlend;
	ERenderBlendOp eBlendOp;
	ERenderBlendMode eSrcBlendAlpha;
	ERenderBlendMode eDestBlendAlpha;
	ERenderBlendOp eBlendOpAlpha;
	unsigned char nRenderTargetWriteMask[8];

	SRenderBlendStateDesc() = default;
	~SRenderBlendStateDesc() = default;
};
