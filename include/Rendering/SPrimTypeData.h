#pragma once

#include "ZRenderInputLayout.h"
#include "ERenderFormat.h"

struct SPrimTypeData
{
    ZRenderInputLayout* m_pInputLayout;
    unsigned int m_nPrimTypeToVertexTypeMapping;
    ERenderFormat m_ePositionFormat;
    ERenderFormat m_eColorFormat;
};
