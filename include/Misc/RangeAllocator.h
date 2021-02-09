#pragma once
#include "IAllocator.h"

class RangeAllocator
{
public:
    unsigned int m_start;
    unsigned int m_size;
    unsigned int m_capacity;
    unsigned int m_pageSize;
    unsigned int m_firstPage;
    unsigned int m_minBlockSize;

    /*class Block
    {
        unsigned int m_start;

        union
        {
            unsigned int m_padding;
            Block* m_nextFree;
        };

        Block* m_prev;
        Block* m_next;
        Block* m_prevFree;
    }* m_first;

    class Block
    {
        unsigned int m_start;

        union
        {
            unsigned int m_padding;
            Block* m_nextFree;
        };

        Block* m_prev;
        Block* m_next;
        Block* m_prevFree;
    }* m_last;

    class Block
    {
        unsigned int m_start;

        union
        {
            unsigned int m_padding;
            Block* m_nextFree;
        };

        Block* m_prev;
        Block* m_next;
        Block* m_prevFree;
    }* m_firstFree;

    class Block
    {
        unsigned int m_start;

        union
        {
            unsigned int m_padding;
            Block* m_nextFree;
        };

        Block* m_prev;
        Block* m_next;
        Block* m_prevFree;
    }* m_pageBounds;*/

    class Block
    {
        unsigned int m_start;

        union
        {
            unsigned int m_padding;
            Block* m_nextFree;
        };

        Block* m_prev;
        Block* m_next;
        Block* m_prevFree;
    }*m_first, * m_last, * m_firstFree, * m_pageBounds;

    IAllocator* m_pBlockAllocator;
};
