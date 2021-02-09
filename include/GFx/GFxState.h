#pragma once

#include "GRefCountBase.h"
#include "StateType.h"

class GFxState : public GRefCountBase<GFxState, 2>
{
public:
    StateType SType;
};
