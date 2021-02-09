#pragma once

#include "ECameraMode.h"
#include "ZHM5CameraColi.h"
#include "SCameraState.h"
#include "SGameUpdateEvent.h"
#include "TEntityRef.h"
#include "SMatrix33.h"

class ZHM5MainCamera;
class ZHitman5;

class ZHM5CameraBaseFunc
{
public:
    alignas(16) ZHM5MainCamera* m_pMainCamera;
    TEntityRef<ZHitman5> m_rHitman;
    ECameraMode m_eCameraType;
    float m_fAngleYaw;
    float m_fAnglePitch;
    ZHM5CameraColi m_CameraColi;
    float m_fFOV;

    virtual ~ZHM5CameraBaseFunc();
    virtual void ActivateCamera(const ZHM5CameraBaseFunc*);
    virtual void DeactivateCamera();
    virtual void UpdateCamera(const SGameUpdateEvent*);
    virtual SCameraState* GetFutureCameraState(SCameraState* result);

    ECameraMode GetCameraType();
    ZHM5MainCamera* GetMainCamera();
    void SetCameraFOV(float fValue);
    ZHM5CameraBaseFunc(ZHM5MainCamera* pMainCamera, TEntityRef<ZHitman5>* rHitman, ECameraMode CamType);
    TEntityRef<ZHitman5>* Hitman(TEntityRef<ZHitman5>* result);
    void CalcGetCameraYawPitchFromDir(float* fYaw, float* fPitch, float4* vDir);
    void CalcGetCameraYawPitch(float* fYaw, float* fPitch);
    bool CalcGetFocalPointFromCameraDir(float4* vFocal);
    SMatrix33* CalcCameraMatrixFromDir(SMatrix33* result, float4* vCamDir);
    SMatrix* CalcCameraMatrixFromPos(SMatrix* result, float4* vFrom, float4* vTo);
    SMatrix* LerpCameraMatPos(SMatrix* result, SMatrix* mvFrom, SMatrix* mvTo, float fPrc);
};
