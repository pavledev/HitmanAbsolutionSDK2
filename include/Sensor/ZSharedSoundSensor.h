#pragma once

#include "TEntityRef.h"
#include "ZSharedSoundSensorDef.h"
#include "TMaxArray.h"
#include "ZAISoundConnector.h"
#include "ZAISoundModifierVolume.h"
#include "SAISoundEvent.h"
#include "ZGridJobRequest.h"
#include "ZGridFloatField.h"
#include "float1.h"
#include "ZSharedKnowledgeRef.h"

struct SDistanceModifiers;
class ZActor;

class ZSharedSoundSensor
{
public:
	TEntityRef<ZSharedSoundSensorDef> m_pSensorDef;
	TMaxArray<TEntityRef<ZAISoundConnector>, 64> m_connectors;
	TMaxArray<TEntityRef<ZAISoundModifierVolume>, 64> m_modifierVolumes;
	TMaxArray<unsigned short, 8> m_hitmanRoomIds;
	SAISoundEvent m_processingEvent;
	float1 m_processingEventZDistance;
	ZGridNodeRef m_processingEventNode;
	ZGridJobRequest<TRefCountPtr<ZGridFloatField>> m_pSoundDistanceRequest;
	TRefCountPtr<ZGridFloatField> m_pSoundDistanceField;
	TMaxArray<TEntityRef<ZActor>, 64> m_affectedActors;
	TMaxArray<SAISoundEvent, 32> m_Events;
	TMaxArray<SAISoundEvent, 8> m_PulseEvents;
	TMaxArray<ZSharedKnowledgeRef, 32> m_soundLocations;
	ZGameTime m_fPulseTime;
	ZGameTime m_tLastGunShot;
	ZGameTime m_tLastHitmanGunShot;
	ZGameTime m_tLastBulletImpact;
	ZGameTime m_tLastThrownItemCollision;
	int m_nActorCleanupIndex;

	static const unsigned int MAX_SOUNDS;
	static const unsigned int MAX_PULSINGSOUNDS;
	static const int MAX_SOUND_CONNECTORS;
	static const int MAX_SOUND_MODIFIER_VOLUMES;

	virtual ~ZSharedSoundSensor() = default;

	ZSharedSoundSensor() = default;
	void RegisterSensorDef(TEntityRef<ZSharedSoundSensorDef> pSensorDef);
	bool RegisterSoundConnector(const TEntityRef<ZAISoundConnector>& pConnector);
	void UnregisterSoundConnector(const TEntityRef<ZAISoundConnector>& pConnector);
	void RegisterSoundModifierVolume(const TEntityRef<ZAISoundModifierVolume>& pVolume);
	void UnregisterSoundModifierVolume(const TEntityRef<ZAISoundModifierVolume>& pVolume);
	void AddSoundEvent(SAISoundEvent& event);
	void AddSoundEvent(EAIEventType eType, ZEntityRef pSender, const float4& vPos, float fRange);
	void AddSoundEvent(EAIEventType eType, ZEntityRef pSender, const float4& vPos);
	void AddSoundEventPulse(EAIEventType eType, ZEntityRef pSender, TEntityRef<ZSpatialEntity> pSpatial, const float4& vPos);
	void RemoveSoundEventPulse(EAIEventType eType, ZEntityRef pSender);
	static float CalculateDistance(const float4& vStart, unsigned short nStartRoomID, const float4& vEnd, unsigned short nEndRoomID, float fMaxDistance, unsigned int nGateFlag, bool bDrawDebug);
	static float CalculateSoundDistance(const float4& vStart, const float4& vEnd, float fMaxDistance, bool bDrawDebug);
	static float CalculateSoundDistance(const TEntityRef<ZSpatialEntity>& pSpatial, const float4& vTarget, float fMaxDistance, bool bDrawDebug);
	static float CalculateWalkDistance(const float4& vStart, const float4& vEnd, float fMaxDistance, bool bDrawDebug);
	void OnGameStarted();
	void OnGameStopped();
	void Reset();
	void Update(const TArrayRef<TEntityRef<ZActor>>& actors);
	float GetEventHearRange(EAIEventType eventType) const;
	void UpdateSounds(const TArrayRef<TEntityRef<ZActor>>& actors);
	ZSharedKnowledgeRef CreateSoundLocation();
	void AddSoundKnowledge(const TMaxArray<TEntityRef<ZActor>, 64>& actors, const SAISoundEvent& ev, float fRadius);
	bool DidHitmanSetOffCarAlarm(SAISoundEvent& event);
	void MapPositionToRoomAndGrid(const float4& vPosition, unsigned short& nRoomId, TMaxArray<unsigned short, 8>& allRooms, ZGridNodeRef& rNode, SDistanceModifiers& modifiers, float1& fZDistance, float fMaxDistanceForConnectors);
};
