#pragma once

#include "ZCameraEntity.h"
#include "ZHM53rdPersonCamProfile.h"
#include "ZHM5CameraProfileBlendDatabase.h"
#include "ZHM5SBCamProfiles.h"
#include "ZHM53rdPersonCamera.h"
#include "ZHM5ShootingBalletCamera.h"
#include "ZHM5AnimCamera.h"
#include "ZHM5ClosetCamera.h"
#include "ZHM5VentilatorCamera.h"
#include "ZHM5CamShaker.h"
#include "ZHM5CamFovModifier.h"
#include "ZMainCameraBlendNodeEntity.h"
#include "ZHM5CameraBaseFunc.h"
#include "ECameraShakerChannel.h"

class ZHitman5;

class ZHM5MainCamera : public ZCameraEntity
{
public:
    bool m_bActive;
    TEntityRef<ZHM53rdPersonCamProfile> m_rHM53rdPersonCamProfile;
    TEntityRef<ZHM5CameraProfileBlendDatabase> m_rCameraProfileBlendDatabase;
    TEntityRef<ZHM5SBCamProfiles> m_rSBCamProfiles;
    bool m_bSetWorldMatrixOnUpdates;
    ZHM5CameraBaseFunc* m_pCurrentCamera;
    ZHM53rdPersonCamera* m_p3rdPersonCamera;
    ZHM5ShootingBalletCamera* m_pShootingBalletCamera;
    ZHM5AnimCamera* m_pAnimCamera;
    ZHM5ClosetCamera* m_pClosetCamera;
    ZHM5VentilatorCamera* m_pVentilatorCamera;
    ZHM5CamShaker m_aCamShaker[5];
    ZHM5CamFovModifier m_CamFovModifier;
    ECameraMode m_eCameraLowLayer;
    bool m_bCameraInitialized;
    ZResourcePtr m_FreeCameraControlFactory;
    const ZMainCameraBlendNodeEntity* m_cameraBlendTree;
    TEntityRef<ZHitman5> m_rHitman;
    float m_fGameCamFov;
    float m_fInitNearZ;

    virtual ~ZHM5MainCamera();
    virtual ZVariantRef* GetVariantRef(ZVariantRef* result);
    virtual int AddRef();
    virtual int Release();
    virtual void* QueryInterface(STypeID* iid);
    virtual void Init();
    virtual void Start();
    virtual void SetFovYDeg(float fFovYDeg);
    virtual float4* GetListenerPos(float4* result);

    float4* GetCameraWorldDir(float4* result);
    bool GotCameraBlendTree();
    void ActivateCameraMode(ECameraMode eCamMode);
    TEntityRef<ZSpatialEntity>* GetFollowGeom(TEntityRef<ZSpatialEntity>* result);
    ZHM5VentilatorCamera* GetVentCamera();
    ZHM5ClosetCamera* GetClosetCamera();
    void ActivateMainCamera();
    float GetInitNearZ();
    ZHM5MainCamera(ZHM5MainCamera* __that);
    void OnActiveChanged();
    SMatrix* UpdateShakers(SMatrix* result, SMatrix* mCam);
    ZHM5AnimCamera* GetAnimCamera();
    ZHM5CamFovModifier* GetCamFovModifier();
    void DeactivateCheckPoint();
    ZHM5CameraBaseFunc* GetCurrentCamera();
    void CreateCameras(TEntityRef<ZHitman5>* rHitman);
    void SetCameraDirection(float4* vLookTo);
    TEntityRef<ZHM5SBCamProfiles>* GetSBCamProfiles(TEntityRef<ZHM5SBCamProfiles>* result);
    ZHM5MainCamera* operator=(ZHM5MainCamera* __that);
    float4* GetCameraFollowGeomDir(float4* result);
    void GeomTransformChangeCallback(ZEntityRef* entity, SMatrix43* mNewValue);
    void SetCameraMatrixWithDefaultListener(SMatrix* mWorld);
    ZHM5MainCamera(ZComponentCreateInfo* pInfo);
    float BlendWithVirtualCameraIfNeeded(float fFoV);
    void SetCameraMatrix(SMatrix* mWorld);
    void EnableCameraControl();
    TEntityRef<ZHM5CameraProfileBlendDatabase>* GetBlendDatabase(TEntityRef<ZHM5CameraProfileBlendDatabase>* result);
    void DestroyCameras();
    void ResetMainCamera();
    void RegisterHitman(TEntityRef<ZHitman5>* rHitman);
    ZHM53rdPersonCamera* Get3rdPersonCam();
    static void RegisterType();
    void SetUserInputWeight(float fWeight);
    void DisableCameraControl();
    ZHM5ShootingBalletCamera* GetSBCam();
    void SetSourceBlendTree(ZMainCameraBlendNodeEntity* cameraBlendTree);
    void HintCameraDirection(float4* vLookTo);
    SMatrix* BlendWithVirtualCameraIfNeeded(SMatrix* result, SMatrix* mWorld);
    void SetCameraMatrixWithSeparateListener(SMatrix* mWorld, float4* vListenerPos);
    TEntityRef<ZHM53rdPersonCamProfile>* Get3rdPersonCamProfile(TEntityRef<ZHM53rdPersonCamProfile>* result);
    bool IsHighLayer(ECameraMode eCamMode);
    void DeactivateMainCamera();
    bool IsCameraInitialized();
    void DeactivateCameraMode();
    void UpdateMainCamera(SGameUpdateEvent* updateEvent, bool bPaused);
    ZHM5CameraBaseFunc* GetCamera(ECameraMode eCamMode);
    ECameraMode GetCurrentCameraMode();
    ZHM5CamShaker* GetCamShaker(ECameraShakerChannel eChannel);
};
