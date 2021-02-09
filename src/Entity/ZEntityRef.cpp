#include "ZEntityRef.h"
#include "Function.h"
#include "BaseAddresses.h"

bool ZEntityRef::operator!=(ZEntityRef* rhs)
{
	return Function::CallMethodAndReturn<bool, ZEntityRef*, ZEntityRef*>(BaseAddresses::runtimeEntity + 0x1A19, this, rhs);
}

bool ZEntityRef::operator==(ZEntityRef* rhs)
{
	return Function::CallMethodAndReturn<bool, ZEntityRef*, ZEntityRef*>(BaseAddresses::runtimeEntity + 0x1B04, this, rhs);
}

ZEntityType** ZEntityRef::QueryInterfacePtr(STypeID* interfaceID)
{
	return Function::CallMethodAndReturn<ZEntityType**, ZEntityRef*, STypeID*>(BaseAddresses::runtimeEntity + 0x1B18, this, interfaceID);
}

ZEntityRef* ZEntityRef::FromEntityTypePtrPtr(ZEntityRef* result, ZEntityType** pEntityTypePtrPtr)
{
	return Function::CallAndReturn<ZEntityRef*, ZEntityRef*, ZEntityType**>(BaseAddresses::runtimeEntity + 0x1C5D, result, pEntityTypePtrPtr);
}

ZString* ZEntityRef::GetDebugNameScenePath(ZString* result)
{
	return Function::CallMethodAndReturn<ZString*, ZEntityRef*, ZString*>(BaseAddresses::runtimeEntity + 0x1D57, this, result);
}

bool ZEntityRef::operator<(ZEntityRef* rhs)
{
	return Function::CallMethodAndReturn<bool, ZEntityRef*, ZEntityRef*>(BaseAddresses::runtimeEntity + 0x1F55, this, rhs);
}

ZString* ZEntityRef::ToString(ZString* result)
{
	return Function::CallMethodAndReturn<ZString*, ZEntityRef*, ZString*>(BaseAddresses::runtimeEntity + 0x1F8C, this, result);
}

void ZEntityRef::RegisterForDeletionListening(ZDelegate<void __cdecl(ZEntityRef&)>* fpCallback)
{
	Function::CallMethod<ZEntityRef*, ZDelegate<void __cdecl(ZEntityRef&)>*>(BaseAddresses::runtimeEntity + 0x2865, this, fpCallback);
}

bool ZEntityRef::IsNull()
{
	return Function::CallMethodAndReturn<bool, ZEntityRef*>(BaseAddresses::runtimeEntity + 0x2A18, this);
}

ZString* ZEntityRef::GetDebugName(ZString* result)
{
	return Function::CallMethodAndReturn<ZString*, ZEntityRef*, ZString*>(BaseAddresses::runtimeEntity + 0x2CBB, this, result);
}

//ZEntityRef::~ZEntityRef()
//{
//	Function::CallMethod<ZEntityRef*>(BaseAddresses::runtimeEntity + 0x2DB0, this);
//}

void ZEntityRef::RegisterType()
{
	Function::Call<>(BaseAddresses::runtimeEntity + 0x2EDC);
}

ZEntityType** ZEntityRef::GetEntityTypePtrPtr()
{
	return Function::CallMethodAndReturn<ZEntityType**, ZEntityRef*>(BaseAddresses::runtimeEntity + 0x3F21, this);
}

ZEntityRef* ZEntityRef::FromTEntityRef(ZEntityRef* result, ZVariantRef entityRef)
{
	return Function::CallAndReturn<ZEntityRef*, ZEntityRef*, ZVariantRef>(BaseAddresses::runtimeEntity + 0x41D3, result, entityRef);
}

//ZEntityRef::ZEntityRef(ZEntityRef* rhs)
//{
//	Function::CallMethod<ZEntityRef*, ZEntityRef*>(BaseAddresses::runtimeEntity + 0xB820, this, rhs);
//}

ZEntityRef* ZEntityRef::operator=(ZEntityRef* rhs)
{
	return Function::CallMethodAndReturn<ZEntityRef*, ZEntityRef*, ZEntityRef*>(BaseAddresses::runtimeEntity + 0x444E, this, rhs);
}

unsigned int ZEntityRef::GetHashCode()
{
	return Function::CallMethodAndReturn<unsigned int, ZEntityRef*>(BaseAddresses::runtimeEntity + 0x46BF, this);
}

ZEntityImpl* ZEntityRef::GetEntityImpl()
{
	return Function::CallMethodAndReturn<ZEntityImpl*, ZEntityRef*>(BaseAddresses::runtimeEntity + 0x493F, this);
}

unsigned int ZEntityRef::ToCString(char* pBuffer, unsigned int nSize, ZString* sFormat)
{
	return Function::CallMethodAndReturn<unsigned int, ZEntityRef*, char*, unsigned int, ZString*>(BaseAddresses::runtimeEntity + 0x4C00, this, pBuffer, nSize, sFormat);
}

//ZEntityRef::ZEntityRef()
//{
//	Function::CallMethod<ZEntityRef*>(BaseAddresses::runtimeEntity + 0xB810, this);
//}

void ZEntityRef::UnregisterForDeletionListening(ZDelegate<void __cdecl(ZEntityRef&)>* fpCallback)
{
	Function::CallMethod<ZEntityRef*, ZDelegate<void __cdecl(ZEntityRef&)>*>(BaseAddresses::runtimeEntity + 0x5727, this, fpCallback);
}

void ZEntityRef::FillSubsetArray(ZString* subsetName, TArray<ZEntityRef>* entities, bool bChildSet)
{
	Function::CallMethod<ZEntityRef*, ZString*, TArray<ZEntityRef>*, bool>(BaseAddresses::runtimeEntity + 0x585D, this, subsetName, entities, bChildSet);
}

bool ZEntityRef::IsRegisteredForDeletionListening(ZDelegate<void __cdecl(ZEntityRef&)>* fpCallback)
{
	return Function::CallMethodAndReturn<bool, ZEntityRef*, ZDelegate<void __cdecl(ZEntityRef&)>*>(BaseAddresses::runtimeEntity + 0x5AF6, this, fpCallback);
}

bool ZEntityRef::operator>(ZEntityRef* rhs)
{
	return Function::CallMethodAndReturn<bool, ZEntityRef*, ZEntityRef*>(BaseAddresses::runtimeEntity + 0x6226, this, rhs);
}
