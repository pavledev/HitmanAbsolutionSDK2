#include "ZHM5MainCamera.h"
#include "Function.h"
#include "BaseAddresses.h"

float4* ZHM5MainCamera::GetCameraWorldDir(float4* result)
{
	return Function::CallMethodAndReturn<float4*, ZHM5MainCamera*, float4*>(BaseAddresses::hitman5Dll + 0x1C3A, this, result);
}

bool ZHM5MainCamera::GotCameraBlendTree()
{
	return Function::CallMethodAndReturn<bool, ZHM5MainCamera*>(BaseAddresses::hitman5Dll + 0x2E46, this);
}

void ZHM5MainCamera::ActivateCameraMode(ECameraMode eCamMode)
{
	Function::CallMethod<ZHM5MainCamera*, ECameraMode>(BaseAddresses::hitman5Dll + 0x3A9E, this, eCamMode);
}

TEntityRef<ZSpatialEntity>* ZHM5MainCamera::GetFollowGeom(TEntityRef<ZSpatialEntity>* result)
{
	return Function::CallMethodAndReturn<TEntityRef<ZSpatialEntity>*, ZHM5MainCamera*, TEntityRef<ZSpatialEntity>*>(BaseAddresses::hitman5Dll + 0x5D85, this, result);
}

ZHM5VentilatorCamera* ZHM5MainCamera::GetVentCamera()
{
	return Function::CallMethodAndReturn<ZHM5VentilatorCamera*, ZHM5MainCamera*>(BaseAddresses::hitman5Dll + 0x74F0, this);
}

ZHM5ClosetCamera* ZHM5MainCamera::GetClosetCamera()
{
	return Function::CallMethodAndReturn<ZHM5ClosetCamera*, ZHM5MainCamera*>(BaseAddresses::hitman5Dll + 0xABAA, this);
}

void ZHM5MainCamera::ActivateMainCamera()
{
	Function::CallMethod<ZHM5MainCamera*>(BaseAddresses::hitman5Dll + 0xDB6B, this);
}

float ZHM5MainCamera::GetInitNearZ()
{
	return Function::CallMethodAndReturn<float, ZHM5MainCamera*>(BaseAddresses::hitman5Dll + 0x1175C, this);
}

void ZHM5MainCamera::OnActiveChanged()
{
	Function::CallMethod<ZHM5MainCamera*>(BaseAddresses::hitman5Dll + 0x11C3E, this);
}

SMatrix* ZHM5MainCamera::UpdateShakers(SMatrix* result, SMatrix* mCam)
{
	return Function::CallMethodAndReturn<SMatrix*, ZHM5MainCamera*, SMatrix*, SMatrix*>(BaseAddresses::hitman5Dll + 0x123C3, this, result, mCam);
}

ZHM5AnimCamera* ZHM5MainCamera::GetAnimCamera()
{
	return Function::CallMethodAndReturn<ZHM5AnimCamera*, ZHM5MainCamera*>(BaseAddresses::hitman5Dll + 0x14E07, this);
}

ZHM5CamFovModifier* ZHM5MainCamera::GetCamFovModifier()
{
	return Function::CallMethodAndReturn<ZHM5CamFovModifier*, ZHM5MainCamera*>(BaseAddresses::hitman5Dll + 0x15294, this);
}

void ZHM5MainCamera::DeactivateCheckPoint()
{
	Function::CallMethod<ZHM5MainCamera*>(BaseAddresses::hitman5Dll + 0x16072, this);
}

ZHM5CameraBaseFunc* ZHM5MainCamera::GetCurrentCamera()
{
	return Function::CallMethodAndReturn<ZHM5CameraBaseFunc*, ZHM5MainCamera*>(BaseAddresses::hitman5Dll + 0x16608, this);
}

void ZHM5MainCamera::CreateCameras(TEntityRef<ZHitman5>* rHitman)
{
	Function::CallMethod<ZHM5MainCamera*, TEntityRef<ZHitman5>*>(BaseAddresses::hitman5Dll + 0x176F2, this, rHitman);
}

void ZHM5MainCamera::SetCameraDirection(float4* vLookTo)
{
	Function::CallMethod<ZHM5MainCamera*, float4*>(BaseAddresses::hitman5Dll + 0x1B5E0, this, vLookTo);
}

