#pragma once

#include "TSharedPointer.h"
#include "ISharedPointerTarget.h"

class ZThreadEvent
{
public:
    TSharedPointer<ISharedPointerTarget> m_pImpl;
};
