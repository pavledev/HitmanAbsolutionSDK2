#pragma once

#include "STypeFunctions.h"
#include "ZString.h"

struct STypeID;

struct IType
{
    STypeFunctions* m_pTypeFunctions;
    unsigned __int16 m_nTypeSize;
    char m_nTypeAlignment;
    char m_nTypeInfoFlags;
    const char* pszTypeName;
    STypeID* typeID;

    bool fromString(void*, IType*, ZString*);
    unsigned int toString(const void*, IType*, char*, unsigned int, ZString*);
};
