#include "ZHitman5.h"
#include "Function.h"
#include "BaseAddresses.h"

ZEntityRef* ZHitman5::GetCurrentOutfitEntity(ZEntityRef* result)
{
	return Function::CallMethodAndReturn<ZEntityRef*, ZHitman5*, ZEntityRef*>(BaseAddresses::hitman5Dll + 0x10A28, this, result);
}

ZHM5MovementLocomotion* ZHitman5::GetMovementLocomotion()
{
	return Function::CallMethodAndReturn<ZHM5MovementLocomotion*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x113D8, this);
}

void ZHitman5::DeactivateCheckPoint(bool bSetCurrentMovement)
{
	Function::CallMethod<ZHitman5*, bool>(BaseAddresses::hitman5Dll + 0x113E7, this, bSetCurrentMovement);
}

ZRuntimeResourceID* ZHitman5::GetEquipOutfitAsyncResourceID(ZRuntimeResourceID* result)
{
	return Function::CallMethodAndReturn<ZRuntimeResourceID*, ZHitman5*, ZRuntimeResourceID*>(BaseAddresses::hitman5Dll + 0x11680, this, result);
}

float4* ZHitman5::GetSkinWidthVectorZ(float4* result)
{
	return Function::CallMethodAndReturn<float4*, ZHitman5*, float4*>(BaseAddresses::hitman5Dll + 0x1188D, this, result);
}

ZHM5MovementLedgeWalk* ZHitman5::GetMovementLedgeWalk()
{
	return Function::CallMethodAndReturn<ZHM5MovementLedgeWalk*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x11A4F, this);
}

ZHM5WeaponRecoil* ZHitman5::GetRecoilController()
{
	return Function::CallMethodAndReturn<ZHM5WeaponRecoil*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x121E8, this);
}

bool ZHitman5::IsUsingKeyCardReader()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x124A4, this);
}

ZHM5BaseInventory* ZHitman5::GetBaseInventory()
{
	return Function::CallMethodAndReturn<ZHM5BaseInventory*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x128B9, this);
}

ZGameTime* ZHitman5::CurrentGameTimeDelta(ZGameTime* result)
{
	return Function::CallMethodAndReturn<ZGameTime*, ZHitman5*, ZGameTime*>(BaseAddresses::hitman5Dll + 0x12DBE, this, result);
}

bool ZHitman5::IsEquipOutfitAsyncReady()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x13926, this);
}

bool ZHitman5::DrawHitmanInFPSMode()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x13C00, this);
}

void ZHitman5::DestroyBaseMovements()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x14001, this);
}

void ZHitman5::EnableAnchorCollision(bool bEnable)
{
	Function::CallMethod<ZHitman5*, bool>(BaseAddresses::hitman5Dll + 0x14709, this, bEnable);
}

ZHM5ActionClient* ZHitman5::GetActionClient()
{
	return Function::CallMethodAndReturn<ZHM5ActionClient*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x150F0, this);
}

bool ZHitman5::IsEnteringCloset()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x1549C, this);
}

void ZHitman5::DestroyCharacterController()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x155D7, this);
}

SMatrix* ZHitman5::CalcTorsoColiMatPos(SMatrix* result)
{
	return Function::CallMethodAndReturn<SMatrix*, ZHitman5*, SMatrix*>(BaseAddresses::hitman5Dll + 0x159E7, this, result);
}

void ZHitman5::CutSequenceEnded()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x1604F, this);
}

bool ZHitman5::IsReloadingOutfitReady()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x170D5, this);
}

bool ZHitman5::IsInDisguise()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x1710C, this);
}

void ZHitman5::GetCapsulePropertiesInternal(float* fRadius, float* fHeight, float* fSkinWidth)
{
	Function::CallMethod<ZHitman5*, float*, float*, float*>(BaseAddresses::hitman5Dll + 0x172EC, this, fRadius, fHeight, fSkinWidth);
}

bool ZHitman5::IsTakingSecurityTape()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x17A9E, this);
}

bool ZHitman5::IsFireArmEquipped()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x17C65, this);
}

void ZHitman5::QueueReset(SMatrix* mvNewPos)
{
	Function::CallMethod<ZHitman5*, SMatrix*>(BaseAddresses::hitman5Dll + 0x18228, this, mvNewPos);
}

void ZHitman5::EquipOutfitResourceAsync_ManualFinish(ZRuntimeResourceID ridNewOutfitLibrary)
{
	Function::CallMethod<ZHitman5*, ZRuntimeResourceID>(BaseAddresses::hitman5Dll + 0x18651, this, ridNewOutfitLibrary);
}

void ZHitman5::HitmanFailedAnimationPackBugAnimators()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x187CD, this);
}

ZHM5ActorControl* ZHitman5::GetActorControl()
{
	return Function::CallMethodAndReturn<ZHM5ActorControl*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x18813, this);
}

bool ZHitman5::IsPushVictimPossible()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x18976, this);
}

void ZHitman5::EnablePlayerCollision(bool bEnable)
{
	Function::CallMethod<ZHitman5*, bool>(BaseAddresses::hitman5Dll + 0x18DFE, this, bEnable);
}

EHM5SoundFootwearType ZHitman5::GetOutfitFootwearType()
{
	return Function::CallMethodAndReturn<EHM5SoundFootwearType, ZHitman5*>(BaseAddresses::hitman5Dll + 0x18E21, this);
}

bool ZHitman5::IsGuidesListEmpty()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x19B78, this);
}

bool ZHitman5::IsMovementEnabled(EBaseMovementType eMovement)
{
	return Function::CallMethodAndReturn<bool, ZHitman5*, EBaseMovementType>(BaseAddresses::hitman5Dll + 0x19C18, this, eMovement);
}

bool ZHitman5::OverlapWithGuideAnchor(ZHM5BaseGuide* pGuide)
{
	return Function::CallMethodAndReturn<bool, ZHitman5*, ZHM5BaseGuide*>(BaseAddresses::hitman5Dll + 0x1A3C0, this, pGuide);
}

bool ZHitman5::IsInSBExecutionMode()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x1A47E, this);
}

bool ZHitman5::IsInSafeZoneMovement()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x1A78F, this);
}

bool ZHitman5::IsDisablingFuseBox()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x1B081, this);
}

void ZHitman5::SetIllegalPushButtonTimer(float fDuration)
{
	Function::CallMethod<ZHitman5*, float>(BaseAddresses::hitman5Dll + 0x1B27F, this, fDuration);
}

void ZHitman5::UpdateMetrics()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x1B2A2, this);
}

void ZHitman5::ResetPelvisOffset(void* pClassPtr)
{
	Function::CallMethod<ZHitman5*, void*>(BaseAddresses::hitman5Dll + 0x1B4AF, this, pClassPtr);
}

void ZHitman5::DestroyControllers()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x1B568, this);
}

bool ZHitman5::GetUseCrowdCameraProfile()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x1B7F7, this);
}

ZGameTime* ZHitman5::GetSBEndGameTime(ZGameTime* result)
{
	return Function::CallMethodAndReturn<ZGameTime*, ZHitman5*, ZGameTime*>(BaseAddresses::hitman5Dll + 0x1B810, this, result);
}

bool ZHitman5::ActivateEnterSafeZone(TEntityRef<ZHM5DisguiseSafeZoneEntity> rSafeZone)
{
	return Function::CallMethodAndReturn<bool, ZHitman5*, TEntityRef<ZHM5DisguiseSafeZoneEntity>>(BaseAddresses::hitman5Dll + 0x1B9FF, this, rSafeZone);
}

ZHM5SneakController* ZHitman5::GetSneakController()
{
	return Function::CallMethodAndReturn<ZHM5SneakController*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x1BB1C, this);
}

