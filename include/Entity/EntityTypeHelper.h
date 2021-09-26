#pragma once

#include "Function.h"
#include "BaseAddresses.h"

class ZEntityType;
struct STypeID;

class EntityTypeHelper
{
public:
	static void* ResolveInterfacePtr(ZEntityType** pEntity, STypeID* typeID)
	{
		return Function::CallAndReturn<void*, ZEntityType**, STypeID*>(BaseAddresses::runtimeEntity + 0x33F30, pEntity, typeID);
	}
};
