#pragma once

#include "ZEntityImpl.h"
#include "ZCameraEntity.h"

class ZFreeCameraControlEntity : public ZEntityImpl
{
public:
    ZEntityRef m_cameraEntity;
    bool m_bActive;
    bool m_bIsGameControlActive;
    ZCameraEntity* m_pControlledCameraEntity;
    float m_fMoveSpeed;
    float m_fTurnSpeed;
    float m_fMovementSpeedMultiplier;
    float m_fRotationSpeedMultiplier;
    float m_fMoveX;
    float m_fMoveY;
    float m_fMoveZ;
    bool m_bMoveInWorldSpace;
    bool m_bResetRoll;
    float m_fPitch;
    float m_fDeltaPitch;
    float m_fRoll;
    float m_fDeltaRoll;
    float m_fDeltaYaw;
    float m_fInitialFov;
    float m_fFov;
    float m_fDeltaFov;
    int m_nControllerId;
};
