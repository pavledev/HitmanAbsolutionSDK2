#pragma once

#include "TEntityRef.h"
#include "ZHitman5.h"

class ZHM5FocusController
{
public:
    bool m_bIsGaining;
    float m_fFocusGainTechniqueModifier;
    float m_fFocusMaxTechniqueModifier;
    float* m_pFocus;
    float m_fAdjustFocus;
    float m_fPendingMinFocus;
    float m_fPendingFocus;
    TEntityRef<ZHitman5> m_pHitman;
};
