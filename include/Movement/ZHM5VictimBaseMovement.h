#pragma once

#include "ZHM5BaseMovement.h"
#include "ZActor.h"
#include "TSharedPointer.h"
#include "ZControlledAnimLocomotion.h"
#include "HM5Utils.h"

class ZHM5VictimBaseMovement : ZHM5BaseMovement
{
    TEntityRef<ZActor> m_pVictim;
    TSharedPointer<ZControlledAnimLocomotion> m_pVictimLocomotion;
    bool m_bWantsControl;
    ZString m_StateMachineName;
    ZString m_AnimNodeName;
    unsigned int m_nAnimNodeID;
    unsigned int m_nMovementStatMachineID;
    SMatrix m_mvHMStartPos;
    SMatrix m_mvHMBlendInPos;
    SMatrix m_mvHMBlendOutPos;
    SMatrix m_mvHMExitPos;
    float m_fBlendInFraction;
    float m_fBlendOutFraction;
    float m_fEarlyOutFraction;
    float m_fAnimDurationReciprocal;
    float m_fAnimFraction;
    float m_fActivateRagdollFraction;
    bool m_bAttachCamera;
    float m_fCameraFOV;
    float m_fCameraBlendTime;
    float m_fEndCameraFollowFraction;
    bool m_bCCScaleActor;
    float m_fCCScaleUpWindowStartTime;
    float m_fCCScaleUpWindowEndTime;
    float m_fCCScaleDownWindowStartTime;
    float m_fCCScaleDownWindowEndTime;
    float m_fCCScaleUpBlend;
    float m_fCCScaleDownBlend;
    float m_fFallSoundTime;
    bool m_bFallSoundTriggered;
    bool m_bControlledStateEntered;
    bool m_bBlendToControlledState;
    bool m_bInterpolateCamBetweenFrames;
    float4 m_vNPCTranslationOffset;
    HM5Utils::SAnimBlend* m_pAnimBlends;
    SMatrix* m_pBlendMats;
    unsigned int m_nNumBlends;
    HM5Utils::SAnimBlend m_aBaseAnimBlends[4];
    SMatrix m_aBaseBlendMats[4];

    virtual bool SetUpAnimation();
    virtual bool InitTimeFractions();
    virtual void InitBlendMatrices();
    virtual SMatrix* GetColiFreeStartPos(SMatrix* result);
    virtual SMatrix* GetBlendInMatPos(SMatrix* result);
    virtual SMatrix* GetBlendOutMatPos(SMatrix* result);
    virtual SMatrix* CalcHitmanExitMatPos(SMatrix* result, const SMatrix*, const SMatrix*, unsigned int, float, float);
    virtual SMatrix* CalcAlignedMatPos(SMatrix* result, const SMatrix*, unsigned int, float);
};
