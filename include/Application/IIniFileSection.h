#pragma once

#include "ZString.h"
#include "TEnumerator.h"

class __declspec(novtable) IIniFileSection
{
public:
	virtual ~IIniFileSection() = default;
	virtual ZString GetName() = 0;
	virtual ZString GetValue(const ZString& string) = 0;
	virtual TEnumerator<ZString> GetOptions() = 0;

	IIniFileSection() = default;
};
