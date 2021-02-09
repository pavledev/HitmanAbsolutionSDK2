#pragma once

#include "IRenderPrimitive.h"

class alignas(16) IRenderPrimitiveMesh : public IRenderPrimitive
{
public:
    unsigned __int8* m_pColiData;
};
