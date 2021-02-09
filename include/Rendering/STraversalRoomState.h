#pragma once

#include "STraversalStats.h"

struct STraversalRoomState
{
    unsigned int nOutPos;
    int nInPos;
    unsigned int nBarrierCounter;
    unsigned int nBarrierTarget;
    unsigned int nInArraySize;
    unsigned int nOutArraySize;
    unsigned int nGateVisitsSize;
    unsigned int nRoomVisitsSize;
    unsigned int nNumVisibleNodes;
    unsigned int nNumVisibleGates;
    unsigned int nNumEdgeOccluders;
    unsigned int nTraverseFlags;
    STraversalStats Stats;
};
