#include "ZKnowledge.h"
#include "Function.h"
#include "BaseAddresses.h"

ZActiveBehavior* ZKnowledge::GetCurrentActiveBehavior()
{
	return Function::CallMethodAndReturn<ZActiveBehavior*, ZKnowledge*>(BaseAddresses::hitman5Dll + 0x7FA90, this);
}

TRefCountPtrArg<SKnownEntity>* ZKnowledge::GetSelf(TRefCountPtrArg<SKnownEntity>* result)
{
	return Function::CallMethodAndReturn<TRefCountPtrArg<SKnownEntity>*, ZKnowledge*, TRefCountPtrArg<SKnownEntity>*>(BaseAddresses::hitman5Dll + 0x96070, this, result);
}

EGameTension ZKnowledge::GetGameTension()
{
	return Function::CallMethodAndReturn<EGameTension, ZKnowledge*>(BaseAddresses::hitman5Dll + 0xA3200, this);
}

const ZSharedKnowledgeRef* ZKnowledge::GetShared()
{
	return Function::CallMethodAndReturn<const ZSharedKnowledgeRef*, ZKnowledge*>(BaseAddresses::hitman5Dll + 0xA91F0, this);
}

float ZKnowledge::GetHMAttention()
{
	return Function::CallMethodAndReturn<float, ZKnowledge*>(BaseAddresses::hitman5Dll + 0xA9200, this);
}

ZGridNodeRef* ZKnowledge::GetActorGridNode(ZGridNodeRef* result)
{
	return Function::CallMethodAndReturn<ZGridNodeRef*, ZKnowledge*, ZGridNodeRef*>(BaseAddresses::hitman5Dll + 0xBA4C0, this, result);
}

unsigned __int8 ZKnowledge::GetNumKnownDeadBodies()
{
	return Function::CallMethodAndReturn<unsigned __int8, ZKnowledge*>(BaseAddresses::hitman5Dll + 0xFC850, this);
}

void ZKnowledge::IncreaseKnownDeadBodies()
{
	Function::CallMethod<ZKnowledge*>(BaseAddresses::hitman5Dll + 0xFC860, this);
}

TEntityRef<ZActor>* ZKnowledge::Self()
{
	return Function::CallMethodAndReturn<TEntityRef<ZActor>*, ZKnowledge*>(BaseAddresses::hitman5Dll + 0xFC870, this);
}

ZSharedKnowledgeRef* ZKnowledge::GetBloodPool(ZSharedKnowledgeRef* result)
{
	return Function::CallMethodAndReturn<ZSharedKnowledgeRef*, ZKnowledge*, ZSharedKnowledgeRef*>(BaseAddresses::hitman5Dll + 0xFD250, this, result);
}

EActorPerceptionSensitivity ZKnowledge::GetPerceptionSensitivity()
{
	return Function::CallMethodAndReturn<EActorPerceptionSensitivity, ZKnowledge*>(BaseAddresses::hitman5Dll + 0x1022A0, this);
}

TEntityRef<ZCrowdActor>* ZKnowledge::GetCrowdActor(TEntityRef<ZCrowdActor>* result)
{
	return Function::CallMethodAndReturn<TEntityRef<ZCrowdActor>*, ZKnowledge*, TEntityRef<ZCrowdActor>*>(BaseAddresses::hitman5Dll + 0x102B50, this, result);
}

float ZKnowledge::DistanceTo(float4* pos)
{
	return Function::CallMethodAndReturn<float, ZKnowledge*, float4*>(BaseAddresses::hitman5Dll + 0x103A00, this, pos);
}

ZActorKnownEntitiesEnumerator ZKnowledge::GetKnownEntityEnumerator()
{
	return Function::CallMethodAndReturn<ZActorKnownEntitiesEnumerator, ZKnowledge*>(BaseAddresses::hitman5Dll + 0x109C20, this);
}

float4* ZKnowledge::GetCameFromPosition(float4* result)
{
	return Function::CallMethodAndReturn<float4*, ZKnowledge*, float4*>(BaseAddresses::hitman5Dll + 0x111390, this, result);
}

bool ZKnowledge::HasCameFromPosition()
{
	return Function::CallMethodAndReturn<bool, ZKnowledge*>(BaseAddresses::hitman5Dll + 0x1121F0, this);
}

