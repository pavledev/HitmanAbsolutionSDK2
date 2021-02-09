#pragma once
#pragma warning(disable : 4005)

#include <D3D11.h>

struct SConstBufferImpl
{
    ID3D11Buffer* m_pBuffer;
    unsigned int m_nSize;
    SConstBufferImpl* pNext;
    unsigned __int16 m_nInternalSize;
    unsigned __int16 _nPad;
};
