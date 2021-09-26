#pragma once

#include "TEnumeratorBase.h"

class IEnumeratorImpl;

template <class T>
class TEnumerator : public TEnumeratorBase<T>
{
public:
    IEnumeratorImpl* m_pEnumeratorImpl;

    TEnumerator() = default;
    ~TEnumerator() = default;
};
