#pragma once

struct SEffectParametersGlowParams
{
	unsigned long long TurbulenceOctaveOffset;
	unsigned long long TurbulenceScaleOffset;
	unsigned long long ColorOffset;
	unsigned long long InvertRimNormalOffset;
	unsigned int SVLW2;

	SEffectParametersGlowParams() = default;
	~SEffectParametersGlowParams() = default;
};