TEntityRef<ZHM5SBCamProfiles>* ZHM5MainCamera::GetSBCamProfiles(TEntityRef<ZHM5SBCamProfiles>* result)
{
	return Function::CallMethodAndReturn<TEntityRef<ZHM5SBCamProfiles>*, ZHM5MainCamera*, TEntityRef<ZHM5SBCamProfiles>*>(BaseAddresses::hitman5Dll + 0x1B8EC, this, result);
}

ZHM5MainCamera* ZHM5MainCamera::operator=(ZHM5MainCamera* __that)
{
	return Function::CallMethodAndReturn<ZHM5MainCamera*, ZHM5MainCamera*, ZHM5MainCamera*>(BaseAddresses::hitman5Dll + 0x1C47C, this, __that);
}

float4* ZHM5MainCamera::GetCameraFollowGeomDir(float4* result)
{
	return Function::CallMethodAndReturn<float4*, ZHM5MainCamera*, float4*>(BaseAddresses::hitman5Dll + 0x1C7C4, this, result);
}

void ZHM5MainCamera::GeomTransformChangeCallback(ZEntityRef* entity, SMatrix43* mNewValue)
{
	Function::CallMethod<ZHM5MainCamera*, ZEntityRef*, SMatrix43*>(BaseAddresses::hitman5Dll + 0x1CE27, this, entity, mNewValue);
}

void ZHM5MainCamera::SetCameraMatrixWithDefaultListener(SMatrix* mWorld)
{
	Function::CallMethod<ZHM5MainCamera*, SMatrix*>(BaseAddresses::hitman5Dll + 0x1F622, this, mWorld);
}

float ZHM5MainCamera::BlendWithVirtualCameraIfNeeded(float fFoV)
{
	return Function::CallMethodAndReturn<float, ZHM5MainCamera*, float>(BaseAddresses::hitman5Dll + 0x22985, this, fFoV);
}

void ZHM5MainCamera::SetCameraMatrix(SMatrix* mWorld)
{
	Function::CallMethod<ZHM5MainCamera*, SMatrix*>(BaseAddresses::hitman5Dll + 0x286E1, this, mWorld);
}

void ZHM5MainCamera::EnableCameraControl()
{
	Function::CallMethod<ZHM5MainCamera*>(BaseAddresses::hitman5Dll + 0x28F51, this);
}

TEntityRef<ZHM5CameraProfileBlendDatabase>* ZHM5MainCamera::GetBlendDatabase(TEntityRef<ZHM5CameraProfileBlendDatabase>* result)
{
	return Function::CallMethodAndReturn<TEntityRef<ZHM5CameraProfileBlendDatabase>*, ZHM5MainCamera*, TEntityRef<ZHM5CameraProfileBlendDatabase>*>(BaseAddresses::hitman5Dll + 0x2973F, this, result);
}

void ZHM5MainCamera::DestroyCameras()
{
	Function::CallMethod<ZHM5MainCamera*>(BaseAddresses::hitman5Dll + 0x2C7E6, this);
}

void ZHM5MainCamera::ResetMainCamera()
{
	Function::CallMethod<ZHM5MainCamera*>(BaseAddresses::hitman5Dll + 0x2D029, this);
}

void ZHM5MainCamera::RegisterHitman(TEntityRef<ZHitman5>* rHitman)
{
	Function::CallMethod<ZHM5MainCamera*, TEntityRef<ZHitman5>*>(BaseAddresses::hitman5Dll + 0x2FA09, this, rHitman);
}

ZHM53rdPersonCamera* ZHM5MainCamera::Get3rdPersonCam()
{
	return Function::CallMethodAndReturn<ZHM53rdPersonCamera*, ZHM5MainCamera*>(BaseAddresses::hitman5Dll + 0x2FB26, this);
}

void ZHM5MainCamera::RegisterType()
{
	Function::Call<>(BaseAddresses::hitman5Dll + 0x2FCCA);
}

void ZHM5MainCamera::SetUserInputWeight(float fWeight)
{
	Function::CallMethod<ZHM5MainCamera*, float>(BaseAddresses::hitman5Dll + 0x315AC, this, fWeight);
}

