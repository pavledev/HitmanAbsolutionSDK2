#pragma once

#include "ERenderResourceMapType.h"

class __declspec(novtable) IRenderPrimitiveBuffer
{
public:
	virtual ~IRenderPrimitiveBuffer() = default;
	virtual void Map(ERenderResourceMapType renderResourceMapType, unsigned int param2, unsigned int param3, void** param4) = 0;
	virtual void Unmap(unsigned long long param1) = 0;
	virtual void Update(unsigned int param1, unsigned int param2, const void* param3) = 0;

	IRenderPrimitiveBuffer() = default;
};
