#pragma once

#include "GRefCountBase.h"
#include "GFxResource.h"

class __declspec(novtable) GFxResourceLibBase : public GRefCountBase<GFxResourceLibBase, 2>
{
public:
	~GFxResourceLibBase() override = default;
	virtual void RemoveResourceOnRelease(GFxResource* fxResource) = 0;
	virtual void PinResource(GFxResource* fxResource) = 0;
	virtual void UnpinResource(GFxResource* fxResource) = 0;

	GFxResourceLibBase() = default;
};
