#pragma once

#include "SVector3.h"
#include "ZGameTime.h"
#include "NMP.h"

struct SBoneScalesList;
template <class T> class TArrayRef;

class ZAnimatedBoneScales
{
public:
	SVector3* m_pBoneScales;
	int m_nNumberOfFrames;
	int m_nNumberOfChannels;
	int m_nFramesPerSecond;

	ZAnimatedBoneScales() = default;
	~ZAnimatedBoneScales() = default;
	static NMP::Memory::Format getMemoryRequirements(int numberOfFrames, int numberOfChannels);
	static ZAnimatedBoneScales* init(const NMP::Memory::Resource* memDesc, TArrayRef<SBoneScalesList> aBoneScales, int nFramesPerSecond);
	void locate();
	void dislocate();
	void restorePtrs();
	int GetNumberOfFrames() const;
	int GetNumberOfChannels() const;
	ZGameTime GetDuration() const;
	SVector3 EvaluateAtFrame(int nBoneIndex, int nFrame) const;
	SVector3 EvaluateAtTime(int nBoneIndex, const ZGameTime& animationTime) const;
};
