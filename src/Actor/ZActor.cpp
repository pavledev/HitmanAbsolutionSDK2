#include "ZActor.h"
#include "Function.h"
#include "BaseAddresses.h"

const TSharedPointer<ZKnowledge>* ZActor::GetKnowledge()
{
	return Function::CallMethodAndReturn<const TSharedPointer<ZKnowledge>*, ZActor*>(BaseAddresses::hitman5Dll + 0x64B80, this);
}

ZActor::EActorState ZActor::GetActorState()
{
	return Function::CallMethodAndReturn<ZActor::EActorState, ZActor*>(BaseAddresses::hitman5Dll + 0x64C30, this);
}

bool ZActor::IsAlive()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x64C40, this);
}

void ZActor::StopShooting()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x64C50, this);
}

bool ZActor::IsShootingRequested()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x64C60, this);
}

void ZActor::SetShootTarget(ZPositionTarget* rTarget)
{
	Function::CallMethod<ZActor*, ZPositionTarget*>(BaseAddresses::hitman5Dll + 0x69050, this, rTarget);
}

void ZActor::StartShooting(ZPositionTarget* rTarget, bool bIgnoreLOF, bool bBlindFire)
{
	Function::CallMethod<ZActor*, ZPositionTarget*, bool, bool>(BaseAddresses::hitman5Dll + 0x6C0F0, this, rTarget, bIgnoreLOF, bBlindFire);
}

void ZActor::ClearShootTarget()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x6E110, this);
}

TArrayRef<SHitInfo>* ZActor::GetHitInfoList(TArrayRef<SHitInfo>* result)
{
	return Function::CallMethodAndReturn<TArrayRef<SHitInfo>*, ZActor*, TArrayRef<SHitInfo>*>(BaseAddresses::hitman5Dll + 0x6F6B0, this, result);
}

bool ZActor::IsSpeaking()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0xBA4F0, this);
}

bool ZActor::IsUnnoticableKillEnabled()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0xBF9B0, this);
}

bool ZActor::IsPacified()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0xE5B80, this);
}

bool ZActor::IsFullyEnabled()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0xED320, this);
}

ZShootTargetInfo* ZActor::GetShootTargetInfo()
{
	return Function::CallMethodAndReturn<ZShootTargetInfo*, ZActor*>(BaseAddresses::hitman5Dll + 0x1006B0, this);
}

void ZActor::SetHasGreetedHM(bool bGreetedHM)
{
	Function::CallMethod<ZActor*, bool>(BaseAddresses::hitman5Dll + 0x1022D0, this, bGreetedHM);
}

bool ZActor::GetHasGreetedHM()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x102300, this);
}

bool ZActor::CanCallForHelp()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x107FB0, this);
}

bool ZActor::IsFemale()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x11B570, this);
}

void ZActor::SetAloneAsHumanShieldVictim(bool bAlone)
{
	Function::CallMethod<ZActor*, bool>(BaseAddresses::hitman5Dll + 0x120920, this, bAlone);
}

bool ZActor::IsMuted()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x122890, this);
}

float4* ZActor::GetBoneWorldPosition(float4* result, unsigned int iBoneId)
{
	return Function::CallMethodAndReturn<float4*, ZActor*, float4*, unsigned int>(BaseAddresses::hitman5Dll + 0x123690, this, result, iBoneId);
}

bool ZActor::IsBodyHidden()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x179890, this);
}

void ZActor::BodyHidden(bool b)
{
	Function::CallMethod<ZActor*, bool>(BaseAddresses::hitman5Dll + 0x1798A0, this, b);
}

void ZActor::SetIsDeadTarget(bool dt)
{
	Function::CallMethod<ZActor*, bool>(BaseAddresses::hitman5Dll + 0x189B20, this, dt);
}

void ZActor::SetSBKillTagged(bool bTagged)
{
	Function::CallMethod<ZActor*, bool>(BaseAddresses::hitman5Dll + 0x189B40, this, bTagged);
}

ZString* ZActor::GetActorName(ZString* result)
{
	return Function::CallMethodAndReturn<ZString*, ZActor*, ZString*>(BaseAddresses::hitman5Dll + 0x20B240, this, result);
}

SMatrix43* ZActor::GetBoneWorldTransform(SMatrix43* result, unsigned int iBoneId)
{
	return Function::CallMethodAndReturn<SMatrix43*, ZActor*, SMatrix43*, unsigned int>(BaseAddresses::hitman5Dll + 0x21F170, this, result, iBoneId);
}

SMatrix43* ZActor::GetBoneTransform(SMatrix43* result, unsigned int iBoneId)
{
	return Function::CallMethodAndReturn<SMatrix43*, ZActor*, SMatrix43*, unsigned int>(BaseAddresses::hitman5Dll + 0x21F1B0, this, result, iBoneId);
}

EActorDeathType ZActor::GetDeathType()
{
	return Function::CallMethodAndReturn<EActorDeathType, ZActor*>(BaseAddresses::hitman5Dll + 0x2E7200, this);
}

bool ZActor::IsReleaseRagdollAfterBodyHiddenTriggered()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x31D2D0, this);
}

bool ZActor::IsDeadTarget()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x3DCBA0, this);
}

