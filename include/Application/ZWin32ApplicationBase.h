#pragma once

#include "ZWin32ApplicationStub.h"

class ZWin32ApplicationBase : public ZWin32ApplicationStub
{
public:
    ZMutex m_exceptionMutex;
};
