#pragma once

#include "TFixedArrayBase.h"
#include "ZArrayRefData.h"

template<class T>
class TArrayRef : TFixedArrayBase<T, ZArrayRefData<T>>
{

};