SActorSoundDefs::EDefinition ZActor::GetActiveSpeak()
{
	return Function::CallMethodAndReturn<SActorSoundDefs::EDefinition, ZActor*>(BaseAddresses::hitman5Dll + 0x3DCC40, this);
}

bool ZActor::IsAvailableOnDifficultyLevel(int iDifficultyLevel)
{
	return Function::CallMethodAndReturn<bool, ZActor*, int>(BaseAddresses::hitman5Dll + 0x3DCE80, this, iDifficultyLevel);
}

void ZActor::OnSpawned()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3DCEF0, this);
}

EActorType ZActor::GetActorType()
{
	return Function::CallMethodAndReturn<EActorType, ZActor*>(BaseAddresses::hitman5Dll + 0x3DCF10, this);
}

EActorRank ZActor::GetActorRank()
{
	return Function::CallMethodAndReturn<EActorRank, ZActor*>(BaseAddresses::hitman5Dll + 0x3DCF20, this);
}

EActorGroup ZActor::GetActorGroup()
{
	return Function::CallMethodAndReturn<EActorGroup, ZActor*>(BaseAddresses::hitman5Dll + 0x3DCF30, this);
}

void ZActor::SetActorGroup(EActorGroup group)
{
	Function::CallMethod<ZActor*, EActorGroup>(BaseAddresses::hitman5Dll + 0x3DCF40, this, group);
}

void ZActor::SetAboutToDie()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3DCF60, this);
}

bool ZActor::IsAboutToDie()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x3DCF70, this);
}

void ZActor::SetDeathType(EActorDeathType eDeathType)
{
	Function::CallMethod<ZActor*, EActorDeathType>(BaseAddresses::hitman5Dll + 0x3DCF80, this, eDeathType);
}

bool ZActor::IsBeingDragged()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x3DCFE0, this);
}

void ZActor::OnInventoryChanged(TArray<TEntityRef<IHM5Item> >* old)
{
	Function::CallMethod<ZActor*, TArray<TEntityRef<IHM5Item> >*>(BaseAddresses::hitman5Dll + 0x3DCFF0, this, old);
}

void ZActor::StopSubtitles(ISoundPlayerChannel* pChannel)
{
	Function::CallMethod<ZActor*, ISoundPlayerChannel*>(BaseAddresses::hitman5Dll + 0x3DD040, this, pChannel);
}

void ZActor::OnWeaponFireProjectile(TEntityRef<ZHM5ItemWeapon>* rWeapon)
{
	Function::CallMethod<ZActor*, TEntityRef<ZHM5ItemWeapon>*>(BaseAddresses::hitman5Dll + 0x3DD0F0, this, rWeapon);
}

unsigned int ZActor::ForceUpdate()
{
	return Function::CallMethodAndReturn<unsigned int, ZActor*>(BaseAddresses::hitman5Dll + 0x3DD110, this);
}

bool ZActor::IsUpdateForced()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x3DD130, this);
}

void ZActor::SetForceUpdate(bool bForced)
{
	Function::CallMethod<ZActor*, bool>(BaseAddresses::hitman5Dll + 0x3DD140, this, bForced);
}

void ZActor::ReleaseRagdollAfterBodyHidden(ZGameTime* curGameTime)
{
	Function::CallMethod<ZActor*, ZGameTime*>(BaseAddresses::hitman5Dll + 0x3DD160, this, curGameTime);
}

void ZActor::SetInSequence(bool b)
{
	Function::CallMethod<ZActor*, bool>(BaseAddresses::hitman5Dll + 0x3DD1A0, this, b);
}

bool ZActor::IsInSequence()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x3DD1D0, this);
}

void ZActor::OnDisableDeathAnimation()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3DD200, this);
}

void ZActor::OnAboutToDie()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3DD210, this);
}

void ZActor::SetInteractionAllowed(EActorInteractionFlag eInteraction, bool bAllowed)
{
	Function::CallMethod<ZActor*, EActorInteractionFlag, bool>(BaseAddresses::hitman5Dll + 0x3DD220, this, eInteraction, bAllowed);
}

bool ZActor::GetInteractionAllowed(EActorInteractionFlag eInteraction)
{
	return Function::CallMethodAndReturn<bool, ZActor*, EActorInteractionFlag>(BaseAddresses::hitman5Dll + 0x3DD260, this, eInteraction);
}

void ZActor::SetActorMultiplier(float fTimeMultiplier)
{
	Function::CallMethod<ZActor*, float>(BaseAddresses::hitman5Dll + 0x3DD2A0, this, fTimeMultiplier);
}

void ZActor::OnEnableUnnoticableKill()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3DD2C0, this);
}

void ZActor::OnDisableUnnoticableKill()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3DD2D0, this);
}

ZAnimatedActor* ZActor::GetAnimatedActor()
{
	return Function::CallMethodAndReturn<ZAnimatedActor*, ZActor*>(BaseAddresses::hitman5Dll + 0x3DD2E0, this);
}

ZActorAnimationState* ZActor::GetAnimationState()
{
	return Function::CallMethodAndReturn<ZActorAnimationState*, ZActor*>(BaseAddresses::hitman5Dll + 0x3DD2F0, this);
}

bool ZActor::IsLeaningAtWindow()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x3DD310, this);
}

