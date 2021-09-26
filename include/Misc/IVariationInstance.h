#pragma once

#include "MR.h"

class ZString;

class __declspec(novtable) IVariationInstance
{
public:
	virtual ~IVariationInstance() = default;
	virtual MR::IAnimSource* GetAnimSource(const ZString& string) = 0;

	IVariationInstance() = default;
};
