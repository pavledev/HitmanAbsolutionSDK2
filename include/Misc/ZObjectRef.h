#pragma once

#include "ZString.h"

class IType;
struct STypeID;

class ZObjectRef
{
public:
	STypeID* m_TypeID;
	void* m_pData;

	ZObjectRef(void* pObject, STypeID* const typeID);
	ZObjectRef() = default;
	~ZObjectRef() = default;
	bool IsNull() const;
	STypeID* GetTypeID() const;
	void* GetData() const;
	const IType* GetType() const;
	ZString ToString(const ZString& sFormat) const;
	ZString ToString() const;
	unsigned int ToCString(char* pBuffer, unsigned int nSize, const ZString& sFormat) const;
	bool FromString(const ZString& sData) const;
	static bool CanConvert(STypeID* from, STypeID* to);
};
