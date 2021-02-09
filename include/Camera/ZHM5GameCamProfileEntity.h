#pragma once

#include "ZEntityImpl.h"
#include "ECameraState.h"
#include "ECameraControls.h"

class alignas(4) ZHM5GameCamProfileEntity : public ZEntityImpl
{
public:
    bool m_bAlignYawPitch;
    float m_fPitchAngle;
    float m_fYawAngle;
    float m_fHeight;
    float m_fStickLength;
    float m_fRadius;
    float m_fRadiusLeft;
    float m_fRotationOffsetY;
    float m_fFOV;
    float m_fPrecisionShotFOV;
    float m_fBlendTime;
    float m_fProfileBlendTime;
    float m_fFacingOffsetX;
    ECameraState m_eState;
    TArray<ECameraState> m_aeStates;
    int m_nPriority;
    float m_fPitchMaxOffset;
    float m_fPitchMinOffset;
    float m_fYawOffset;
    float m_fYawBase;
    bool m_bEnableSmootingAtLimits;
    bool m_bYawBlendOutRadius;
    bool m_bYawAnimation;
    float m_fRotationOffsetYYaw;
    float m_fStickLengthYaw;
    float m_fYawAnimationRange;
    bool m_bPitchAnimation;
    float m_fHeightPitch;
    float m_fPitchAngle0;
    float m_fPitchAngle1;
    bool m_bEnablePitchLevelOut;
    bool m_bEnableSmoothing;
    bool m_bEnableAimAssist;
    ECameraControls m_eCameraControls;
    bool m_bUseCollisionHeight;
    float m_fCollisionHeight;
    bool m_bAimPushOut;
    bool m_bEnableSoftCollision;
    float m_fTossHeight;
    bool m_bActivated;
};
