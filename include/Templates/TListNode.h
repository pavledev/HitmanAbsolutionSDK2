#pragma once

template<class T>
class TListNode
{
public:
    TListNode<T>* m_pNext;
    TListNode<T>* m_pPrevious;
    T m_data;

    TListNode() = default;
    ~TListNode() = default;
};
