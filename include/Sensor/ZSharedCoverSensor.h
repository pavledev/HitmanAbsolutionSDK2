#pragma once

#include "TMap.h"
#include "SRoomCoverInfo.h"

class ZSharedCoverSensor
{
public:
    TMap<unsigned short, SRoomCoverInfo> m_RoomGroups;

    virtual ~ZSharedCoverSensor();
};
