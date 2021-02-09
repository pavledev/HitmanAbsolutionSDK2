#pragma once

#include "SMatrix43.h"
#include "ZEvent0.h"
#include "SCutSequenceData.h"

class IMorphemeCutSequenceAnimatable
{
public:
    virtual void CutSequenceStarted(ISequenceEntity*, const ZString*, float);
    virtual void CutSequenceUpdate(ISequenceEntity*, ZString, float);
    virtual SMatrix43* CutSequenceGetWorldTransform(SMatrix43* result);
    virtual void CutSequenceSetWorldTransform(const SMatrix43*);
    virtual SMatrix43* CutSequenceGetParentTransform(SMatrix43* result);
    virtual void CutSequenceSetParentTransform(const SMatrix43*);
    virtual void CutSequenceEnded(ISequenceEntity*, ZString);
    virtual ZEvent0* GetAnimatableChangedEvent();
    virtual void AbortCutSequence();
    virtual bool SetCutSequenceData(ISequenceEntity*, const SCutSequenceData*, const ZString*, float);
    virtual ~IMorphemeCutSequenceAnimatable();

    IMorphemeCutSequenceAnimatable();
    IMorphemeCutSequenceAnimatable(IMorphemeCutSequenceAnimatable const&);
    IMorphemeCutSequenceAnimatable* operator=(IMorphemeCutSequenceAnimatable const&);
};
