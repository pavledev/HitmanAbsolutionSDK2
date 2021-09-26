#pragma once

#include "SRenderTexture2DAccess.h"
#include "ZRenderDepthStencilView.h"

struct SRenderShadowMap
{
	unsigned int m_nSize;
	SRenderTexture2DAccess m_Target;
	SRenderTexture2DAccess m_Temp[2];
	ZRenderDepthStencilView* m_pTempDSV;
	SRenderTexture2DAccess m_NormalMap;
	SRenderTexture2DAccess m_SmallNormalMap;
	SRenderTexture2DAccess m_DiffuseMap;
	SRenderTexture2DAccess m_SmallDiffuseMap;
	ZRenderShaderResourceView* m_pDepthSRV;

	SRenderShadowMap() = default;
	~SRenderShadowMap() = default;
};
