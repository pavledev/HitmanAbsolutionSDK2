#include "IComponentInterface.h"
#include "Function.h"
#include "BaseAddresses.h"

void IComponentInterface::RegisterType()
{
	Function::Call<>(BaseAddresses::hitman5Dll + 0x8C9FB0);
}
