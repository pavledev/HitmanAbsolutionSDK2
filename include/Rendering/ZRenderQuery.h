#pragma once
#pragma warning(disable : 4005)

#include "SRenderQueryDesc.h"
#include <D3D11.h>

class ZRenderQuery
{
public:
    SRenderQueryDesc m_Description;
    ID3D11Query* m_pQueryD3D;
    ID3D11DeviceContext* m_pDeviceContext;

    virtual ~ZRenderQuery();
};
