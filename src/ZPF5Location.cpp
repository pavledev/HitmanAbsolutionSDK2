#include "ZPF5Location.h"
#include "Function.h"
#include "BaseAddresses.h"

ZPF5Location::ZPF5Location()
{
	Function::CallMethod<ZPF5Location*>(BaseAddresses::runtimePathFinder + 0x3380, this);
}
