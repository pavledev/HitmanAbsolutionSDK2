#pragma once

#include "IComponentInterface.h"
#include "IBaseConstraint.h"

class IFixedConstraint : public IComponentInterface
{
public:
    virtual IBaseConstraint* GetBaseConstraint();
};