void ZHitman5::GetAimWeaponCollisionExtends(float4* vShoulder, float4* vMuzzle, bool bRightSideAim)
{
	Function::CallMethod<ZHitman5*, float4*, float4*, bool>(BaseAddresses::hitman5Dll + 0x1BBAD, this, vShoulder, vMuzzle, bRightSideAim);
}

void ZHitman5::UpdateBaseMovements()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x1BC93, this);
}

void ZHitman5::DebugDisplayBones()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x1BF59, this);
}

bool ZHitman5::SendRequestToActiveStateMachines(eMorphemeRequests nRequest)
{
	return Function::CallMethodAndReturn<bool, ZHitman5*, eMorphemeRequests>(BaseAddresses::hitman5Dll + 0x1C67F, this, nRequest);
}

int ZHitman5::GetMaxAmmoForAmmoType(eAmmoType ammoType)
{
	return Function::CallMethodAndReturn<int, ZHitman5*, eAmmoType>(BaseAddresses::hitman5Dll + 0x1C819, this, ammoType);
}

ZHM5MovementDragBody* ZHitman5::GetMovementDragBody()
{
	return Function::CallMethodAndReturn<ZHM5MovementDragBody*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x1C90E, this);
}

void ZHitman5::ReleaseCurrentOutfitInternal()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x1CD50, this);
}

void ZHitman5::DebugDisplayMorphemeStatus()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x1D45D, this);
}

SGameInput* ZHitman5::GetGameInput()
{
	return Function::CallMethodAndReturn<SGameInput*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x1D561, this);
}

bool ZHitman5::IsInDisguiseSafeZone()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x1E191, this);
}

bool ZHitman5::IsChangingClothes()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x1E9F2, this);
}

void ZHitman5::SetDecriminalizedShooting(bool b)
{
	Function::CallMethod<ZHitman5*, bool>(BaseAddresses::hitman5Dll + 0x1F28A, this, b);
}

SMatrix* ZHitman5::GetClosetMatrix(SMatrix* result)
{
	return Function::CallMethodAndReturn<SMatrix*, ZHitman5*, SMatrix*>(BaseAddresses::hitman5Dll + 0x1F4BF, this, result);
}

void ZHitman5::SetWalkOnLedgeMovementGuide(ZHM5BaseGuide* pGuide)
{
	Function::CallMethod<ZHitman5*, ZHM5BaseGuide*>(BaseAddresses::hitman5Dll + 0x1F9D8, this, pGuide);
}

ZHM5MovementDead* ZHitman5::GetMovementDead()
{
	return Function::CallMethodAndReturn<ZHM5MovementDead*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x20054, this);
}

bool ZHitman5::CheckWeaponCollisionOTS(SMatrix* mvFrom, SMatrix* mvTo)
{
	return Function::CallMethodAndReturn<bool, ZHitman5*, SMatrix*, SMatrix*>(BaseAddresses::hitman5Dll + 0x209D2, this, mvFrom, mvTo);
}

ZHM5BaseMovement* ZHitman5::GetCurrentMovement()
{
	return Function::CallMethodAndReturn<ZHM5BaseMovement*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x20BA3, this);
}

bool ZHitman5::GuideActionPerformSecondary()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x2128D, this);
}

bool ZHitman5::GetDecriminalizedWeapons()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x21576, this);
}

bool ZHitman5::IsWalkingSlowly()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x21CA6, this);
}

ZHM5GuideController* ZHitman5::GetGuideController()
{
	return Function::CallMethodAndReturn<ZHM5GuideController*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x223F4, this);
}

TEntityRef<ZOutfitKitEntity>* ZHitman5::GetOutfitKit(TEntityRef<ZOutfitKitEntity>* result)
{
	return Function::CallMethodAndReturn<TEntityRef<ZOutfitKitEntity>*, ZHitman5*, TEntityRef<ZOutfitKitEntity>*>(BaseAddresses::hitman5Dll + 0x2241C, this, result);
}

void ZHitman5::MoveToMatPos(SMatrix* mvMatPos, bool bResetLockPos, bool bTriggerChangerHandlers)
{
	Function::CallMethod<ZHitman5*, SMatrix*, bool, bool>(BaseAddresses::hitman5Dll + 0x226B0, this, mvMatPos, bResetLockPos, bTriggerChangerHandlers);
}

void ZHitman5::UpdateMovementRelatedCache()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x22796, this);
}

bool ZHitman5::GetDecriminalizedShooting()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x22822, this);
}

bool ZHitman5::ShouldCheckWeaponCollision()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x229BC, this);
}

ZHM5MovementShootingBallet* ZHitman5::GetMovementShootingBallet()
{
	return Function::CallMethodAndReturn<ZHM5MovementShootingBallet*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x23204, this);
}

void ZHitman5::UpdateWeaponStreaming()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x239CF, this);
}

void ZHitman5::ExitOTSMode()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x23BDC, this);
}

bool ZHitman5::IsRifleEquipped()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x23F10, this);
}

bool ZHitman5::IsItemsEnabled()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x24186, this);
}

void ZHitman5::ActivateFrameUpdate()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x244EC, this);
}

void ZHitman5::CacheCCAnims(TEntityRef<ZActor>* rActor)
{
	Function::CallMethod<ZHitman5*, TEntityRef<ZActor>*>(BaseAddresses::hitman5Dll + 0x2462C, this, rActor);
}

TEntityRef<IHM5Outfit>* ZHitman5::GetOutfitFromClothBundle(TEntityRef<IHM5Outfit>* result, ZEntityRef* rOwner)
{
	return Function::CallMethodAndReturn<TEntityRef<IHM5Outfit>*, ZHitman5*, TEntityRef<IHM5Outfit>*, ZEntityRef*>(BaseAddresses::hitman5Dll + 0x24762, this, result, rOwner);
}

float4* ZHitman5::MinimizeWeaponCorrection(float4* result, SSphereSweepInput* coliin, SSphereSweepOutput* coliout, float4* vOffset)
{
	return Function::CallMethodAndReturn<float4*, ZHitman5*, float4*, SSphereSweepInput*, SSphereSweepOutput*, float4*>(BaseAddresses::hitman5Dll + 0x249D3, this, result, coliin, coliout, vOffset);
}

ZHM5MovementKickVictim* ZHitman5::GetMovementKickVictim()
{
	return Function::CallMethodAndReturn<ZHM5MovementKickVictim*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x25748, this);
}

ZDynamicResourceLibrary* ZHitman5::EquipOutfitFromClothBundle(ZEntityRef* rOwner, ZDynamicResourceLibrary* pNewOutfitLibrary)
{
	return Function::CallMethodAndReturn<ZDynamicResourceLibrary*, ZHitman5*, ZEntityRef*, ZDynamicResourceLibrary*>(BaseAddresses::hitman5Dll + 0x257ED, this, rOwner, pNewOutfitLibrary);
}

bool ZHitman5::IsPullVictimPossible()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x25E14, this);
}

ZHM5MainCamera* ZHitman5::GetMainCamera()
{
	return Function::CallMethodAndReturn<ZHM5MainCamera*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x26193, this);
}

bool ZHitman5::IsKnifeKilling()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x26A80, this);
}

void ZHitman5::GeomTransformChangeCallback(ZEntityRef* entity, SMatrix43* mNewValue)
{
	Function::CallMethod<ZHitman5*, ZEntityRef*, SMatrix43*>(BaseAddresses::hitman5Dll + 0x26AC6, this, entity, mNewValue);
}

bool ZHitman5::IsPerformingIllegalPushButton()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x26EDB, this);
}

ZHM5AimAssist* ZHitman5::GetAimAssist()
{
	return Function::CallMethodAndReturn<ZHM5AimAssist*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x27115, this);
}

