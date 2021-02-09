#pragma once

#include "GFxFileConstants.h"
#include "GFxState.h"
#include "StateType.h"

class GFxStateBag : public GFxFileConstants
{
public:
    virtual GFxStateBag* GetStateBagImpl();
    virtual ~GFxStateBag();
    virtual void SetState(StateType, GFxState*);
    virtual GFxState* GetStateAddRef(StateType);
    virtual void GetStatesAddRef(GFxState**, const StateType*, unsigned int);
};
