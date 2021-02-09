#pragma once

#include "ZDelegate.h"

class alignas(8) ZThread
{
public:
    ZDelegate<unsigned int __cdecl(void*)> m_function;
    int m_handle;
    ZString m_sName;
    unsigned int m_nExitCode;
    int m_nStackSize;
    unsigned __int8 m_nJoinState;
};
