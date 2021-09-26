#pragma once

#include "ZHM5CameraBaseFunc.h"
#include "SIOIEvent.h"
#include "eAnimCameraMode.h"
#include "HM5Utils.h"
#include "ZMapPoly.h"
#include "ECameraState.h"
#include "ECameraOffset.h"
#include "ZGameTime.h"

class IMorphemeEntity;
class ZLinkedEntity;
class ZSpatialEntity;

class ZHM5AnimCamera : public ZHM5CameraBaseFunc
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

	~ZHM5AnimCamera() override = default;
	void ActivateCamera(const ZHM5CameraBaseFunc* pOldCamera) override;
	void DeactivateCamera() override;
	void UpdateCamera(const SGameUpdateEvent& updateEvent) override;
	IFutureCameraState::SCameraState GetFutureCameraState() override;

	ZHM5AnimCamera() = default;
	ZHM5AnimCamera(ZHM5MainCamera* pMainCamera, const TEntityRef<ZHitman5>& rHitman, ECameraMode CamType);
	void SetActiveAnimNodeId(unsigned int nNodeId);
	void SetActiveAnimNodeIdAndEvents(unsigned int nNodeId);
	void SetTargetFOV(float fFOV);
	void SetBlendInDuration(float fBlendDuration);
	void SetCamBoneID(unsigned int id);
	void SetCheckCamColi(bool bVal);
	void SetAnimCameraMode(eAnimCameraMode AnimCameraMode);
	void SetCustomNetworkInstance(ZMorphemeNetworkInstance* pMorphemeNetworkCustom);
	void SetCalcualteFromEndOfAnimation(bool b);
	void SetEndOfAnimationMatrix(const SMatrix& m);
	void SetBlendToGameCamera(const SMatrix& mvCameraGround, ECameraState eCameraState, ECameraOffset eCameraOffset);
	void SetInterpolateBetweenFrames(const SMatrix& mvAnimStart, bool bInterpolateBetweenFrames);
	void UpdateFOV(float fFraction);
	void ResetToDefaults();
	ZMorphemeNetworkInstance* GetActiveNetworkInstance() const;
	bool CheckCameraCollision(const float4& vFrom, const float4& vTo, float4& vColiPoint);
	bool HandleCheckCut(float fTimeFraction, unsigned int& nCutCameraBoneId);
};
