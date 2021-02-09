#include "ZResourcePtr.h"
#include "Function.h"
#include "BaseAddresses.h"

EResourceStatus ZResourcePtr::GetResourceStatus()
{
	return Function::CallMethodAndReturn<EResourceStatus, ZResourcePtr*>(BaseAddresses::runtimeResource + 0x1046, this);
}

void ZResourcePtr::ReleaseStub(ZResourceStub* pStub)
{
	Function::CallMethod<ZResourcePtr*, ZResourceStub*>(BaseAddresses::runtimeResource + 0x1087, this, pStub);
}

unsigned int ZResourcePtr::GetHashCode()
{
	return Function::CallMethodAndReturn<unsigned int, ZResourcePtr*>(BaseAddresses::runtimeResource + 0x1195, this);
}

bool ZResourcePtr::AreAllReferencesLoaded()
{
	return Function::CallMethodAndReturn<bool, ZResourcePtr*>(BaseAddresses::runtimeResource + 0x11EF, this);
}

ZResourcePtr::ZResourcePtr(ZResourcePtr* rhs)
{
	Function::CallMethod<ZResourcePtr*, ZResourcePtr*>(BaseAddresses::runtimeResource + 0x35E10, this, rhs);
}

void ZResourcePtr::SetResourceStatus(EResourceStatus eStatus)
{
	Function::CallMethod<ZResourcePtr*, EResourceStatus>(BaseAddresses::runtimeResource + 0x17AD, this, eStatus);
}

bool ZResourcePtr::Failed()
{
	return Function::CallMethodAndReturn<bool, ZResourcePtr*>(BaseAddresses::runtimeResource + 0x1AF5, this);
}

bool ZResourcePtr::HasNewerVersion()
{
	return Function::CallMethodAndReturn<bool, ZResourcePtr*>(BaseAddresses::runtimeResource + 0x1B63, this);
}

void* ZResourcePtr::GetInstallingRawPointer()
{
	return Function::CallMethodAndReturn<void*, ZResourcePtr*>(BaseAddresses::runtimeResource + 0x1DF2, this);
}

ZResourcePtr::ZResourcePtr()
{
	Function::CallMethod<ZResourcePtr*>(BaseAddresses::runtimeResource + 0x359A0, this);
}

IResourceInstaller* ZResourcePtr::GetResourceInstaller()
{
	return Function::CallMethodAndReturn<IResourceInstaller*, ZResourcePtr*>(BaseAddresses::runtimeResource + 0x1EDD, this);
}

bool ZResourcePtr::Exists()
{
	return Function::CallMethodAndReturn<bool, ZResourcePtr*>(BaseAddresses::runtimeResource + 0x235B, this);
}

bool ZResourcePtr::IsLeakTrackingEnabled()
{
	return Function::CallAndReturn<bool>(BaseAddresses::runtimeResource + 0x28AB);
}

bool ZResourcePtr::Rebind()
{
	return Function::CallMethodAndReturn<bool, ZResourcePtr*>(BaseAddresses::runtimeResource + 0x2A45, this);
}

bool ZResourcePtr::AreAllReferencesLoaded(THashSet<ZResourceStub*, TDefaultHashSetPolicy<ZResourceStub*> >* visitedStubs)
{
	return Function::CallMethodAndReturn<bool, ZResourcePtr*, THashSet<ZResourceStub*, TDefaultHashSetPolicy<ZResourceStub*> >*>(BaseAddresses::runtimeResource + 0x2A7C, this, visitedStubs);
}

bool ZResourcePtr::operator>(ZResourcePtr* rhs)
{
	return Function::CallMethodAndReturn<bool, ZResourcePtr*, ZResourcePtr*>(BaseAddresses::runtimeResource + 0x2B7B, this, rhs);
}

ZResourcePtr::ZResourcePtr(ZResourceStub* pResourceHeader)
{
	Function::CallMethod<ZResourcePtr*>(BaseAddresses::runtimeResource + 0x35E40, this);
}

ZRuntimeResourceID* ZResourcePtr::GetRuntimeResourceID(ZRuntimeResourceID* result)
{
	return Function::CallMethodAndReturn<ZRuntimeResourceID*, ZResourcePtr*, ZRuntimeResourceID*>(BaseAddresses::runtimeResource + 0x2DBF, this, result);
}

