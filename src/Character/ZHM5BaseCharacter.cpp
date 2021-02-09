#include "ZHM5BaseCharacter.h"
#include "Function.h"
#include "BaseAddresses.h"
#include <iostream>

TEntityRef<ZRenderableEntity>* ZHM5BaseCharacter::GetRenderableEntity(TEntityRef<ZRenderableEntity>* result)
{
	return Function::CallMethodAndReturn<TEntityRef<ZRenderableEntity>*, ZHM5BaseCharacter*, TEntityRef<ZRenderableEntity>*>(BaseAddresses::hitman5Dll + 0x68FB0, this, result);
}

TEntityRef<IHM5Item>* ZHM5BaseCharacter::GetRightHandItem(TEntityRef<IHM5Item>* result)
{
	return Function::CallMethodAndReturn<TEntityRef<IHM5Item>*, ZHM5BaseCharacter*, TEntityRef<IHM5Item>*>(BaseAddresses::hitman5Dll + 0x68FF0, this, result);
}

ZHM5BaseCharacter* ZHM5BaseCharacter::operator=(ZHM5BaseCharacter* __that)
{
	return Function::CallMethodAndReturn<ZHM5BaseCharacter*, ZHM5BaseCharacter*, ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x713E0, this, __that);
}

void ZHM5BaseCharacter::SetNPCCollisionWithHitmanParams(float fRadiusScale, float fFrontOffset)
{
	Function::CallMethod<ZHM5BaseCharacter*, float, float>(BaseAddresses::hitman5Dll + 0xC8A80, this, fRadiusScale, fFrontOffset);
}

TEntityRef<IHM5ItemWeapon>* ZHM5BaseCharacter::GetRightHandWeapon(TEntityRef<IHM5ItemWeapon>* result)
{
	return Function::CallMethodAndReturn<TEntityRef<IHM5ItemWeapon>*, ZHM5BaseCharacter*, TEntityRef<IHM5ItemWeapon>*>(BaseAddresses::hitman5Dll + 0xC9C70, this, result);
}

ZHM5Ragdoll* ZHM5BaseCharacter::GetHM5Ragdoll()
{
	return Function::CallMethodAndReturn<ZHM5Ragdoll*, ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0xE8A30, this);
}

TEntityRef<IHM5Item>* ZHM5BaseCharacter::GetLeftHandItem(TEntityRef<IHM5Item>* result)
{
	return Function::CallMethodAndReturn<TEntityRef<IHM5Item>*, ZHM5BaseCharacter*, TEntityRef<IHM5Item>*>(BaseAddresses::hitman5Dll + 0x184040, this, result);
}

TEntityRef<IHM5ItemWeapon>* ZHM5BaseCharacter::GetLeftHandWeapon(TEntityRef<IHM5ItemWeapon>* result)
{
	return Function::CallMethodAndReturn<TEntityRef<IHM5ItemWeapon>*, ZHM5BaseCharacter*, TEntityRef<IHM5ItemWeapon>*>(BaseAddresses::hitman5Dll + 0x185CA0, this, result);
}

ZCrowdActorCore* ZHM5BaseCharacter::GetCrowdCore()
{
	return Function::CallMethodAndReturn<ZCrowdActorCore*, ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1D86C0, this);
}

bool ZHM5BaseCharacter::IsInCrowd()
{
	return Function::CallMethodAndReturn<bool, ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1D86D0, this);
}

float4* ZHM5BaseCharacter::GetVelocity(float4* result)
{
	return Function::CallMethodAndReturn<float4*, ZHM5BaseCharacter*, float4*>(BaseAddresses::hitman5Dll + 0x1E0170, this, result);
}

bool ZHM5BaseCharacter::IsShotColiAddded()
{
	return Function::CallMethodAndReturn<bool, ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1E7F30, this);
}

void ZHM5BaseCharacter::SetShootColiSystemActive(bool bAdd)
{
	Function::CallMethod<ZHM5BaseCharacter*, bool>(BaseAddresses::hitman5Dll + 0x1E8310, this, bAdd);
}

void ZHM5BaseCharacter::ReleaseShootColiSystem()
{
	Function::CallMethod<ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1E83E0, this);
}

bool ZHM5BaseCharacter::ShootColiInitialized()
{
	return Function::CallMethodAndReturn<bool, ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1E8470, this);
}

void ZHM5BaseCharacter::UpdateBodyCollision()
{
	Function::CallMethod<ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1E8480, this);
}

void ZHM5BaseCharacter::ReleaseBodyColi()
{
	Function::CallMethod<ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1E8550, this);
}

