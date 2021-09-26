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
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

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

	static SComponentMapEntry s_componentMap[0];

	~ZHM5MainCamera() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	void Start() override;
	void SetFovYDeg(float fFovYDeg) override;

	float4 GetListenerPos() const override;

	ZHM5MainCamera() = default;
	ZHM5MainCamera(const ZHM5MainCamera& __that);
	ZHM5MainCamera(ZComponentCreateInfo& pInfo);
	static void RegisterType();
	void UpdateMainCamera(const SGameUpdateEvent& updateEvent, bool bPaused);
	TEntityRef<ZSpatialEntity> GetFollowGeom() const;
	float4 GetCameraFollowGeomDir() const;
	bool IsCameraInitialized() const;
	bool GotCameraBlendTree() const;
	void ActivateCameraMode(ECameraMode eCamMode);
	void DeactivateCameraMode();
	ZHM5CameraBaseFunc* GetCurrentCamera() const;
	ECameraMode GetCurrentCameraMode();
	void DeactivateCheckPoint();
	ZHM5AnimCamera* GetAnimCamera() const;
	ZHM53rdPersonCamera* Get3rdPersonCam() const;
	ZHM5ShootingBalletCamera* GetSBCam() const;
	ZHM5ClosetCamera* GetClosetCamera() const;
	ZHM5VentilatorCamera* GetVentCamera() const;
	ZHM5CamShaker& GetCamShaker(ECameraShakerChannel eChannel);
	ZHM5CamFovModifier& GetCamFovModifier();
	void ResetMainCamera();
	void RegisterHitman(const TEntityRef<ZHitman5>& rHitman);
	void SetCameraMatrix(const SMatrix& mWorld);
	void SetCameraMatrixWithDefaultListener(const SMatrix& mWorld);
	void SetCameraMatrixWithSeparateListener(const SMatrix& mWorld, const float4& vListenerPos);
	float4 GetCameraWorldDir() const;
	TEntityRef<ZHM53rdPersonCamProfile> Get3rdPersonCamProfile() const;
	TEntityRef<ZHM5CameraProfileBlendDatabase> GetBlendDatabase() const;
	TEntityRef<ZHM5SBCamProfiles> GetSBCamProfiles() const;
	void DisableCameraControl();
	void EnableCameraControl();
	void SetSourceBlendTree(const ZMainCameraBlendNodeEntity* cameraBlendTree);
	void SetCameraDirection(const float4& vLookTo);
	void HintCameraDirection(const float4& vLookTo);
	void SetUserInputWeight(float fWeight);
	float GetInitNearZ() const;
	void GeomTransformChangeCallback(const ZEntityRef& entity, const SMatrix43& mNewValue);
	float BlendWithVirtualCameraIfNeeded(float fFoV);
	SMatrix BlendWithVirtualCameraIfNeeded(const SMatrix& mWorld);
	SMatrix UpdateShakers(const SMatrix& mCam);
	void OnActiveChanged();
	void DeactivateMainCamera();
	void ActivateMainCamera();
	void CreateCameras(const TEntityRef<ZHitman5>& rHitman);
	void DestroyCameras();
	ZHM5CameraBaseFunc* GetCamera(ECameraMode eCamMode);
	bool IsHighLayer(ECameraMode eCamMode) const;
	ZHM5MainCamera& operator=(const ZHM5MainCamera& __that);
};
