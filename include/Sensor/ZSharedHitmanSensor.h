#pragma once

#include "TMaxArray.h"
#include "ZSharedKnowledgeRef.h"
#include "EGameTension.h"
#include "EAISharedEventType.h"
#include "EActorType.h"
#include "ZGameTime.h"
#include "ZHM5IndicatorManager.h"

struct SActorCounts;
class IAsyncRayHandle;
class ZActor;
class ZHitman5;
class ZSpatialEntity;
struct SKnownEntity;
struct ShitmanSensorRadarBlip;
struct float4;
template <class T> class TArrayRef;
template <class T> class TEntityRef;
template <class T> class TMaxArrayRef;
template <class T> class TRefCountPtr;

class ZSharedHitmanSensor
{
public:
	struct SShotRecord
	{
		ZGameTime m_time;
		bool m_bHit;

		SShotRecord(const SShotRecord& __that);
		SShotRecord() = default;
		SShotRecord& operator=(const SShotRecord& __that);
	};

	TMaxArray<SShotRecord, 32> m_aShotHistory;
	ZSharedKnowledgeRef m_pCurrentHitman;
	EGameTension m_eGameTension;
	ZGameTime m_NextFootstepSoundTime;
	unsigned int m_nShotAccuracyCacheFrame;
	float m_fShotAccuracy;
	bool m_bHitmanIsInCombat;
	bool m_bDisguiseBroken;
	bool m_bDisguiseTrespassing;
	bool m_bDisguiseIllegalAction;
	bool m_bDisguiseAttentionBoostForCombatChange;
	bool m_bIsRecievingHuntAttention;
	int m_nSoundDistanceUpdateIndex;
	IAsyncRayHandle* m_pRayCastHandle;
	TMaxArray<ShitmanSensorRadarBlip, 128> m_aRadarblips;

	ZSharedHitmanSensor() = default;
	~ZSharedHitmanSensor() = default;
	void Update(const TArrayRef<TEntityRef<ZActor>>& actors);
	void SetHitmanSharedEvent(EAISharedEventType eventType, bool bCurrent, float fDuration);
	bool IsHitmanEventCurrent(EAISharedEventType eventType) const;
	void GameStarted();
	void GameStopped();
	void Reset();
	const ZSharedKnowledgeRef& GetCurrentHitman();
	void OnHitmanChanged(TEntityRef<ZHitman5> pNewHitman);
	bool IsRecievingHuntAttention() const;
	void ResetShotAccuracy();
	void RecordShotAccuracy(bool bHitAnActor);
	int GetShotAccuracy(float fTimeFrame, float& fAccuracyOut);
	bool RayCylinderTest(const float4& vTop, const float4& vBottom, const float4& vRayStart, const float4& vRayDir, float fCylinderRadius);
	static float GetActorPanAngle(TEntityRef<ZActor> pActor);
	EGameTension CountActorsMoods(const TEntityRef<ZActor>& pActor, bool& bCombat, SActorCounts& actorCounts, TMaxArrayRef<TEntityRef<ZActor>>& enemies, const TRefCountPtr<SKnownEntity>& pKnownHitman);
	ZHM5IndicatorManager::EIndicatorType GetIndicatorType(EActorType actorType, EGameTension tension);
	ZHM5IndicatorManager::EIndicatorType GetIndicatorTypeNew(const TEntityRef<ZActor>& pActor, bool bIsHuntingHitman);
	void AddToIndicatorManger(const TEntityRef<ZSpatialEntity>& pSpatial, ZHM5IndicatorManager::EIndicatorType eIndicatorType, bool bHitmanInSight);
	void CleanupRay();
};
