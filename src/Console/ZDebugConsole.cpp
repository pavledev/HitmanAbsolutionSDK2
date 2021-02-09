#include "ZDebugConsole.h"
#include "Function.h"
#include "BaseAddresses.h"

void ZDebugConsole::OnStopEvent(ZString* sEvent, ZVariantRef* oldValue)
{
	Function::CallMethod<ZDebugConsole*, ZString*, ZVariantRef*>(BaseAddresses::hitman5Dll + 0x117A7, this, sEvent, oldValue);
}

const char* ZDebugConsole::GetLine(int lLine)
{
	return Function::CallMethodAndReturn<const char*, ZDebugConsole*, int>(BaseAddresses::hitman5Dll + 0x1F26C, this, lLine);
}

void ZDebugConsole::SplitToArgs(char* pszString, unsigned int* pargc, char*** pargv)
{
	Function::CallMethod<ZDebugConsole*, char*, unsigned int*, char***>(BaseAddresses::hitman5Dll + 0x2E825, this, pszString, pargc, pargv);
}

void ZDebugConsole::AddLine(char* Format)
{
	Function::CallMethod<ZDebugConsole*, char*>(BaseAddresses::hitman5Dll + 0x2EE15, this, Format);
}

void ZDebugConsole::FrameUpdate(SGameUpdateEvent* updateEvent)
{
	Function::CallMethod<ZDebugConsole*, SGameUpdateEvent*>(BaseAddresses::hitman5Dll + 0x3E9CD, this, updateEvent);
}

void ZDebugConsole::Command()
{
	Function::CallMethod<ZDebugConsole*>(BaseAddresses::hitman5Dll + 0x43AF9, this);
}

void ZDebugConsole::ExecuteCommand(const char* szCommand)
{
	Function::CallMethod<ZDebugConsole*, const char*>(BaseAddresses::hitman5Dll + 0x62A330, this, szCommand);
}

int ZDebugConsole::OnInput(int iKey, int iMask, void* pThis)
{
	return Function::CallAndReturn<int, int, int, void*>(BaseAddresses::hitman5Dll + 0x4AD9F, iKey, iMask, pThis);
}

const SComponentMapEntry* ZDebugConsole::GetComponentInterfacesInternal()
{
	return Function::CallMethodAndReturn<const SComponentMapEntry*, ZDebugConsole*>(BaseAddresses::hitman5Dll + 0x12DC90, this);
}

void ZDebugConsole::GetHistory(int iDir)
{
	Function::CallMethod<ZDebugConsole*, int>(BaseAddresses::hitman5Dll + 0x629850, this, iDir);
}

void ZDebugConsole::AddHistory(char* szLine)
{
	Function::CallMethod<ZDebugConsole*, char*>(BaseAddresses::hitman5Dll + 0x629EB0, this, szLine);
}

void ZDebugConsole::EnableConsole(bool bEnable)
{
	Function::CallMethod<ZDebugConsole*, bool>(BaseAddresses::hitman5Dll + 0x62A5F0, this, bEnable);
}
