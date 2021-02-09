#pragma once

#include "ZHM5VictimBaseMovement.h"
#include "ZHM5GuideWindow.h"
#include "EWindowStatus.h"

class ZHM5MovementPullVictimThroughWindow : public ZHM5VictimBaseMovement
{
public:
    ZHM5GuideWindow* m_pWindow;
    EWindowStatus m_WindowStatus;
    ZHM5GuideLedge* m_pLedge;
    float m_fBlendInFraction;
    float m_fBlendOutFraction;
    SMatrix m_aBlendMats[4];
    HM5Utils::SAnimBlend m_aAnimBlends[4];
    bool m_bGrabEventSent;
    bool m_bAnimateWindow;
    SMatrix m_mvWindowStartMatPos;
    float m_fStartWindowAnimTime;
    float m_fStopWindowAnimTime;
    float4 m_vWindowDeltaZ;
    ECameraOffset m_eCameraOffset;
    bool m_bActivateButtonPrompt;
    bool m_bVictimFacingBack;
    bool m_bCameraInitialized;
    float m_fDesiredStickLength;
    float m_fCurCamStickLength;
    float m_fDesiredHeight;
    float m_fCurCamHeight;
    float4 m_vDesiredGround;
    float4 m_vCurrentFocusPoint;
    SMatrix m_CameraGround;
};
