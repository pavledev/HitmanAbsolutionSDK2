#pragma once

#include "ESoundPlayParameters.h"
#include "TArray.h"

class ZSoundSelector
{
public:
	struct SLayerRepeatCountLimit
	{
		unsigned char nLayerIndex;
		unsigned char nRepeatLimit;

		bool operator==(const SLayerRepeatCountLimit& rhs);
	};

	ESoundPlayParameters m_eSelectionMode;
	int m_nNoRepeatsCount;
	TArray<SLayerRepeatCountLimit> m_aSubSoundRepeatCounts;
	int m_nSubsoundCount;
	unsigned int m_nLastPlayed;
	TArray<unsigned char> m_aLastPlayed;
	int m_nShuffleIndex;

	ZSoundSelector(const ZSoundSelector& __that);
	ZSoundSelector() = default;
	void SetNoRepeatsCount(int nNoRepeatsCount);
	void SetSelectionMode(ESoundPlayParameters selectionMode);
	void AddSubSoundRepeatCount(unsigned char nSubSoundIndex, unsigned char nRepeatCount);
	int GetNextSubsound(int subSoundCount);
	void Shuffle();
	~ZSoundSelector() = default;
};
