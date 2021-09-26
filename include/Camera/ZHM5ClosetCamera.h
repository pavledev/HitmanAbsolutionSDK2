#pragma once

#include "ZHM5CameraBaseFunc.h"
#include "ECameraMode.h"
#include "IFutureCameraState.h"
#include "SMatrix.h"
#include "float4.h"

class ZHM5MainCamera;
class ZHitman5;
struct SGameUpdateEvent;
template <class T> class TEntityRef;

class ZHM5ClosetCamera : public ZHM5CameraBaseFunc
{
public:
	float m_fMainCameraNearZ;
	SMatrix m_MatPos;
	SMatrix m_PeekMatPos;
	float4 m_vDirection;
	float m_fPeekPrc;
	float m_fPeekSpeed;
	float m_fHorViewAngleMax;
	float m_fVertViewAngleMax;
	float m_fXAxesRotation;
	float m_fYAxesRotation;
	float m_fActivationFOV;
	bool m_bZoom;

	~ZHM5ClosetCamera() override = default;
	void ActivateCamera(const ZHM5CameraBaseFunc* pOldCamera) override;
	void DeactivateCamera() override;
	void UpdateCamera(const SGameUpdateEvent& updateEvent) override;
	IFutureCameraState::SCameraState GetFutureCameraState() override;

	ZHM5ClosetCamera() = default;
	ZHM5ClosetCamera(ZHM5MainCamera* pMainCamera, const TEntityRef<ZHitman5>& rHitman, ECameraMode CamType);
	void SetPeekMatPos(const SMatrix& m0);
	void SetStartPeekMatPos(const SMatrix& m0);
	void SetHorAngleLimit(float fMaxHorAngle);
	void SetVertAngleLimit(float fMaxVertAngle);
	float GetPeekPrc() const;
};
