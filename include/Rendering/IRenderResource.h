#pragma once

#include "IRenderRefCount.h"
#include "ERenderResourceType.h"

class __declspec(novtable) IRenderResource : public IRenderRefCount
{
public:
	~IRenderResource() override = default;
	virtual ERenderResourceType GetResourceType() const = 0;

	IRenderResource() = default;
};