bool ZHitman5::IsStrafing()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x27223, this);
}

float4* ZHitman5::CheckPlayerCollision(float4* result, float4* vTo, bool bCollisionEnabled)
{
	return Function::CallMethodAndReturn<float4*, ZHitman5*, float4*, float4*, bool>(BaseAddresses::hitman5Dll + 0x2758E, this, result, vTo, bCollisionEnabled);
}

void ZHitman5::GetHitmanAABB(float4* vMin, float4* vMax)
{
	Function::CallMethod<ZHitman5*, float4*, float4*>(BaseAddresses::hitman5Dll + 0x275E3, this, vMin, vMax);
}

bool ZHitman5::IsTakingKeycard()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x27750, this);
}

bool ZHitman5::IsDoingCoverToCoverMove()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x27890, this);
}

float ZHitman5::GetMorphemeBlindFireWeight()
{
	return Function::CallMethodAndReturn<float, ZHitman5*>(BaseAddresses::hitman5Dll + 0x27C28, this);
}

void ZHitman5::ResetGuidesList()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x27F07, this);
}

bool ZHitman5::CheckWeaponCollision(SMatrix* mvFrom, SMatrix* mvTo)
{
	return Function::CallMethodAndReturn<bool, ZHitman5*, SMatrix*, SMatrix*>(BaseAddresses::hitman5Dll + 0x2864B, this, mvFrom, mvTo);
}

void ZHitman5::SetBurningFocusFlag(bool b)
{
	Function::CallMethod<ZHitman5*, bool>(BaseAddresses::hitman5Dll + 0x28C90, this, b);
}

bool ZHitman5::GetDecriminalizedAiming()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x297F8, this);
}

ZHM5MovementCloseCombat* ZHitman5::GetMovementCloseCombat()
{
	return Function::CallMethodAndReturn<ZHM5MovementCloseCombat*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x29B09, this);
}

ZHM5TossController* ZHitman5::GetTossController()
{
	return Function::CallMethodAndReturn<ZHM5TossController*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x2A02C, this);
}

bool ZHitman5::CanOperateObject(ZHM5Action* pAction, bool* bShouldDisplayFarFeedback)
{
	return Function::CallMethodAndReturn<bool, ZHitman5*, ZHM5Action*, bool*>(BaseAddresses::hitman5Dll + 0x2A1CB, this, pAction, bShouldDisplayFarFeedback);
}

unsigned int* ZHitman5::GetControlParams()
{
	return Function::CallMethodAndReturn<unsigned int*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x2A3BA, this);
}

ZTargetTracker* ZHitman5::GetTargetTracker()
{
	return Function::CallMethodAndReturn<ZTargetTracker*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x2A428, this);
}

void ZHitman5::QueueFastTargetSelection()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x2A775, this);
}

float4* ZHitman5::GetCurrentFacing(float4* result)
{
	return Function::CallMethodAndReturn<float4*, ZHitman5*, float4*>(BaseAddresses::hitman5Dll + 0x2AB49, this, result);
}

TEntityRef<ZHM5LooseTargetEncounter>* ZHitman5::GetLooseTargetEncounter(TEntityRef<ZHM5LooseTargetEncounter>* result)
{
	return Function::CallMethodAndReturn<TEntityRef<ZHM5LooseTargetEncounter>*, ZHitman5*, TEntityRef<ZHM5LooseTargetEncounter>*>(BaseAddresses::hitman5Dll + 0x2AF36, this, result);
}

void ZHitman5::UpdateGameStateFromFocus()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x2B0D5, this);
}

bool ZHitman5::IsSurendering()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x2B841, this);
}

bool ZHitman5::HasFocus()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x2BF58, this);
}

ZEntityRef* ZHitman5::GetRenderDestination(ZEntityRef* result)
{
	return Function::CallMethodAndReturn<ZEntityRef*, ZHitman5*, ZEntityRef*>(BaseAddresses::hitman5Dll + 0x2C025, this, result);
}

const TEntityRef<ZActor>* ZHitman5::GetDragVictim(TEntityRef<ZActor>* result)
{
	return Function::CallMethodAndReturn<const TEntityRef<ZActor>*, ZHitman5*, TEntityRef<ZActor>*>(BaseAddresses::hitman5Dll + 0x2C160, this, result);
}

SMatrix* ZHitman5::GetTargetPelvisOffset(SMatrix* result)
{
	return Function::CallMethodAndReturn<SMatrix*, ZHitman5*, SMatrix*>(BaseAddresses::hitman5Dll + 0x2C4A8, this, result);
}

void ZHitman5::Die(SHitInfo* HitInfo)
{
	Function::CallMethod<ZHitman5*, SHitInfo*>(BaseAddresses::hitman5Dll + 0x2C4D0, this, HitInfo);
}

bool ZHitman5::IsEquipFiberWireReady()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x2C615, this);
}

void ZHitman5::SetIsInCloseCombat(bool bVal)
{
	Function::CallMethod<ZHitman5*, bool>(BaseAddresses::hitman5Dll + 0x2C61A, this, bVal);
}

bool ZHitman5::IsInContextActionInteraction()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x2C72D, this);
}

void ZHitman5::StopKillingMovements()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x2C97B, this);
}

void ZHitman5::SetDrawAsPlayerRecursive(ZEntityRef rEntity, bool bState)
{
	Function::CallMethod<ZHitman5*, ZEntityRef, bool>(BaseAddresses::hitman5Dll + 0x2D19B, this, rEntity, bState);
}

bool ZHitman5::IsMovingOnLedge()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x2D407, this);
}

void ZHitman5::StopDragBody()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x2DD49, this);
}

bool ZHitman5::IsFiberWireEquipped()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x2DFE2, this);
}

bool ZHitman5::ReadyForArrest()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x2E249, this);
}

void ZHitman5::UpdatePelvisOffset()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x2E7A8, this);
}

bool ZHitman5::GetFreeCamPos(SMatrix43* mvPos)
{
	return Function::CallMethodAndReturn<bool, ZHitman5*, SMatrix43*>(BaseAddresses::hitman5Dll + 0x2EB45, this, mvPos);
}

void ZHitman5::SetIsInInstinctMode(bool bVal)
{
	Function::CallMethod<ZHitman5*, bool>(BaseAddresses::hitman5Dll + 0x2EEB5, this, bVal);
}

SMatrix* ZHitman5::CalcRightCalfColiMatPos(SMatrix* result)
{
	return Function::CallMethodAndReturn<SMatrix*, ZHitman5*, SMatrix*>(BaseAddresses::hitman5Dll + 0x2F82E, this, result);
}

void ZHitman5::Jump(SMatrix* mTo, bool bResetLockPos)
{
	Function::CallMethod<ZHitman5*, SMatrix*, bool>(BaseAddresses::hitman5Dll + 0x2F90F, this, mTo, bResetLockPos);
}

ZEntityRef* ZHitman5::GetInitialOutfitEntity(ZEntityRef* result)
{
	return Function::CallMethodAndReturn<ZEntityRef*, ZHitman5*, ZEntityRef*>(BaseAddresses::hitman5Dll + 0x2F964, this, result);
}

bool ZHitman5::IsWalkingFast()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x2FE9B, this);
}

ZHM5MovementOperateCPDoor* ZHitman5::GetMovementOperateCPDoor()
{
	return Function::CallMethodAndReturn<ZHM5MovementOperateCPDoor*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x2FFCC, this);
}

unsigned int* ZHitman5::GetLastSentRequest()
{
	return Function::CallMethodAndReturn<unsigned int*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x30639, this);
}

bool ZHitman5::DropItem(TEntityRef<IHM5Item>* rItem)
{
	return Function::CallMethodAndReturn<bool, ZHitman5*, TEntityRef<IHM5Item>*>(BaseAddresses::hitman5Dll + 0x30738, this, rItem);
}

