#pragma once

#include "TArray.h"
#include "IAsyncRayHandle.h"

struct SSoundVolumetricOcclusionData
{
	TArray<IAsyncRayHandle*> m_pRayQueryHandle;
	TArray<ZRayQueryOutput> m_pRayQueryOutput;

	SSoundVolumetricOcclusionData() = default;
	~SSoundVolumetricOcclusionData() = default;
};
