#pragma once

#include "IHM5OSD.h"

class IHM5OSDDisplay
{
public:
	virtual void Update(IHM5OSD*);
	virtual ~IHM5OSDDisplay();
};
