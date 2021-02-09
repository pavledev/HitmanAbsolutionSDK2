#pragma once

class ZCyclicBuffer
{
public:
    char* m_pBuffer;
    int m_iBufferSize;
    int m_iFirst;
    int m_iCount;
    int m_iStart;
    int m_iEnd;

    virtual ~ZCyclicBuffer();

    ZCyclicBuffer(int iBufferSize);
    void FreeSpace();
    void* Alloc(int iSize);
    int Count();
    int Last();
    int First();
    void* Get(int iNr);
    int SpaceFree();
};
