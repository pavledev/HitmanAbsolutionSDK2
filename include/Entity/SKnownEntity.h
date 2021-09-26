#pragma once

#include "ZEntityRef.h"
#include "ZSharedKnowledgeRef.h"
#include "EKnownEntityPoseType.h"
#include "ZGameTime.h"
#include "EAIEventType.h"
#include "EAISharedEventType.h"
#include "SMatrix.h"
#include "TMaxArray.h"
#include "float4.h"

struct SAIEvent;

struct SKnownEntity
{
	ZEntityRef m_pActor;
	unsigned int m_nRefCount;
	ZSharedKnowledgeRef m_pSharedKnowledge;
	unsigned int m_nBooleanEvents;
	unsigned int m_nBooleanEventsHandled;
	TMaxArray<unsigned short, 16> m_events;
	EKnownEntityPoseType m_knownPose;
	SMatrix m_knownWorldMatrix;
	float4 m_vKnownVelocity;
	float4 m_vLastVelocityReferencePosition;
	ZGameTime m_tLastWorldMatrixUpdate;
	ZGameTime m_tLastVelocityUpdate;

	static ZEntityRef s_EmptyEntityRef;
	static const ZGameTime s_GameTimeZero;

	static void RegisterType();
	SKnownEntity(const SKnownEntity& __that);
	SKnownEntity() = default;
	~SKnownEntity() = default;
	void AddRef();
	void Release();
	static SAIEvent* GetEventFromIndex(unsigned short index);
	const ZSharedKnowledgeRef& GetShared();
	float ActualDistanceTo(const float4& pos) const;
	const SMatrix& ActualTransform() const;
	const float4& ActualPosition() const;
	const SMatrix& ActualMatrix() const;
	const float4 KnownPosition() const;
	const bool HasKnownPosition() const;
	const SMatrix& KnownMatrix() const;
	float KnownDistanceTo(const float4& pos) const;
	const float4& KnownVelocity() const;
	EKnownEntityPoseType KnownPose() const;
	float4 PredictedPosition(ZGameTime fWhen);
	void UpdateKnownPosition(const float4& pos);
	void UpdateKnownMatrix(const SMatrix& transform);
	void UpdateKnownPose(EKnownEntityPoseType poseType);
	bool NewEvent(EAIEventType type, float tDuration);
	bool RenewEvent(EAIEventType type, float tDuration);
	void ExpireEvent(EAIEventType type, float tDelay);
	void ExpireEvent(EAIEventType type);
	void SetEvent(EAIEventType type, bool bIsCurrent);
	float GetDuration(EAIEventType type);
	float GetAge(EAIEventType type);
	float GetExpired(EAIEventType type);
	int EventCount() const;
	unsigned short GetEventIndex(int nIndex) const;
	bool EventExists(EAIEventType type) const;
	bool IsCurrent(EAISharedEventType type) const;
	bool IsCurrent(EAIEventType type) const;
	bool IsCurrentAndUnhandled(EAIEventType type) const;
	bool IsExpired(EAIEventType type) const;
	bool IsUnhandled(EAIEventType type) const;
	bool IsHandled(EAIEventType type) const;
	bool MinEventAge(EAIEventType type, float fSeconds) const;
	bool MaxEventAge(EAIEventType type, float fSeconds) const;
	bool MinEventExpired(EAIEventType type, float fSeconds) const;
	bool MinAllEventExpired(EAIEventType* types, float fSeconds) const;
	bool MaxEventExpired(EAIEventType type, float fSeconds) const;
	void MarkHandled(EAIEventType type);
	bool RenewSharedEvent(EAISharedEventType type, float tDuration);
	bool RenewSharedEvent(EAISharedEventType type);
	void ExpireSharedEvent(EAISharedEventType type, float tDelay);
	void ExpireSharedEvent(EAISharedEventType type);
	void SetSharedEvent(EAISharedEventType type, bool bIsCurrent);
	bool MinSharedEventAge(EAISharedEventType type, float fSeconds) const;
	bool MaxSharedEventAge(EAISharedEventType type, float fSeconds) const;
	bool MinSharedEventExpired(EAISharedEventType type, float fSeconds) const;
	bool MaxSharedEventExpired(EAISharedEventType type, float fSeconds) const;
	const ZEntityRef& GetEntity();
	void FreeMe();
	SAIEvent* GetEvent(EAIEventType type) const;
	SAIEvent* CreateEventA(EAIEventType type);
	bool RemoveExpiredEvents();
	void UpdateKnownVelocity();
	SKnownEntity& operator=(const SKnownEntity& __that);
};
