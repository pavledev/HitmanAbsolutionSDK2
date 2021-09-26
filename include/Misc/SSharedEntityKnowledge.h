#pragma once

#include "EKnownEntityType.h"
#include "SMatrix.h"
#include "ZEntityRef.h"
#include "TMaxArray.h"
#include "EAISharedEventType.h"
#include "EActorType.h"
#include "EActorRank.h"
#include "float4.h"

class ZSituationInstance;
struct SAISharedEvent;

struct SSharedEntityKnowledge
{
	EKnownEntityType m_type;
	SMatrix m_actualWorldMatrix;
	bool m_bPerceptible;
	ZEntityRef m_pEntity;

	union 
	{
		struct 
		{
			EActorType m_actorType : 16;
			EActorRank m_actorRank : 16;
		};

		float m_fWalkingDistance;
		float m_radius;
	};

	unsigned short m_room;
	ZSituationInstance* m_pCurrentSituation;
	TMaxArray<unsigned short, 64> m_sharedEvents;
	TMaxArray<unsigned char, 64> m_sharedEventTypes;
	ZEntityRef m_pOutfit;
	int m_nRefCount;

	SSharedEntityKnowledge() = default;
	float4 ActualPosition() const;
	static SAISharedEvent* GetEventFromIndex(unsigned short index);
	bool IsCurrent(EAISharedEventType type);
	bool MinSharedEventAge(EAISharedEventType type, float fSeconds);
	bool MaxSharedEventAge(EAISharedEventType type, float fSeconds);
	bool MinSharedEventExpired(EAISharedEventType type, float fSeconds);
	bool MaxSharedEventExpired(EAISharedEventType type, float fSeconds);
	bool NewSharedEvent(EAISharedEventType type, float duration);
	bool RenewSharedEvent(EAISharedEventType type, float duration);
	int ExpireSharedEvent(EAISharedEventType type, float fDelay);
	bool RemoveExpiredSharedEvents();
	EKnownEntityType GetType() const;
	EActorType GetActorType() const;
	EActorRank GetActorRank() const;
	ZEntityRef GetOutfit() const;
	void SetOutfit(ZEntityRef pOutfit);
	void IncRefCount(unsigned int nMemDebugID);
	void DecRefCount(unsigned int nMemDebugID);
	SAISharedEvent* GetSharedEvent(EAISharedEventType type);
	SAISharedEvent* CreateSharedEvent(EAISharedEventType type);
	~SSharedEntityKnowledge() = default;
};