bool ZHitman5::IsThrowingSomething()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x307F6, this);
}

void ZHitman5::UpdateNearestRail()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x30918, this);
}

bool ZHitman5::IsInVentilatorShaft()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x30A7B, this);
}

bool ZHitman5::IsCurrentOutfitReady()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x30E6D, this);
}

void ZHitman5::RegisterClothBundlePool(TEntityRef<IHM5ClothBundlePool>* rPool)
{
	Function::CallMethod<ZHitman5*, TEntityRef<IHM5ClothBundlePool>*>(BaseAddresses::hitman5Dll + 0x31476, this, rPool);
}

void ZHitman5::PlayTargetEncounterCut()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x315F7, this);
}

void ZHitman5::GetHitmanAABB(SMatrix* m0, float4* s0)
{
	Function::CallMethod<ZHitman5*, SMatrix*, float4*>(BaseAddresses::hitman5Dll + 0x31750, this, m0, s0);
}

void ZHitman5::InitInitialInventory()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x31A84, this);
}

ZRuntimeResourceID* ZHitman5::GetOutfitResourceFromClothBundle(ZRuntimeResourceID* result, ZEntityRef* rOwner)
{
	return Function::CallMethodAndReturn<ZRuntimeResourceID*, ZHitman5*, ZRuntimeResourceID*, ZEntityRef*>(BaseAddresses::hitman5Dll + 0x323A3, this, result, rOwner);
}

void ZHitman5::SetOTSModeActive(bool bOTS)
{
	Function::CallMethod<ZHitman5*, bool>(BaseAddresses::hitman5Dll + 0x32493, this, bOTS);
}

ZHM5MovementLedgeHang* ZHitman5::GetMovementLedgeHang()
{
	return Function::CallMethodAndReturn<ZHM5MovementLedgeHang*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x32669, this);
}

bool ZHitman5::IsGravityEnabled()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x32763, this);
}

void ZHitman5::SetupAimAssists(float fBlendInTime, float fAimTime)
{
	Function::CallMethod<ZHitman5*, float, float>(BaseAddresses::hitman5Dll + 0x3277C, this, fBlendInTime, fAimTime);
}

void ZHitman5::SetDecriminalizedAiming(bool b)
{
	Function::CallMethod<ZHitman5*, bool>(BaseAddresses::hitman5Dll + 0x32781, this, b);
}

EBaseMovementType ZHitman5::GetCurrentMovementType()
{
	return Function::CallMethodAndReturn<EBaseMovementType, ZHitman5*>(BaseAddresses::hitman5Dll + 0x329FC, this);
}

bool ZHitman5::PickupItemDirect(TEntityRef<IHM5Item>* rItem)
{
	return Function::CallMethodAndReturn<bool, ZHitman5*, TEntityRef<IHM5Item>*>(BaseAddresses::hitman5Dll + 0x32E39, this, rItem);
}

bool ZHitman5::IsFiberWireKillPossible()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x33596, this);
}

void ZHitman5::CreateBaseMovements()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x33A87, this);
}

bool ZHitman5::IsVentilatorShaftPeekPossible()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x33C85, this);
}

bool ZHitman5::Arrest(TEntityRef<ZActor>* rActor)
{
	return Function::CallMethodAndReturn<bool, ZHitman5*, TEntityRef<ZActor>*>(BaseAddresses::hitman5Dll + 0x33F50, this, rActor);
}

IHM5ClothBundlePool* ZHitman5::GetClothBundlePool()
{
	return Function::CallMethodAndReturn<IHM5ClothBundlePool*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x340F4, this);
}

void ZHitman5::InitMorphemeIDs()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x34310, this);
}

unsigned int* ZHitman5::GetRequests()
{
	return Function::CallMethodAndReturn<unsigned int*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x3481F, this);
}

void ZHitman5::DebugContactMaterial()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x34BC6, this);
}

void ZHitman5::EquipOutfitResource(ZRuntimeResourceID ridNewOutfitLibrary, TEntityRef<IHM5Outfit> Outfit, bool bPlaceClothBundle, bool bForce)
{
	Function::CallMethod<ZHitman5*, ZRuntimeResourceID, TEntityRef<IHM5Outfit>, bool, bool>(BaseAddresses::hitman5Dll + 0x34DD8, this, ridNewOutfitLibrary, Outfit, bPlaceClothBundle, bForce);
}

bool ZHitman5::IsKillingByPush()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x34F9F, this);
}

bool ZHitman5::IsStanding()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x3517A, this);
}

float4* ZHitman5::GetArrestPos(float4* result)
{
	return Function::CallMethodAndReturn<float4*, ZHitman5*, float4*>(BaseAddresses::hitman5Dll + 0x353E1, this, result);
}

void ZHitman5::SetNearestContainer(ZHM5Action* pAction)
{
	Function::CallMethod<ZHitman5*, ZHM5Action*>(BaseAddresses::hitman5Dll + 0x35A8A, this, pAction);
}

bool ZHitman5::IsEnteringVent()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x35DC8, this);
}

void ZHitman5::PlayerCollision(SMatrix* mvFrom, SMatrix* mvTo, float fDeltaTime)
{
	Function::CallMethod<ZHitman5*, SMatrix*, SMatrix*, float>(BaseAddresses::hitman5Dll + 0x364B7, this, mvFrom, mvTo, fDeltaTime);
}

bool ZHitman5::IsGuideInGuidesList(ZHM5BaseGuide* pGuide)
{
	return Function::CallMethodAndReturn<bool, ZHitman5*, ZHM5BaseGuide*>(BaseAddresses::hitman5Dll + 0x3685E, this, pGuide);
}

const ZEntityRef* ZHitman5::GetMorphemeVariationResource()
{
	return Function::CallMethodAndReturn<const ZEntityRef*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x36886, this);
}

void ZHitman5::ActivateEnterVentilatorShaft(TEntityRef<ZHM5GuideVentilatorShaft> rVentilatorShaft)
{
	Function::CallMethod<ZHitman5*, TEntityRef<ZHM5GuideVentilatorShaft>>(BaseAddresses::hitman5Dll + 0x368E0, this, rVentilatorShaft);
}

bool ZHitman5::IsNonFireArmEquipped()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x36A89, this);
}

void ZHitman5::ReloadCurrentOutfit()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x36A9D, this);
}

void ZHitman5::GetPulse(float* fPulse, float* fWalkPulse)
{
	Function::CallMethod<ZHitman5*, float*, float*>(BaseAddresses::hitman5Dll + 0x36F75, this, fPulse, fWalkPulse);
}

bool ZHitman5::IsPlayerNPCCollisionEnabled()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x372CC, this);
}

SMatrix* ZHitman5::CalcLeftCalfColiMatPos(SMatrix* result)
{
	return Function::CallMethodAndReturn<SMatrix*, ZHitman5*, SMatrix*>(BaseAddresses::hitman5Dll + 0x37664, this, result);
}

ZHM5CoverPlane* ZHitman5::GetNearestRail()
{
	return Function::CallMethodAndReturn<ZHM5CoverPlane*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x37A56, this);
}

bool ZHitman5::IsPerformingTakedown()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x37A6F, this);
}

bool ZHitman5::RightSideAim()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x38037, this);
}

void ZHitman5::DeactivateFrameUpdate()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x3830C, this);
}

void ZHitman5::SetMovementAndLocomotionFlagsDefault(unsigned __int64 nMovementFlags, unsigned int nLocomotionFlags, unsigned __int64 nCustomFlags)
{
	Function::CallMethod<ZHitman5*, unsigned __int64, unsigned int, unsigned __int64>(BaseAddresses::hitman5Dll + 0x38631, this, nMovementFlags, nLocomotionFlags, nCustomFlags);
}

