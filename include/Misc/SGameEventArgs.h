#pragma once

#include "EGameEventArgType.h"

class SGameEventArgs
{
public:
    EGameEventArgType m_eType;

    virtual ~SGameEventArgs();
};
