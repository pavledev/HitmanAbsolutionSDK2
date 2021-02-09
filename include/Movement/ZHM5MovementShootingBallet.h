#pragma once

#include "ZHM5BaseMovement.h"
#include "EShootingBalletState.h"
#include "SHM5SBShared.h"
#include "ZHM5ShootingBalletWeapon.h"
#include "SSBAnim.h"
#include "SBWeaponNodes.h"
#include "HM5Utils.h"
#include "SSBFocus.h"

class alignas(16) ZHM5MovementShootingBallet : public ZHM5BaseMovement
{
public:
    EShootingBalletState m_eShootingBalletState;
    SHM5SBShared m_SBShared;
    ZHM5ShootingBalletWeapon* m_pSBWeapon;
    bool m_bEnteredTagAnimNode;
    float m_fTagTime;
    ZGameTime m_StartRealTime;
    ZGameTime m_EndTime;
    bool m_bTagRampUpSignalSend;
    bool m_bAnyoneDamaged;
    float m_fCinMultiplier;
    float m_fForcedTimeMultiplier;
    const SSBAnim* m_pEndAnimation;
    float m_fImpactZoomTime;
    float m_fTagModeTimeMultiplyerOverride;
    ZMapPoly m_MapPoly;
    SBWeaponNodes* m_pWeaponNodes;
    ESBWeaponType m_eCurrentWeaponType;
    bool m_bKilledAllCharacterChecked;
    int m_nCharactersKilled;
    bool m_bReturnToCover;
    ZHM5CoverPlane* m_pLastCoverPlane;
    SMatrix m_mvLastCoverPos;
    bool m_bFaceRight;
    bool m_bCoverHighStance;
    bool m_bUsesManualControlForCamera;
    unsigned int m_nEnterFromCoverAnimID;
    unsigned int m_nSBWildCardTransitID;
    HM5Utils::SAnimBlend m_sAnimBlend;
    SMatrix m_mvStartMatPos;
    SMatrix m_mvDestMatPos;
    SMatrix m_mvCameraGroundStart;
    float4 m_vCameraOffset;
    bool m_bLerpCameraGround;
    float m_fCameraLerpFraction;
    float m_fBlendOutFraction;
    float4 m_avGripOffset[2];
    SQuaternion m_aqGripOrientation[2];
    float m_fCameraAim;
    bool m_bAimBlendOut;
    float m_fAimBlendOutTime;
    float m_afTagLookAtWeightsHorizontal[6];
    float m_afTagLookAtWeightsVertical[6];
    SSBFocus m_SBFocus;
    bool m_bForced;
    bool m_bAllowPlayerToExecute;
    bool m_bExecuteWhenInstinctRunsOut;
    TEntityRef<ZActor> m_rPrimaryActor;
    bool m_bForceExecute;
    float m_fStartFocus;
    bool m_bLookAtPoseChanged;
    bool m_bUpdateLookAt;
};
