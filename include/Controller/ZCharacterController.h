#pragma once

#include "ZCharacterControllerBlender.h"
#include "SVector4.h"
#include "EGait.h"
#include "ESpeed.h"
#include "MR.h"
#include "SQV.h"
#include "SVector3.h"
#include "ZCharacterControllerClip.h"
#include "float4.h"

class ZAnimationLibrary;
class ZSPUAnimationLibrary;
struct SCutSequenceData;
struct SMatrix;
template <class T> class TArray;
template <class T> class TArrayRef;

class ZCharacterController
{
public:
	ZCharacterControllerBlender m_blender;
	unsigned short m_nTransitionToIndex;
	unsigned short m_nPreferredClipIndex;
	ZCharacterControllerClip m_partialAnimationClip;
	float m_nPartialAnimBlendTime;
	float m_nPartialAnimationPlayWeight;
	SQV m_trajectoryDelta;
	MR::EventSeqPosition m_footstepEvent;
	float m_fSequenceFraction;
	float m_fCutSequenceWeight;
	float m_fTimeModifier;
	float m_fTimeToFirstOverride;
	SVector4 m_vLookAtIKTarget;
	unsigned int m_nOverrideClipFlags;
	unsigned char m_nOverrideStage;
	bool m_bAllowOverrides;
	unsigned short m_nSequenceClipIndex;
	SVector3 m_desiredHeading;
	SVector3 m_desiredFacing;
	unsigned char m_desiredGait : 3;
	unsigned char m_desiredSpeed : 3;
	unsigned char m_bUseCutSequenceData : 1;

	ZCharacterController() = default;
	void SetDesiredGait(EGait desiredGait);
	void SetDesiredSpeed(ESpeed desiredSpeed);
	void SetDesiredHeading(const float4& normalizedDirection);
	void SetDesiredFacing(const float4& normalizedDirection);
	void SetDesiredState(EGait desiredGait, ESpeed desiredSpeed, const float4& normalizedHeading, const float4& normalizedFacing);
	void ClearPreferredClip();
	void SetAllowOverrides(bool bAllowOverrides);
	void SetOverrideStage(unsigned char nStage);
	unsigned char GetOverrideStage() const;
	unsigned short SetCutSequenceData(unsigned short nClipIndex, const SCutSequenceData& data);
	void SetCutSequenceWeight(float fWeight);
	void ClearCutSequenceData();
	void SetLookAtIKTarget(const float4& vTarget);
	void PlayPartialAnimation(const ZAnimationLibrary* animationLibrary, unsigned short clipIndex, float nPlayWeight, float nBlendTime);
	float GetPartialAnimationPlayWeight() const;
	unsigned short GetPartialAnimationClipIndex() const;
	EGait GetDesiredGait() const;
	ESpeed GetDesiredSpeed() const;
	float4 GetDesiredHeading() const;
	float4 GetDesiredFacing() const;
	unsigned short GetCurrentClip() const;
	unsigned short GetNextClip() const;
	unsigned short GetClip0() const;
	unsigned short GetClip1() const;
	float GetBlendWeight() const;
	bool GetBlend() const;
	void SetAnimationOverrideClipFlags(unsigned int clipFlags);
	SQV Update(const ZSPUAnimationLibrary* animationLibrary, const SMatrix& objectToWorldTransform, float fDeltaTimeInSeconds);
	SQV GetTrajectoryDelta() const;
	int SampleEvents(MR::TriggeredEventsPool* pEventsPool, MR::TriggeredEventsBuffer* pEventsBuffer, const ZAnimationLibrary* animationLibrary) const;
	void FillBoneCache(const ZAnimationLibrary* animationLibrary, TArrayRef<SQV> boneCache, const TArray<int>& meshIDToRigID, const TArrayRef<int>& meshHierarchy, const TArrayRef<SQV const> meshBindPose) const;
	unsigned short QueueTransformBuffer(ZAnimationLibrary* animationLibrary, unsigned short meshRigIndex, unsigned int priority, unsigned int maxBlendPriority) const;
	unsigned short FindNextBestClip(const SMatrix& objectToWorldTransform, const ZSPUAnimationLibrary* animationLibrary, bool& pAllowAnimationChange, SVector4& additionalRotation) const;
	unsigned short FindTransitionClip(const SMatrix& objectToWorldTransform, unsigned short nextClipIndex, const ZSPUAnimationLibrary* animationLibrary, bool& pAllowAnimationChange, SVector4& additionalRotation) const;
	~ZCharacterController() = default;
};