void ZHM5BaseCharacter::SetShootColiPrimitiveActive(bool bAdd)
{
	Function::CallMethod<ZHM5BaseCharacter*, bool>(BaseAddresses::hitman5Dll + 0x1E85B0, this, bAdd);
}

bool ZHM5BaseCharacter::InBoneAnimatedSequence()
{
	return Function::CallMethodAndReturn<bool, ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1E86F0, this);
}

void ZHM5BaseCharacter::SendEventsToConsumers()
{
	Function::CallMethod<ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1E89B0, this);
}

void ZHM5BaseCharacter::ApplyExplosionOnRagdoll(SExplodeInfo* explosionInfo, float4* vOrigin)
{
	Function::CallMethod<ZHM5BaseCharacter*, SExplodeInfo*, float4*>(BaseAddresses::hitman5Dll + 0x1E8B10, this, explosionInfo, vOrigin);
}

IPhysicsSystem* ZHM5BaseCharacter::GetBodyColi()
{
	return Function::CallMethodAndReturn<IPhysicsSystem*, ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1E8B40, this);
}

void ZHM5BaseCharacter::OnAnimationRigChanged(ZAnimationRig* pRig, SMatrix* pTranslation)
{
	Function::CallMethod<ZHM5BaseCharacter*, ZAnimationRig*, SMatrix*>(BaseAddresses::hitman5Dll + 0x1E8B50, this, pRig, pTranslation);
}

void ZHM5BaseCharacter::RagdollEaseInAfterGrab(ZGameTime* Now)
{
	Function::CallMethod<ZHM5BaseCharacter*, ZGameTime*>(BaseAddresses::hitman5Dll + 0x1E8B70, this, Now);
}

ZMorphemeNetworkInstance* ZHM5BaseCharacter::GetAttachedChildNetworkInstanceFromInstanceId(int nInstanceId)
{
	return Function::CallMethodAndReturn<ZMorphemeNetworkInstance*, ZHM5BaseCharacter*, int>(BaseAddresses::hitman5Dll + 0x1E8C90, this, nInstanceId);
}

void ZHM5BaseCharacter::DestroyChildNetworkInstance(int nNetworkInstanceId)
{
	Function::CallMethod<ZHM5BaseCharacter*, int>(BaseAddresses::hitman5Dll + 0x1E8CC0, this, nNetworkInstanceId);
}

void ZHM5BaseCharacter::SetBodyCollisionEnabled(bool bEnabled)
{
	Function::CallMethod<ZHM5BaseCharacter*, bool>(BaseAddresses::hitman5Dll + 0x1E8D30, this, bEnabled);
}

void ZHM5BaseCharacter::ReleaseShootColiPrimitive()
{
	Function::CallMethod<ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1EA350, this);
}

void ZHM5BaseCharacter::ReleaseShootColi()
{
	Function::CallMethod<ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1EA3E0, this);
}

void ZHM5BaseCharacter::HandleTriggeredEvents()
{
	Function::CallMethod<ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1EA400, this);
}

TEntityRef<ZCrowdEntity>* ZHM5BaseCharacter::GetCurrentCrowd(TEntityRef<ZCrowdEntity>* result)
{
	return Function::CallMethodAndReturn<TEntityRef<ZCrowdEntity>*, ZHM5BaseCharacter*, TEntityRef<ZCrowdEntity>*>(BaseAddresses::hitman5Dll + 0x1EA480, this, result);
}

void ZHM5BaseCharacter::UpdateAvoidParam(float nDt)
{
	Function::CallMethod<ZHM5BaseCharacter*, float>(BaseAddresses::hitman5Dll + 0x1EA540, this, nDt);
}

TEntityRef<IHM5Item>* ZHM5BaseCharacter::GetFreeBoneItem(TEntityRef<IHM5Item>* result)
{
	return Function::CallMethodAndReturn<TEntityRef<IHM5Item>*, ZHM5BaseCharacter*, TEntityRef<IHM5Item>*>(BaseAddresses::hitman5Dll + 0x1EA7B0, this, result);
}

void ZHM5BaseCharacter::ApplyImpulseOnRagdoll(float4* vPosition, float4* vImpulse, unsigned int nBoneIndex, bool bRandomize)
{
	Function::CallMethod<ZHM5BaseCharacter*, float4*, float4*, unsigned int, bool>(BaseAddresses::hitman5Dll + 0x1EAB10, this, vPosition, vImpulse, nBoneIndex, bRandomize);
}

void ZHM5BaseCharacter::UpdateInCrowdFlag()
{
	Function::CallMethod<ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1EBAE0, this);
}

