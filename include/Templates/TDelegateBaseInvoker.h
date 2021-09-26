#pragma once

#include "ZVariant.h"
#include "TArrayRef.h"
#include "ZVariantRef.h"

template <class T>
struct TDelegateBaseInvoker
{
	unsigned int argCount;
	ZVariant(*pfInvoke)(void* param1, const TArrayRef<ZVariantRef>& arrayRef);
	STypeID* retType;
	STypeID* a0Type;

	static const TDelegateBaseInvoker ms_invokeData;

	TDelegateBaseInvoker() = default;
	~TDelegateBaseInvoker() = default;
};