void ZResourcePtr::AddRefStub(ZResourceStub* pStub)
{
	Function::CallMethod<ZResourcePtr*, ZResourceStub*>(BaseAddresses::runtimeResource + 0x2E96, this, pStub);
}

void ZResourcePtr::RemoveStatusChangedListener(ZDelegate<void __cdecl(ZRuntimeResourceID&)>* d)
{
	Function::CallMethod<ZResourcePtr*, ZDelegate<void __cdecl(ZRuntimeResourceID&)>*>(BaseAddresses::runtimeResource + 0x2ED2, this, d);
}

unsigned int ZResourcePtr::GetResourceTag()
{
	return Function::CallMethodAndReturn<unsigned int, ZResourcePtr*>(BaseAddresses::runtimeResource + 0x34B8, this);
}

void ZResourcePtr::SetResourceData(void* pResourceData)
{
	Function::CallMethod<ZResourcePtr*, void*>(BaseAddresses::runtimeResource + 0x35DF, this, pResourceData);
}

bool ZResourcePtr::IsReady()
{
	return Function::CallMethodAndReturn<bool, ZResourcePtr*>(BaseAddresses::runtimeResource + 0x3B3E, this);
}

ZResourcePtr::ZResourcePtr(ZRuntimeResourceID* rid)
{
	Function::CallMethod<ZResourcePtr*, ZRuntimeResourceID*>(BaseAddresses::runtimeResource + 0x36320, this, rid);
}

ZResourcePtr::~ZResourcePtr()
{
	Function::CallMethod<ZResourcePtr*>(BaseAddresses::runtimeResource + 0x3E2C, this);
}

ZResourcePtr* ZResourcePtr::GetNewestVersion(ZResourcePtr* result)
{
	return Function::CallMethodAndReturn<ZResourcePtr*, ZResourcePtr*, ZResourcePtr*>(BaseAddresses::runtimeResource + 0x40C0, this, result);
}

bool ZResourcePtr::operator==(ZResourcePtr* rhs)
{
	return Function::CallMethodAndReturn<bool, ZResourcePtr*, ZResourcePtr*>(BaseAddresses::runtimeResource + 0x41B5, this, rhs);
}

bool ZResourcePtr::RebindEvenIfNotReady()
{
	return Function::CallMethodAndReturn<bool, ZResourcePtr*>(BaseAddresses::runtimeResource + 0x45BB, this);
}

ZResourceStub* ZResourcePtr::GetResourceStub()
{
	return Function::CallMethodAndReturn<ZResourceStub*, ZResourcePtr*>(BaseAddresses::runtimeResource + 0x465B, this);
}

ZResourcePtr* ZResourcePtr::operator=(ZResourcePtr* rhs)
{
	return Function::CallMethodAndReturn<ZResourcePtr*, ZResourcePtr*, ZResourcePtr*>(BaseAddresses::runtimeResource + 0x46C9, this, rhs);
}

void ZResourcePtr::SetLeakTrackingEnabled(bool bEnabled)
{
	Function::Call<bool>(BaseAddresses::runtimeResource + 0x49D0, bEnabled);
}

void* ZResourcePtr::GetRawPointer()
{
	return Function::CallMethodAndReturn<void*, ZResourcePtr*>(BaseAddresses::runtimeResource + 0x4A20, this);
}

bool ZResourcePtr::operator<(ZResourcePtr* rhs)
{
	return Function::CallMethodAndReturn<bool, ZResourcePtr*, ZResourcePtr*>(BaseAddresses::runtimeResource + 0x4BAB, this, rhs);
}

void ZResourcePtr::Release()
{
	Function::CallMethod<ZResourcePtr*>(BaseAddresses::runtimeResource + 0x4C4B, this);
}

bool ZResourcePtr::operator!=(ZResourcePtr* rhs)
{
	return Function::CallMethodAndReturn<bool, ZResourcePtr*, ZResourcePtr*>(BaseAddresses::runtimeResource + 0x4CB4, this, rhs);
}

void ZResourcePtr::AddStatusChangedListener(ZDelegate<void __cdecl(ZRuntimeResourceID&)>* d)
{
	Function::CallMethod<ZResourcePtr*, ZDelegate<void __cdecl(ZRuntimeResourceID&)>*>(BaseAddresses::runtimeResource + 0x4CFF, this, d);
}
