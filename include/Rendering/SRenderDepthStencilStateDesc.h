#pragma once

#include "ERenderCompareFunc.h"
#include "ERenderStencilOp.h"

struct SRenderDepthStencilStateDesc
{
	enum EDepthWriteMask
	{
		DEPTH_WRITE_MASK_NONE = 1,
		DEPTH_WRITE_MASK_ALL = 2
	};

	enum EHiStencilFunc_Xbox360
	{
		HISTENCILFUNC_DEFAULT = 2,
		HISTENCILFUNC_NOTEQUAL = 1,
		HISTENCILFUNC_EQUAL = 0
	};

	struct SStencilOpDesc
	{
		ERenderStencilOp eStencilFailOp;
		ERenderStencilOp eStencilDepthFailOp;
		ERenderStencilOp eStencilPassOp;
		ERenderCompareFunc eStencilFunc;
	};

	bool bDepthEnable;
	EDepthWriteMask eDepthWriteMask;
	ERenderCompareFunc eDepthFunc;
	bool bStencilEnable;
	unsigned char nStencilReadMask;
	unsigned char nStencilWriteMask;
	SStencilOpDesc frontFace;
	SStencilOpDesc backFace;

	SRenderDepthStencilStateDesc() = default;
	~SRenderDepthStencilStateDesc() = default;
};
