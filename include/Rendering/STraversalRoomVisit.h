#pragma once

struct STraversalRoomVisit
{
	unsigned short nClipPlaneIndex;
	unsigned short nRoomId;
	unsigned short nNumClipPlanes;
	unsigned short _pad;

	STraversalRoomVisit() = default;
	~STraversalRoomVisit() = default;
};
