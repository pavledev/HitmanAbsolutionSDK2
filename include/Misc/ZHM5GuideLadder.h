#pragma once

#include "ZHM5BaseGuide.h"

class alignas(16) ZHM5GuideLadder : public ZHM5BaseGuide
{
public:
    int m_nNumOfRungs;
    ZResourcePtr m_pHelper;
    float m_fHeight;
    SMatrix m_mvMountDismountBottom;
    SMatrix m_mvMountDismountTop;
    float4 m_vBottomMountDir;
    float4 m_vTopMountDir;
    bool m_bIgnoreTransformCallback;
};
