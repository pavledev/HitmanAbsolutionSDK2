#pragma once
#include <winnt.h>

class GLock
{
public:
    _RTL_CRITICAL_SECTION cs;

    class Locker
    {
    public:
        GLock* pLock;
    };
};
