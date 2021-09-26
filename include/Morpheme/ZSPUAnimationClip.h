#pragma once

#include "MR.h"
#include "EGait.h"
#include "ESpeed.h"
#include "ESyncEvent.h"

namespace NMP {
class DataBuffer;
class Quat;
class Vector3;
}  // namespace NMP

class ZSPUAnimationClip
{
public:
	unsigned short m_animSourceSize;
	unsigned short m_clipIndex;
	const MR::IAnimSource* m_ppuAnimSource;
	const MR::Rig* m_ppuRig;
	const MR::EventsSequenceDef* m_ppuSyncTrack;
	const MR::TrajectoryControlBase* m_ppuTrajectoryChannel;
	const MR::TrajectoryControlBase* m_spuTrajectoryChannel;
	unsigned short m_trajectorySize;
	unsigned short m_numSyncEvents;
	const char* m_ppuName;
	float m_fSampleFrequency;
	float m_fDurationInSeconds;
	EGait m_gait;
	ESpeed m_speed;
	bool m_bIsEnabled;
	unsigned char m_nOverrideStageFlags;
	bool m_bStartFromBeginning;
	bool m_bGenerateDeltaTransforms;
	bool m_bMirrored;
	ESyncEvent m_eFirstSyncEvent;

	ZSPUAnimationClip() = default;
	~ZSPUAnimationClip() = default;
	float getDuration() const;
	unsigned short getClipIndex() const;
	bool PlayToEnd() const;
	EGait getGait() const;
	ESpeed getSpeed() const;
	ESyncEvent getFirstSyncEvent() const;
	void updateEventSequence(MR::EventsSequenceTimeStretch& eventSequence, unsigned int clipOffset, ESyncEvent syncEvent) const;
	void getTrajectoryTransformAtFraction(float fFraction, NMP::Quat& trajectoryAtt, NMP::Vector3& trajectoryPos) const;
	void getTransformAtFraction(float fFraction, unsigned int rigIndex, NMP::Quat& channelAtt, NMP::Vector3& channelPos) const;
	void computeAtFraction(float fFraction, NMP::DataBuffer* buffer) const;
};
