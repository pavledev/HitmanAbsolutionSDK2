#pragma once

template<class A, int B>
class alignas(16) TArrayFixedHeap
{
public:
    struct ZElement
    {
        char m_memory[sizeof(A)];
    } m_memory[B];

    void** m_pFreeElement;
};
