#pragma once

#include "ZRenderBlendState.h"
#include "ZRenderRasterizerState.h"
#include "ZRenderDepthStencilState.h"

class SRenderSharedStates
{
public:
    ZRenderBlendState* m_BlendStates[39];
    ZRenderRasterizerState* m_RasterizerStates[12];
    ZRenderDepthStencilState* m_DepthStencilStates[36];
    ZRenderBlendState* m_DecalBlend_LUT[2][2][2];
};
