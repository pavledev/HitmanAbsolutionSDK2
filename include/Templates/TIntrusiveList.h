#pragma once

template <class A, class B>
class TIntrusiveList
{
public:
    A* m_pFirst;
    A* m_pLast;

    TIntrusiveList() = default;
    ~TIntrusiveList() = default;
};
