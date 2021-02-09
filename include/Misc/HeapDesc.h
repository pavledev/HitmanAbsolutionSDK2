#pragma once

class HeapDesc
{
public:
    unsigned int Flags;
    unsigned int MinAlign;
    unsigned int Granularity;
    unsigned int Reserve;
    unsigned int Threshold;
    unsigned int Limit;
    unsigned int HeapId;
    unsigned int Arena;
};
