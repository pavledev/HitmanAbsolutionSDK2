#pragma once

#include "ZRenderPrimitiveInstance.h"

class SRenderPrimitiveEntry
{
public:
    ZRenderPrimitiveInstance* m_pPrimitiveInstance;
    IRenderPrimitive* m_pRenderPrimitive;
    ZRenderGraphNode* m_pRenderGraphNode;
    unsigned int nSortValue;
};
