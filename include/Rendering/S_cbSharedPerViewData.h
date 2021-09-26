#pragma once

#include "SMatrix44.h"

struct S_cbSharedPerViewData
{
	SMatrix44 mProjection;
	SMatrix44 mViewToViewport;
	SMatrix44 mViewToWorld;
	SVector4 vViewRemap;
	SVector4 vViewDepthRemap;
	SVector4 vEyeVectorUL;
	SVector4 vEyeVectorLR;
	SVector4 v4ShadowRange;
	SVector4 vViewSpaceUpVector;
	SVector4 vGlobalLitFactor;
	SVector4 vViewportSize;
	SVector4 vEngineTime;
	SVector4 vShaderColor0;
	SVector4 vShaderColor1;
	SVector4 vShaderColor2;
	SVector4 vShaderColor3;
	SVector4 vShaderColor4;
	SVector4 vClipPlane;

	S_cbSharedPerViewData() = default;
	~S_cbSharedPerViewData() = default;
};