float ZKnowledge::GetHitPoints()
{
	return Function::CallMethodAndReturn<float, ZKnowledge*>(BaseAddresses::hitman5Dll + 0x189B10, this);
}

void ZKnowledge::SetCrowdActorReleaseTimer(unsigned __int16 nFrames)
{
	Function::CallMethod<ZKnowledge*, unsigned __int16>(BaseAddresses::hitman5Dll + 0x1A02D0, this, nFrames);
}

unsigned __int16 ZKnowledge::GetCrowdActorReleaseTimer()
{
	return Function::CallMethodAndReturn<unsigned __int16, ZKnowledge*>(BaseAddresses::hitman5Dll + 0x1D8AB0, this);
}

TEntityRef<ZHM5BodyContainer>* ZKnowledge::GetBodyContainer(TEntityRef<ZHM5BodyContainer>* result)
{
	return Function::CallMethodAndReturn<TEntityRef<ZHM5BodyContainer>*, ZKnowledge*, TEntityRef<ZHM5BodyContainer>*>(BaseAddresses::hitman5Dll + 0x1D8E50, this, result);
}

void ZKnowledge::SetBodyHitTimer(float time)
{
	Function::CallMethod<ZKnowledge*, float>(BaseAddresses::hitman5Dll + 0x21F1F0, this, time);
}

void ZKnowledge::SetForceMinHP(float fForceMinHP)
{
	Function::CallMethod<ZKnowledge*, float>(BaseAddresses::hitman5Dll + 0x21F210, this, fForceMinHP);
}

void ZKnowledge::SetBodyContainer(TEntityRef<ZHM5BodyContainer> pContainer)
{
	Function::CallMethod<ZKnowledge*, TEntityRef<ZHM5BodyContainer>>(BaseAddresses::hitman5Dll + 0x2CD6E0, this, pContainer);
}

bool ZKnowledge::IsControlled()
{
	return Function::CallMethodAndReturn<bool, ZKnowledge*>(BaseAddresses::hitman5Dll + 0x301D40, this);
}

float ZKnowledge::GetBodyHitTimer()
{
	return Function::CallMethodAndReturn<float, ZKnowledge*>(BaseAddresses::hitman5Dll + 0x3DCAC0, this);
}

ZHM5CoverPlane* ZKnowledge::GetCurrentCover()
{
	return Function::CallMethodAndReturn<ZHM5CoverPlane*, ZKnowledge*>(BaseAddresses::hitman5Dll + 0x3DCAD0, this);
}

void ZKnowledge::SetCurrentCover(ZHM5CoverPlane* pCover)
{
	Function::CallMethod<ZKnowledge*, ZHM5CoverPlane*>(BaseAddresses::hitman5Dll + 0x3DCAE0, this, pCover);
}

bool ZKnowledge::IsBloodPoolPlaced()
{
	return Function::CallMethodAndReturn<bool, ZKnowledge*>(BaseAddresses::hitman5Dll + 0x3DCAF0, this);
}

bool ZKnowledge::GetAllowRagdollDamageReactions()
{
	return Function::CallMethodAndReturn<bool, ZKnowledge*>(BaseAddresses::hitman5Dll + 0x3DCB10, this);
}

void ZKnowledge::SetCurrentHitpoints(float fHitpoints)
{
	Function::CallMethod<ZKnowledge*, float>(BaseAddresses::hitman5Dll + 0x3DF5B0, this, fHitpoints);
}

const SMatrix* ZKnowledge::GetTransform()
{
	return Function::CallMethodAndReturn<const SMatrix*, ZKnowledge*>(BaseAddresses::hitman5Dll + 0x3F3990, this);
}

void ZKnowledge::ReleaseControlled()
{
	Function::CallMethod<ZKnowledge*>(BaseAddresses::hitman5Dll + 0x3FFE20, this);
}

void ZKnowledge::AdjustHitpoint(float fDeltaHitpoints)
{
	Function::CallMethod<ZKnowledge*, float>(BaseAddresses::hitman5Dll + 0x3FFE30, this, fDeltaHitpoints);
}

void ZKnowledge::SetHMAttention(float fAttention)
{
	Function::CallMethod<ZKnowledge*, float>(BaseAddresses::hitman5Dll + 0x3FFEB0, this, fAttention);
}

