#pragma once

struct STraversalContextAlloc
{
    const void* pOwner;
    unsigned int nIndex;
    ZRenderTraversalContext* pContext;
};
