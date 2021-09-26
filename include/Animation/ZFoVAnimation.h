#pragma once

#include "NMP.h"

class ZGameTime;
template <class T> class TArrayRef;

class ZFoVAnimation
{
public:
	float* m_pFoVPerFrame;
	int m_nNumberOfFrames;
	int m_nFramesPerSecond;

	ZFoVAnimation() = default;
	~ZFoVAnimation() = default;
	static NMP::Memory::Format getMemoryRequirements(int numberOfFrames);
	static ZFoVAnimation* init(const NMP::Memory::Resource* memDesc, TArrayRef<float> aFoVPerFrame, int nFramesPerSecond);
	void locate();
	void dislocate();
	void restorePtrs();
	int GetNumberOfFrames() const;
	ZGameTime GetDuration() const;
	float EvaluateAtFrame(int nFrame);
	float EvaluateAtTime(const ZGameTime& animationTime);
};
