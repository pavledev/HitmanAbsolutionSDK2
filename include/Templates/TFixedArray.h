#pragma once

#include "TFixedArrayBase.h"
#include "ZFixedArrayData.h"

template<class A, int B>
class TFixedArray : TFixedArrayBase<A, ZFixedArrayData<A, B>>
{

};
