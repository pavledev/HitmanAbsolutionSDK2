#pragma once

#include "ZActorAnimationProgram.h"

class alignas(16) ZControlledAnimLocomotion : ZActorAnimationProgram
{
    bool m_bAdvanceAnimation;
    float m_fAnimPrct;
    float m_fAnimDuration;
    SMatrix m_mvMatPos;
    SMatrix m_mvStartMatPos;
    SMatrix m_mvTargetMatPos;
    unsigned int m_nAnimNodeId;
    unsigned int m_nAnimSMNodeId;
    ZString m_sAnimName;
    ZString m_sAnimSMName;
};