void ZKnowledge::SetHMAttentionType(EHMAttentionType eType)
{
	Function::CallMethod<ZKnowledge*, EHMAttentionType>(BaseAddresses::hitman5Dll + 0x3FFEC0, this, eType);
}

void ZKnowledge::SetHMAttentionGainOutOfSight(bool bVal)
{
	Function::CallMethod<ZKnowledge*, bool>(BaseAddresses::hitman5Dll + 0x3FFED0, this, bVal);
}

bool ZKnowledge::GetHMAttentionGainOutOfSight()
{
	return Function::CallMethodAndReturn<bool, ZKnowledge*>(BaseAddresses::hitman5Dll + 0x3FFEF0, this);
}

float ZKnowledge::GetAmbientTime()
{
	return Function::CallMethodAndReturn<float, ZKnowledge*>(BaseAddresses::hitman5Dll + 0x3FFF00, this);
}

int ZKnowledge::GetSharedKnowledgeCount()
{
	return Function::CallAndReturn<int>(BaseAddresses::hitman5Dll + 0x400520);
}

ZSharedKnowledgeRef* ZKnowledge::GetSharedKnowledgeByIndex(ZSharedKnowledgeRef* result, int nIndex)
{
	return Function::CallAndReturn<ZSharedKnowledgeRef*, ZSharedKnowledgeRef*, int>(BaseAddresses::hitman5Dll + 0x400530, result, nIndex);
}

void ZKnowledge::SetHelpPoint(TEntityRef<ZSpatialEntity>* pHelpPoint)
{
	Function::CallMethod<ZKnowledge*, TEntityRef<ZSpatialEntity>*>(BaseAddresses::hitman5Dll + 0x400560, this, pHelpPoint);
}

TEntityRef<ZSpatialEntity>* ZKnowledge::GetHelpPoint(TEntityRef<ZSpatialEntity>* result)
{
	return Function::CallMethodAndReturn<TEntityRef<ZSpatialEntity>*, ZKnowledge*, TEntityRef<ZSpatialEntity>*>(BaseAddresses::hitman5Dll + 0x400590, this, result);
}

void ZKnowledge::DeleteBloodPool()
{
	Function::CallMethod<ZKnowledge*>(BaseAddresses::hitman5Dll + 0x4006F0, this);
}

void ZKnowledge::RemoveKnownEntity(TRefCountPtr<SKnownEntity>* knownEntity)
{
	Function::CallMethod<ZKnowledge*, TRefCountPtr<SKnownEntity>*>(BaseAddresses::hitman5Dll + 0x401020, this, knownEntity);
}

TRefCountPtrArg<SKnownEntity>* ZKnowledge::AddKnownEntity(TRefCountPtrArg<SKnownEntity>* result, ZSharedKnowledgeRef* pShared)
{
	return Function::CallMethodAndReturn<TRefCountPtrArg<SKnownEntity>*, ZKnowledge*, TRefCountPtrArg<SKnownEntity>*, ZSharedKnowledgeRef*>(BaseAddresses::hitman5Dll + 0x4010A0, this, result, pShared);
}

TRefCountPtrArg<SKnownEntity>* ZKnowledge::GetKnownLocation(TRefCountPtrArg<SKnownEntity>* result, float4* vPosition, unsigned __int16 room)
{
	return Function::CallMethodAndReturn<TRefCountPtrArg<SKnownEntity>*, ZKnowledge*, TRefCountPtrArg<SKnownEntity>*, float4*, unsigned __int16>(BaseAddresses::hitman5Dll + 0x4011B0, this, result, vPosition, room);
}

TRefCountPtr<SKnownEntity>* ZKnowledge::FindUnhandled(TRefCountPtr<SKnownEntity>* result, EAIEventType type)
{
	return Function::CallMethodAndReturn<TRefCountPtr<SKnownEntity>*, ZKnowledge*, TRefCountPtr<SKnownEntity>*, EAIEventType>(BaseAddresses::hitman5Dll + 0x4012E0, this, result, type);
}

TRefCountPtr<SKnownEntity>* ZKnowledge::FindCurrent(TRefCountPtr<SKnownEntity>* result, EAIEventType type)
{
	return Function::CallMethodAndReturn<TRefCountPtr<SKnownEntity>*, ZKnowledge*, TRefCountPtr<SKnownEntity>*, EAIEventType>(BaseAddresses::hitman5Dll + 0x401440, this, result, type);
}