ZTargetTrackerGUI* ZHitman5::GetTargetTrackerGUI()
{
	return Function::CallMethodAndReturn<ZTargetTrackerGUI*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x38C2B, this);
}

void ZHitman5::ReleaseWeaponMaterial(TEntityRef<IHM5Item>* rItem)
{
	Function::CallMethod<ZHitman5*, TEntityRef<IHM5Item>*>(BaseAddresses::hitman5Dll + 0x39045, this, rItem);
}

ZHM5ReloadController* ZHitman5::GetReloadController()
{
	return Function::CallMethodAndReturn<ZHM5ReloadController*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x393E7, this);
}

ZHM5MovementSurrender* ZHitman5::GetMovementSurrender()
{
	return Function::CallMethodAndReturn<ZHM5MovementSurrender*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x3979D, this);
}

ZHitman5PermissionHandler* ZHitman5::GetPermissionHandler()
{
	return Function::CallMethodAndReturn<ZHitman5PermissionHandler*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x39991, this);
}

void ZHitman5::SetDecriminalizedCrossdressing(bool b)
{
	Function::CallMethod<ZHitman5*, bool>(BaseAddresses::hitman5Dll + 0x39B85, this, b);
}

bool ZHitman5::IsKnifingFromBehind()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x39D79, this);
}

bool ZHitman5::IsKillingByKick()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x3A0B2, this);
}

ZHM5WeaponControl* ZHitman5::GetWeaponControl()
{
	return Function::CallMethodAndReturn<ZHM5WeaponControl*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x3A17A, this);
}

bool ZHitman5::ActivateExitSafeZone()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x3AB93, this);
}

void ZHitman5::LoadWeaponMaterial(TEntityRef<IHM5Item>* rItem)
{
	Function::CallMethod<ZHitman5*, TEntityRef<IHM5Item>*>(BaseAddresses::hitman5Dll + 0x3ADD7, this, rItem);
}

ZHM5EquipController* ZHitman5::GetEquipController()
{
	return Function::CallMethodAndReturn<ZHM5EquipController*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x3AF9E, this);
}

float ZHitman5::CurrentGameTimeMultiplier()
{
	return Function::CallMethodAndReturn<float, ZHitman5*>(BaseAddresses::hitman5Dll + 0x3B3B8, this);
}

SRecoilAnimInfo ZHitman5::GetRecoilAnimInfo(TEntityRef<ZHM5ItemWeapon>* rWeapon, bool bDual)
{
	return Function::CallMethodAndReturn<SRecoilAnimInfo, ZHitman5*, TEntityRef<ZHM5ItemWeapon>*, bool>(BaseAddresses::hitman5Dll + 0x3B5C0, this, rWeapon, bDual);
}

bool ZHitman5::QueryHM5Flag(EHitmanGState queryFlag)
{
	return Function::CallMethodAndReturn<bool, ZHitman5*, EHitmanGState>(BaseAddresses::hitman5Dll + 0x3BF2A, this, queryFlag);
}

ZHM5BaseMovement* ZHitman5::GetMovementOfType(EBaseMovementType eType)
{
	return Function::CallMethodAndReturn<ZHM5BaseMovement*, ZHitman5*, EBaseMovementType>(BaseAddresses::hitman5Dll + 0x3C740, this, eType);
}

bool ZHitman5::IsOperatingCheckPointDoor()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x3C8FD, this);
}

ZHM5AimController* ZHitman5::GetAimController()
{
	return Function::CallMethodAndReturn<ZHM5AimController*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x3CA79, this);
}

void ZHitman5::SetHitmanTimeMultiplier(float fTimeMultiplier, bool bFromManager)
{
	Function::CallMethod<ZHitman5*, float, bool>(BaseAddresses::hitman5Dll + 0x3CAC4, this, fTimeMultiplier, bFromManager);
}

void ZHitman5::UpdatePulse(float fDeltaTime)
{
	Function::CallMethod<ZHitman5*, float>(BaseAddresses::hitman5Dll + 0x3CDF3, this, fDeltaTime);
}

bool ZHitman5::IsDisablingFusebox()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x3CFA6, this);
}

bool ZHitman5::IsLocomotionEnabled(ENetworkMoveStatus eNetworkMoveStatus)
{
	return Function::CallMethodAndReturn<bool, ZHitman5*, ENetworkMoveStatus>(BaseAddresses::hitman5Dll + 0x3D104, this, eNetworkMoveStatus);
}

void ZHitman5::SetCurrentMovement(ZHM5BaseMovement* pCurrentMovement)
{
	Function::CallMethod<ZHitman5*, ZHM5BaseMovement*>(BaseAddresses::hitman5Dll + 0x3D8D4, this, pCurrentMovement);
}

bool ZHitman5::GetDecriminalizedCloseCombat()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x3E41E, this);
}

void ZHitman5::SetInsideCloset(bool bValue)
{
	Function::CallMethod<ZHitman5*, bool>(BaseAddresses::hitman5Dll + 0x3E4D7, this, bValue);
}

void ZHitman5::ActivateCheckPoint()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x3E6F8, this);
}

ZHM5MovementPushVictim* ZHitman5::GetMovementPushVictim()
{
	return Function::CallMethodAndReturn<ZHM5MovementPushVictim*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x3E8FB, this);
}

void ZHitman5::UpdateMovementPostCam(SMatrix* mvFrom, SMatrix* mvTo)
{
	Function::CallMethod<ZHitman5*, SMatrix*, SMatrix*>(BaseAddresses::hitman5Dll + 0x3EC7A, this, mvFrom, mvTo);
}

ZHitman5* ZHitman5::operator=(ZHitman5* __that)
{
	return Function::CallMethodAndReturn<ZHitman5*, ZHitman5*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x3F0B7, this, __that);
}

bool ZHitman5::IsMountingLedge()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x3F1CF, this);
}

void ZHitman5::ForceQueuedMovement(EBaseMovementType eMovementType, IHM5ForceMovementCallBack* pForceMovementCallBack)
{
	Function::CallMethod<ZHitman5*, EBaseMovementType, IHM5ForceMovementCallBack*>(BaseAddresses::hitman5Dll + 0x3F1F2, this, eMovementType, pForceMovementCallBack);
}

ZHM5Health* ZHitman5::GetHealth()
{
	return Function::CallMethodAndReturn<ZHM5Health*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x3F34B, this);
}

bool ZHitman5::IsThrowingExplosives()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x3F756, this);
}

ZHM5CCTargetController* ZHitman5::GetCloseCombatTargetController()
{
	return Function::CallMethodAndReturn<ZHM5CCTargetController*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x3FD4B, this);
}

void ZHitman5::SignalAgilitySoundManager(ZHM5BaseMovement* pPrevMovement, ZHM5BaseMovement* pNextMovement)
{
	Function::CallMethod<ZHitman5*, ZHM5BaseMovement*, ZHM5BaseMovement*>(BaseAddresses::hitman5Dll + 0x40D86, this, pPrevMovement, pNextMovement);
}

ZHM5DisguiseSafeZoneMovement* ZHitman5::GetMovementDisguiseSafeZone()
{
	return Function::CallMethodAndReturn<ZHM5DisguiseSafeZoneMovement*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x410CE, this);
}

void ZHitman5::SetPelvisOffset(SMatrix* mvOffset, void* pClassPtr)
{
	Function::CallMethod<ZHitman5*, SMatrix*, void*>(BaseAddresses::hitman5Dll + 0x4157E, this, mvOffset, pClassPtr);
}

bool ZHitman5::IsKickVictimPossible()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x41673, this);
}

bool ZHitman5::GetDecriminalizedCrossdressing()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x4247E, this);
}

