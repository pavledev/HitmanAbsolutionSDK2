#pragma once

#include "ZFindAnimPos.h"

class alignas(16) ZFindAnimPositions
{
public:
    ZFindAnimPos m_aFindAnimPos[2];
    bool m_abConstrainPos[2];
    bool m_bSolved;
    int m_iNumIter;
    float m_fTimeSpent;
};
