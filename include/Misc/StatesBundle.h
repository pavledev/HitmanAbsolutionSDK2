#pragma once

#include "ZRenderBlendState.h"
#include "ZRenderRasterizerState.h"
#include "ZRenderDepthStencilState.h"

struct StatesBundle
{
    ZRenderBlendState* m_pBlendState;
    float m_fBlendFactor;
    ZRenderRasterizerState* m_pRasterizerState;
    unsigned int m_nStencilRef;
    ZRenderDepthStencilState* m_pDepthStencilState;
};
