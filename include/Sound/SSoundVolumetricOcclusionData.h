#pragma once

#include "TArray.h"
#include "IAsyncRayHandle.h"

class SSoundVolumetricOcclusionData
{
public:
    TArray<IAsyncRayHandle*> m_pRayQueryHandle;
    TArray<ZRayQueryOutput> m_pRayQueryOutput;
};