void ZHitman5::PrepareForCutSequence()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x42569, this);
}

void ZHitman5::UpdateSniperMode()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x42618, this);
}

const SHitmanGameplayState* ZHitman5::GetHitmanGameplayState()
{
	return Function::CallMethodAndReturn<const SHitmanGameplayState*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x43284, this);
}

bool ZHitman5::GuideActionPerform()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x434B9, this);
}

bool ZHitman5::IsInSequence()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x43856, this);
}

TEntityRef<ZHM5BodyContainer>* ZHitman5::GetNearestContainer(TEntityRef<ZHM5BodyContainer>* result)
{
	return Function::CallMethodAndReturn<TEntityRef<ZHM5BodyContainer>*, ZHitman5*, TEntityRef<ZHM5BodyContainer>*>(BaseAddresses::hitman5Dll + 0x4495E, this, result);
}

void ZHitman5::UpdateBlendIn(SGameUpdateEvent* updateEvent)
{
	Function::CallMethod<ZHitman5*, SGameUpdateEvent*>(BaseAddresses::hitman5Dll + 0x44995, this, updateEvent);
}

ZHM5MovementToss* ZHitman5::GetMovementToss()
{
	return Function::CallMethodAndReturn<ZHM5MovementToss*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x44F99, this);
}

float ZHitman5::GetSneakWeight()
{
	return Function::CallMethodAndReturn<float, ZHitman5*>(BaseAddresses::hitman5Dll + 0x45651, this);
}

ENetworkState ZHitman5::GetLocomotionStartState()
{
	return Function::CallMethodAndReturn<ENetworkState, ZHitman5*>(BaseAddresses::hitman5Dll + 0x45D04, this);
}

void ZHitman5::OnSceneStopping()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x4613C, this);
}

bool ZHitman5::IsFiberWiring()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x4684E, this);
}

bool ZHitman5::IsShootingInCover()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x46998, this);
}

void ZHitman5::SetItemHandling(bool bVal, unsigned int iActionClientFilter)
{
	Function::CallMethod<ZHitman5*, bool, unsigned int>(BaseAddresses::hitman5Dll + 0x46AAB, this, bVal, iActionClientFilter);
}

bool ZHitman5::EnterOTSMode()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x46BBE, this);
}

ZHM5SniperController* ZHitman5::GetSniperController()
{
	return Function::CallMethodAndReturn<ZHM5SniperController*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x46BD2, this);
}

int ZHitman5::GetFramesPassed()
{
	return Function::CallMethodAndReturn<int, ZHitman5*>(BaseAddresses::hitman5Dll + 0x472DA, this);
}

bool ZHitman5::IsExitingCloset()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x476A4, this);
}

void ZHitman5::EquipOutfitResourceAsync(bool bEquipWhenReady, ZRuntimeResourceID ridNewOutfitLibrary, TEntityRef<IHM5Outfit> Outfit, bool bPlaceClothBundle, bool bForce)
{
	Function::CallMethod<ZHitman5*, bool, ZRuntimeResourceID, TEntityRef<IHM5Outfit>, bool, bool>(BaseAddresses::hitman5Dll + 0x47C12, this, bEquipWhenReady, ridNewOutfitLibrary, Outfit, bPlaceClothBundle, bForce);
}

void ZHitman5::DeSelectOTSMode()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x4852C, this);
}

void ZHitman5::AddFocus(float fDelta)
{
	Function::CallMethod<ZHitman5*, float>(BaseAddresses::hitman5Dll + 0x485E0, this, fDelta);
}

void ZHitman5::DebugDisplayStatus()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x4866C, this);
}

void ZHitman5::EnableGravity(bool bEnable)
{
	Function::CallMethod<ZHitman5*, bool>(BaseAddresses::hitman5Dll + 0x4867B, this, bEnable);
}

void ZHitman5::CreateCharacterController()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x486FD, this);
}

bool ZHitman5::IsInCarryCivilianMovement()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x487AC, this);
}

void ZHitman5::OnWeaponFireProjectile(TEntityRef<ZHM5ItemWeapon>* rWeapon)
{
	Function::CallMethod<ZHitman5*, TEntityRef<ZHM5ItemWeapon>*>(BaseAddresses::hitman5Dll + 0x487D4, this, rWeapon);
}

ZHM5InputControlScheme* ZHitman5::GetControlScheme()
{
	return Function::CallMethodAndReturn<ZHM5InputControlScheme*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x4891E, this);
}

bool ZHitman5::HasQueuedForceMovementCallBack(IHM5ForceMovementCallBack* pForceMovementCallBack)
{
	return Function::CallMethodAndReturn<bool, ZHitman5*, IHM5ForceMovementCallBack*>(BaseAddresses::hitman5Dll + 0x48B1C, this, pForceMovementCallBack);
}

SMatrix* ZHitman5::CalcHeadColiMatPos(SMatrix* result)
{
	return Function::CallMethodAndReturn<SMatrix*, ZHitman5*, SMatrix*>(BaseAddresses::hitman5Dll + 0x492D3, this, result);
}

bool ZHitman5::CanPickOrSwap(TEntityRef<IHM5Item>* rItem)
{
	return Function::CallMethodAndReturn<bool, ZHitman5*, TEntityRef<IHM5Item>*>(BaseAddresses::hitman5Dll + 0x4955D, this, rItem);
}

bool ZHitman5::IsEnteringWindow()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x495B2, this);
}

void ZHitman5::QueueForcedMovement(EBaseMovementType eMovementType, IHM5ForceMovementCallBack* pForceMovementCallBack)
{
	Function::CallMethod<ZHitman5*, EBaseMovementType, IHM5ForceMovementCallBack*>(BaseAddresses::hitman5Dll + 0x4960C, this, eMovementType, pForceMovementCallBack);
}

ZHM5MovementHideInCloset* ZHitman5::GetMovementHideInCloset()
{
	return Function::CallMethodAndReturn<ZHM5MovementHideInCloset*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x49B61, this);
}

void ZHitman5::SetLoadScreenActive(bool bActive)
{
	Function::CallMethod<ZHitman5*, bool>(BaseAddresses::hitman5Dll + 0x49D0A, this, bActive);
}

void ZHitman5::UpdateHandleReset()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x49F30, this);
}

void ZHitman5::RelocatePlayerCollision(float4* vPos)
{
	Function::CallMethod<ZHitman5*, float4*>(BaseAddresses::hitman5Dll + 0x4A359, this, vPos);
}

bool ZHitman5::ActorIgnoreDamage(TEntityRef<ZActor> rActor)
{
	return Function::CallMethodAndReturn<bool, ZHitman5*, TEntityRef<ZActor>>(BaseAddresses::hitman5Dll + 0x4A381, this, rActor);
}

bool ZHitman5::IsVentilatorShaftExitPossible()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x4A953, this);
}

void ZHitman5::SetMorphemeVariationResource(ZEntityRef pVariationResource)
{
	Function::CallMethod<ZHitman5*, ZEntityRef>(BaseAddresses::hitman5Dll + 0x4ADF9, this, pVariationResource);
}

void ZHitman5::UpdateCameraProfile(SHM5GameCamParams* CurrentProfile)
{
	Function::CallMethod<ZHitman5*, SHM5GameCamParams*>(BaseAddresses::hitman5Dll + 0x4B196, this, CurrentProfile);
}

bool ZHitman5::CanStartCloseCombat()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x4B3DA, this);
}

float ZHitman5::CurrentGameTimeDeltaNormalized()
{
	return Function::CallMethodAndReturn<float, ZHitman5*>(BaseAddresses::hitman5Dll + 0x4B7A4, this);
}

void ZHitman5::RegisterType()
{
	Function::Call<>(BaseAddresses::hitman5Dll + 0x4B99D);
}

