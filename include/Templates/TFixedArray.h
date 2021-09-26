#pragma once

#include "TFixedArrayBase.h"
#include "ZFixedArrayData.h"

class IContainerType;
struct STemplatedTypeName1;

template <class A, int B>
class TFixedArray : public TFixedArrayBase<A, ZFixedArrayData<A, B>>
{
public:
	static STemplatedTypeName1 s_typeName;
	static IContainerType s_typeInfo;

	TFixedArray() = default;
	~TFixedArray() = default;
};
