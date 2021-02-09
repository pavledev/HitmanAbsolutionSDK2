#pragma once

#include "ZHM5CoverPlane.h"
#include "SMatrix.h"
#include "eCoverStance.h"

class alignas(16) sExitCoverInfo
{
public:
    ZHM5CoverPlane* m_pCoverPlane;
    SMatrix m_mvPosOnCoverPlane;
    eCoverStance m_eStance;
    bool m_bAtCorner;
    bool m_bFacingRight;
};
