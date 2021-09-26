#pragma once

#include "ZString.h"

struct STypeID;
class IClassType;
class IArrayType;
class ZVariantRef;
struct STypeFunctions;

class IType
{
public:
	const STypeFunctions* m_pTypeFunctions;
	unsigned short m_nTypeSize;
	unsigned char m_nTypeAlignment;
	unsigned char m_nTypeInfoFlags;
	const char* pszTypeName;
	STypeID* typeID;
	bool (*fromString)(void* param1, const IType* type, const ZString& string);
	unsigned int (*toString)(const void* param1, const IType* type, char* param3, unsigned int param4, const ZString& string);

	IType() = default;
	~IType() = default;
	const char* GetTypeName() const;
	STypeID* GetTypeID() const;
	void PlacementConstruct(void* pObject, const void* pSource) const;
	void PlacementConstruct(void* pObject) const;
	void Destruct(void* pObject) const;
	void Assign(void* pDestination, const void* pSource) const;
	void Assign(void* pObject, ZVariantRef rhs) const;
	bool FromString(void* pObject, const ZString& sSource) const;
	ZString ToString(const void* pObject, const ZString& sFormat) const;
	ZString ToString(const void* pObject) const;
	unsigned int ToCString(char* pBuffer, unsigned int nSize, const void* pObject, const ZString& sFormat) const;
	void* Construct() const;
	void DestructAndFree(void* pObject) const;
	unsigned int GetTypeSize() const;
	unsigned int GetTypeAlignment() const;
	bool IsTEntityRef() const;
	bool IsTResourcePtr() const;
	const IClassType* QueryClassInterface() const;
	const IArrayType* QueryArrayType() const;
};
