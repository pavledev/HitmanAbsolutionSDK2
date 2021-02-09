#pragma once

#include "ZHM5BaseMovement.h"
#include "ELocoState.h"
#include "ZHM5LocomotionNetwork.h"
#include "ZHM5LocomotionInput.h"

class alignas(16) ZHM5MovementLocomotion : public ZHM5BaseMovement
{
public:
    ELocoState m_eLocoState;
    ZHM5LocomotionNetwork m_LocomotionNetwork;
    ZHM5LocomotionInput m_LocomotionInput;
    unsigned int m_nRequestEnterLocomotion;
    unsigned int m_nControlParamSneakSpeedFactorID;
    unsigned int m_nControlParamSneakPelvisAngleID;
    unsigned int m_nControlParamSneakPelvisOffssetID;
    unsigned int m_nControlParamWalkTurnSpeedID;
    unsigned int n_nControlParamRunTurnSpeedID;
    unsigned int m_nLocomotionState;
    unsigned int m_nStandMask;
    unsigned int m_nStrafeMask;
    ENetworkState m_eNetworkStartState;
    bool m_bStartRight;
    bool m_bStartRunning;
    bool m_bLerpPos;
    bool m_bLerpCameraGround;
    float m_fTransitionInFraction;
    int m_nHMMovementIndex;
    float4 m_vStartPos;
    float4 m_vLerpPos;
    SMatrix m_mCameraGroundStart;
    ZMapPoly m_Mapper;
    float m_fSwingAtWillWeight;
    float m_fSwingAtWillHoldTime;
    bool m_bSwingAtWillActive;
    float m_fAimTime;
    ZMapPoly m_MapPolyAim;
    SInputRestriction m_InputRestriction;
    SMatrix m_mStandRotBase;
    SMatrix m_mSneakdRotBase;
    bool m_bLookAtPointInitialized;
    float4 m_vLookAtPoint;
    float4 m_vLookAtDir;
    float m_fLookAtHoldTime;
    float m_fLookAtTargetWeight;
    float m_fMaxYaw;
    float m_fMaxPitch;
    float m_afStandLookAtHorWeights[6];
    float m_afStandLookAtVerWeights[6];
    float m_afSneakLookAtHorWeights[6];
    float m_afSneakLookAtVerWeights[6];
    float m_afLookAtHorWeights[6];
    float m_afLookAtVerWeights[6];
    bool m_bOpenDoorActive;
    float m_fOpenDoorWeight;
};
