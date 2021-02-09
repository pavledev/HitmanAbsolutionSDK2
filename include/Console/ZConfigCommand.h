#pragma once

#include "ZString.h"

class ZConfigCommand
{
public:
    const char* m_pszName;
    ZConfigCommand* m_pNext;

    enum ECLASSTYPE : __int32
    {
        ECLASS_FLOAT = 0x0,
        ECLASS_INT = 0x1,
        ECLASS_STRING = 0x2,
        ECLASS_UNKNOWN = 0x3
    };

    virtual ECLASSTYPE GetType();
    virtual void Execute(const unsigned int, const char**) = 0;

    ZConfigCommand* Next();
    ZString* Name(ZString* result);
    static ZConfigCommand* First();
    ZConfigCommand(char* pszName);
    static void ExecuteCommand(ZString* pCommandName, char* argv);
    static ZConfigCommand* GetConfigVariable(ZString* pszName);
};
