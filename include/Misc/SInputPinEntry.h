#pragma once

#include "SPinInfo.h"

struct SInputPinEntry
{
	unsigned int m_nPinID;
	SPinInfo m_InputPinInfo;

	SInputPinEntry() = default;
	~SInputPinEntry() = default;
};