TRefCountPtr<SKnownEntity>* ZKnowledge::FindCurrent(TRefCountPtr<SKnownEntity>* result, EAIEventType type, float maxAge)
{
	return Function::CallMethodAndReturn<TRefCountPtr<SKnownEntity>*, ZKnowledge*, TRefCountPtr<SKnownEntity>*, EAIEventType, float>(BaseAddresses::hitman5Dll + 0x401590, this, result, type, maxAge);
}

void ZKnowledge::MarkAllHandled(EAIEventType type)
{
	Function::CallMethod<ZKnowledge*, EAIEventType>(BaseAddresses::hitman5Dll + 0x401770, this, type);
}

bool ZKnowledge::HasUnhandledEvent(EAIEventType eEventType)
{
	return Function::CallMethodAndReturn<bool, ZKnowledge*, EAIEventType>(BaseAddresses::hitman5Dll + 0x401820, this, eEventType);
}

unsigned int ZKnowledge::HasEvent(EAIEventType eEventType)
{
	return Function::CallMethodAndReturn<unsigned int, ZKnowledge*, EAIEventType>(BaseAddresses::hitman5Dll + 0x401A00, this, eEventType);
}

TRefCountPtrArg<SKnownEntity>* ZKnowledge::GetKnownEntity(TRefCountPtrArg<SKnownEntity>* result, ZSharedKnowledgeRef* pShared)
{
	return Function::CallMethodAndReturn<TRefCountPtrArg<SKnownEntity>*, ZKnowledge*, TRefCountPtrArg<SKnownEntity>*, ZSharedKnowledgeRef*>(BaseAddresses::hitman5Dll + 0x401B40, this, result, pShared);
}

void ZKnowledge::SetHasWeapon(bool bHasWeapon)
{
	Function::CallMethod<ZKnowledge*, bool>(BaseAddresses::hitman5Dll + 0x401BD0, this, bHasWeapon);
}

bool ZKnowledge::UpdateCrowdReleaseTimer()
{
	return Function::CallMethodAndReturn<bool, ZKnowledge*>(BaseAddresses::hitman5Dll + 0x401C20, this);
}

void ZKnowledge::SetGameTension(EGameTension tension)
{
	Function::CallMethod<ZKnowledge*, EGameTension>(BaseAddresses::hitman5Dll + 0x401CC0, this, tension);
}

void ZKnowledge::SetTransform(SMatrix* mTransform, ZPF5Location* location)
{
	Function::CallMethod<ZKnowledge*, SMatrix*, ZPF5Location*>(BaseAddresses::hitman5Dll + 0x4023F0, this, mTransform, location);
}

void ZKnowledge::RemoveAllKnownEntities(bool bKeepSelf)
{
	Function::CallMethod<ZKnowledge*, bool>(BaseAddresses::hitman5Dll + 0x402560, this, bKeepSelf);
}

ZSharedKnowledgeRef* ZKnowledge::FindSharedKnowledge(ZSharedKnowledgeRef* result, ZEntityRef* pEntity)
{
	return Function::CallAndReturn<ZSharedKnowledgeRef*, ZSharedKnowledgeRef*, ZEntityRef*>(BaseAddresses::hitman5Dll + 0x4025F0, result, pEntity);
}

ZSharedKnowledgeRef* ZKnowledge::FindSharedKnowledgeWithOutfit(ZSharedKnowledgeRef* result, ZEntityRef* rEntity, TEntityRef<IHM5Outfit> rOutfit)
{
	return Function::CallAndReturn<ZSharedKnowledgeRef*, ZSharedKnowledgeRef*, ZEntityRef*, TEntityRef<IHM5Outfit>>(BaseAddresses::hitman5Dll + 0x402680, result, rEntity, rOutfit);
}

TRefCountPtrArg<SKnownEntity>* ZKnowledge::FindOrAddKnownEntity(TRefCountPtrArg<SKnownEntity>* result, ZSharedKnowledgeRef pShared)
{
	return Function::CallMethodAndReturn<TRefCountPtrArg<SKnownEntity>*, ZKnowledge*, TRefCountPtrArg<SKnownEntity>*, ZSharedKnowledgeRef>(BaseAddresses::hitman5Dll + 0x402790, this, result, pShared);
}

