#pragma once

#include "SRenderPostfilterParametersBase.h"
#include "SVector4.h"
#include "SVector2.h"

struct SVector3;

struct SRenderPostfilterParametersFog : SRenderPostfilterParametersBase
{
	enum
	{
		NUM_PERLIN_OCTAVES = 4
	};

	bool m_bUseQuarterRes;
	bool m_bFogBeforePostEffects;
	bool m_bGlobal;
	float m_fDensity;
	SVector4 m_vColor;
	SVector4 m_vTurbulenceOctaveVelocity[4];
	SVector4 m_vFogTurbulenceData;
	SVector2 m_vFogNearDistance;

	SRenderPostfilterParametersFog() = default;
	~SRenderPostfilterParametersFog() = default;
	float* FogTurbulenceOpacity();
	SVector3* FogTurbulenceScale();
	SVector2* FogNearDistance();
	void Lerp(const SRenderPostfilterParametersFog& source, const SRenderPostfilterParametersFog& target, float fLerp, unsigned int nLerpState);
};
