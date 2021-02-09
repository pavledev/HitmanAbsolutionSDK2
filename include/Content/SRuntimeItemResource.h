#pragma once

#include "ZResourcePtr.h"

class SRuntimeItemResource
{
public:
    ZResourcePtr pResource;
    unsigned int nRefCount;
};
