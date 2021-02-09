#pragma once
#pragma warning(disable : 4005)

#include <D3D11.h>

struct __declspec(align(4)) BinkDrawData
{
    ID3D11ShaderResourceView* m_Yview;
    ID3D11ShaderResourceView* m_cRview;
    ID3D11ShaderResourceView* m_cBview;
    ID3D11ShaderResourceView* m_Aview;
    unsigned int m_width;
    unsigned int m_height;
    float m_fAlpha_level;
    __int8 m_bIs_premultiplied_alpha : 1;
    __int8 m_bHasAlpha : 1;
};
