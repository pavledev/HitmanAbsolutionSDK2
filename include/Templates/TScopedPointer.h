#pragma once

template <class T>
class TScopedPointer
{
public:
    T* m_pObject;

    TScopedPointer() = default;
    ~TScopedPointer() = default;
};
