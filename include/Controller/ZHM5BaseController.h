#pragma once

#include "EHM5BaseControllerType.h"
#include "SHM5ControllerUpdateEvent.h"

class ZHM5BaseController
{
public:
    EHM5BaseControllerType m_eType;

    virtual ~ZHM5BaseController();
    virtual void Update(const SHM5ControllerUpdateEvent*);
    virtual void Reset(EHM5ResetReason);
};
