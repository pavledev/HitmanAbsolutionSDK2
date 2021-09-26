#pragma once

template <class T>
struct THashSetNode
{
    int m_iNext;
    T m_data;

    THashSetNode() = default;
    ~THashSetNode() = default;
};
