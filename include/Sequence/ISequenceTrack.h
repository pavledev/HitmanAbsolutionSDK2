#pragma once

#include "IComponentInterface.h"
#include "ZGameTime.h"
#include "ZEntityRef.h"
#include "TEntityRef.h"

class ISequenceTrack : public IComponentInterface
{
public:
    virtual bool CanStart();
    virtual void StartSequence(bool, bool);
    virtual void SetPausedState(bool);
    virtual void End(bool, bool, bool, bool);
    virtual void Update(ZGameTime, ZGameTime);
    virtual bool IsReady(ZGameTime, ZGameTime, bool);
    virtual void ResetPrefetchedData();
    virtual ZEntityRef* GetTargetEntity(ZEntityRef* result);
    virtual void SetSequence(const TEntityRef<ISequenceEntity>*);
    virtual TEntityRef<ISequenceEntity>* GetSequence(TEntityRef<ISequenceEntity>* result);
};