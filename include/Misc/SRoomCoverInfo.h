#pragma once

#include "TList.h"
#include "SCoverTimestamp.h"

class alignas(4) SRoomCoverInfo
{
public:
    unsigned __int16 nEntryRoomID;
    TList<SCoverTimestamp> CoverInfos;
    SVector3 vThreatPos;
    bool bChecked;
};
