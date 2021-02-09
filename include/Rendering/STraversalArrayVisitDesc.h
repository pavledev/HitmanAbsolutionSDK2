#pragma once

#include "ZRenderGraphNode.h"

struct STraversalArrayVisitDesc
{
    ZRenderGraphNode** nArrayStart;
    ZRenderGraphNode** nArrayEnd;
    unsigned __int16 nNumClipPlanes;
    unsigned __int16 nNumTotalClipPlanes;
    unsigned __int16 nClipPlanesIndexOffset;
    unsigned __int16 nPad;
};
