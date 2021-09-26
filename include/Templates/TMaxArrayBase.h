#pragma once

#include "TArrayIterator.h"

template <class A, class B>
class TMaxArrayBase : public B
{
public:
    unsigned int m_nSize;

    TMaxArrayBase() = default;
    ~TMaxArrayBase() = default;

    TArrayIterator<A> Begin()
    {
        TArrayIterator<A> arrayIterator;
        arrayIterator->m_pCurrent = reinterpret_cast<A*>(this);

        return arrayIterator;
    }

    TArrayIterator<A> End()
    {
        TArrayIterator<A> arrayIterator;
        arrayIterator->m_pCurrent = (A*)((char*)this + sizeof(A) * this->m_nSize);

        return arrayIterator;
    }

    unsigned int Size()
    {
        return this->m_nSize;
    }

    A* operator[](unsigned int nIndex)
    {
        return (A*)((char*)this + sizeof(A) * nIndex);
    }
};