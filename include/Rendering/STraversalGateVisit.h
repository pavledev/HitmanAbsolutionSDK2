#pragma once

struct STraversalGateVisit
{
	unsigned short nClipPlaneIndex;
	unsigned short nGateId;
	unsigned short nNumClipPlanes;
	unsigned short _pad;

	STraversalGateVisit() = default;
	~STraversalGateVisit() = default;
};
