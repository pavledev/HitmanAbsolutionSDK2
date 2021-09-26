#pragma once

#include "ZHM5CameraBaseFunc.h"
#include "ZHM5MovementVentilatorShaft.h"
#include "HM5Utils.h"
#include "ZMapPoly.h"
#include "ECameraState.h"

class ZHM5VentilatorCamera : public ZHM5CameraBaseFunc
{
public:
	float4 m_vLastPosition;
	SMatrix m_CamAtActivation;
	float m_fFOVAtActivation;
	float4 m_vDirection;
	unsigned int m_nCameraBoneId;
	ZHM5MovementVentilatorShaft* m_pMovement;
	float m_fXAxesRotation;
	float m_fYAxesRotation;
	TEntityRef<ZSpatialEntity> m_rPeekPosition;
	bool m_bFlipPeekZ;
	float m_fInsideVentilator;
	float m_fCameraBonePeekPositionPrc;
	float m_fMainCameraNearZ;
	bool m_bBlendIn;
	float m_fBlendInPrc;
	float4 m_vBlendInPosition;
	ZMorphemeNetworkInstance* m_pNetwork;
	ZMapPoly m_MapPoly;
	bool m_bBlendToGameCamera;
	HM5Utils::SYawPitchBlend m_YawPitchBlend;
	SMatrix m_mvGameCameraGround;
	SMatrix m_mvEndOfAnimationMatrix;
	ECameraState m_eGameCameraState;
	int m_nCamBoneMeshId;
	float m_fAnimDuration;
	float m_fMountBlendInFraction;
	float m_fDismountBlendOutFraction;
	float m_fDismountBlendOutFractionToGameCam;

	~ZHM5VentilatorCamera() override = default;
	void ActivateCamera(const ZHM5CameraBaseFunc* pOldCamera) override;
	void DeactivateCamera() override;
	void UpdateCamera(const SGameUpdateEvent& updateEvent) override;
	IFutureCameraState::SCameraState GetFutureCameraState() override;

	ZHM5VentilatorCamera() = default;
	ZHM5VentilatorCamera(ZHM5MainCamera* pMainCamera, const TEntityRef<ZHitman5>& rHitman, ECameraMode CamType);
	void SetPeekPosition(const TEntityRef<ZSpatialEntity>& Ref);
	void SetInsideVentilator(float fFraction);
	void ResetLookXY();
	bool IsZoomActive() const;
	void SetCameraBonePeekPositionPrc(float fValue);
	void SetFlipPeekZ(bool bValue);
	void SetBlendToGameCamera(const SMatrix& mvGameCameraGround, const SMatrix& mvEndOfAnimationMatrix, ECameraState eGameCameraState, unsigned int nAnimNodeId);
	void CalcCameraMatPosFromPeekPosition(SMatrix& m0);
	float GetEventFraction(unsigned int nAnimNode, unsigned int nEvent) const;
};
