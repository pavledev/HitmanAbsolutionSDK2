#pragma once

#include "STypeID.h"

struct STypeIDData
{
	STypeID id;
	const char* (*pFunc)(STypeID* typeID);

	STypeIDData() = default;
	~STypeIDData() = default;
};
