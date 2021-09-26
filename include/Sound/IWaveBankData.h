#pragma once

#include "ZRuntimeResourceID.h"

struct SWaveBankFXData;
template <class T> class TResourcePtr;

class __declspec(novtable) IWaveBankData
{
public:
	virtual const TResourcePtr<SWaveBankFXData>& GetFXResource() const = 0;
	virtual ZRuntimeResourceID GetRuntimeResourceID() const = 0;
	virtual bool IsNotDucking() const = 0;
	virtual ~IWaveBankData() = default;

	IWaveBankData() = default;
};
