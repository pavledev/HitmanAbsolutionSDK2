#include "ZConfigCommand.h"
#include "Function.h"
#include "BaseAddresses.h"

ZConfigCommand* ZConfigCommand::Next()
{
	return Function::CallMethodAndReturn<ZConfigCommand*, ZConfigCommand*>(BaseAddresses::hitman5Dll + 0x629A60, this);
}

ZString* ZConfigCommand::Name(ZString* result)
{
	return Function::CallMethodAndReturn<ZString*, ZConfigCommand*, ZString*>(BaseAddresses::hitman5Dll + 0x2F83F0, this, result);
}

ZConfigCommand* ZConfigCommand::First()
{
	return Function::CallAndReturn<ZConfigCommand*>(BaseAddresses::hitman5Dll + 0x8A0C60);
}

void ZConfigCommand::ExecuteCommand(ZString* pCommandName, char* argv)
{
	Function::Call<ZString*, char*>(BaseAddresses::hitman5Dll + 0x8A0D10, pCommandName, argv);
}

ZConfigCommand* ZConfigCommand::GetConfigVariable(ZString* pszName)
{
	return Function::CallAndReturn<ZConfigCommand*, ZString*>(BaseAddresses::hitman5Dll + 0x8A0DA0, pszName);
}