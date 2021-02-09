#pragma once

#include "MR.h"

class IVariationInstance
{
public:
	virtual ~IVariationInstance();
	virtual MR::IAnimSource* GetAnimSource(const ZString*);
};
