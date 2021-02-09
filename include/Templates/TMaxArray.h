#pragma once

#include "TMaxArrayBase.h"
#include "ZMaxArrayData.h"

template <class A, int B>
class TMaxArray : public TMaxArrayBase<A, ZMaxArrayData<A, B>>
{

};