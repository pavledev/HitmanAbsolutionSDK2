#include "IHM5BaseCharacter.h"
#include "Function.h"
#include "BaseAddresses.h"

void IHM5BaseCharacter::RegisterType()
{
	Function::Call<>(BaseAddresses::hitman5Dll + 0x1E9F40);
}