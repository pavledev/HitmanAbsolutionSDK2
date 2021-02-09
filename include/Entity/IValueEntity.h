#pragma once

#include "ZVariant.h"

class IValueEntity
{
public:
	virtual ~IValueEntity();
	virtual ZVariant* GetValue(ZVariant* result);
};
