#pragma once

#include "float4.h"

const struct SGWaypoint
{
    union
    {
        struct
        {
            __int16 nNeighbor0;
            __int16 nNeighbor1;
            __int16 nNeighbor2;
            __int16 nNeighbor3;
            __int16 nNeighbor4;
            __int16 nNeighbor5;
            __int16 nNeighbor6;
            __int16 nNeighbor7;
        };

        __int16 Neighbors[8];
    };

    float4 vPos;
};
