#pragma once

#include "SPathPoint.h"

class ZPF5Path
{
public:
    int m_nRefCount;
    int m_nPathPointCount;
    SPathPoint* m_pPathPointList;
    bool m_bStrict;
    unsigned __int16 m_nCrossedRegions;
};
