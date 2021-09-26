#pragma once

template <class T> class SSharedValueContainer;

template <class T>
class TSharedValue
{
public:
    SSharedValueContainer<T>* m_pValue;

    TSharedValue() = default;
    ~TSharedValue() = default;
};