bool ZActor::IsFacingDirection(float4* vDir, float fAngleToleranceDegrees)
{
	return Function::CallMethodAndReturn<bool, ZActor*, float4*, float>(BaseAddresses::hitman5Dll + 0x3DD320, this, vDir, fAngleToleranceDegrees);
}

bool ZActor::HasLocomotionControlledBySequence()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x3DD440, this);
}

bool ZActor::IsInFullBodySequence()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x3DD4D0, this);
}

void ZActor::OnUnrecoverableError(ZString* reason)
{
	Function::CallMethod<ZActor*, ZString*>(BaseAddresses::hitman5Dll + 0x3DD5D0, this, reason);
}

void ZActor::RemoveActorBroken()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3DD5E0, this);
}

void ZActor::DisableAmbientLookAt()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3DD630, this);
}

void ZActor::EnableAmbientLookAt()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3DD640, this);
}

void ZActor::RemoveGlow()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3DD650, this);
}

int ZActor::LookAroundAct_GetCount()
{
	return Function::CallMethodAndReturn<int, ZActor*>(BaseAddresses::hitman5Dll + 0x3DD690, this);
}

void ZActor::LookAroundAct_Shuffle()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3DD6A0, this);
}

void ZActor::BodyWaterSplashed(bool b)
{
	Function::CallMethod<ZActor*, bool>(BaseAddresses::hitman5Dll + 0x3DD740, this, b);
}

bool ZActor::AttachItem(EAttachLocation eLocation, TEntityRef<IHM5Item>* rItem)
{
	return Function::CallMethodAndReturn<bool, ZActor*, EAttachLocation, TEntityRef<IHM5Item>*>(BaseAddresses::hitman5Dll + 0x3DF7E0, this, eLocation, rItem);
}

EAttachLocation ZActor::GetItemLocation(TEntityRef<IHM5Item>* rItem)
{
	return Function::CallMethodAndReturn<EAttachLocation, ZActor*, TEntityRef<IHM5Item>*>(BaseAddresses::hitman5Dll + 0x3DF8F0, this, rItem);
}

TEntityRef<IHM5Item>* ZActor::GetAttachedItem(TEntityRef<IHM5Item>* result, EAttachLocation eLocation)
{
	return Function::CallMethodAndReturn<TEntityRef<IHM5Item>*, ZActor*, TEntityRef<IHM5Item>*, EAttachLocation>(BaseAddresses::hitman5Dll + 0x3DFA00, this, result, eLocation);
}

bool ZActor::GetAttachLocation(TEntityRef<IHM5Item> pItem, EAttachLocation* loc)
{
	return Function::CallMethodAndReturn<bool, ZActor*, TEntityRef<IHM5Item>, EAttachLocation*>(BaseAddresses::hitman5Dll + 0x3DFB40, this, pItem, loc);
}

void ZActor::UpdateHumanShieldMovement(ZString* sRequest)
{
	Function::CallMethod<ZActor*, ZString*>(BaseAddresses::hitman5Dll + 0x3DFDA0, this, sRequest);
}

void ZActor::SetDefaultHumansShieldState(unsigned int nStrafeID)
{
	Function::CallMethod<ZActor*, unsigned int>(BaseAddresses::hitman5Dll + 0x3DFDC0, this, nStrafeID);
}

void ZActor::UpdateCarryCivilianMovement(ZString* sRequest)
{
	Function::CallMethod<ZActor*, ZString*>(BaseAddresses::hitman5Dll + 0x3DFDE0, this, sRequest);
}

void ZActor::SetDefaultCarryCivilianState(unsigned int nStrafeID)
{
	Function::CallMethod<ZActor*, unsigned int>(BaseAddresses::hitman5Dll + 0x3DFE00, this, nStrafeID);
}

void ZActor::OnCompiledBehaviorTreeChanged()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3DFE20, this);
}

bool ZActor::IsBehaviorPromoted(TEntityRef<ZBehaviorEntityBase> rBehavior)
{
	return Function::CallMethodAndReturn<bool, ZActor*, TEntityRef<ZBehaviorEntityBase>>(BaseAddresses::hitman5Dll + 0x3DFEC0, this, rBehavior);
}

float ZActor::GetSpeakEndTime()
{
	return Function::CallMethodAndReturn<float, ZActor*>(BaseAddresses::hitman5Dll + 0x3DFF20, this);
}

float ZActor::GetSequenceEndTime()
{
	return Function::CallMethodAndReturn<float, ZActor*>(BaseAddresses::hitman5Dll + 0x3DFFA0, this);
}

bool ZActor::IsEnemyInFrontArc(float fArcHalfangleInDeg)
{
	return Function::CallMethodAndReturn<bool, ZActor*, float>(BaseAddresses::hitman5Dll + 0x3E0020, this, fArcHalfangleInDeg);
}

void ZActor::OnHelpPointChanged()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3E01C0, this);
}

TEntityRef<IHM5Item>* ZActor::GetInitialRightHandItem(TEntityRef<IHM5Item>* result)
{
	return Function::CallMethodAndReturn<TEntityRef<IHM5Item>*, ZActor*, TEntityRef<IHM5Item>*>(BaseAddresses::hitman5Dll + 0x3E01E0, this, result);
}

void ZActor::FlagDeathAsUnnoticed()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3E0240, this);
}

