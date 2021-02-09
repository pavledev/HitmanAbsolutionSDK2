#pragma once

#include "IPhysicsObject.h"

class ZPhysicsObjectProxy
{
public:
    IPhysicsObject* m_pObj;
    unsigned int m_nNumRefs;

    enum UnkEnum : __int32
    {
        INITIAL_POOL_SIZE = 0x1F4
    };
};
