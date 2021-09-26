#include "Function.h"
#include "BaseAddresses.h"
#include "Singletons.h"

namespace Singletons
{

	ZContentKitManager* GetContentKitManager()
	{
		return Function::CallAndReturn<ZContentKitManager*>(BaseAddresses::hitman5Dll + 0x12DC60);
	}

	ZUIOptions* GetUIOptions()
	{
		return Function::CallAndReturn<ZUIOptions*>(BaseAddresses::hitman5Dll + 0x1B03C0);
	}

	ZHUDManager* GetHUDManager()
	{
		return Function::CallAndReturn<ZHUDManager*>(BaseAddresses::hitman5Dll + 0xC83E0);
	}

	ZHM5ActionManager* GetHM5ActionManager()
	{
		return Function::CallAndReturn<ZHM5ActionManager*>(BaseAddresses::hitman5Dll + 0x9E610);
	}

	ZHM5SBTargetPropManager* GetSBTargetPropManager()
	{
		return Function::CallAndReturn<ZHM5SBTargetPropManager*>(BaseAddresses::hitman5Dll + 0x189AD0);
	}

	ZActorManager* GetActorManager()
	{
		return Function::CallAndReturn<ZActorManager*>(BaseAddresses::hitman5Dll + 0xA9210);
	}

	ZGameStatsManager* GetGameStatsManager()
	{
		return Function::CallAndReturn<ZGameStatsManager*>(BaseAddresses::hitman5Dll + 0xBA570);
	}

	ZLevelManager* GetLevelManager()
	{
		return Function::CallAndReturn<ZLevelManager*>(BaseAddresses::hitman5Dll + 0x65CA0);
	}

	ZCheckPointManager* GetCheckPointManager()
	{
		return Function::CallAndReturn<ZCheckPointManager*>(BaseAddresses::hitman5Dll + 0x79A20);
	}

	ZInputActionManager* GetInputActionManager()
	{
		return Function::CallAndReturn<ZInputActionManager*>(BaseAddresses::hitman5Dll + 0x12AC90);
	}

	IInputDeviceManager* GetInputDeviceManager()
	{
		return Function::CallAndReturn<IInputDeviceManager*>(BaseAddresses::hitman5Dll + 0x154C60);
	}

	ZDebugConsole* GetDebugConsole()
	{
		return reinterpret_cast<ZDebugConsole*>(BaseAddresses::hitman5Dll + 0xCA54F0);
	}
}
