#pragma once

#include "IRenderMaterialEntity.h"

struct SFloatArrayModifer
{
    IRenderMaterialEntity::EModifierOperation m_eOperation;
    unsigned __int16 m_nOffset;
    unsigned __int16 m_nSize;
    unsigned __int16 m_Offset3;
    unsigned __int16 m_Index3;
};
