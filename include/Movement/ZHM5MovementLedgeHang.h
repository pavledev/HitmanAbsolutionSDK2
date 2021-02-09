#pragma once

#include "ZHM5BaseLedgeMovement.h"
#include "ZHitmanMorphemePostProcessorLedgeHangCallback.h"
#include "ZActor.h"
#include "ZControlledAnimLocomotion.h"
#include "HM5Utils.h"
#include "ZMapPoly.h"

class ZHM5MovementLedgeHang : public ZHM5BaseLedgeMovement, public ZHitmanMorphemePostProcessorLedgeHangCallback
{
public:
    SMatrix43 m_mvDestJumpUp320cm;
    bool m_bSecDestSet;
    float m_fJumpUp320FirstContact;
    float4 m_vPelvisPushDir;
    bool m_bTurningCorner;
    float m_fTurnCornerAngle;
    TEntityRef<ZActor> m_pVictim;
    TSharedPointer<ZControlledAnimLocomotion> m_pVictimLoco;
    float m_fAnimPrct;
    float m_fAnimDelta;
    ZString m_sVictimAnimSM;
    ZString m_sVictimAnim;
    float m_fAllignTime;
    float m_fFallSoundTime;
    bool m_bFallSoundTriggered;
    SMatrix m_mvVictimStartMatPos;
    SVector3 m_vNearEnemyPO;
    SMatrix m_mEnd;
    SMatrix m_mStart;
    HM5Utils::SAnimBlend m_sAnimBlend;
    ZMapPoly m_MapPoly;
    float m_fHandIKBlend;
    float m_fCameraEndBlendFraction;
    ZGameTime m_timeInLedgeHangPullUpDown;
    ZGameTime m_timeInLedgeHangPullLeftRight;
    bool m_bActivateButtonPrompt;
    bool m_bRequestControl;
    bool m_bMountFromTop;
    float m_fCameraPullVictimBlendInTime;
    float m_fEndCameraFollowFraction;
    float m_fActivateRagdollFraction;
    bool m_bCameraInitialized;
    float m_fDesiredStickLength;
    float m_fCurCamStickLength;
    float m_fDesiredHeight;
    float m_fCurCamHeight;
    float4 m_vDesiredGround;
    float4 m_vCurrentFocusPoint;
    SMatrix m_CameraGround;
};
