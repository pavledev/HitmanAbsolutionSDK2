#include "TSListIterator.h"
#include "BaseAddresses.h"
#include "ZHM5ActionManager.h"

template<>
unsigned int TSListIterator<ZHM5ActionManager::SActionTreeEntry>::IncrementOperatorOffset()
{
	return BaseAddresses::hitman5Dll + 0x144660;
}

template<>
unsigned int TSListIterator<ZHM5ActionManager::SActionTreeEntry>::AssignmentOperatorOffset()
{
	return BaseAddresses::hitman5Dll + 0x144550;
}
