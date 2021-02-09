#pragma once

#include "eItemType.h"

class SRecoilEntry
{
public:
    unsigned int m_nAnimNodeID;
    float m_fAnimDuration;
    float m_fAnimTime;
    bool m_bKeepHandsRelative;
    bool m_bLeftHandRelativeAnimation;
    bool m_bMirror;
    bool m_bSwapAttachers;
    eItemType m_eItemType;
};
