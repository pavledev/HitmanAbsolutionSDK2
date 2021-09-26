#pragma once

#include "ZObjectRef.h"
#include "ZVariant.h"

struct STypeID;

class ZVariantRef : public ZObjectRef
{
public:
	ZVariantRef(const ZVariant& rhs);
	~ZVariantRef() = default;
	ZVariantRef(const ZVariantRef& rhs);
	ZVariantRef(void* pObject, STypeID* const typeID);
	ZVariantRef() = default;
	void Assign(ZVariantRef rhs) const;
};
