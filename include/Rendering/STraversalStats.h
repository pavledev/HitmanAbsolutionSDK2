#pragma once

struct STraversalStats
{
    float fTimeSetup;
    float fTimeTraverseRooms[3];
    float fTimeSort;
    unsigned int nNumArraysTraversed;
    unsigned int nNumNodesTested;
};