EActorPerceptionSensitivity ZActor::GetPerceptionSensitivity(EGameTension eTension)
{
	return Function::CallMethodAndReturn<EActorPerceptionSensitivity, ZActor*, EGameTension>(BaseAddresses::hitman5Dll + 0x3E02F0, this, eTension);
}

void ZActor::UpdateReleaseRagdollAfterBodyHidden(ZGameTime* curGameTime)
{
	Function::CallMethod<ZActor*, ZGameTime*>(BaseAddresses::hitman5Dll + 0x3E03D0, this, curGameTime);
}

void ZActor::SetHitPointsDirect(float fHitpoints)
{
	Function::CallMethod<ZActor*, float>(BaseAddresses::hitman5Dll + 0x3E0450, this, fHitpoints);
}

bool ZActor::IsFacingPosition(float4* vPos, float fAngleToleranceDegrees)
{
	return Function::CallMethodAndReturn<bool, ZActor*, float4*, float>(BaseAddresses::hitman5Dll + 0x3E0490, this, vPos, fAngleToleranceDegrees);
}

ZKnowledge* ZActor::Knowledge()
{
	return Function::CallMethodAndReturn<ZKnowledge*, ZActor*>(BaseAddresses::hitman5Dll + 0x3E05C0, this);
}

const ZKnowledge* ZActor::KnowledgeConst()
{
	return Function::CallMethodAndReturn<const ZKnowledge*, ZActor*>(BaseAddresses::hitman5Dll + 0x3E05D0, this);
}

void ZActor::OnTestUnrecoverableError()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3E05E0, this);
}

void ZActor::SetAmbientLookAtCharacter(TEntityRef<ZHM5BaseCharacter>* rCharacter)
{
	Function::CallMethod<ZActor*, TEntityRef<ZHM5BaseCharacter>*>(BaseAddresses::hitman5Dll + 0x3E0610, this, rCharacter);
}

void ZActor::GeomTransformChangeCallback(ZEntityRef* entity, SMatrix43* mNewValue)
{
	Function::CallMethod<ZActor*, ZEntityRef*, SMatrix43*>(BaseAddresses::hitman5Dll + 0x3E0640, this, entity, mNewValue);
}

ZRuntimeResourceID* ZActor::GetHMAsResourceID(ZRuntimeResourceID* result)
{
	return Function::CallMethodAndReturn<ZRuntimeResourceID*, ZActor*, ZRuntimeResourceID*>(BaseAddresses::hitman5Dll + 0x3E1FD0, this, result);
}

bool ZActor::IsNude()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x3E2010, this);
}

void ZActor::ChangeToNude()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3E2070, this);
}

void ZActor::HideAttachedNonWeapons()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3E20E0, this);
}

void ZActor::ShowAttachedNonWeapons()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3E22D0, this);
}

void ZActor::StartSubtitles(ISoundPlayerChannel* pChannel)
{
	Function::CallMethod<ZActor*, ISoundPlayerChannel*>(BaseAddresses::hitman5Dll + 0x3E24A0, this, pChannel);
}

float ZActor::CalcGetBoneDamageMultiplier(unsigned int nHitBoneIndex)
{
	return Function::CallMethodAndReturn<float, ZActor*, unsigned int>(BaseAddresses::hitman5Dll + 0x3E2660, this, nHitBoneIndex);
}

float ZActor::GetInitHitPoints()
{
	return Function::CallMethodAndReturn<float, ZActor*>(BaseAddresses::hitman5Dll + 0x3E27F0, this);
}

unsigned __int16 ZActor::UpdateRoomID()
{
	return Function::CallMethodAndReturn<unsigned __int16, ZActor*>(BaseAddresses::hitman5Dll + 0x3E2810, this);
}

ZString* ZActor::LookAroundAct_Select(ZString* result, int nIndex)
{
	return Function::CallMethodAndReturn<ZString*, ZActor*, ZString*, int>(BaseAddresses::hitman5Dll + 0x3E2930, this, result, nIndex);
}

ZString* ZActor::LookAroundAct_SelectRandom(ZString* result)
{
	return Function::CallMethodAndReturn<ZString*, ZActor*, ZString*>(BaseAddresses::hitman5Dll + 0x3E2A00, this, result);
}

void ZActor::TryInitAnimatedActor()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3E3D00, this);
}

void ZActor::TryUninitAnimatedActor()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3E3E00, this);
}

void ZActor::SignalKillSoundManager(bool bCheckForSilencedKill)
{
	Function::CallMethod<ZActor*, bool>(BaseAddresses::hitman5Dll + 0x3E3E40, this, bCheckForSilencedKill);
}

bool ZActor::IsBoss()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x3E4090, this);
}

TEntityRef<IHM5ItemWeapon>* ZActor::GetCurrentWeapon(TEntityRef<IHM5ItemWeapon>* result)
{
	return Function::CallMethodAndReturn<TEntityRef<IHM5ItemWeapon>*, ZActor*, TEntityRef<IHM5ItemWeapon>*>(BaseAddresses::hitman5Dll + 0x3E41C0, this, result);
}

void ZActor::SwitchWeaponHand(bool bSwitchToLeftHand)
{
	Function::CallMethod<ZActor*, bool>(BaseAddresses::hitman5Dll + 0x3E43C0, this, bSwitchToLeftHand);
}

