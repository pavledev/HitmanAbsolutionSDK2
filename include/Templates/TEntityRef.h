#pragma once

#include "ZEntityRef.h"

template<class T>
class TEntityRef
{
public:
    ZEntityRef m_entityRef;
    T* m_pInterfaceRef;
};
