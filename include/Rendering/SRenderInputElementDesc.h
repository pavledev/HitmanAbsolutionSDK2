#pragma once

#include "ERenderInputElement.h"
#include "ERenderInputClassification.h"
#include "ERenderFormat.h"

struct SRenderInputElementDesc
{
	unsigned char nOffset;
	ERenderFormat eFormat : 8;
	ERenderInputElement eElement : 8;
	unsigned char nElementIndex;
	unsigned char nStreamIndex;
	ERenderInputClassification eClassification : 8;
	unsigned short nInstanceDataStepRate;

	SRenderInputElementDesc() = default;
	~SRenderInputElementDesc() = default;
};
