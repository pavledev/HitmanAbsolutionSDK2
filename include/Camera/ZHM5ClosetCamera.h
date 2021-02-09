#pragma once

#include "ZHM5CameraBaseFunc.h"

class alignas(16) ZHM5ClosetCamera : public ZHM5CameraBaseFunc
{
public:
    float m_fMainCameraNearZ;
    SMatrix m_MatPos;
    SMatrix m_PeekMatPos;
    float4 m_vDirection;
    float m_fPeekPrc;
    float m_fPeekSpeed;
    float m_fHorViewAngleMax;
    float m_fVertViewAngleMax;
    float m_fXAxesRotation;
    float m_fYAxesRotation;
    float m_fActivationFOV;
    bool m_bZoom;
};