TEntityRef<IHM5ItemWeapon>* ZActor::GetPistolInInventory(TEntityRef<IHM5ItemWeapon>* result)
{
	return Function::CallMethodAndReturn<TEntityRef<IHM5ItemWeapon>*, ZActor*, TEntityRef<IHM5ItemWeapon>*>(BaseAddresses::hitman5Dll + 0x3E45F0, this, result);
}

TEntityRef<IHM5ItemWeapon>* ZActor::GetRifleInInventory(TEntityRef<IHM5ItemWeapon>* result)
{
	return Function::CallMethodAndReturn<TEntityRef<IHM5ItemWeapon>*, ZActor*, TEntityRef<IHM5ItemWeapon>*>(BaseAddresses::hitman5Dll + 0x3E47B0, this, result);
}

void ZActor::UnholsterWeapon(TEntityRef<IHM5ItemWeapon>* rWeapon)
{
	Function::CallMethod<ZActor*, TEntityRef<IHM5ItemWeapon>*>(BaseAddresses::hitman5Dll + 0x3E49B0, this, rWeapon);
}

bool ZActor::HasHandGun()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x3E4AB0, this);
}

void ZActor::RemoveBehavior(TEntityRef<ZBehaviorEntityBase> rBehavior)
{
	Function::CallMethod<ZActor*, TEntityRef<ZBehaviorEntityBase>>(BaseAddresses::hitman5Dll + 0x3E5010, this, rBehavior);
}

void ZActor::PromoteBehavior(TEntityRef<ZBehaviorEntityBase> rBehavior)
{
	Function::CallMethod<ZActor*, TEntityRef<ZBehaviorEntityBase>>(BaseAddresses::hitman5Dll + 0x3E50B0, this, rBehavior);
}

void ZActor::OnDefaultEmitterSpeakFailed(ISoundPlayerChannel* pChannel, IWaveBankData* pWaveBankData, int nSubSoundIndex, void* pUserData)
{
	Function::CallMethod<ZActor*, ISoundPlayerChannel*, IWaveBankData*, int, void*>(BaseAddresses::hitman5Dll + 0x3E5130, this, pChannel, pWaveBankData, nSubSoundIndex, pUserData);
}

void ZActor::StartLipSync(ISoundPlayerChannel* pChannel, TRefCountPtr<ZSoundPlayerCallbackExtraData> pExtraData)
{
	Function::CallMethod<ZActor*, ISoundPlayerChannel*, TRefCountPtr<ZSoundPlayerCallbackExtraData>>(BaseAddresses::hitman5Dll + 0x3E51D0, this, pChannel, pExtraData);
}

void ZActor::StopLipSync(ISoundPlayerChannel* pChannel)
{
	Function::CallMethod<ZActor*, ISoundPlayerChannel*>(BaseAddresses::hitman5Dll + 0x3E5410, this, pChannel);
}

bool ZActor::IsWeaponFiring()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x3E5550, this);
}

void ZActor::EndShootEnemy()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3E55A0, this);
}

bool ZActor::HasFullClip()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x3E55E0, this);
}

bool ZActor::NeedReload()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x3E5650, this);
}

void ZActor::Reload()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3E56B0, this);
}

ZString* ZActor::GetWeaponName(ZString* result)
{
	return Function::CallMethodAndReturn<ZString*, ZActor*, ZString*>(BaseAddresses::hitman5Dll + 0x3E56F0, this, result);
}

void ZActor::UpdateHasWeapon()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3E59D0, this);
}

bool ZActor::TestAllTargetsKilled(bool* bHaveTargets)
{
	return Function::CallAndReturn<bool, bool*>(BaseAddresses::hitman5Dll + 0x3E5B00, bHaveTargets);
}

EActorPerceptionSensitivity ZActor::GetPerceptionSensitivity()
{
	return Function::CallMethodAndReturn<EActorPerceptionSensitivity, ZActor*>(BaseAddresses::hitman5Dll + 0x3E5BE0, this);
}

void ZActor::ExpireSharedEvent(EAISharedEventType eventType)
{
	Function::CallMethod<ZActor*, EAISharedEventType>(BaseAddresses::hitman5Dll + 0x3E5C70, this, eventType);
}

void ZActor::AttachWeaponToHolster(TEntityRef<IHM5ItemWeapon> pWeapon, ZString* sBoneName)
{
	Function::CallMethod<ZActor*, TEntityRef<IHM5ItemWeapon>, ZString*>(BaseAddresses::hitman5Dll + 0x3E5CA0, this, pWeapon, sBoneName);
}

void ZActor::UpdateFaceFX()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3E5E60, this);
}

void ZActor::OnAnimationRigChanged(ZAnimationRig* pRig, SMatrix* pMatrix)
{
	Function::CallMethod<ZActor*, ZAnimationRig*, SMatrix*>(BaseAddresses::hitman5Dll + 0x3E6C90, this, pRig, pMatrix);
}

void ZActor::StopBeingDragged()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3E6CF0, this);
}

