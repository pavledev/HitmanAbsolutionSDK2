#pragma once

#include "TResourcePtr.h"
#include "SColorRGB.h"
#include "SVector2.h"

class ZRenderMaterialInstance;

struct SDecalCreationContext
{
	TResourcePtr<ZRenderMaterialInstance> m_Material;
	SColorRGB m_Color;
	float m_fAlpha;
	float m_fAngle;
	SVector2 m_vUVOffset;
	SVector2 m_vTiling;

	SDecalCreationContext() = default;
	~SDecalCreationContext() = default;
};
