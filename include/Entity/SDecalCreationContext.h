#pragma once

#include "TResourcePtr.h"
#include "ZRenderMaterialInstance.h"
#include "SColorRGB.h"

class SDecalCreationContext
{
public:
    TResourcePtr<ZRenderMaterialInstance> m_Material;
    SColorRGB m_Color;
    float m_fAlpha;
    float m_fAngle;
    SVector2 m_vUVOffset;
    SVector2 m_vTiling;
};
