#pragma once

#include "ZVariant.h"
#include "TArrayRef.h"

class ZVariantRef;

struct SDelegateBaseInvoker
{
	unsigned int argCount;
	ZVariant (*pfInvoke)(void* param1, const TArrayRef<ZVariantRef>& arrayRef);
	STypeID* retType;
	STypeID* a0Type;

	SDelegateBaseInvoker() = default;
	~SDelegateBaseInvoker() = default;
};
