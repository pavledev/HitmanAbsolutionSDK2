#pragma once
#pragma warning(disable : 4005)

#include <D3D11.h>

struct SBinding
{
    ID3D11InputLayout* m_pInputLayout;
    unsigned __int8* m_pIAInputSignature;
    unsigned int m_nIAInputSignatureSize;
};
