#pragma once

#include "IRenderRefCount.h"
#include "TArray.h"
#include "IRenderResource.h"

class IRenderTextureResource : public IRenderRefCount
{
public:
    TArray<IRenderResource*> m_Resources;
};