TEntityRef<IHM5ItemWeapon>* ZHitman5::GetFailSafeDisarmWeapon(TEntityRef<IHM5ItemWeapon>* result)
{
	return Function::CallMethodAndReturn<TEntityRef<IHM5ItemWeapon>*, ZHitman5*, TEntityRef<IHM5ItemWeapon>*>(BaseAddresses::hitman5Dll + 0x4C3F2, this, result);
}

ZHM5MovementHumanShield* ZHitman5::GetMovementHumanShield()
{
	return Function::CallMethodAndReturn<ZHM5MovementHumanShield*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x4C780, this);
}

void ZHitman5::ResetImmediate(SMatrix* mvNewPos)
{
	Function::CallMethod<ZHitman5*, SMatrix*>(BaseAddresses::hitman5Dll + 0x4CDA2, this, mvNewPos);
}

void ZHitman5::SetMovementAndLocomotionFlags(unsigned __int64 nMovementFlags, unsigned int nLocomotionFlags, unsigned __int64 nCustomFlags)
{
	Function::CallMethod<ZHitman5*, unsigned __int64, unsigned int, unsigned __int64>(BaseAddresses::hitman5Dll + 0x4CFCD, this, nMovementFlags, nLocomotionFlags, nCustomFlags);
}

bool ZHitman5::IsWalking()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x4D0EA, this);
}

bool ZHitman5::IsInInteractiveCutsequence()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x4D59F, this);
}

void ZHitman5::UpdateMovementContext(ZHM5BaseMovement* pNextMovement)
{
	Function::CallMethod<ZHitman5*, ZHM5BaseMovement*>(BaseAddresses::hitman5Dll + 0x4D757, this, pNextMovement);
}

bool ZHitman5::GetIsInInstinctMode()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x4D874, this);
}

bool ZHitman5::IsBlindFiring()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x4DBE9, this);
}

void ZHitman5::UpdateCameraEvent(SCameraUpdateEvent* CameraUpdateEvent)
{
	Function::CallMethod<ZHitman5*, SCameraUpdateEvent*>(BaseAddresses::hitman5Dll + 0x4DD65, this, CameraUpdateEvent);
}

ZHM5CoverPlane* ZHitman5::GetCurrentCoverPlane()
{
	return Function::CallMethodAndReturn<ZHM5CoverPlane*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x4E927, this);
}

float ZHitman5::GetMoveLength()
{
	return Function::CallMethodAndReturn<float, ZHitman5*>(BaseAddresses::hitman5Dll + 0x4ECD8, this);
}

void ZHitman5::SetInMinigame(bool bMiniGame)
{
	Function::CallMethod<ZHitman5*, bool>(BaseAddresses::hitman5Dll + 0x4EE77, this, bMiniGame);
}

float ZHitman5::GetVelocity()
{
	return Function::CallMethodAndReturn<float, ZHitman5*>(BaseAddresses::hitman5Dll + 0x4F23C, this);
}

bool ZHitman5::IsCustomFlagEnabled(ECustomFlags eCustomFlags)
{
	return Function::CallMethodAndReturn<bool, ZHitman5*, ECustomFlags>(BaseAddresses::hitman5Dll + 0x4F2C8, this, eCustomFlags);
}

void ZHitman5::UpdateInstinctMode()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x4F494, this);
}

void ZHitman5::LevelEnded()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x4F4FD, this);
}

ZResourcePtr* ZHitman5::GetOutfitMovie(ZResourcePtr* result)
{
	return Function::CallMethodAndReturn<ZResourcePtr*, ZHitman5*, ZResourcePtr*>(BaseAddresses::hitman5Dll + 0x4F7D2, this, result);
}

void ZHitman5::InitSequenceRelatedFields()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x4F8C2, this);
}

ZHM5MovementVentilatorShaft* ZHitman5::GetMovementVentilatorShaft()
{
	return Function::CallMethodAndReturn<ZHM5MovementVentilatorShaft*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x4FC96, this);
}

bool ZHitman5::IsDualEquipped()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x4FE76, this);
}

void ZHitman5::CheckFirstColi()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x4FF6B, this);
}

bool ZHitman5::IsExitingVent()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x50164, this);
}

void ZHitman5::UpdateOTSMode()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x50196, this);
}

ZHM5MovementCarryCivilian* ZHitman5::GetMovementCarryCivilian()
{
	return Function::CallMethodAndReturn<ZHM5MovementCarryCivilian*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x501A0, this);
}

void ZHitman5::HandleCustomFlagSequence(unsigned __int64 nCustomFlags)
{
	Function::CallMethod<ZHitman5*, unsigned __int64>(BaseAddresses::hitman5Dll + 0x50556, this, nCustomFlags);
}

void ZHitman5::DeactivateCheckPointBeforeSpawnDelete()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x507EF, this);
}

ZGameTime* ZHitman5::CurrentRealTimeDelta(ZGameTime* result)
{
	return Function::CallMethodAndReturn<ZGameTime*, ZHitman5*, ZGameTime*>(BaseAddresses::hitman5Dll + 0x512B7, this, result);
}

const SOutfitData* ZHitman5::GetOutfitData()
{
	return Function::CallMethodAndReturn<const SOutfitData*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x512D5, this);
}

void ZHitman5::UpdateGuidesList()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x51ADC, this);
}

bool ZHitman5::CanSkipSequence()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x51BBD, this);
}

bool ZHitman5::IsClosetPeekPossible()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x51C4E, this);
}

bool ZHitman5::SelectOTSMode()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x51E9C, this);
}

bool ZHitman5::IsPlayerCollisionEnabled()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x64DA0, this);
}

ZHitmanMorphemePostProcessor* ZHitman5::GetPostProcessor()
{
	return Function::CallMethodAndReturn<ZHitmanMorphemePostProcessor*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x64E10, this);
}

ZHM5PostfilterController* ZHitman5::GetHitmanPostfilterController()
{
	return Function::CallMethodAndReturn<ZHM5PostfilterController*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x64E90, this);
}

SMatrix* ZHitman5::GetCurrentPelvisOffset(SMatrix* result)
{
	return Function::CallMethodAndReturn<SMatrix*, ZHitman5*, SMatrix*>(BaseAddresses::hitman5Dll + 0x64F80, this, result);
}

void ZHitman5::SetInterpolatePelvisOffset(bool bInterpolate)
{
	Function::CallMethod<ZHitman5*, bool>(BaseAddresses::hitman5Dll + 0x64FB0, this, bInterpolate);
}

const ZHitman5PermissionHandler* ZHitman5::GetPermissionHandlerConst()
{
	return Function::CallMethodAndReturn<const ZHitman5PermissionHandler*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x65060, this);
}

void ZHitman5::SetDecriminalizedWeapons(bool b)
{
	Function::CallMethod<ZHitman5*, bool>(BaseAddresses::hitman5Dll + 0x65100, this, b);
}

void ZHitman5::SetDecriminalizedCloseCombat(bool b)
{
	Function::CallMethod<ZHitman5*, bool>(BaseAddresses::hitman5Dll + 0x65160, this, b);
}

const SGameUpdateEvent* ZHitman5::CurrentUpdateEvent()
{
	return Function::CallMethodAndReturn<const SGameUpdateEvent*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x651C0, this);
}

ZHM5InputControl* ZHitman5::GetInputControl()
{
	return Function::CallMethodAndReturn<ZHM5InputControl*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x65960, this);
}

ZHM5FocusController* ZHitman5::GetFocusController()
{
	return Function::CallMethodAndReturn<ZHM5FocusController*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x659F0, this);
}