TRefCountPtr<SKnownEntity>* ZKnowledge::FindEvent(TRefCountPtr<SKnownEntity>* result, EAIEventType type)
{
	return Function::CallMethodAndReturn<TRefCountPtr<SKnownEntity>*, ZKnowledge*, TRefCountPtr<SKnownEntity>*, EAIEventType>(BaseAddresses::hitman5Dll + 0x402870, this, result, type);
}

void ZKnowledge::ExpireAllEvents(EAIEventType type)
{
	Function::CallMethod<ZKnowledge*, EAIEventType>(BaseAddresses::hitman5Dll + 0x402960, this, type);
}

TRefCountPtrArg<SKnownEntity>* ZKnowledge::GetKnownEntity(TRefCountPtrArg<SKnownEntity>* result, ZEntityRef* ref)
{
	return Function::CallMethodAndReturn<TRefCountPtrArg<SKnownEntity>*, ZKnowledge*, TRefCountPtrArg<SKnownEntity>*, ZEntityRef*>(BaseAddresses::hitman5Dll + 0x402A10, this, result, ref);
}

TRefCountPtrArg<SKnownEntity>* ZKnowledge::GetHitman(TRefCountPtrArg<SKnownEntity>* result)
{
	return Function::CallMethodAndReturn<TRefCountPtrArg<SKnownEntity>*, ZKnowledge*, TRefCountPtrArg<SKnownEntity>*>(BaseAddresses::hitman5Dll + 0x402B50, this, result);
}

void ZKnowledge::CleanupCurrentBehavior()
{
	Function::CallMethod<ZKnowledge*>(BaseAddresses::hitman5Dll + 0x402BE0, this);
}

void ZKnowledge::TerminateCurrentBehavior()
{
	Function::CallMethod<ZKnowledge*>(BaseAddresses::hitman5Dll + 0x402C50, this);
}

void ZKnowledge::OnBehaviorTreeChanged()
{
	Function::CallMethod<ZKnowledge*>(BaseAddresses::hitman5Dll + 0x402CD0, this);
}

void ZKnowledge::TerminateBehavior()
{
	Function::CallMethod<ZKnowledge*>(BaseAddresses::hitman5Dll + 0x402D10, this);
}

bool ZKnowledge::ProcessSuggestedBehavior(SBehaviorBase** pSelected, SBehaviorTreeContext* context, SBehaviorBase* pLastSelected)
{
	return Function::CallMethodAndReturn<bool, ZKnowledge*, SBehaviorBase**, SBehaviorTreeContext*, SBehaviorBase*>(BaseAddresses::hitman5Dll + 0x402D90, this, pSelected, context, pLastSelected);
}

void ZKnowledge::InitializeCurrentBehavior(SBehaviorBase* pBehavior)
{
	Function::CallMethod<ZKnowledge*, SBehaviorBase*>(BaseAddresses::hitman5Dll + 0x403000, this, pBehavior);
}

void ZKnowledge::EnterControlled()
{
	Function::CallMethod<ZKnowledge*>(BaseAddresses::hitman5Dll + 0x4030D0, this);
}

void ZKnowledge::RemoveReferencesToEntity(ZEntityRef* ref)
{
	Function::CallMethod<ZKnowledge*, ZEntityRef*>(BaseAddresses::hitman5Dll + 0x4034C0, this, ref);
}

TRefCountPtr<SKnownEntity>* ZKnowledge::FindCurrentSharedEvent(TRefCountPtr<SKnownEntity>* result, EAISharedEventType type)
{
	return Function::CallMethodAndReturn<TRefCountPtr<SKnownEntity>*, ZKnowledge*, TRefCountPtr<SKnownEntity>*, EAISharedEventType>(BaseAddresses::hitman5Dll + 0x403570, this, result, type);
}

void ZKnowledge::UpdateBehaviorSelection()
{
	Function::CallMethod<ZKnowledge*>(BaseAddresses::hitman5Dll + 0x403630, this);
}

void ZKnowledge::SelectCompiledBehavior()
{
	Function::CallMethod<ZKnowledge*>(BaseAddresses::hitman5Dll + 0x4036B0, this);
}

