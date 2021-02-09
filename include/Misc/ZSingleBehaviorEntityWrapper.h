#pragma once

#include "ZBehaviorEntityBase.h"

class ZSingleBehaviorEntityWrapper : public ZBehaviorEntityBase
{
public:
    SBehaviorBase* m_pBehavior;
};
