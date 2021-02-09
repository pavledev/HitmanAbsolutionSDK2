#include "ZUIOptions.h"
#include "Function.h"
#include "BaseAddresses.h"

int ZUIOptions::Int(unsigned int key)
{
	return Function::CallMethodAndReturn<int, ZUIOptions*, unsigned int>(BaseAddresses::hitman5Dll + 0x1C4B00, this, key);
}

template<class T>
void ZUIOptions::RegisterForOptionChange(_EUIOptionKey optionKey, ZDelegate<void __cdecl(T)> callback, unsigned int offset)
{
	Function::CallMethod<ZUIOptions*, _EUIOptionKey, ZDelegate<void __cdecl(T)>>(BaseAddresses::hitman5Dll + offset, this, optionKey, callback);
}

template<class T>
void ZUIOptions::UnregisterForOptionChange(_EUIOptionKey optionKey, ZDelegate<void __cdecl(T)> callback, unsigned int offset)
{
	Function::CallMethod<ZUIOptions*, _EUIOptionKey, ZDelegate<void __cdecl(T)>>(BaseAddresses::hitman5Dll + offset, this, optionKey, callback);
}

float ZUIOptions::Float(unsigned int key)
{
	return Function::CallMethodAndReturn<float, ZUIOptions*, unsigned int>(BaseAddresses::hitman5Dll + 0x219E50, this, key);
}

bool ZUIOptions::Bool(unsigned int key)
{
	return Function::CallMethodAndReturn<bool, ZUIOptions*, unsigned int>(BaseAddresses::hitman5Dll + 0x219E80, this, key);
}

void ZUIOptions::SetInt(unsigned int key, int value)
{
	Function::CallMethod<ZUIOptions*, unsigned int, int>(BaseAddresses::hitman5Dll + 0x57EE50, this, key, value);
}

template<class T>
Values<T>* ZUIOptions::GetValues(unsigned int offset)
{
	return Function::CallMethodAndReturn<Values<T>*, ZUIOptions*>(BaseAddresses::hitman5Dll + offset, this);
}

void ZUIOptions::LoadDefaults()
{
	Function::CallMethod<ZUIOptions*>(BaseAddresses::hitman5Dll + 0x5A0960, this);
}

void ZUIOptions::WriteData()
{
	Function::CallMethod<ZUIOptions*>(BaseAddresses::hitman5Dll + 0x5A0990, this);
}

bool ZUIOptions::Save()
{
	return Function::CallMethodAndReturn<bool, ZUIOptions*>(BaseAddresses::hitman5Dll + 0x5A0EE0, this);
}

void ZUIOptions::ReadData()
{
	Function::CallMethod<ZUIOptions*>(BaseAddresses::hitman5Dll + 0x5A2B80, this);
}

void ZUIOptions::OnLoadDone(ESaveLoadSlotStatus eStatus)
{
	Function::CallMethod<ZUIOptions*, ESaveLoadSlotStatus>(BaseAddresses::hitman5Dll + 0x5A3760, this, eStatus);
}

const SComponentMapEntry* ZUIOptions::GetComponentInterfacesInternal()
{
	return Function::CallMethodAndReturn<const SComponentMapEntry*, ZUIOptions*>(BaseAddresses::hitman5Dll + 0x5A5B80, this);
}

void ZUIOptions::SetFloat(unsigned int key, float value)
{
	Function::CallMethod<ZUIOptions*, unsigned int, float>(BaseAddresses::hitman5Dll + 0x6D5740, this, key, value);
}

void ZUIOptions::SetBool(unsigned int key, bool value)
{
	Function::CallMethod<ZUIOptions*, unsigned int, bool>(BaseAddresses::hitman5Dll + 0x6D5780, this, key, value);
}
