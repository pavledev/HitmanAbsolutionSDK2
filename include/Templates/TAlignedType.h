#pragma once

template<int T>
struct __declspec(align(T)) TAlignedType
{
    char dummy;
};
