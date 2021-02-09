#pragma once

#include "SCrowdMapData.h"

class ZCrowdMap : public SCrowdMapData
{
public:
    enum CellStatus : __int32
    {
        CELLS_UNKNOWN = 0x0,
        CELLS_CANDIDATE = 0x1,
        CELLS_KNOWN = 0x2
    };

    class SCrowdMapFlowCostsTemp
    {
    public:
        TArray<TArray<float>> m_aFlowChannels;
    };
};
