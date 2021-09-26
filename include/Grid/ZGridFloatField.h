#pragma once

#include "TArray.h"

class ZGridNodeRef;

class ZGridFloatField
{
public:
	int m_nRefCount;
	float m_fInitialValue;
	TArray<float> m_field;

	ZGridFloatField() = default;
	ZGridFloatField(const ZGridFloatField& __that);
	ZGridFloatField(float fInitialValue);
	void AddRef();
	void Release();
	unsigned int Size();
	float GetValue(const ZGridNodeRef& ref) const;
	void SetValue(const ZGridNodeRef& ref, float fValue);
	void Reset(float fValue);
	~ZGridFloatField() = default;
	ZGridFloatField& operator=(const ZGridFloatField& __that);
};
