#pragma once

template <class T>
class TArray
{
public:
    T* m_pStart;
    T* m_pEnd;
    T* m_pLast;

    int Size()
    {
        return this->m_pEnd - this->m_pStart;
    }

    T* operator[](unsigned int nIndex)
    {
        return &this->m_pStart[nIndex];
    }
};
