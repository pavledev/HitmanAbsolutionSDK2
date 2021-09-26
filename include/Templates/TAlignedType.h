#pragma once

template <int T>
class alignas(T) TAlignedType
{
public:
    char dummy;

    TAlignedType() = default;
    ~TAlignedType() = default;
};
