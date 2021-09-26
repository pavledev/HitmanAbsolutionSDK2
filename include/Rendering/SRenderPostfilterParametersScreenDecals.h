#pragma once

#include "SRenderPostfilterParametersBase.h"
#include "SVector3.h"
#include "SVector2.h"
#include "ZResourcePtr.h"

struct SRenderPostfilterParametersScreenDecals : SRenderPostfilterParametersBase
{
	float m_fTimeToLive;
	float m_fSettleTime;
	float m_fFadeTime;
	float m_fScaleTime;
	float m_fOpacity;
	float m_fRefractionScale;
	float m_fBlurrinessScale;
	float m_fColorScale;
	SVector3 m_vColor;
	SVector2 m_vTiles;
	SVector3 m_vSizes[3];
	ZResourcePtr m_pTextureResources[3];

	SRenderPostfilterParametersScreenDecals(const SRenderPostfilterParametersScreenDecals& __that);
	SRenderPostfilterParametersScreenDecals() = default;
	~SRenderPostfilterParametersScreenDecals() = default;
	SRenderPostfilterParametersScreenDecals& operator=(const SRenderPostfilterParametersScreenDecals& __that);
};
