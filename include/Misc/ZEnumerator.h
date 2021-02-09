#pragma once

#include "ZGridNodeRef.h"

class ZEnumerator
{
public:
    const ZGridNodeRef* m_Me;
    ZGridNodeRef m_Current;
    int m_nCurrentDirection;
};