TEntityRef<IHM5Item>* ZActor::DetachItem(TEntityRef<IHM5Item>* result, EAttachLocation eLocation, bool bAddToPhysicsWorld, bool bRemoveFromInventory)
{
	return Function::CallMethodAndReturn<TEntityRef<IHM5Item>*, ZActor*, TEntityRef<IHM5Item>*, EAttachLocation, bool, bool>(BaseAddresses::hitman5Dll + 0x3E6DE0, this, result, eLocation, bAddToPhysicsWorld, bRemoveFromInventory);
}

void ZActor::DropAttachedItems(bool bDropWeapon)
{
	Function::CallMethod<ZActor*, bool>(BaseAddresses::hitman5Dll + 0x3E6FB0, this, bDropWeapon);
}

void ZActor::DropKeycardNoPhysics()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3E7130, this);
}

void ZActor::DropAllItems()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3E7580, this);
}

bool ZActor::UnholsterWeapon()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x3E7A90, this);
}

TEntityRef<IHM5ItemWeapon>* ZActor::GetDisarmWeapon(TEntityRef<IHM5ItemWeapon>* result)
{
	return Function::CallMethodAndReturn<TEntityRef<IHM5ItemWeapon>*, ZActor*, TEntityRef<IHM5ItemWeapon>*>(BaseAddresses::hitman5Dll + 0x3E7B60, this, result);
}

void ZActor::ReleaseCarryCivilian()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3E7D40, this);
}

void ZActor::StopSpeak()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3E7D90, this);
}

void ZActor::OnSpeakFailed(ISoundPlayerChannel* pChannel, IWaveBankData* pWaveBankData, int nSubSoundIndex, void* pUserData)
{
	Function::CallMethod<ZActor*, ISoundPlayerChannel*, IWaveBankData*, int, void*>(BaseAddresses::hitman5Dll + 0x3E7EA0, this, pChannel, pWaveBankData, nSubSoundIndex, pUserData);
}

void ZActor::OnSpeakBeginPlay(ISoundPlayerChannel* pChannel, IWaveBankData* pWaveBankData, int nSubSoundIndex, void* pUserData, TRefCountPtr<ZSoundPlayerCallbackExtraData> pExtraData)
{
	Function::CallMethod<ZActor*, ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>>(BaseAddresses::hitman5Dll + 0x3E7FF0, this, pChannel, pWaveBankData, nSubSoundIndex, pUserData, pExtraData);
}

void ZActor::OnSpeakEndPlay(ISoundPlayerChannel* pChannel, IWaveBankData* pWaveBankData, int nSubSoundIndex, void* pUserData)
{
	Function::CallMethod<ZActor*, ISoundPlayerChannel*, IWaveBankData*, int, void*>(BaseAddresses::hitman5Dll + 0x3E8070, this, pChannel, pWaveBankData, nSubSoundIndex, pUserData);
}

void ZActor::OnDefaultEmitterSpeakBeginPlay(ISoundPlayerChannel* pChannel, IWaveBankData* pWaveBankData, int nSubSoundIndex, void* pUserData, TRefCountPtr<ZSoundPlayerCallbackExtraData> pExtraData)
{
	Function::CallMethod<ZActor*, ISoundPlayerChannel*, IWaveBankData*, int, void*, TRefCountPtr<ZSoundPlayerCallbackExtraData>>(BaseAddresses::hitman5Dll + 0x3E8190, this, pChannel, pWaveBankData, nSubSoundIndex, pUserData, pExtraData);
}

void ZActor::OnDefaultEmitterSpeakEndPlay(ISoundPlayerChannel* pChannel, IWaveBankData* pWaveBankData, int nSubSoundIndex, void* pUserData)
{
	Function::CallMethod<ZActor*, ISoundPlayerChannel*, IWaveBankData*, int, void*>(BaseAddresses::hitman5Dll + 0x3E8200, this, pChannel, pWaveBankData, nSubSoundIndex, pUserData);
}

bool ZActor::CheckLOF(float4* vShotOrigin, float4* vShotHitPosition, float4* vCollision)
{
	return Function::CallMethodAndReturn<bool, ZActor*, float4*, float4*, float4*>(BaseAddresses::hitman5Dll + 0x3E8280, this, vShotOrigin, vShotHitPosition, vCollision);
}

bool ZActor::CalculateShot(ZEntityRef* target, float4* vShotOrigin, float4* vShotHitPosition)
{
	return Function::CallMethodAndReturn<bool, ZActor*, ZEntityRef*, float4*, float4*>(BaseAddresses::hitman5Dll + 0x3E83E0, this, target, vShotOrigin, vShotHitPosition);
}

void ZActor::ShootEnemy()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3E85E0, this);
}

void ZActor::UpdateShooting(SGameUpdateEvent* updateEvent)
{
	Function::CallMethod<ZActor*, SGameUpdateEvent*>(BaseAddresses::hitman5Dll + 0x3E8AC0, this, updateEvent);
}

void ZActor::ReleaseKnowledge()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3E8C90, this);
}

void ZActor::ImmediateDeinitialize()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3E8D40, this);
}

void ZActor::ImmediateDisable()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3E8E50, this);
}

void ZActor::FlagDeathAsMurder()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3E91B0, this);
}

void ZActor::SetAssert(ZString* sBreakpointName, bool bEnable)
{
	Function::CallMethod<ZActor*, ZString*, bool>(BaseAddresses::hitman5Dll + 0x3E9370, this, sBreakpointName, bEnable);
}

