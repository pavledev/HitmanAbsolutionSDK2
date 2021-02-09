#include "SSharedEntityKnowledge.h"
#include "Function.h"
#include "BaseAddresses.h"

EKnownEntityType SSharedEntityKnowledge::GetType()
{
	return Function::CallMethodAndReturn<EKnownEntityType, SSharedEntityKnowledge*>(BaseAddresses::hitman5Dll + 0x93960, this);
}

SAISharedEvent* SSharedEntityKnowledge::GetEventFromIndex(unsigned __int16 index)
{
	return Function::CallAndReturn<SAISharedEvent*, unsigned __int16>(BaseAddresses::hitman5Dll + 0x93C60, index);
}

SAISharedEvent* SSharedEntityKnowledge::GetSharedEvent(EAISharedEventType type)
{
	return Function::CallMethodAndReturn<SAISharedEvent*, SSharedEntityKnowledge*, EAISharedEventType>(BaseAddresses::hitman5Dll + 0x940D0, this, type);
}

bool SSharedEntityKnowledge::IsCurrent(EAISharedEventType type)
{
	return Function::CallMethodAndReturn<bool, SSharedEntityKnowledge*, EAISharedEventType>(BaseAddresses::hitman5Dll + 0x943A0, this, type);
}

int SSharedEntityKnowledge::ExpireSharedEvent(EAISharedEventType type, float fDelay)
{
	return Function::CallMethodAndReturn<int, SSharedEntityKnowledge*, EAISharedEventType, float>(BaseAddresses::hitman5Dll + 0xA7790, this, type, fDelay);
}

bool SSharedEntityKnowledge::RemoveExpiredSharedEvents()
{
	return Function::CallMethodAndReturn<bool, SSharedEntityKnowledge*>(BaseAddresses::hitman5Dll + 0xAA210, this);
}

SAISharedEvent* SSharedEntityKnowledge::CreateSharedEvent(EAISharedEventType type)
{
	return Function::CallMethodAndReturn<SAISharedEvent*, SSharedEntityKnowledge*, EAISharedEventType>(BaseAddresses::hitman5Dll + 0xAA5A0, this, type);
}

bool SSharedEntityKnowledge::NewSharedEvent(EAISharedEventType type, float duration)
{
	return Function::CallMethodAndReturn<bool, SSharedEntityKnowledge*, EAISharedEventType, float>(BaseAddresses::hitman5Dll + 0xAA680, this, type, duration);
}

bool SSharedEntityKnowledge::RenewSharedEvent(EAISharedEventType type, float duration)
{
	return Function::CallMethodAndReturn<bool, SSharedEntityKnowledge*, EAISharedEventType, float>(BaseAddresses::hitman5Dll + 0xAA740, this, type, duration);
}

bool SSharedEntityKnowledge::MinSharedEventAge(EAISharedEventType type, float fSeconds)
{
	return Function::CallMethodAndReturn<bool, SSharedEntityKnowledge*, EAISharedEventType, float>(BaseAddresses::hitman5Dll + 0xB1B80, this, type, fSeconds);
}

bool SSharedEntityKnowledge::MaxSharedEventAge(EAISharedEventType type, float fSeconds)
{
	return Function::CallMethodAndReturn<bool, SSharedEntityKnowledge*, EAISharedEventType, float>(BaseAddresses::hitman5Dll + 0xB1C10, this, type, fSeconds);
}

void SSharedEntityKnowledge::IncRefCount(unsigned int nMemDebugID)
{
	Function::CallMethod<SSharedEntityKnowledge*, unsigned int>(BaseAddresses::hitman5Dll + 0xB97F0, this, nMemDebugID);
}

void SSharedEntityKnowledge::DecRefCount(unsigned int nMemDebugID)
{
	Function::CallMethod<SSharedEntityKnowledge*, unsigned int>(BaseAddresses::hitman5Dll + 0xB9800, this, nMemDebugID);
}

float4* SSharedEntityKnowledge::ActualPosition(float4* result)
{
	return Function::CallMethodAndReturn<float4*, SSharedEntityKnowledge*, float4*>(BaseAddresses::hitman5Dll + 0xFD220, this, result);
}

bool SSharedEntityKnowledge::MaxSharedEventExpired(EAISharedEventType type, float fSeconds)
{
	return Function::CallMethodAndReturn<bool, SSharedEntityKnowledge*, EAISharedEventType, float>(BaseAddresses::hitman5Dll + 0x104870, this, type, fSeconds);
}

bool SSharedEntityKnowledge::MinSharedEventExpired(EAISharedEventType type, float fSeconds)
{
	return Function::CallMethodAndReturn<bool, SSharedEntityKnowledge*, EAISharedEventType, float>(BaseAddresses::hitman5Dll + 0x11CBD0, this, type, fSeconds);
}

ZEntityRef* SSharedEntityKnowledge::GetOutfit(ZEntityRef* result)
{
	return Function::CallMethodAndReturn<ZEntityRef*, SSharedEntityKnowledge*, ZEntityRef*>(BaseAddresses::hitman5Dll + 0x3DB410, this, result);
}

void SSharedEntityKnowledge::SetOutfit(ZEntityRef pOutfit)
{
	Function::CallMethod<SSharedEntityKnowledge*, ZEntityRef>(BaseAddresses::hitman5Dll + 0x3DB440, this, pOutfit);
}

EActorType SSharedEntityKnowledge::GetActorType()
{
	return Function::CallMethodAndReturn<EActorType, SSharedEntityKnowledge*>(BaseAddresses::hitman5Dll + 0x409FD0, this);
}

EActorRank SSharedEntityKnowledge::GetActorRank()
{
	return Function::CallMethodAndReturn<EActorRank, SSharedEntityKnowledge*>(BaseAddresses::hitman5Dll + 0x452EF0, this);
}
