#include "ZHM5CameraBaseFunc.h"
#include "Function.h"
#include "BaseAddresses.h"

ECameraMode ZHM5CameraBaseFunc::GetCameraType()
{
	return Function::CallMethodAndReturn<ECameraMode, ZHM5CameraBaseFunc*>(BaseAddresses::hitman5Dll + 0x28F280, this);
}

ZHM5MainCamera* ZHM5CameraBaseFunc::GetMainCamera()
{
	return Function::CallMethodAndReturn<ZHM5MainCamera*, ZHM5CameraBaseFunc*>(BaseAddresses::hitman5Dll + 0x39ACF0, this);
}

void ZHM5CameraBaseFunc::SetCameraFOV(float fValue)
{
	Function::CallMethod<ZHM5CameraBaseFunc*, float>(BaseAddresses::hitman5Dll + 0x3AD3C0, this, fValue);
}

TEntityRef<ZHitman5>* ZHM5CameraBaseFunc::Hitman(TEntityRef<ZHitman5>* result)
{
	return Function::CallMethodAndReturn<TEntityRef<ZHitman5>*, ZHM5CameraBaseFunc*, TEntityRef<ZHitman5>*>(BaseAddresses::hitman5Dll + 0x3AD4D0, this, result);
}

void ZHM5CameraBaseFunc::CalcGetCameraYawPitchFromDir(float* fYaw, float* fPitch, float4* vDir)
{
	Function::CallMethod<ZHM5CameraBaseFunc*, float*, float*, float4*>(BaseAddresses::hitman5Dll + 0x3AD510, this, fYaw, fPitch, vDir);
}

void ZHM5CameraBaseFunc::CalcGetCameraYawPitch(float* fYaw, float* fPitch)
{
	Function::CallMethod<ZHM5CameraBaseFunc*, float*, float*>(BaseAddresses::hitman5Dll + 0x3AD760, this, fYaw, fPitch);
}

bool ZHM5CameraBaseFunc::CalcGetFocalPointFromCameraDir(float4* vFocal)
{
	return Function::CallMethodAndReturn<bool, ZHM5CameraBaseFunc*, float4*>(BaseAddresses::hitman5Dll + 0x3AD7C0, this, vFocal);
}

SMatrix33* ZHM5CameraBaseFunc::CalcCameraMatrixFromDir(SMatrix33* result, float4* vCamDir)
{
	return Function::CallMethodAndReturn<SMatrix33*, ZHM5CameraBaseFunc*, SMatrix33*, float4*>(BaseAddresses::hitman5Dll + 0x3ADB70, this, result, vCamDir);
}

SMatrix* ZHM5CameraBaseFunc::CalcCameraMatrixFromPos(SMatrix* result, float4* vFrom, float4* vTo)
{
	return Function::CallAndReturn<SMatrix*, SMatrix*, float4*, float4*>(BaseAddresses::hitman5Dll + 0x3ADC80, result, vFrom, vTo);
}

SMatrix* ZHM5CameraBaseFunc::LerpCameraMatPos(SMatrix* result, SMatrix* mvFrom, SMatrix* mvTo, float fPrc)
{
	return Function::CallMethodAndReturn<SMatrix*, ZHM5CameraBaseFunc*, SMatrix*, SMatrix*, SMatrix*, float>(BaseAddresses::hitman5Dll + 0x3ADDD0, this, result, mvFrom, mvTo, fPrc);
}
