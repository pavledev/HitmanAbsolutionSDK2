#pragma once

#include "NMP.h"

struct SFacePoseChannel;

struct SFacePoseFloatChannelCollection
{
	struct SFacePoseChannelInfo
	{
		char* pszPoseName;
		unsigned int nUid;
	};

	struct SFacePoseSectionInfo
	{
		unsigned char* pSection;
		unsigned int nSectionSize;
	};

	SFacePoseChannelInfo* m_pFacePoseChannels;
	SFacePoseSectionInfo* m_pFacePoseSectionInfos;
	unsigned int m_nSizeExcludingSections;
	unsigned short m_nFacePoseChannelCount;
	unsigned short m_nUncompressedPoseChannelSize;
	unsigned int m_nCompleteMemoryRequirements;

	SFacePoseFloatChannelCollection() = default;
	~SFacePoseFloatChannelCollection() = default;
	static NMP::Memory::Format GetMemoryRequirements(const NMP::BitArray& facePoseUsedChannels, int nChannelLength, int nNumChannels, const SFacePoseChannel* pChannels);
	static int GetFacePoseUsedChannelsCount(const NMP::BitArray& bitArray);
	static unsigned char* Init(unsigned char* pPlacement, const NMP::Memory::Format& format, const NMP::BitArray& facePoseUsedChannels, int nChannelLength, int nNumChannels, const SFacePoseChannel* pChannels);
	void Locate();
	void Dislocate();
	static void GetWeights(float* aWeights, unsigned int nFloatChannelCount, const unsigned char* pSection, int nSectionFrame);
	void Relocate(const void* pOldAddress, bool bRelocateNames);
	unsigned int GetMemoryRequirementsExcludingSections() const;
	unsigned int GetSectionIndex(unsigned int nFrame) const;
	unsigned int GetSectionFrameIndex(unsigned int nFrame) const;
	const unsigned char* GetSection(unsigned int nSectionIndex) const;
	unsigned int GetSectionSize(unsigned int nSectionIndex) const;
	const char* GetChannelName(unsigned int nChannelIndex) const;
	unsigned int GetChannelUid(unsigned int nChannelIndex) const;
};
