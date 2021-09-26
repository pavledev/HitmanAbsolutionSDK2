#pragma once

#include "ZCharacterControllerClip.h"
#include "ESyncEvent.h"
#include "MR.h"
#include "SQV.h"

class ZAnimationLibrary;
class ZSPUAnimationLibrary;
namespace NMP {
class DataBuffer;
}  // namespace NMP

class ZCharacterControllerBlender
{
public:
	ZCharacterControllerClip m_clip0;
	ZCharacterControllerClip m_clip1;
	float m_fBlendWeight;
	ESyncEvent m_syncEventSemantic;
	MR::EventSeqPosition m_syncEventPosition;
	bool m_bBlend;
	bool m_bLoopedOnLastUpdate;

	ZCharacterControllerBlender() = default;
	~ZCharacterControllerBlender() = default;
	void Configure(const ZSPUAnimationLibrary* animationLibrary, const unsigned short clipIndex);
	void KeepCurrentAnimation();
	bool BeginUpdate(const ZSPUAnimationLibrary* animationLibrary);
	bool UpdateTime(float fDeltaTimeInSeconds, bool& pAllowAnimChange);
	MR::EventSeqPosition GetCurrentClipSequencePosition() const;
	unsigned short GetCurrentClip() const;
	unsigned short GetNextClip() const;
	unsigned short GetClip0() const;
	unsigned short GetClip1() const;
	float GetBlendWeight() const;
	bool GetBlend() const;
	MR::EventSeqPosition GetSyncEventPosition() const;
	void SetBlendWeight(float fBlendWeight);
	bool HasLoopedOnLastUpdate() const;
	SQV GetTrajectoryDelta(const ZSPUAnimationLibrary* animationLibrary) const;
	ESyncEvent GetSyncEventSemantic() const;
	void GetTransformBuffer(const ZAnimationLibrary* animationLibrary, NMP::DataBuffer* buffer) const;
	unsigned short QueueTransformBuffer(ZAnimationLibrary* animationLibrary, unsigned int priority, unsigned int maxBlendPriority) const;
	bool CanQueueTransformBuffer() const;
	int SampleEvents(MR::TriggeredEventsPool* pEventsPool, MR::TriggeredEventsBuffer* pEventsBuffer, const ZAnimationLibrary* animationLibrary) const;
	float IncrementTimeFraction(float fractionFrom, float deltaTimeFraction);
};
