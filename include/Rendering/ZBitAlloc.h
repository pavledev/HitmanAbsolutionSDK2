#pragma once

class ZBitAlloc
{
public:
    unsigned __int64* m_pChunks;
    unsigned int m_nUsed;
    unsigned int m_nSlots;
    unsigned int m_nChunks;
};
