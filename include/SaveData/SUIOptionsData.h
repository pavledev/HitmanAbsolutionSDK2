#pragma once

#include "TArray.h"

struct SUIOptionValue;

struct SUIOptionsData
{
	TArray<SUIOptionValue> data;

	SUIOptionsData(const SUIOptionsData& __that);
	SUIOptionsData() = default;
	~SUIOptionsData() = default;
	SUIOptionsData& operator=(const SUIOptionsData& __that);
};
