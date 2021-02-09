#pragma once

#include "STypeID.h"

class ZObjectRef
{
public:
    STypeID* m_TypeID;
    void* m_pData;
};
