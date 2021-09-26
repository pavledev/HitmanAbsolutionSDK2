#pragma once

#include "TArray.h"

struct SFaceFXAnimationRef;
struct SSubtitleRef;

struct SWaveBankFXData
{
	TArray<SFaceFXAnimationRef> m_aFaceFXAnimationRefs;
	TArray<SSubtitleRef> m_aSubtitleRefs;

	SFaceFXAnimationRef* GetFaceFXAnimationRef(int i);
	SSubtitleRef* GetSubtitleRef(int i);
	SWaveBankFXData() = default;
	~SWaveBankFXData() = default;
};