bool ZHM5BaseCharacter::IsInAmbientCrowd()
{
	return Function::CallMethodAndReturn<bool, ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1EBCC0, this);
}

void ZHM5BaseCharacter::InitHand(sHand* pHand)
{
	Function::CallMethod<ZHM5BaseCharacter*, sHand*>(BaseAddresses::hitman5Dll + 0x1EBD20, this, pHand);
}

void ZHM5BaseCharacter::InitBack(sBack* pBack)
{
	Function::CallMethod<ZHM5BaseCharacter*, sBack*>(BaseAddresses::hitman5Dll + 0x1EBDE0, this, pBack);
}

void ZHM5BaseCharacter::InitFreeBone(SFreeBone* pFreeBone)
{
	Function::CallMethod<ZHM5BaseCharacter*, SFreeBone*>(BaseAddresses::hitman5Dll + 0x1EBE40, this, pFreeBone);
}

bool ZHM5BaseCharacter::IsGrabPathClear(float4* vGrabTargetPos)
{
	return Function::CallMethodAndReturn<bool, ZHM5BaseCharacter*, float4*>(BaseAddresses::hitman5Dll + 0x1ECD30, this, vGrabTargetPos);
}

void ZHM5BaseCharacter::SetupGeomAnimatorLink()
{
	Function::CallMethod<ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1ED210, this);
}

void ZHM5BaseCharacter::UpdateShootColiPrimitive(bool bMoveInsteadOfSet)
{
	Function::CallMethod<ZHM5BaseCharacter*, bool>(BaseAddresses::hitman5Dll + 0x1ED860, this, bMoveInsteadOfSet);
}

bool ZHM5BaseCharacter::IsOnScreen()
{
	return Function::CallMethodAndReturn<bool, ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1ED930, this);
}

ZMorphemeNetworkInstance* ZHM5BaseCharacter::GetMorphemeNetwork()
{
	return Function::CallMethodAndReturn<ZMorphemeNetworkInstance*, ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1ED960, this);
}

int ZHM5BaseCharacter::CreateChildNetworkInstance(TEntityRef<IChildNetworkEntity>* rChildNetworkEntity, bool bUseVariation)
{
	return Function::CallMethodAndReturn<int, ZHM5BaseCharacter*, TEntityRef<IChildNetworkEntity>*, bool>(BaseAddresses::hitman5Dll + 0x1EDB60, this, rChildNetworkEntity, bUseVariation);
}

void ZHM5BaseCharacter::CreateShootColiPrimitive()
{
	Function::CallMethod<ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1EE610, this);
}

void ZHM5BaseCharacter::CreateShootColiSystem()
{
	Function::CallMethod<ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1EE7D0, this);
}

void ZHM5BaseCharacter::UpdateShootColiSystem(bool bMoveInsteadOfSet)
{
	Function::CallMethod<ZHM5BaseCharacter*, bool>(BaseAddresses::hitman5Dll + 0x1EE7E0, this, bMoveInsteadOfSet);
}

void ZHM5BaseCharacter::PushCrowdActors()
{
	Function::CallMethod<ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1EE8F0, this);
}

void ZHM5BaseCharacter::InitBaseChar()
{
	Function::CallMethod<ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1EEDE0, this);
}

void ZHM5BaseCharacter::OnEventConsumerCollectionChanged()
{
	Function::CallMethod<ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1EF650, this);
}

void ZHM5BaseCharacter::UpdateShootColi()
{
	Function::CallMethod<ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1EF760, this);
}

void ZHM5BaseCharacter::ApplyHitInfoOnRagdoll(SHitInfo* HitInfo)
{
	Function::CallMethod<ZHM5BaseCharacter*, SHitInfo*>(BaseAddresses::hitman5Dll + 0x1EF850, this, HitInfo);
}

void ZHM5BaseCharacter::DetachChildNetwork(unsigned int nNodeId)
{
	Function::CallMethod<ZHM5BaseCharacter*, unsigned int>(BaseAddresses::hitman5Dll + 0x1EFB40, this, nNodeId);
}

void ZHM5BaseCharacter::RequestDetachChildNetwork(unsigned int nNodeId, float fTimeOut)
{
	Function::CallMethod<ZHM5BaseCharacter*, unsigned int, float>(BaseAddresses::hitman5Dll + 0x1EFC00, this, nNodeId, fTimeOut);
}

void ZHM5BaseCharacter::UpdateChildNetworkInfo(SGameUpdateEvent* updateEvent)
{
	Function::CallMethod<ZHM5BaseCharacter*, SGameUpdateEvent*>(BaseAddresses::hitman5Dll + 0x1EFC80, this, updateEvent);
}

