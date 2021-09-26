#pragma once

#include "ZEvent2.h"

template <class A, class B, class C, class D, class E>
class ZEvent : public ZEvent2<A, B>
{
public:
	ZEvent() = default;
	~ZEvent() = default;
};
