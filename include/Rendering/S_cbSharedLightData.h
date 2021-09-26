#pragma once

#include "SMatrix44.h"

struct S_cbSharedLightData
{
	SVector4 vParams0;
	SVector4 vParams1;
	SVector4 vParams2;
	SVector4 vLightDiffuse;
	SVector4 vHalfLightBoxFadeNeg;
	SVector4 vHalfLightBoxFadePos;
	SVector4 vRcpLightBoxFadeNeg;
	SVector4 vRcpLightBoxFadePos;
	SVector4 vLightPosView;
	SVector4 vLightDirView;
	SVector4 vProjectorTilingOffset;
	SMatrix44 mViewToShadowProjTrans;
	SMatrix44 mViewToLightProjTrans;
	SVector4 vLightParams;
	SVector4 vRestrictLightBoxVectorX;
	SVector4 vRestrictLightBoxVectorY;
	SVector4 vRestrictLightBoxVectorZ;
	SVector4 vRestrictLightBoxPosition;

	S_cbSharedLightData() = default;
	~S_cbSharedLightData() = default;
};
