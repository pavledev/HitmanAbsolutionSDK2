#pragma once

#include "SVector2.h"
#include "SLightMinMaxGridRange.h"

class SLightMinMaxGrid
{
public:
    SVector2* m_pData;
    bool* m_pValid;
    SLightMinMaxGridRange m_PriorityRanges[3];
    SLightMinMaxGridRange m_PrevCellUpdate[3];
    unsigned int m_nNumReadCells;
    unsigned int m_nNumWrittenCells;
};
