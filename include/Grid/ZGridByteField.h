#pragma once

#include "TArray.h"

class ZGridNodeRef;

class ZGridByteField
{
public:
	int m_nRefCount;
	char m_nInitialValue;
	TArray<signed char> m_field;

	ZGridByteField() = default;
	ZGridByteField(const ZGridByteField& __that);
	ZGridByteField(char nInitialValue);
	void AddRef();
	void Release();
	unsigned int Size();
	char GetValue(const ZGridNodeRef& ref) const;
	void SetValue(const ZGridNodeRef& ref, char nValue);
	void Reset(char nValue);
	~ZGridByteField() = default;
	ZGridByteField& operator=(const ZGridByteField& __that);
};
