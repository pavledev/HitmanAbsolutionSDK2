#pragma once

#include "GRefCountBase.h"
#include "Params.h"

class GFxFunctionHandler : public GRefCountBase<GFxFunctionHandler, 2>
{
public:
	virtual void Call(const Params*);
};
