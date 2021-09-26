#pragma once

#include "TSharedPointer.h"

class ZResourceReader;

class ZWaveBankFSBData
{
public:
	TSharedPointer<ZResourceReader> m_pReader;
	const void* m_pSoundData;
	unsigned int m_nSoundSize;

	ZWaveBankFSBData() = default;
	ZWaveBankFSBData(TSharedPointer<ZResourceReader> pReader, const void* pSoundData, unsigned int nSoundSize);
	~ZWaveBankFSBData() = default;
	const void* GetFSBData();
	unsigned int GetSoundSize() const;
};
