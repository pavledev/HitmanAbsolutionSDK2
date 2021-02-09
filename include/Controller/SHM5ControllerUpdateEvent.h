#pragma once

#include "SGameUpdateEvent.h"
#include "SMatrix.h"
#include "SVector2.h"
#include "ZHM5BaseMovement.h"

class alignas(16) SHM5ControllerUpdateEvent
{
public:
    SGameUpdateEvent m_GameUpdateEvent;
    SMatrix m_mHitman;
    SMatrix m_mInvHitman;
    SMatrix m_mCamera;
    SVector2 m_vCameraRelativeTurn;
    bool m_bCameraRightSide;
    ZHM5BaseMovement* m_pCurrentMovement;
    bool m_bIsFiring;
};
