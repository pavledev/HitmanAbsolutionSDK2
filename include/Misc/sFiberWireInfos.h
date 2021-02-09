#pragma once

#include "SMatrix.h"

class alignas(16) sFiberWireInfos
{
public:
    SMatrix m_mvAttacherTarget[2];
    SMatrix m_mvVictimNeck;
    bool m_bValid;
};
