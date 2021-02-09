#pragma once

#include "ISharedPointerTarget.h"

class ZSharedPointerTarget : public ISharedPointerTarget
{
public:
    int m_iRefCount;
};
