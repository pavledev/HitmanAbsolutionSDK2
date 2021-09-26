#pragma once

#include "IComponentInterface.h"
#include "ESequencePreviewState.h"
#include "ZGameTime.h"
#include "TArray.h"
#include "ZString.h"

class ISequenceTrack;
class ZSpatialEntity;
struct SMatrix;
class ZEventNull;
template <class A, class B, class C, class D, class E> class ZEvent;
template <class T> class TEntityRef;

class __declspec(novtable) ISequenceEntity : public IComponentInterface
{
public:
	~ISequenceEntity() override = default;
	virtual bool StartSequence(bool param1) = 0;
	virtual void Stop() = 0;
	virtual void Abort() = 0;
	virtual bool IsPaused() const = 0;
	virtual bool IsPausedOnStart() const = 0;
	virtual bool IsPreviewing() const = 0;
	virtual bool IsRunning() const = 0;
	virtual bool IsReady() const = 0;
	virtual void EnablePreview() = 0;
	virtual void DisablePreview() = 0;
	virtual void UpdatePreview(ZGameTime gameTime, bool param2) = 0;
	virtual void SetPreviewPlayState(ESequencePreviewState sequencePreviewState) = 0;
	virtual bool GetForce2DSounds() const = 0;
	virtual void SetForce2DSoundsInPreview(bool param1) = 0;
	virtual void GettingDeactivated() = 0;
	virtual bool ShouldSignalOutputPins() const = 0;
	virtual void NotifyHierarchyChanged() = 0;
	virtual void SetTime(float param1) = 0;
	virtual float GetDuration() const = 0;
	virtual float GetEffectiveSequenceTime() const = 0;
	virtual int GetLoopCount() const = 0;
	virtual int GetCurrentLoop() const = 0;
	virtual void Pause(bool param1) = 0;
	virtual TArray<TEntityRef<ISequenceTrack>> GetTracks() = 0;
	virtual ZString GetSequenceName() = 0;
	virtual void NotifySequenceRequiresUpdate() = 0;
	virtual bool HasSequenceOrigin() = 0;
	virtual void SetSequenceOrigin(TEntityRef<ZSpatialEntity> entityRef) = 0;
	virtual SMatrix GetSequenceOriginTransform() = 0;
	virtual ZEvent<ISequenceEntity*, ZEventNull, ZEventNull, ZEventNull, ZEventNull>& GetOnStopEvent() = 0;
	virtual ZEvent<ISequenceEntity*, ZEventNull, ZEventNull, ZEventNull, ZEventNull>& GetOnAbortEvent() = 0;
	virtual ZEvent<ISequenceEntity*, ZEventNull, ZEventNull, ZEventNull, ZEventNull>& GetOnStartEvent() = 0;
	virtual void ForceExecuteCommands() = 0;

	static void RegisterType();
	ISequenceEntity() = default;
};