ZSharedKnowledgeRef* ZKnowledge::AddSharedKnowledge(ZSharedKnowledgeRef* result, ZEntityRef* pEntity)
{
	return Function::CallAndReturn<ZSharedKnowledgeRef*, ZSharedKnowledgeRef*, ZEntityRef*>(BaseAddresses::hitman5Dll + 0x403D10, result, pEntity);
}

ZSharedKnowledgeRef* ZKnowledge::FindOrAddSharedKnowledge(ZSharedKnowledgeRef* result, ZEntityRef* pEntity)
{
	return Function::CallAndReturn<ZSharedKnowledgeRef*, ZSharedKnowledgeRef*, ZEntityRef*>(BaseAddresses::hitman5Dll + 0x404070, result, pEntity);
}

TRefCountPtrArg<SKnownEntity>* ZKnowledge::AddKnownEntity(TRefCountPtrArg<SKnownEntity>* result, ZEntityRef* ref)
{
	return Function::CallMethodAndReturn<TRefCountPtrArg<SKnownEntity>*, ZKnowledge*, TRefCountPtrArg<SKnownEntity>*, ZEntityRef*>(BaseAddresses::hitman5Dll + 0x404110, this, result, ref);
}

TRefCountPtrArg<SKnownEntity>* ZKnowledge::FindOrAddKnownEntity(TRefCountPtrArg<SKnownEntity>* result, ZEntityRef* ref)
{
	return Function::CallMethodAndReturn<TRefCountPtrArg<SKnownEntity>*, ZKnowledge*, TRefCountPtrArg<SKnownEntity>*, ZEntityRef*>(BaseAddresses::hitman5Dll + 0x404210, this, result, ref);
}

TRefCountPtrArg<SKnownEntity>* ZKnowledge::AddKnownLocation(TRefCountPtrArg<SKnownEntity>* result, float4* vPosition, float fRadius, unsigned __int16 room)
{
	return Function::CallMethodAndReturn<TRefCountPtrArg<SKnownEntity>*, ZKnowledge*, TRefCountPtrArg<SKnownEntity>*, float4*, float, unsigned __int16>(BaseAddresses::hitman5Dll + 0x404340, this, result, vPosition, fRadius, room);
}

TRefCountPtrArg<SKnownEntity>* ZKnowledge::SetKnownLocation(TRefCountPtrArg<SKnownEntity>* result, EAIEventType nEvent, float4* vPosition, float fRadius, unsigned __int16 nRoom)
{
	return Function::CallMethodAndReturn<TRefCountPtrArg<SKnownEntity>*, ZKnowledge*, TRefCountPtrArg<SKnownEntity>*, EAIEventType, float4*, float, unsigned __int16>(BaseAddresses::hitman5Dll + 0x4045D0, this, result, nEvent, vPosition, fRadius, nRoom);
}

void ZKnowledge::PlaceBloodPool()
{
	Function::CallMethod<ZKnowledge*>(BaseAddresses::hitman5Dll + 0x404830, this);
}

void ZKnowledge::SetSelfEntity(TEntityRef<ZActor>* pSelf)
{
	Function::CallMethod<ZKnowledge*, TEntityRef<ZActor>*>(BaseAddresses::hitman5Dll + 0x4050D0, this, pSelf);
}

void ZKnowledge::SetAllowCutSequence(bool bAllow)
{
	Function::CallMethod<ZKnowledge*, bool>(BaseAddresses::hitman5Dll + 0x407ED0, this, bAllow);
}

void ZKnowledge::SetWaypointBehavior(SBehavior_Waypoint* pWaypointBehavior)
{
	Function::CallMethod<ZKnowledge*, SBehavior_Waypoint*>(BaseAddresses::hitman5Dll + 0x412E00, this, pWaypointBehavior);
}

SBehavior_Waypoint* ZKnowledge::GetWaypointBehavior()
{
	return Function::CallMethodAndReturn<SBehavior_Waypoint*, ZKnowledge*>(BaseAddresses::hitman5Dll + 0x412E10, this);
}

void ZKnowledge::SetWaypointIndex(int nWaypointIndex)
{
	Function::CallMethod<ZKnowledge*, int>(BaseAddresses::hitman5Dll + 0x412E20, this, nWaypointIndex);
}

int ZKnowledge::GetWaypointIndex()
{
	return Function::CallMethodAndReturn<int, ZKnowledge*>(BaseAddresses::hitman5Dll + 0x412E30, this);
}

