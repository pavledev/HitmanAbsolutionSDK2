#pragma once

#include "HeapDesc.h"

class GMemoryHeap;

class HeapInfo
{
public:
    HeapDesc Desc;
    GMemoryHeap* pParent;
    char* pName;
};
