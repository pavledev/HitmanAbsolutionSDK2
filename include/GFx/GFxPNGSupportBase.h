#pragma once

#include "GFxState.h"
#include "GImage.h"
#include "GFile.h"
#include "GMemoryHeap.h"

class __declspec(novtable) GFxPNGSupportBase : public GFxState
{
public:
	~GFxPNGSupportBase() override = default;
	virtual GImage* CreateImage(GFile* file, GMemoryHeap* memoryHeap) = 0;

	GFxPNGSupportBase() = default;
};
