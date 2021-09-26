#pragma once

#include "ZVariant.h"

class __declspec(novtable) IValueEntity
{
public:
	virtual ~IValueEntity() = default;
	virtual ZVariant GetValue() = 0;

	static void RegisterType();
	IValueEntity() = default;
};
