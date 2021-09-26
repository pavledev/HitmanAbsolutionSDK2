#pragma once

template <class T>
struct ZArrayRefData
{
    T* m_pStart;
    T* m_pEnd;

    ZArrayRefData() = default;
    ~ZArrayRefData() = default;
};
