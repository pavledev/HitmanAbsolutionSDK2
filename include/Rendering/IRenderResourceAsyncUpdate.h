#pragma once

#include "IRenderRefCount.h"

class __declspec(novtable) IRenderResourceAsyncUpdate : public IRenderRefCount
{
public:
	~IRenderResourceAsyncUpdate() override = default;
	virtual void Apply() = 0;

	IRenderResourceAsyncUpdate() = default;
};
