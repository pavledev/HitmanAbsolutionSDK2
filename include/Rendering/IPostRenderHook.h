#pragma once

#include "ZRenderDevice.h"

class IPostRenderHook
{
public:
	virtual void OnPostRender(ZRenderDevice*);
	virtual ~IPostRenderHook();
};
