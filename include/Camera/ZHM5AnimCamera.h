#pragma once

#include "ZHM5CameraBaseFunc.h"
#include "SIOIEvent.h"
#include "eAnimCameraMode.h"
#include "HM5Utils.h"

class alignas(16) ZHM5AnimCamera : public ZHM5CameraBaseFunc
{
public:
    unsigned int m_nActiveAnimNodeId;
    TEntityRef<IMorphemeEntity> m_pMorph;
    ZMorphemeNetworkInstance* m_pMorphemeNetworkHitman;
    ZMorphemeNetworkInstance* m_pMorphemeNetworkCustom;
    unsigned int m_nCamBoneId;
    ZLinkedEntity* m_pLinkedPtr;
    ZSpatialEntity* m_pSpatialPtr;
    float m_fTargetFOV;
    ZGameTime m_tActivationTime;
    float m_fBlendInDuration;
    float m_fBlendInTime;
    float m_fStartFOV;
    ZMapPoly m_MapPoly;
    SIOIEvent m_Events[32];
    int m_nNumOfEvents;
    bool m_bBlendToAnimCam;
    bool m_bCheckCamColi;
    bool m_bPushFocalPointOut;
    eAnimCameraMode m_eAnimCameraMode;
    bool m_bCalculateFromEndOfAnimation;
    SMatrix m_mvEndOfAnimationMatrix;
    SMatrix m_mvStartMatPos;
    HM5Utils::SYawPitchBlend m_YawPitchBlend;
    bool m_bCalculateDeltaForBlend;
    bool m_bBlendToGameCamera;
    SMatrix m_mvGameCameraGround;
    ECameraState m_eGameCameraState;
    ECameraOffset m_eCameraOffset;
    SMatrix m_mvAnimStart;
    bool m_bInterpolateBetweenFrames;
};
