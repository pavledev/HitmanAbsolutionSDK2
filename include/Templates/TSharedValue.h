#pragma once

#include "SSharedValueContainer.h"

template<class T>
class TSharedValue
{
public:
    SSharedValueContainer<T>* m_pValue;
};
