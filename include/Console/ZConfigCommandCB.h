#pragma once

#include "ZConfigCommand.h"

class ZConfigCommandCB : public ZConfigCommand
{
public:
    void* m_pUserData;
    void(__cdecl* m_pCallBack)(ZString, const unsigned int, const char**, void*);
};
