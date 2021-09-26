#pragma once

#include "TMaxArrayBase.h"

template <class T> struct ZMaxArrayRefData;

template <class T>
class TMaxArrayRef : public TMaxArrayBase<T, ZMaxArrayRefData<T>>
{
public:
	TMaxArrayRef() = default;
	~TMaxArrayRef() = default;
};
