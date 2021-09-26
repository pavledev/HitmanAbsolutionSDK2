#pragma once

#include "IContainerType.h"

class IArrayType
{
public:
	IContainerType containerType;
	void (*setSize)(void* param1, unsigned int param2);

	IArrayType() = default;
	~IArrayType() = default;
	unsigned int GetSize(void* pContainer) const;
	void SetSize(void* pContainer, unsigned int nSize) const;
	STypeID* GetElementType() const;
	ZVariantRef GetElement(void* pContainer, int nIndex) const;
};
