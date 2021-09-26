#pragma once

#include "STypeIDStorage.h"
#include "STypeIDData.h"
#include "Function.h"

struct STypeID;

template <class T>
struct TTypeIDHelper
{
	inline static STypeIDStorage id;
	inline static STypeIDData data;

	TTypeIDHelper() = default;
	~TTypeIDHelper() = default;

	static unsigned int TypeIDOffset();

	static STypeID* GetTypeID()
	{
		return Function::CallAndReturn<STypeID*>(TypeIDOffset());
	}
};
