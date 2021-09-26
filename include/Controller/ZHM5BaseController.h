#pragma once

#include "EHM5BaseControllerType.h"
#include "EHM5ResetReason.h"

struct SHM5ControllerUpdateEvent;

class ZHM5BaseController
{
public:
	EHM5BaseControllerType m_eType;

	virtual ~ZHM5BaseController() = default;
	virtual void Update(const SHM5ControllerUpdateEvent& HM5ControllerUpdateEvent);
	virtual void Reset(EHM5ResetReason eResetReason);

	ZHM5BaseController() = default;
	ZHM5BaseController(EHM5BaseControllerType eType);
};
