#pragma once

#include "IComponentInterface.h"
#include "ZGameTime.h"
#include "ZEntityRef.h"
#include "TEntityRef.h"

class ISequenceEntity;

class __declspec(novtable) ISequenceTrack : public IComponentInterface
{
public:
	~ISequenceTrack() override = default;
	virtual bool CanStart() = 0;
	virtual void StartSequence(bool param1, bool param2) = 0;
	virtual void SetPausedState(bool param1) = 0;
	virtual void End(bool param1, bool param2, bool param3, bool param4) = 0;
	virtual void Update(ZGameTime gameTime, ZGameTime gameTime2) = 0;
	virtual bool IsReady(ZGameTime gameTime, ZGameTime gameTime2, bool param3) = 0;
	virtual void ResetPrefetchedData() = 0;
	virtual ZEntityRef GetTargetEntity() = 0;
	virtual void SetSequence(const TEntityRef<ISequenceEntity>& entityRef) = 0;
	virtual TEntityRef<ISequenceEntity> GetSequence() = 0;

	static void RegisterType();
	ISequenceTrack(const ISequenceTrack& __that);
	ISequenceTrack() = default;
	ISequenceTrack& operator=(const ISequenceTrack& __that);
};
