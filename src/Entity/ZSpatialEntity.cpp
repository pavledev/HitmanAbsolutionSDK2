#include "ZSpatialEntity.h"

SMatrix* ZSpatialEntity::GetObjectToWorldMatrix(SMatrix* matrix)
{
	return Function::CallMethodAndReturn<SMatrix*, ZSpatialEntity*, SMatrix*>(BaseAddresses::hitman5Dll + 0x8D8F62, this, matrix);
}

void ZSpatialEntity::SetObjectToWorldMatrix(SMatrix* matrix)
{
	Function::CallMethod<ZSpatialEntity*, SMatrix*>(BaseAddresses::hitman5Dll + 0x8D8F68, this, matrix);
}

float4* ZSpatialEntity::GetWorldPosition(float4* f)
{
	return Function::CallMethodAndReturn<float4*, ZSpatialEntity*, float4*>(BaseAddresses::hitman5Dll + 0x8D8F74, this, f);
}

float4* ZSpatialEntity::GetWorldDirection(float4* f1, float4* f2)
{
	return Function::CallMethodAndReturn<float4*, ZSpatialEntity*, float4*, float4*>(BaseAddresses::hitman5Dll + 0x8D8FBC, this, f1, f2);
}

void ZSpatialEntity::UnregisterObjectToWorldChangeCallBack(ZDelegate<void __cdecl (ZEntityRef const&, SMatrix43 const&)> const& zDelegate)
{
	Function::CallMethod<ZSpatialEntity*, ZDelegate<void __cdecl (ZEntityRef const&, SMatrix43 const&)> const&>(BaseAddresses::hitman5Dll + 0x8D90E2, this, zDelegate);
}

void ZSpatialEntity::RegisterObjectToWorldChangeCallBack(ZDelegate<void __cdecl (ZEntityRef const&, SMatrix43 const&)> const& zDelegate)
{
	Function::CallMethod<ZSpatialEntity*, ZDelegate<void __cdecl (ZEntityRef const&, SMatrix43 const&)> const&>(BaseAddresses::hitman5Dll + 0x8D90E8, this, zDelegate);
}

float4* ZSpatialEntity::GetWorldPosition(float4* f1, float4* f2)
{
	return Function::CallMethodAndReturn<float4*, ZSpatialEntity*, float4*, float4*>(BaseAddresses::hitman5Dll + 0x8D9100, this, f1, f2);
}

void ZSpatialEntity::SetWorldPosition(float4* f)
{
	Function::CallMethod<ZSpatialEntity*, float4*>(BaseAddresses::hitman5Dll + 0x8D9106, this, f);
}

float4* ZSpatialEntity::GetLocalPosition(float4* f1, float4* f2)
{
	return Function::CallMethodAndReturn<float4*, ZSpatialEntity*, float4*, float4*>(BaseAddresses::hitman5Dll + 0x8D9112, this, f1, f2);
}

ZSpatialEntity* ZSpatialEntity::GetTransformParent()
{
	return Function::CallMethodAndReturn<ZSpatialEntity*, ZSpatialEntity*>(BaseAddresses::hitman5Dll + 0x8D9118, this);
}

void ZSpatialEntity::Detach()
{
	Function::CallMethod<ZSpatialEntity*>(BaseAddresses::hitman5Dll + 0x8D9130, this);
}

SMatrix* ZSpatialEntity::GetObjectToParentMatrix(SMatrix* matrix)
{
	return Function::CallMethodAndReturn<SMatrix*, ZSpatialEntity*, SMatrix*>(BaseAddresses::hitman5Dll + 0x8D9172, this, matrix);
}

float4* ZSpatialEntity::GetLocalPosition(float4* f)
{
	return Function::CallMethodAndReturn<float4*, ZSpatialEntity*, float4*>(BaseAddresses::hitman5Dll + 0x8D9178, this, f);
}

void ZSpatialEntity::SetObjectToParentMatrix(SMatrix* matrix)
{
	Function::CallMethod<ZSpatialEntity*, SMatrix*>(BaseAddresses::hitman5Dll + 0x8D917E, this, matrix);
}

float4* ZSpatialEntity::GetLocalDirection(float4* f1, float4* f2)
{
	return Function::CallMethodAndReturn<float4*, ZSpatialEntity*, float4*, float4*>(BaseAddresses::hitman5Dll + 0x8D9184, this, f1, f2);
}

void ZSpatialEntity::AttachChild(ZSpatialEntity* spatialEntity)
{
	Function::CallMethod<ZSpatialEntity*, ZSpatialEntity*>(BaseAddresses::hitman5Dll + 0x8D919C, this, spatialEntity);
}

void ZSpatialEntity::SetObjectToWorldMatrixNoChangeHandlers(SMatrix* matrix)
{
	Function::CallMethod<ZSpatialEntity*, SMatrix*>(BaseAddresses::hitman5Dll + 0x8D91A8, this, matrix);
}

void ZSpatialEntity::SetLocalPosition(float4* f)
{
	Function::CallMethod<ZSpatialEntity*, float4*>(BaseAddresses::hitman5Dll + 0x8D9220, this, f);
}

void ZSpatialEntity::AttachTo(ZSpatialEntity* spatialEntity)
{
	Function::CallMethod<ZSpatialEntity*, ZSpatialEntity*>(BaseAddresses::hitman5Dll + 0x8D9226, this, spatialEntity);
}
