#pragma once

template <class T>
class TIterator
{
public:
    T* m_pCurrent;

    TIterator() = default;
    ~TIterator() = default;
};
