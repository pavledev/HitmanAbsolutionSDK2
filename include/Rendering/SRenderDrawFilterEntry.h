#pragma once

#include "ZRenderGraphNode.h"
#include "ZRenderPrimitiveInstance.h"

struct alignas(4) SRenderDrawFilterEntry
{
    ZRenderGraphNode* m_pNode;
    ZRenderPrimitiveInstance* m_pPrimitiveInstance;
    char m_nLODFade;
    __int8 m_bUseFade : 1;
    __int8 m_bSimpleShader : 1;
};