void ZHitman5::SetCurrentControlScheme(ZHM5InputControlScheme* pNewControlScheme)
{
	Function::CallMethod<ZHitman5*, ZHM5InputControlScheme*>(BaseAddresses::hitman5Dll + 0x28F990, this, pNewControlScheme);
}

void ZHitman5::EnablePlayerNPCCollision(bool bEnable)
{
	Function::CallMethod<ZHitman5*, bool>(BaseAddresses::hitman5Dll + 0x290000, this, bEnable);
}

ZRuntimeResourceID* ZHitman5::GetCurrentOutfitResourceID(ZRuntimeResourceID* result)
{
	return Function::CallMethodAndReturn<ZRuntimeResourceID*, ZHitman5*, ZRuntimeResourceID*>(BaseAddresses::hitman5Dll + 0x290390, this, result);
}

void ZHitman5::SetHangOnLedgeMovementGuide(ZHM5BaseGuide* pGuide)
{
	Function::CallMethod<ZHitman5*, ZHM5BaseGuide*>(BaseAddresses::hitman5Dll + 0x290780, this, pGuide);
}

int ZHitman5::GetControllerId()
{
	return Function::CallMethodAndReturn<int, ZHitman5*>(BaseAddresses::hitman5Dll + 0x290AE0, this);
}

bool ZHitman5::IsInMinigame()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x290B10, this);
}

ZHM5MovementFiberWireKill* ZHitman5::GetMovementFiberWireKill()
{
	return Function::CallMethodAndReturn<ZHM5MovementFiberWireKill*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x290B80, this);
}

ZHM5MovementPullVictimThroughWindow* ZHitman5::GetMovementPullVictimFromWindow()
{
	return Function::CallMethodAndReturn<ZHM5MovementPullVictimThroughWindow*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x290B90, this);
}

void ZHitman5::ClearQueuedForceMovement()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x290C60, this);
}

ZHM5MovementLadder* ZHitman5::GetMovementLadder()
{
	return Function::CallMethodAndReturn<ZHM5MovementLadder*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x290CF0, this);
}

ZHM5MovementCover* ZHitman5::GetMovementCover()
{
	return Function::CallMethodAndReturn<ZHM5MovementCover*, ZHitman5*>(BaseAddresses::hitman5Dll + 0x290D20, this);
}

void ZHitman5::SetHitmanPostfilterController(ZHM5PostfilterController* pHM5PostfilterController)
{
	Function::CallMethod<ZHitman5*, ZHM5PostfilterController*>(BaseAddresses::hitman5Dll + 0x290E90, this, pHM5PostfilterController);
}

void ZHitman5::SetAvoidParams(float fLeftRight, float fBlend)
{
	Function::CallMethod<ZHitman5*, float, float>(BaseAddresses::hitman5Dll + 0x290EF0, this, fLeftRight, fBlend);
}

bool ZHitman5::CanBeArrested()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x2911F0, this);
}

bool ZHitman5::IsRunning()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x292510, this);
}

void ZHitman5::SetSneaking(bool bSet)
{
	Function::CallMethod<ZHitman5*, bool>(BaseAddresses::hitman5Dll + 0x292600, this, bSet);
}

void ZHitman5::SetHoldsUtilityMode(bool bSet)
{
	Function::CallMethod<ZHitman5*, bool>(BaseAddresses::hitman5Dll + 0x292630, this, bSet);
}

bool ZHitman5::IsDoingDeadlyThrow()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x292C30, this);
}

bool ZHitman5::IsKillingByPull()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x292D70, this);
}

bool ZHitman5::IsDumpingBody()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x293120, this);
}

bool ZHitman5::IsInSBTagMode()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x293740, this);
}

void ZHitman5::SetLooseTargetEncounterCutRef(TEntityRef<ZHM5LooseTargetEncounter> rLooseTargetEncounter)
{
	Function::CallMethod<ZHitman5*, TEntityRef<ZHM5LooseTargetEncounter>>(BaseAddresses::hitman5Dll + 0x293BB0, this, rLooseTargetEncounter);
}

bool ZHitman5::PrepareTargetEncounterCut()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x295F40, this);
}

bool ZHitman5::CanPlayLooseTargetEncounterCut()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x295F60, this);
}

bool ZHitman5::IsAiming()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x296F00, this);
}

void ZHitman5::UpdateAlternateFire()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x296FC0, this);
}

bool ZHitman5::SwapItemDirect(TEntityRef<IHM5Item>* rNewItem, TEntityRef<IHM5Item>* rDisposedItem)
{
	return Function::CallMethodAndReturn<bool, ZHitman5*, TEntityRef<IHM5Item>*, TEntityRef<IHM5Item>*>(BaseAddresses::hitman5Dll + 0x298910, this, rNewItem, rDisposedItem);
}

bool ZHitman5::UnHolster(ZHM5WeaponSet* weaponSet)
{
	return Function::CallMethodAndReturn<bool, ZHitman5*, ZHM5WeaponSet*>(BaseAddresses::hitman5Dll + 0x298ED0, this, weaponSet);
}

void ZHitman5::UnloadCurrentOutfit()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x29A110, this);
}

void ZHitman5::ExitSniperMode()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x29A640, this);
}

bool ZHitman5::BlockedByCrowd()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x29B030, this);
}

void ZHitman5::ResetBlendInState()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x29B1F0, this);
}

void ZHitman5::CreateControllers()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x29B3C0, this);
}

void ZHitman5::CheckHitmanNPCCollision(SMatrix* mvFrom, SMatrix* mvTo)
{
	Function::CallMethod<ZHitman5*, SMatrix*, SMatrix*>(BaseAddresses::hitman5Dll + 0x2A03E0, this, mvFrom, mvTo);
}

void ZHitman5::EquipOutfitInternal(ZDynamicResourceLibrary* pNewOutfitLibrary, TEntityRef<IHM5Outfit> Outfit, bool bPlaceClothBundle, TEntityRef<ZSpatialEntity> pClothBundlePosition, bool bForce)
{
	Function::CallMethod<ZHitman5*, ZDynamicResourceLibrary*, TEntityRef<IHM5Outfit>, bool, TEntityRef<ZSpatialEntity>, bool>(BaseAddresses::hitman5Dll + 0x2A1880, this, pNewOutfitLibrary, Outfit, bPlaceClothBundle, pClothBundlePosition, bForce);
}

bool ZHitman5::EnterSniperMode()
{
	return Function::CallMethodAndReturn<bool, ZHitman5*>(BaseAddresses::hitman5Dll + 0x2A2650, this);
}

ZDynamicResourceLibrary* ZHitman5::EquipOutfitFromCharacter(TEntityRef<ZHM5BaseCharacter>* pCharacter, ZDynamicResourceLibrary* pNewOutfitLibrary)
{
	return Function::CallMethodAndReturn<ZDynamicResourceLibrary*, ZHitman5*, TEntityRef<ZHM5BaseCharacter>*, ZDynamicResourceLibrary*>(BaseAddresses::hitman5Dll + 0x2A4440, this, pCharacter, pNewOutfitLibrary);
}

void ZHitman5::OnLoadingOutfitStatusChanged(ZRuntimeResourceID* rid)
{
	Function::CallMethod<ZHitman5*, ZRuntimeResourceID*>(BaseAddresses::hitman5Dll + 0x2A4F50, this, rid);
}

void ZHitman5::EquipOutfitResourceAsync_Abort(ZRuntimeResourceID ridNewOutfitLibrary)
{
	Function::CallMethod<ZHitman5*, ZRuntimeResourceID>(BaseAddresses::hitman5Dll + 0x2A86B0, this, ridNewOutfitLibrary);
}

void ZHitman5::CutSequenceStarted()
{
	Function::CallMethod<ZHitman5*>(BaseAddresses::hitman5Dll + 0x2A8710, this);
}