void ZHM5BaseCharacter::CleanupChildNetworkInfo()
{
	Function::CallMethod<ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1EFDA0, this);
}

void ZHM5BaseCharacter::GetRenderableEntities(TMaxArray<TEntityRef<ZRenderableEntity>, 4>* RenderableEntities)
{
	Function::CallMethod<ZHM5BaseCharacter*, TMaxArray<TEntityRef<ZRenderableEntity>, 4>*>(BaseAddresses::hitman5Dll + 0x1EFE40, this, RenderableEntities);
}

void ZHM5BaseCharacter::SetDontDraw(bool bDontDraw)
{
	Function::CallMethod<ZHM5BaseCharacter*, bool>(BaseAddresses::hitman5Dll + 0x1F0090, this, bDontDraw);
}

void ZHM5BaseCharacter::CreateShootColi()
{
	Function::CallMethod<ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1F05A0, this);
}

void ZHM5BaseCharacter::SetShootColiActive(bool bAdd)
{
	Function::CallMethod<ZHM5BaseCharacter*, bool>(BaseAddresses::hitman5Dll + 0x1F05B0, this, bAdd);
}

void ZHM5BaseCharacter::BaseCharacterUpdate(SGameUpdateEvent* updateEvent)
{
	Function::CallMethod<ZHM5BaseCharacter*, SGameUpdateEvent*>(BaseAddresses::hitman5Dll + 0x1F06A0, this, updateEvent);
}

void ZHM5BaseCharacter::BaseCharacterRagdollOnlyUpdate(SGameUpdateEvent* updateEvent)
{
	Function::CallMethod<ZHM5BaseCharacter*, SGameUpdateEvent*>(BaseAddresses::hitman5Dll + 0x1F08D0, this, updateEvent);
}

void ZHM5BaseCharacter::AddSecondaryCollisionEntity(TEntityRef<ZLinkedEntity> pLinked)
{
	Function::CallMethod<ZHM5BaseCharacter*, TEntityRef<ZLinkedEntity>>(BaseAddresses::hitman5Dll + 0x1F0D10, this, pLinked);
}

void ZHM5BaseCharacter::RemoveSecondaryCollisionEntity(TEntityRef<ZLinkedEntity> pLinked)
{
	Function::CallMethod<ZHM5BaseCharacter*, TEntityRef<ZLinkedEntity>>(BaseAddresses::hitman5Dll + 0x1F0D50, this, pLinked);
}

bool ZHM5BaseCharacter::SetupRagdoll()
{
	return Function::CallMethodAndReturn<bool, ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1F14C0, this);
}

void ZHM5BaseCharacter::OnMorphemeEntityUninitialized()
{
	Function::CallMethod<ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1F1610, this);
}

void ZHM5BaseCharacter::OnMorphemeEntityInitialized()
{
	Function::CallMethod<ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1F1630, this);
}

void ZHM5BaseCharacter::RegisterForAnimationRigChangeListening()
{
	Function::CallMethod<ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1F1740, this);
}

void ZHM5BaseCharacter::UnregisterForAnimationRigChangeListening()
{
	Function::CallMethod<ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x1F17A0, this);
}

void ZHM5BaseCharacter::InitShootColiSystemData()
{
	Function::Call<>(BaseAddresses::hitman5Dll + 0x1F1800);
}

void ZHM5BaseCharacter::DestroyShootColiSystemData()
{
	Function::Call<>(BaseAddresses::hitman5Dll + 0x1F1C40);
}

ZMorphemeNetworkInstance* ZHM5BaseCharacter::GetAttachedChildNetworkInstance(unsigned int nNodeId)
{
	return Function::CallMethodAndReturn<ZMorphemeNetworkInstance*, ZHM5BaseCharacter*, unsigned int>(BaseAddresses::hitman5Dll + 0x1F1CD0, this, nNodeId);
}

bool ZHM5BaseCharacter::InternalAttachChildNetwork(unsigned int nNodeId, int nInstanceId)
{
	return Function::CallMethodAndReturn<bool, ZHM5BaseCharacter*, unsigned int, int>(BaseAddresses::hitman5Dll + 0x1F1D30, this, nNodeId, nInstanceId);
}

void ZHM5BaseCharacter::SetFPSDrawMode(bool bFPSDrawMode)
{
	Function::CallMethod<ZHM5BaseCharacter*, bool>(BaseAddresses::hitman5Dll + 0x1F1E70, this, bFPSDrawMode);
}

void ZHM5BaseCharacter::AddBaseCharacter()
{
	Function::Call<>(BaseAddresses::hitman5Dll + 0x1F21B0);
}