TEntityRef<ZSequenceControllerEntity>* ZKnowledge::GetSequenceController(TEntityRef<ZSequenceControllerEntity>* result)
{
	return Function::CallMethodAndReturn<TEntityRef<ZSequenceControllerEntity>*, ZKnowledge*, TEntityRef<ZSequenceControllerEntity>*>(BaseAddresses::hitman5Dll + 0x4131A0, this, result);
}

void ZKnowledge::SetLastReachedWaypoint(TEntityRef<ZWaypointEntity> pWaypoint)
{
	Function::CallMethod<ZKnowledge*, TEntityRef<ZWaypointEntity>>(BaseAddresses::hitman5Dll + 0x4131E0, this, pWaypoint);
}

TEntityRef<ZWaypointEntity>* ZKnowledge::GetLastReachedWaypoint(TEntityRef<ZWaypointEntity>* result)
{
	return Function::CallMethodAndReturn<TEntityRef<ZWaypointEntity>*, ZKnowledge*, TEntityRef<ZWaypointEntity>*>(BaseAddresses::hitman5Dll + 0x413210, this, result);
}

void ZKnowledge::SetPerceptionSensitivitySequence(EActorPerceptionSensitivity sensitivity)
{
	Function::CallMethod<ZKnowledge*, EActorPerceptionSensitivity>(BaseAddresses::hitman5Dll + 0x4308A0, this, sensitivity);
}

float ZKnowledge::GetHMSoundDistance()
{
	return Function::CallMethodAndReturn<float, ZKnowledge*>(BaseAddresses::hitman5Dll + 0x43B6F0, this);
}

void ZKnowledge::SetHMSoundDistance(float fWalkDistance)
{
	Function::CallMethod<ZKnowledge*, float>(BaseAddresses::hitman5Dll + 0x43B700, this, fWalkDistance);
}

void ZKnowledge::ResetCameFromPosition()
{
	Function::CallMethod<ZKnowledge*>(BaseAddresses::hitman5Dll + 0x471760, this);
}

bool ZKnowledge::HasWeapon()
{
	return Function::CallMethodAndReturn<bool, ZKnowledge*>(BaseAddresses::hitman5Dll + 0x477FE0, this);
}

void ZKnowledge::SetCameFromPosition(float4* v)
{
	Function::CallMethod<ZKnowledge*, float4*>(BaseAddresses::hitman5Dll + 0x478F70, this, v);
}

void ZKnowledge::SetPerceptionSensitivityAct(EActorPerceptionSensitivity sensitivity)
{
	Function::CallMethod<ZKnowledge*, EActorPerceptionSensitivity>(BaseAddresses::hitman5Dll + 0x49B6A0, this, sensitivity);
}

void ZKnowledge::SetAllowRagdollDamageReactions(bool bAllow)
{
	Function::CallMethod<ZKnowledge*, bool>(BaseAddresses::hitman5Dll + 0x49B6C0, this, bAllow);
}

SBehaviorBase* ZKnowledge::GetCurrentCompiledBehavior()
{
	return Function::CallMethodAndReturn<SBehaviorBase*, ZKnowledge*>(BaseAddresses::hitman5Dll + 0x4A3B60, this);
}

bool ZKnowledge::GetAllowCutSequence()
{
	return Function::CallMethodAndReturn<bool, ZKnowledge*>(BaseAddresses::hitman5Dll + 0x4A3B70, this);
}

void ZKnowledge::SetSequenceController(TEntityRef<ZSequenceControllerEntity> pSequenceCtrl)
{
	Function::CallMethod<ZKnowledge*, TEntityRef<ZSequenceControllerEntity>>(BaseAddresses::hitman5Dll + 0x4A3F80, this, pSequenceCtrl);
}

void ZKnowledge::SetCrowdActor(TEntityRef<ZCrowdActor> pCrowdActor)
{
	Function::CallMethod<ZKnowledge*, TEntityRef<ZCrowdActor>>(BaseAddresses::hitman5Dll + 0x4C2C90, this, pCrowdActor);
}

void ZKnowledge::AbortCurrentBehavior()
{
	Function::CallMethod<ZKnowledge*>(BaseAddresses::hitman5Dll + 0x5D6BF0, this);
}
