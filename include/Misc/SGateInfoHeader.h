#pragma once

#include "SQV.h"
#include "SVector3.h"
#include "ZGateEntity.h"
#include "SRoomInfoEntry.h"

class SGateInfoHeader
{
public:
    SQV mTransform;
    SVector3 m_vSize;
    ZGateEntity* pGateEntity;
    SRoomInfoEntry Clients;
    float fClipDistance;
    unsigned __int16 nCurrentRoom;
    unsigned __int16 nNeighbourRoom;
    unsigned __int16 nFlags : 15;
    __int8 m_bIsOpen : 1;
};
