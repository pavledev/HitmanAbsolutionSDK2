#pragma once

#include "ZEntityImpl.h"
#include "IValueEntity.h"

class ZHM5ValueReceiver_Base : public ZEntityImpl, public IValueEntity
{
public:
	virtual void OnGet();
};