void ZHM5MainCamera::DisableCameraControl()
{
	Function::CallMethod<ZHM5MainCamera*>(BaseAddresses::hitman5Dll + 0x320DD, this);
}

ZHM5ShootingBalletCamera* ZHM5MainCamera::GetSBCam()
{
	return Function::CallMethodAndReturn<ZHM5ShootingBalletCamera*, ZHM5MainCamera*>(BaseAddresses::hitman5Dll + 0x32C54, this);
}

void ZHM5MainCamera::SetSourceBlendTree(ZMainCameraBlendNodeEntity* cameraBlendTree)
{
	Function::CallMethod<ZHM5MainCamera*, ZMainCameraBlendNodeEntity*>(BaseAddresses::hitman5Dll + 0x370D3, this, cameraBlendTree);
}

void ZHM5MainCamera::HintCameraDirection(float4* vLookTo)
{
	Function::CallMethod<ZHM5MainCamera*, float4*>(BaseAddresses::hitman5Dll + 0x399FA, this, vLookTo);
}

SMatrix* ZHM5MainCamera::BlendWithVirtualCameraIfNeeded(SMatrix* result, SMatrix* mWorld)
{
	return Function::CallMethodAndReturn<SMatrix*, ZHM5MainCamera*, SMatrix*, SMatrix*>(BaseAddresses::hitman5Dll + 0x3B08E, this, result, mWorld);
}

void ZHM5MainCamera::SetCameraMatrixWithSeparateListener(SMatrix* mWorld, float4* vListenerPos)
{
	Function::CallMethod<ZHM5MainCamera*, SMatrix*, float4*>(BaseAddresses::hitman5Dll + 0x41F79, this, mWorld, vListenerPos);
}

TEntityRef<ZHM53rdPersonCamProfile>* ZHM5MainCamera::Get3rdPersonCamProfile(TEntityRef<ZHM53rdPersonCamProfile>* result)
{
	return Function::CallMethodAndReturn<TEntityRef<ZHM53rdPersonCamProfile>*, ZHM5MainCamera*, TEntityRef<ZHM53rdPersonCamProfile>*>(BaseAddresses::hitman5Dll + 0x44805, this, result);
}

bool ZHM5MainCamera::IsHighLayer(ECameraMode eCamMode)
{
	return Function::CallMethodAndReturn<bool, ZHM5MainCamera*, ECameraMode>(BaseAddresses::hitman5Dll + 0x467C2, this, eCamMode);
}

void ZHM5MainCamera::DeactivateMainCamera()
{
	Function::CallMethod<ZHM5MainCamera*>(BaseAddresses::hitman5Dll + 0x479D8, this);
}

bool ZHM5MainCamera::IsCameraInitialized()
{
	return Function::CallMethodAndReturn<bool, ZHM5MainCamera*>(BaseAddresses::hitman5Dll + 0x4A066, this);
}

void ZHM5MainCamera::DeactivateCameraMode()
{
	Function::CallMethod<ZHM5MainCamera*>(BaseAddresses::hitman5Dll + 0x4FBEC, this);
}

void ZHM5MainCamera::UpdateMainCamera(SGameUpdateEvent* updateEvent, bool bPaused)
{
	Function::CallMethod<ZHM5MainCamera*, SGameUpdateEvent*, bool>(BaseAddresses::hitman5Dll + 0x51195, this, updateEvent, bPaused);
}

ZHM5CameraBaseFunc* ZHM5MainCamera::GetCamera(ECameraMode eCamMode)
{
	return Function::CallMethodAndReturn<ZHM5CameraBaseFunc*, ZHM5MainCamera*, ECameraMode>(BaseAddresses::hitman5Dll + 0x51708, this, eCamMode);
}

ECameraMode ZHM5MainCamera::GetCurrentCameraMode()
{
	return Function::CallMethodAndReturn<ECameraMode, ZHM5MainCamera*>(BaseAddresses::hitman5Dll + 0x52090, this);
}

ZHM5CamShaker* ZHM5MainCamera::GetCamShaker(ECameraShakerChannel eChannel)
{
	return Function::CallMethodAndReturn<ZHM5CamShaker*, ZHM5MainCamera*, ECameraShakerChannel>(BaseAddresses::hitman5Dll + 0x52608, this, eChannel);
}
