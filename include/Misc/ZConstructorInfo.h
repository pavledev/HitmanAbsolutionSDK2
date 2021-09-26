#pragma once

#include "TArrayRef.h"

struct SDelegateBaseInvoker;
class ZVariantRef;
struct STypeID;

class ZConstructorInfo
{
public:
	void (*m_mfp)();
	const SDelegateBaseInvoker* m_pInvokeData;

	ZConstructorInfo() = default;
	~ZConstructorInfo() = default;
	TArrayRef<STypeID* const> GetArgumentTypes() const;
	bool IsViable(const TArrayRef<STypeID*> argtypes) const;
	bool IsViable(const TArrayRef<ZVariantRef> args) const;
	void Call(void* pObject, const TArrayRef<ZVariantRef> args) const;
};
