#pragma once

#include "ZHM5BaseMovement.h"
#include "ZHitmanMorphemePostProcessorFiberWireCallback.h"
#include "ZActor.h"
#include "EMoveType.h"
#include "ZControlledAnimLocomotion.h"
#include "HM5Utils.h"

class ZHM5MovementFiberWireKill : public ZHM5BaseMovement, public ZHitmanMorphemePostProcessorFiberWireCallback
{
public:
    TEntityRef<ZActor> m_pVictim;
    ZString m_sVictimAnimSM;
    ZString m_sVictimAnim;
    unsigned int m_nActiveAnimId;
    unsigned int m_nToStandOrSneakAnimId;
    float m_fAnimFraction;
    float m_fAnimFraction2;
    float m_fAnimDelta;
    float m_fAnimDelta2;
    float m_fAlignTime;
    float m_fContactTime;
    float m_fDropItemsFraction;
    SMatrix m_mVictimStart;
    SMatrix m_mVictionAlign;
    float m_fHandRetargetFrom;
    float m_fHandRetargetTo;
    float m_fNPCDeadFraction;
    float m_fImpactFraction;
    float m_fDragBlendHeightLow;
    float m_fDragBlendHeightHigh;
    EMoveType m_eMoveType;
    bool m_bUpdate;
    TSharedPointer<ZControlledAnimLocomotion> m_pLoco;
    TEntityRef<IHM5Item> m_rFiberWire;
    bool m_bEffectPlayed;
    bool m_bShortAnim;
    bool m_bActivateButtonPrompt;
    float m_fCurrentTimeMultiplier;
    float m_fFailSafeEndFraction;
    float m_fFiberWireFeedBackWeight;
    int m_nDragBoneMeshId;
    SMatrix m_mvHitmanStartMatPos;
    SMatrix m_mvHitmanDestMatPos;
    HM5Utils::SAnimBlend m_sAnimBlend;
    float m_fEndCameraFollowFraction;
    bool m_bCameraInitialized;
    float m_fDesiredStickLength;
    float m_fCurCamStickLength;
    float m_fDesiredHeight;
    float m_fCurCamHeight;
    float4 m_vDesiredGround;
    float4 m_vCurrentFocusPoint;
    SMatrix m_CameraGround;
};
