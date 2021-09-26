#pragma once

#include "IType.h"

struct SContainerTypeVTable;
struct STypeID;

class IContainerType
{
public:
	IType type;
	STypeID* elementType;
	SContainerTypeVTable* pVTab;

	IContainerType() = default;
	~IContainerType() = default;
	STypeID* GetElementType() const;
	void* Begin(void* pContainer) const;
	unsigned int GetSize(void* pContainer) const;
};
