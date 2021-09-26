#pragma once

#include "TRefCountPtr.h"

class ZSoundPlayerCallbackExtraData
{
public:
	void* m_pAnimSetSourceStart;
	unsigned int m_nAnimSetSizeTotal;
	unsigned int m_nRefCount;

	ZSoundPlayerCallbackExtraData() = default;
	static TRefCountPtr<ZSoundPlayerCallbackExtraData> Create(unsigned int _nAnimSetSize);
	~ZSoundPlayerCallbackExtraData() = default;
	void AddRef();
	void Release();
	void GetAnimSetInfo(unsigned int nAnimSetIndex, void** pAnimSetSource, unsigned int& nDataSize) const;
	static void TraceAllocations();
	static unsigned int GetActiveObjectCount();
	ZSoundPlayerCallbackExtraData(unsigned int _nAnimSetSize);
};
