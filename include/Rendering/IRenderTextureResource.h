#pragma once

#include "IRenderRefCount.h"
#include "TArray.h"

class IRenderResource;

class IRenderTextureResource : public IRenderRefCount
{
public:
	TArray<IRenderResource*> m_Resources;

	~IRenderTextureResource() override = default;

	unsigned int GetSequenceLength() const;
	IRenderTextureResource() = default;
};
