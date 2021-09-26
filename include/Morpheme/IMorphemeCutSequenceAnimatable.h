#pragma once

#include "SMatrix43.h"

class ISequenceEntity;
class ZEvent0;
class ZString;
struct SCutSequenceData;

class __declspec(novtable) IMorphemeCutSequenceAnimatable
{
public:
	virtual void CutSequenceStarted(ISequenceEntity* sequenceEntity, const ZString& string, float param3) = 0;
	virtual void CutSequenceUpdate(ISequenceEntity* sequenceEntity, ZString string, float param3) = 0;
	virtual SMatrix43 CutSequenceGetWorldTransform() = 0;
	virtual void CutSequenceSetWorldTransform(const SMatrix43& matrix43) = 0;
	virtual SMatrix43 CutSequenceGetParentTransform() = 0;
	virtual void CutSequenceSetParentTransform(const SMatrix43& matrix43) = 0;
	virtual void CutSequenceEnded(ISequenceEntity* sequenceEntity, ZString string) = 0;
	virtual ZEvent0& GetAnimatableChangedEvent() = 0;
	virtual void AbortCutSequence() = 0;
	virtual bool SetCutSequenceData(ISequenceEntity* sequenceEntity, const SCutSequenceData& cutSequenceData, const ZString& string, float param4) = 0;
	virtual ~IMorphemeCutSequenceAnimatable() = default;

	static void RegisterType();
	IMorphemeCutSequenceAnimatable() = default;
};
