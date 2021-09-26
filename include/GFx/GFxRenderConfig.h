#pragma once

#include "GFxState.h"
#include "GPtr.h"
#include "GRenderer.h"

class GFxRenderConfig : public GFxState
{
public:
	enum RenderFlagType
	{
		RF_StrokeCorrect = 0,
		RF_StrokeNormal = 1,
		RF_StrokeHairline = 2,
		RF_StrokeMask = 3,
		RF_EdgeAA = 16,
		RF_OptimizeTriangles = 32,
		RF_NoViewCull = 256
	};

	GPtr<GRenderer> pRenderer;
	float MaxCurvePixelError;
	unsigned long RenderFlags;
	float StrokerAAWidth;
	unsigned long RendererCapBits;
	unsigned long RendererVtxFmts;

	~GFxRenderConfig() override = default;

	GFxRenderConfig() = default;
	GRenderer* GetRenderer() const;
};
