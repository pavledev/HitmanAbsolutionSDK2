#pragma once

template <class A, int B>
class alignas(16) TArrayFixedHeap
{
public:
    struct ZElement
    {
        char m_memory[sizeof(A)];
    };

    ZElement m_memory[B];
    void** m_pFreeElement;

    TArrayFixedHeap() = default;
    ~TArrayFixedHeap() = default;

    A* operator[](unsigned int nIndex)
    {
        return (A*)((char*)this + sizeof(A) * nIndex);
    }
};