bool ZActor::IsSharedEventCurrent(EAISharedEventType eventType)
{
	return Function::CallMethodAndReturn<bool, ZActor*, EAISharedEventType>(BaseAddresses::hitman5Dll + 0x3E9400, this, eventType);
}

void ZActor::RenewSharedEvent(EAISharedEventType eventType, float fDuration)
{
	Function::CallMethod<ZActor*, EAISharedEventType, float>(BaseAddresses::hitman5Dll + 0x3E9420, this, eventType, fDuration);
}

void ZActor::OnForceUnholster()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3E9450, this);
}

void ZActor::AttachWeaponsToHolsters()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3E9480, this);
}

TEntityRef<ZPointOfInterestEntity>* ZActor::GetRandomStaticPointOfInterest(TEntityRef<ZPointOfInterestEntity>* result)
{
	return Function::CallMethodAndReturn<TEntityRef<ZPointOfInterestEntity>*, ZActor*, TEntityRef<ZPointOfInterestEntity>*>(BaseAddresses::hitman5Dll + 0x3E9590, this, result);
}

bool ZActor::GetAmbientLookAt(float4* wsLookAt, bool* bEyesOnly)
{
	return Function::CallMethodAndReturn<bool, ZActor*, float4*, bool*>(BaseAddresses::hitman5Dll + 0x3E99E0, this, wsLookAt, bEyesOnly);
}

void ZActor::RegisterTransformChangeCallback()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3E9DB0, this);
}

void ZActor::UnregisterTransformChangeCallback()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3E9E00, this);
}

bool ZActor::IsHitTarget()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x3EB420, this);
}

void ZActor::StartBeingDragged()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3EB500, this);
}

void ZActor::StartPull(bool bWindow)
{
	Function::CallMethod<ZActor*, bool>(BaseAddresses::hitman5Dll + 0x3EB640, this, bWindow);
}

void ZActor::StartPush()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3EB6B0, this);
}

void ZActor::HolsterWeapon()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3EB6E0, this);
}

EActorCCPreset ZActor::GetCCPreset()
{
	return Function::CallMethodAndReturn<EActorCCPreset, ZActor*>(BaseAddresses::hitman5Dll + 0x3EB920, this);
}

bool ZActor::EnterCarryCivilian(bool bDirectToStandIdle)
{
	return Function::CallMethodAndReturn<bool, ZActor*, bool>(BaseAddresses::hitman5Dll + 0x3EBB00, this, bDirectToStandIdle);
}

TSharedPointer<ZControlledAnimLocomotion>* ZActor::CreateControlledProgram(TSharedPointer<ZControlledAnimLocomotion>* result, ZString* sAnimSMName, ZString* sAnimName)
{
	return Function::CallMethodAndReturn<TSharedPointer<ZControlledAnimLocomotion>*, ZActor*, TSharedPointer<ZControlledAnimLocomotion>*, ZString*, ZString*>(BaseAddresses::hitman5Dll + 0x3EBC20, this, result, sAnimSMName, sAnimName);
}

TSharedPointer<ZControlledAnimLocomotion>* ZActor::StartControlledAnim(TSharedPointer<ZControlledAnimLocomotion>* result, ZString* sAnimSMName, ZString* sAnimName, bool bSetAnimProgram, bool bBlendToControlledState)
{
	return Function::CallMethodAndReturn<TSharedPointer<ZControlledAnimLocomotion>*, ZActor*, TSharedPointer<ZControlledAnimLocomotion>*, ZString*, ZString*, bool, bool>(BaseAddresses::hitman5Dll + 0x3EBC70, this, result, sAnimSMName, sAnimName, bSetAnimProgram, bBlendToControlledState);
}

void ZActor::SetMuted(bool bMuted)
{
	Function::CallMethod<ZActor*, bool>(BaseAddresses::hitman5Dll + 0x3EBDC0, this, bMuted);
}

bool ZActor::Speak(ZResourcePtr pWavebank)
{
	return Function::CallMethodAndReturn<bool, ZActor*, ZResourcePtr>(BaseAddresses::hitman5Dll + 0x3EBE10, this, pWavebank);
}

void ZActor::SelectBehavior(SGameUpdateEvent* updateEvent)
{
	Function::CallMethod<ZActor*, SGameUpdateEvent*>(BaseAddresses::hitman5Dll + 0x3EC040, this, updateEvent);
}

void ZActor::InitializeKnowledge()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3EC0C0, this);
}

void ZActor::OnEnable()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3EC280, this);
}

void ZActor::OnDisable()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3EC330, this);
}

void ZActor::ImmediateInitialize()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3EC3C0, this);
}

void ZActor::FlagDeathAsAccident()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3EC4C0, this);
}

void ZActor::FlagDeathAsPacify(bool bByAccident)
{
	Function::CallMethod<ZActor*, bool>(BaseAddresses::hitman5Dll + 0x3EC650, this, bByAccident);
}

void ZActor::OnAccidentStart()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3EC850, this);
}

void ZActor::OnForceHolster()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3EC880, this);
}

