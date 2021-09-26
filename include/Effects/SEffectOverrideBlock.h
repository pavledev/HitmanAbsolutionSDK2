#pragma once

#include "SVertexShaderOverrideBlock.h"

struct SEffectOverrideBlock
{
	enum
	{
		HPOS_ONLY = 0,
		HPOS_AND_POS = 1,
		HPOS_AND_POS_PAN = 2,
		FULL_SIMPLE = 3,
		FULL = 4,
		FULL_PAN = 5,
		NUM_OVERRIDE_LAYERS = 6
	};

	SVertexShaderOverrideBlock m_OvverrideLayers[6];

	SEffectOverrideBlock() = default;
	~SEffectOverrideBlock() = default;
};
