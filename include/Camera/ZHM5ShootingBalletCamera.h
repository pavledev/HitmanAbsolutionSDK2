#pragma once

#include "ZHM5CameraBaseFunc.h"
#include "ESBView.h"
#include "SHM5SBShared.h"
#include "SSBCamTargetProfile.h"
#include "ZHM5SBCamProfiles.h"
#include "SCameraCollisionVariable.h"
#include "SSoftCollisionCache.h"
#include "AutoRotationOnZoom.h"
#include "SSBAnim.h"

class alignas(16) ZHM5ShootingBalletCamera : public ZHM5CameraBaseFunc
{
public:
    ESBView m_eCurrentView;
    SHM5SBShared* m_pSBShared;
    ZMapPoly m_MapPoly;
    ZMapPoly m_MapPolyZoom;
    unsigned int m_nLookAtTag;
    float4 m_vPointOfInterest;
    float4 m_vCamPos;
    float m_fUserPitch;
    float m_fCameraYaw;
    float m_fYawBuffer;
    float m_fPitchBuffer;
    float m_fCameraPitch;
    bool m_bAnimIsTargetView;
    SMatrix m_mCamEnd;
    unsigned int m_nZoomTag;
    unsigned int m_nZoomBoneId;
    bool m_bDetached;
    bool m_bAreaClear;
    SSBCamHitmanProfile m_StartProfile;
    float m_fYawToLastTag;
    float m_fPitchToLastTag;
    float m_fLastTagLength;
    float4 m_vLookAtPos;
    float m_fLookAtTagStartFraction;
    bool m_bInterpolateLookAtPos;
    const SSBAnim* m_pCurrentAnim;
    unsigned int m_nAnimationTag;
    int m_nCamAnimBone;
    float m_fImpactViewZoomTime;
    float m_fImpactViewFraction;
    float m_fZoomBoneTime;
    float4 m_vZoomStartCam;
    float m_fZoomDeltaYaw;
    float m_fZoomDeltaPitch;
    float m_fZoomFovStart;
    bool m_bEndStartInterpolation;
    bool m_bOverwriteListenerPos;
    bool m_bPitchFlip;
    float m_fImpactViewRollAngle;
    float m_fImpactViewDist;
    float m_fImpactViewSpeedYaw;
    float m_fImpactViewSpeedPitch;
    SSBCamHitmanProfile m_HitmanTargetProfile;
    SSBCamTargetProfile m_TargetProfile;
    unsigned int m_nTargetProfileIndex;
    SSBCamHitmanProfile m_HitmanViewProfile;
    TEntityRef<ZHM5SBCamProfiles> m_rSBCamProfiles;
    bool m_bZoomComplete;
    bool m_bBehindNPC;
    SCameraCollisionVariable m_CameraCollision;
    SSoftCollisionCache m_SoftCollisionCache;
    SSoftCollisionCache m_SoftCollisionObstacleCache;
    float m_fStickLengthPullIn;
    float m_fObstacleCollideTime;
    AutoRotationOnZoom m_autoRotate;

    class alignas(16) SSBCamUpdate
    {
    public:
        float4 m_vCollisionFrom;
        float4 m_vCollisionTo;
        float4 m_vCamDir;
        float4 m_vLookAtPoint;
        bool m_bLookAtPoint;
        bool m_bUpdateCam;
        float m_fRoll;
        float m_fFovY;
    };
};
