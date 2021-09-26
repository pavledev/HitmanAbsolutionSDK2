#pragma once

#include "ZVariantRef.h"

class ZGenericMemberFunctionTarget;

class ZPinFunctor
{
public:
	void (*pfInvoke)(void (*param1)(), ZGenericMemberFunctionTarget* genericMemberFunctionTarget, const ZVariantRef& variantRef, unsigned int param4);
	void (*func)();

	ZPinFunctor() = default;
	~ZPinFunctor() = default;
	void Invoke(void* pObj, const ZVariantRef& a1, unsigned int nExtraData) const;
};
