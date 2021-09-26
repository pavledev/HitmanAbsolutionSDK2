#include "TSList.h"
#include "BaseAddresses.h"
#include "ZHM5ActionManager.h"

template<>
unsigned int TSList<ZHM5ActionManager::SActionTreeEntry>::BeginOffset()
{
	return BaseAddresses::hitman5Dll + 0x144B30;
}

template<>
unsigned int TSList<ZHM5ActionManager::SActionTreeEntry>::EndOffset()
{
	return BaseAddresses::hitman5Dll + 0x144B50;
}
