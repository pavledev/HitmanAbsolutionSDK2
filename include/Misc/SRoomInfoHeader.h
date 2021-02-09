#pragma once

#include "SVector3.h"
#include "SRoomInfoEntry.h"
#include "SMatrix43.h"
#include "TArray.h"
#include "ZRenderGraphNode.h"

class SRoomInfoHeader
{
public:
    SVector3 vOBBCenter;
    SRoomInfoEntry Gates;
    SVector3 vOBBHalfSize;
    SMatrix43 mOBBTransform;
    SRoomInfoEntry Excludes;
    SRoomInfoEntry Includes;
    SRoomInfoEntry Occluders;
    TArray<ZRenderGraphNode*>* DynamicNodes;
    SRoomInfoEntry Nodes;
    unsigned int nNumClients;
    TArray<ZRenderGraphNode*>* Lights;
    unsigned __int16 nFlags;
    unsigned __int16 nGateSet;
};
