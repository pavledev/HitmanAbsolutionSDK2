#pragma once

#include "TBag.h"
#include "TMaxArray.h"
#include "TEntityRef.h"
#include "ZSharedKnowledgeRef.h"
#include "ZSharedSensorDef.h"
#include "EGameTension.h"
#include "EActorPerceptionSensitivity.h"
#include "SMatrix.h"
#include "float4.h"

class ZActor;
class IAsyncRayHandle;
class ZAIVisionBlockerPlane;
template <class T> class TArrayRef;

class ZSharedVisibilitySensor
{
public:
	enum EVisibilityVolume
	{
		VV_NONE = 0,
		VV_CLOSE = 1,
		VV_PERIPHERAL = 2,
		VV_FOCUS = 3
	};

	struct SActorInfo
	{
		TEntityRef<ZActor> pActor;
		SMatrix mActorTransform;
		SMatrix mHead;
		EGameTension eTension;
		EActorPerceptionSensitivity eSensitivity;
		const ZSharedSensorDef::SVisibilitySetting* pVisibilitySettings;

		SActorInfo(const SActorInfo& __that);
		SActorInfo() = default;
		~SActorInfo() = default;
		SActorInfo& operator=(const SActorInfo& __that);
	};

	struct SRayCast
	{
		IAsyncRayHandle* m_pCollisionHandle;
		TEntityRef<ZActor> m_pActor;
		ZSharedKnowledgeRef m_rObject;
		float4 m_vFrom;
		float4 m_vTo;

		SRayCast(const SRayCast& __that);
		SRayCast() = default;
		~SRayCast() = default;
		SRayCast& operator=(const SRayCast& __that);
	};

	TBag<SRayCast, TMaxArray<SRayCast, 128>> m_rays;
	int m_nActorIndex;
	int m_nObjectIndex;
	char m_nBoneIndex;
	TMaxArray<TEntityRef<ZAIVisionBlockerPlane>, 32> m_visionBlockerPlanes;

	ZSharedVisibilitySensor() = default;
	void RegisterVisionBlockerPlane(const TEntityRef<ZAIVisionBlockerPlane>& rVolume);
	void UnregisterVisionBlockerPlane(const TEntityRef<ZAIVisionBlockerPlane>& rVolume);
	void Update(const TArrayRef<TEntityRef<ZActor>>& actors);
	void CleanupRays();
	void FillUpActorCache(const TArrayRef<TEntityRef<ZActor>>& actors, TMaxArray<SActorInfo, 50>& actorCache, const TEntityRef<ZSharedSensorDef>& pSensorDef);
	void UpdateHitmanVisibility(const TMaxArray<SActorInfo, 50>& actors, const TEntityRef<ZSharedSensorDef>& pSensorDef);
	void UpdateGeneralVisibility(const TMaxArray<SActorInfo, 50>& actors, const TEntityRef<ZSharedSensorDef>& pSensorDef);
	void CheckVisibility(const SActorInfo& actor, const ZSharedKnowledgeRef& rObject, const float4& vPoint);
	EVisibilityVolume CheckVisibilityVolumes(const SActorInfo& actor, const float4& vTarget);
	void SetVisibility(const TEntityRef<ZActor>& pActor, const ZSharedKnowledgeRef& rObject, bool bVisible);
	void SetNotVisible(const TEntityRef<ZActor>& pActor, const ZSharedKnowledgeRef& rObject);
	void QueueRayCast(const TEntityRef<ZActor>& pActor, const ZSharedKnowledgeRef& rObject, const float4& vFrom, const float4& vTo);
	void UpdateRayCasts();
	~ZSharedVisibilitySensor() = default;
};
