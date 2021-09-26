#pragma once

#include "ZObjectRef.h"

class ZString;
class ZVariantRef;
struct STypeID;

class ZVariant : public ZObjectRef
{
public:
	static const ZVariant g_EmptyVariant;

	ZVariant(const ZVariantRef& rhs);
	ZVariant(const ZVariant& rhs);
	ZVariant(STypeID* type);
	ZVariant(STypeID* type, const void* pData);
	ZVariant() = default;
	void Set(const ZVariantRef& rhs);
	void Set(const ZVariant& rhs);
	void Set(STypeID* type);
	void Set(STypeID* type, const void* pData);
	void Allocate(STypeID* type);
	~ZVariant() = default;
	void Acquire(ZVariantRef rhs);
	ZVariant& operator=(const ZVariant& rhs);
	void Clear();
	bool FromString(STypeID* type, const ZString& sData);
	static const ZVariant& GetEmpty();
};
