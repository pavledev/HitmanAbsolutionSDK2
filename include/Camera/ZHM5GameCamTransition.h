#pragma once

#include "ZEntityImpl.h"
#include "ECameraState.h"

class ZHM5GameCamTransition : public ZEntityImpl
{
public:
    float m_fTransitionTime;
    bool m_bTransitionWhileMoving;
    bool m_bAlignToBaseAngles;
    bool m_bIgnoreProfileAlignment;
    TArray<ECameraState> m_aeFromStates;
    TArray<ECameraState> m_aeToStates;
};
