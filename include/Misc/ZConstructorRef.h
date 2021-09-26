#pragma once

#include "TArrayRef.h"

class ZConstructorInfo;
class ZVariantRef;
struct STypeID;

class ZConstructorRef
{
public:
	TArrayRef<ZConstructorInfo const> m_aConstructors;

	ZConstructorRef(TArrayRef<ZConstructorInfo const> aConstructors);
	ZConstructorRef() = default;
	~ZConstructorRef() = default;
	void Call(void* pObject, unsigned int nIndex, const TArrayRef<ZVariantRef> args) const;
	int GetBestViable(const TArrayRef<STypeID*> argtypes) const;
	int GetBestViable(const TArrayRef<ZVariantRef> args) const;
};
