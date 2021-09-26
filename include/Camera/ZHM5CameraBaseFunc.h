#pragma once

#include "ECameraMode.h"
#include "ZHM5CameraColi.h"
#include "TEntityRef.h"
#include "SMatrix33.h"
#include "IFutureCameraState.h"
#include "SMatrix.h"

class ZHM5MainCamera;
class ZHitman5;
struct SGameUpdateEvent;
struct float4;

class __declspec(novtable) ZHM5CameraBaseFunc
{
public:
	ZHM5MainCamera* m_pMainCamera;
	TEntityRef<ZHitman5> m_rHitman;
	ECameraMode m_eCameraType;
	float m_fAngleYaw;
	float m_fAnglePitch;
	ZHM5CameraColi m_CameraColi;
	float m_fFOV;

	virtual ~ZHM5CameraBaseFunc() = default;
	virtual void ActivateCamera(const ZHM5CameraBaseFunc* pOldCamera);
	virtual void DeactivateCamera();
	virtual void UpdateCamera(const SGameUpdateEvent& updateEvent);
	virtual IFutureCameraState::SCameraState GetFutureCameraState() = 0;

	ZHM5CameraBaseFunc() = default;
	ZHM5CameraBaseFunc(ZHM5MainCamera* pMainCamera, const TEntityRef<ZHitman5>& rHitman, ECameraMode CamType);
	ZHM5MainCamera* GetMainCamera() const;
	TEntityRef<ZHitman5> Hitman() const;
	ECameraMode GetCameraType() const;
	SMatrix33 CalcCameraMatrixFromDir(const float4& vCamDir);
	static SMatrix CalcCameraMatrixFromPos(const float4& vFrom, const float4& vTo);
	void SetCameraFOV(const float fValue);
	void CalcGetCameraYawPitchFromDir(float& fYaw, float& fPitch, const float4& vDir) const;
	void CalcGetCameraYawPitch(float& fYaw, float& fPitch);
	bool CalcGetFocalPointFromCameraDir(float4& vFocal);
	SMatrix LerpCameraMatPos(const SMatrix& mvFrom, const SMatrix& mvTo, float fPrc);
};
