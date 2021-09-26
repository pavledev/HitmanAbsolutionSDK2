#pragma once

#include "TList.h"
#include "SVector3.h"

struct SCoverTimestamp;

struct SRoomCoverInfo
{
	unsigned short nEntryRoomID;
	TList<SCoverTimestamp> CoverInfos;
	SVector3 vThreatPos;
	bool bChecked;

	void SortCoverInfos();
	SRoomCoverInfo(const SRoomCoverInfo& __that);
	SRoomCoverInfo() = default;
	~SRoomCoverInfo() = default;
	SRoomCoverInfo& operator=(const SRoomCoverInfo& __that);
};
