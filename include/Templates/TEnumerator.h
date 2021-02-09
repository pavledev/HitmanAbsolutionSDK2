#pragma once

#include "TEnumeratorBase.h"
#include "IEnumeratorImpl.h"

template<class T>
class TEnumerator : TEnumeratorBase<T>
{
public:
    IEnumeratorImpl* m_pEnumeratorImpl;
};
