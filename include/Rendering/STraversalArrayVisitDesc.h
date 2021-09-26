#pragma once

class ZRenderGraphNode;

struct STraversalArrayVisitDesc
{
	ZRenderGraphNode** nArrayStart;
	ZRenderGraphNode** nArrayEnd;
	unsigned short nNumClipPlanes;
	unsigned short nNumTotalClipPlanes;
	unsigned short nClipPlanesIndexOffset;
	unsigned short nPad;

	STraversalArrayVisitDesc() = default;
	~STraversalArrayVisitDesc() = default;
};
