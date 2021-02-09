#pragma once

#include "STypeIDStorage.h"
#include "STypeIDData.h"
#include "Function.h"
#include "BaseAddresses.h"

template<class T>
class TTypeIDHelper
{
public:
	static STypeIDStorage id;
	static STypeIDData data;

	static STypeID* GetTypeID(unsigned int offset)
	{
		return Function::CallAndReturn<STypeID*>(BaseAddresses::hitman5Dll + offset);
	}
};

template<class T>
STypeIDStorage TTypeIDHelper<T>::id;

template<class T>
STypeIDData TTypeIDHelper<T>::data;
