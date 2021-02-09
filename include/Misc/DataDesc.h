#pragma once

struct alignas(4) DataDesc
{
    unsigned int Size;
    volatile int RefCount;
    char Data[1];
};
