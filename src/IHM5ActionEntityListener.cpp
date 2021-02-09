#include "IHM5ActionEntityListener.h"
#include "Function.h"
#include "BaseAddresses.h"

void IHM5ActionEntityListener::RegisterType()
{
	return Function::Call<>(BaseAddresses::hitman5Dll + 0x138DB0);
}