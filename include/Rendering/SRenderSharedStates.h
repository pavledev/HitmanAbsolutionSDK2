#pragma once

#include "EMaterialBlendState.h"
#include "EMaterialRasterizerState.h"
#include "EMaterialDepthStencilState.h"

class ZRenderBlendState;
class ZRenderDepthStencilState;
class ZRenderRasterizerState;

struct SRenderSharedStates
{
	ZRenderBlendState* m_BlendStates[39];
	ZRenderRasterizerState* m_RasterizerStates[12];
	ZRenderDepthStencilState* m_DepthStencilStates[36];
	ZRenderBlendState* m_DecalBlend_LUT[2][2][2];

	SRenderSharedStates() = default;
	~SRenderSharedStates() = default;
	void CreateBlendState(EMaterialBlendState e);
	ZRenderBlendState* GetBlendState(EMaterialBlendState e);
	ZRenderRasterizerState* GetRasterizerState(EMaterialRasterizerState e);
	ZRenderDepthStencilState* GetDepthStencilState(EMaterialDepthStencilState e);
	ZRenderBlendState* GetSharedBlendState3RTWriteMaskRGB(bool bRenderTarget0, bool bRenderTarget1, bool bRenderTarget2);
};
