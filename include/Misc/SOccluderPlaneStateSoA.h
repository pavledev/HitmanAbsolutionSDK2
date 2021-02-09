#pragma once

#include "float4.h"

struct alignas(16) SOccluderPlaneStateSoA
{
    float4 OccluderPlanes[40];
    unsigned int nNumPerOccluders[8];
    unsigned int nNumOccluders;
};
