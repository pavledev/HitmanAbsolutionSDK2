#pragma once

#include "ZHM5VictimBaseMovement.h"
#include "ZHM5BaseGuide.h"

class ZHM5MovementKickVictim : public ZHM5VictimBaseMovement
{
public:
    bool m_bWantsControl;
    bool m_bGrabEventSent;
    ZHM5BaseGuide* m_pLedge;
    SMatrix m_aBlendMats[4];
    HM5Utils::SAnimBlend m_aAnimBlends[4];
    bool m_bCameraInitialized;
    float m_fDesiredStickLength;
    float m_fCurCamStickLength;
    float m_fDesiredHeight;
    float m_fCurCamHeight;
    float4 m_vDesiredGround;
    float4 m_vCurrentFocusPoint;
    SMatrix m_CameraGround;
};
