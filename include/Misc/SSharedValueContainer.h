#pragma once

template<class T>
class SSharedValueContainer
{
public:
    unsigned int m_nRefCount;
    T m_value;
};