void ZActor::KillActor(EActorDeathType eDeathType, bool bDeathVisible)
{
	Function::CallMethod<ZActor*, EActorDeathType, bool>(BaseAddresses::hitman5Dll + 0x3ED520, this, eDeathType, bDeathVisible);
}

void ZActor::DeadlyThrowKill(TEntityRef<IHM5Item> rItem, bool bIsThrowFromBehind)
{
	Function::CallMethod<ZActor*, TEntityRef<IHM5Item>, bool>(BaseAddresses::hitman5Dll + 0x3ED690, this, rItem, bIsThrowFromBehind);
}

void ZActor::OnFallImpact(TEntityRef<ZActor> pActor)
{
	Function::CallMethod<ZActor*, TEntityRef<ZActor>>(BaseAddresses::hitman5Dll + 0x3ED850, this, pActor);
}

void ZActor::ReleaseHumanShield()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3ED8E0, this);
}

bool ZActor::ImmediateEnable()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x3EDBE0, this);
}

void ZActor::OnKillActor()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3EE800, this);
}

void ZActor::OnKillUnnoticed()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3EE940, this);
}

void ZActor::OnKillByPacify()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3EEAB0, this);
}

void ZActor::OnKillByAccident()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3EED00, this);
}

void ZActor::OnKillByUnnoticedAccident()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3EEE60, this);
}

void ZActor::OnPacifyByAccident()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3EEFA0, this);
}

void ZActor::OnAccidentEnd()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3EF180, this);
}

void ZActor::RegisterType()
{
	Function::Call<>(BaseAddresses::hitman5Dll + 0x3EF210);
}

void ZActor::HandleHealth()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x3F04D0, this);
}

void ZActor::CloseCombatEvent(ECCActorEvent eEvent, ECCActorEventDir eDir, TEntityRef<ZHM5ItemCCWeapon>* rWeapon)
{
	Function::CallMethod<ZActor*, ECCActorEvent, ECCActorEventDir, TEntityRef<ZHM5ItemCCWeapon>*>(BaseAddresses::hitman5Dll + 0x3F2170, this, eEvent, eDir, rWeapon);
}

bool ZActor::GetSBKillTagged()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x3F3860, this);
}

bool ZActor::IsSpeakPlaying()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x3F3870, this);
}

const TResourcePtr<ZCompiledBehaviorTree>* ZActor::GetBehaviorTree()
{
	return Function::CallMethodAndReturn<const TResourcePtr<ZCompiledBehaviorTree>*, ZActor*>(BaseAddresses::hitman5Dll + 0x3FFDB0, this);
}

bool ZActor::IsRadioActAllowed()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x415D80, this);
}

void ZActor::SetSeenDying(bool b)
{
	Function::CallMethod<ZActor*, bool>(BaseAddresses::hitman5Dll + 0x44C3B0, this, b);
}

bool ZActor::IsPreferredAccidentInvestigator()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x45C0E0, this);
}

bool ZActor::IsAccidentShy()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x45C0F0, this);
}

ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull>* ZActor::GetSpeakInterruptedEvent()
{
	return Function::CallMethodAndReturn<ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull>*, ZActor*>(BaseAddresses::hitman5Dll + 0x4A9F00, this);
}

ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull>* ZActor::GetSpeakEndEvent()
{
	return Function::CallMethodAndReturn<ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull>*, ZActor*>(BaseAddresses::hitman5Dll + 0x4A9F10, this);
}

TArray<TEntityRef<ZBehaviorEntityBase> >* ZActor::GetBehaviors()
{
	return Function::CallMethodAndReturn<TArray<TEntityRef<ZBehaviorEntityBase> >*, ZActor*>(BaseAddresses::hitman5Dll + 0x4BBB30, this);
}

void ZActor::ForceEnable()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x4C2C50, this);
}

void ZActor::ForceDisable()
{
	Function::CallMethod<ZActor*>(BaseAddresses::hitman5Dll + 0x4C2C60, this);
}

void ZActor::SetRegisteredDeathType(EActorDeathType eDeathType)
{
	Function::CallMethod<ZActor*, EActorDeathType>(BaseAddresses::hitman5Dll + 0x4C2C70, this, eDeathType);
}

bool ZActor::GetContractsEligible()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x548630, this);
}

TArray<ZString>* ZActor::GetStatLabels()
{
	return Function::CallMethodAndReturn<TArray<ZString>*, ZActor*>(BaseAddresses::hitman5Dll + 0x5E7690, this);
}

bool ZActor::HasBeenPacified()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x5E76A0, this);
}

EActorDeathType ZActor::GetRegisteredDeathType()
{
	return Function::CallMethodAndReturn<EActorDeathType, ZActor*>(BaseAddresses::hitman5Dll + 0x5E76B0, this);
}

void ZActor::SetContractsEligible(bool bEligible)
{
	Function::CallMethod<ZActor*, bool>(BaseAddresses::hitman5Dll + 0x608C00, this, bEligible);
}

const STokenID* ZActor::GetTokenID()
{
	return Function::CallMethodAndReturn<const STokenID*, ZActor*>(BaseAddresses::hitman5Dll + 0x62F250, this);
}

bool ZActor::IsDisabledByForwardSpawn()
{
	return Function::CallMethodAndReturn<bool, ZActor*>(BaseAddresses::hitman5Dll + 0x62F260, this);
}