void ZHM5BaseCharacter::RemoveBaseCharacter()
{
	Function::Call<>(BaseAddresses::hitman5Dll + 0x1F21D0);
}

bool ZHM5BaseCharacter::AttachChildNetwork(unsigned int nNodeId, TEntityRef<IChildNetworkEntity>* rChildNetworkEntity, bool bUseVariation)
{
	return Function::CallMethodAndReturn<bool, ZHM5BaseCharacter*, unsigned int, TEntityRef<IChildNetworkEntity>*, bool>(BaseAddresses::hitman5Dll + 0x1F2D70, this, nNodeId, rChildNetworkEntity, bUseVariation);
}

bool ZHM5BaseCharacter::AttachChildNetwork(unsigned int nNodeId, ZResourcePtr* networkResourcePtr)
{
	return Function::CallMethodAndReturn<bool, ZHM5BaseCharacter*, unsigned int, ZResourcePtr*>(BaseAddresses::hitman5Dll + 0x1F2E20, this, nNodeId, networkResourcePtr);
}

void ZHM5BaseCharacter::RegisterType()
{
	Function::Call<>(BaseAddresses::hitman5Dll + 0x1F3A10);
}

float ZHM5BaseCharacter::GetNPCCollisionRadiusScale()
{
	return Function::CallMethodAndReturn<float, ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x28F130, this);
}

float ZHM5BaseCharacter::GetNPCCollisionFrontOffset()
{
	return Function::CallMethodAndReturn<float, ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x28F140, this);
}

void ZHM5BaseCharacter::SetForceBoneUpdate(bool bForce)
{
	Function::CallMethod<ZHM5BaseCharacter*, bool>(BaseAddresses::hitman5Dll + 0x294290, this, bForce);
}

bool ZHM5BaseCharacter::IsInLimitVisionAreaZone()
{
	return Function::CallMethodAndReturn<bool, ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x43B620, this);
}

bool ZHM5BaseCharacter::IsInsideLimitVisionArea()
{
	return Function::CallMethodAndReturn<bool, ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x43B630, this);
}

bool ZHM5BaseCharacter::IsBlockedByLimitVisionArea()
{
	return Function::CallMethodAndReturn<bool, ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x43B640, this);
}

void ZHM5BaseCharacter::SetCrowdObstacleType(unsigned __int16 type)
{
	Function::CallMethod<ZHM5BaseCharacter*, unsigned __int16>(BaseAddresses::hitman5Dll + 0x4C2C30, this, type);
}

const TEntityRef<ZVolumeTriggerListenerEntity>* ZHM5BaseCharacter::GetActiveVolumeTriggerListener(TEntityRef<ZVolumeTriggerListenerEntity>* result)
{
	return Function::CallMethodAndReturn<const TEntityRef<ZVolumeTriggerListenerEntity>*, ZHM5BaseCharacter*, TEntityRef<ZVolumeTriggerListenerEntity>*>(BaseAddresses::hitman5Dll + 0x4CCDA0, this, result);
}

void ZHM5BaseCharacter::SetActiveVolumeTriggerListener(TEntityRef<ZVolumeTriggerListenerEntity>* volumeTrigger)
{
	Function::CallMethod<ZHM5BaseCharacter*, TEntityRef<ZVolumeTriggerListenerEntity>*>(BaseAddresses::hitman5Dll + 0x52D4E0, this, volumeTrigger);
}

void ZHM5BaseCharacter::SetInLimitVisionAreaZone(bool bIsInLimitVisionAreaZone)
{
	Function::CallMethod<ZHM5BaseCharacter*, bool>(BaseAddresses::hitman5Dll + 0x53A460, this, bIsInLimitVisionAreaZone);
}

void ZHM5BaseCharacter::SetInsideLimitVisionArea(bool bInsideLimitVisionArea)
{
	Function::CallMethod<ZHM5BaseCharacter*, bool>(BaseAddresses::hitman5Dll + 0x53A480, this, bInsideLimitVisionArea);
}

void ZHM5BaseCharacter::SetIsBlockedByLimitVisionArea(bool bIsBlockedByLimitVisionArea)
{
	Function::CallMethod<ZHM5BaseCharacter*, bool>(BaseAddresses::hitman5Dll + 0x53A4A0, this, bIsBlockedByLimitVisionArea);
}

unsigned __int16 ZHM5BaseCharacter::GetCrowdObstacleType()
{
	return Function::CallMethodAndReturn<unsigned __int16, ZHM5BaseCharacter*>(BaseAddresses::hitman5Dll + 0x5E7660, this);
}
