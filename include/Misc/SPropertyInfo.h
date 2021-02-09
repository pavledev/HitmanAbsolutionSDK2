#pragma once

#include "STypeID.h"

struct SPropertyInfo
{
    STypeID* m_Type;
    unsigned int m_nExtraData;
    unsigned int m_Flags;

    void m_PropertySetCallBack(void*, void*, unsigned int, bool);
    void m_PropetyGetter(void*, void*, unsigned int);
};
