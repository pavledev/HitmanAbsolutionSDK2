#pragma once

#include "GFxState.h"
#include "GFxLogBase.h"

class GFxLog : public GFxState, public GFxLogBase<GFxLog>
{
public:
	~GFxLog() override = default;

	GFxLog() = default;
};
