#pragma once

#include "ZMovementAnimNode.h"

class alignas(16) ZMovementAnimNodeEx : public ZMovementAnimNode
{
public:
    float4 m_vGroundMovement;
    float m_fLength;
    float m_fDuration;
    float m_fSpeed;
};
