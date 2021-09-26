#pragma once

template <class T>
class TEnumeratorBase
{
public:
    T* m_pCurrent;
    T* m_pEnd;

    TEnumeratorBase() = default;
    ~TEnumeratorBase() = default;
};
