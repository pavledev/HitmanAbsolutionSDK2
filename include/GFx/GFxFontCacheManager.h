#pragma once

#include "GFxState.h"
#include "GFxFontCacheManagerImpl.h"

class GFxFontCacheManager : public GFxState
{
public:
	struct TextureConfig
	{
		unsigned int TextureWidth;
		unsigned int TextureHeight;
		unsigned int MaxNumTextures;
		unsigned int MaxSlotHeight;
		unsigned int SlotPadding;
		unsigned int TexUpdWidth;
		unsigned int TexUpdHeight;

		TextureConfig() = default;
	};

	TextureConfig CacheTextureConfig;
	bool DynamicCacheEnabled;
	bool Text3DVectorizationEnabled;
	float MaxRasterScale;
	unsigned int SteadyCount;
	unsigned int MaxVectorCacheSize;
	float FauxItalicAngle;
	float FauxBoldRatio;
	float OutlineRatio;
	unsigned int NumLockedFrames;
	GFxFontCacheManagerImpl* pCache;

	~GFxFontCacheManager() override = default;

	GFxFontCacheManager() = default;
};
