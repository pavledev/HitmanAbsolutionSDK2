#pragma once

#include "ObjectInterface.h"
#include "ValueType.h"
#include "ValueUnion.h"

class GFxValue
{
public:
    ObjectInterface* pObjectInterface;
    ValueType Type;
    ValueUnion Value;
};
