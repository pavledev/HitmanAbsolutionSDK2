#pragma once

template <class T>
class TComponentPtr
{
public:
    T* m_pComponent;

    TComponentPtr() = default;
    ~TComponentPtr() = default;
};
