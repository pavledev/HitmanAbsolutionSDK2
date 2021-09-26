#pragma once

#include "MR.h"
#include "ESyncEvent.h"
#include "SQV.h"

class ZSPUAnimationLibrary;
class ZAnimationLibrary;
namespace NMP {
class DataBuffer;
}  // namespace NMP
struct SMatrix;

class ZCharacterControllerClip
{
public:
	MR::EventsSequenceTimeStretch m_eventSequenceTimeStretch;
	float m_fPrevAnimationTime;
	float m_fPrevTimeFraction;
	float m_fCurTimeFraction;
	float m_fDeltaTimeFraction;
	float m_fDuration;
	unsigned short m_clipIndex;
	bool m_bLoop;
	bool m_loopedOnLastUpdate;

	ZCharacterControllerClip() = default;
	bool operator==(const ZCharacterControllerClip& rhs) const;
	void Configure(const ZSPUAnimationLibrary* animationLibrary, const unsigned short clipIndex, unsigned int clipOffset, ESyncEvent syncEvent);
	void CopyFrom(const ZCharacterControllerClip& rhs);
	unsigned short GetCurrentClip() const;
	float GetDuration() const;
	const MR::EventsSequenceTimeStretch* GetEventSequence() const;
	void ResetTime();
	bool UpdateTime(float fDeltaTimeInSeconds);
	bool UpdateTime(MR::EventSeqPosition from, MR::EventSeqPosition to);
	bool UpdateTimeFractions(float fDeltaTimeFraction);
	void UpdateTimeFractionsInternal();
	int SampleEvents(float fWeight, MR::TriggeredEventsPool* pEventsPool, MR::TriggeredEventsBuffer* pEventsBuffer, const ZAnimationLibrary* animationLibrary) const;
	unsigned short QueueTransformBuffer(ZAnimationLibrary* animationLibrary, unsigned int priority) const;
	unsigned int GetEventUserData(unsigned int index) const;
	float GetTimeFraction() const;
	MR::EventSeqPosition GetSequencePosition() const;
	void GetTrajectoryAtTime(const ZSPUAnimationLibrary* animationLibrary, float fFraction, MR::AttribDataPosQuatChannel& trajectory) const;
	SMatrix GetTrajectoryAtTime(const ZSPUAnimationLibrary* animationLibrary, float fFraction) const;
	void GetTrajectoryDelta(const ZSPUAnimationLibrary* animationLibrary, MR::AttribDataPosQuatChannel& trajectoryDelta) const;
	void GetTransformBuffer(const ZAnimationLibrary* animationLibrary, NMP::DataBuffer* buffer) const;
	void GetTransformBufferAtFraction(const ZAnimationLibrary* animationLibrary, float fFraction, NMP::DataBuffer* buffer) const;
	~ZCharacterControllerClip() = default;
};
