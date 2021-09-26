#pragma once

#include "TBag.h"
#include "IAsyncRayHandle.h"
#include "ZGridJobRequest.h"
#include "TMaxArray.h"

class ZActor;
class ZLinkedEntity;
class ZSharedKnowledgeRef;

class ZShootTargetSensor
{
public:
	struct SRayCast
	{
		IAsyncRayHandle* m_pCollisionHandle;
		TEntityRef<ZActor> m_pActor;
		TEntityRef<ZLinkedEntity> m_pTarget;
		float4 m_vFrom;
		float4 m_vTo;

		SRayCast(const SRayCast& __that);
		SRayCast() = default;
		~SRayCast() = default;
		SRayCast& operator=(const SRayCast& __that);
	};

	TBag<SRayCast, TMaxArray<SRayCast, 128>> m_rays;
	TEntityRef<ZActor> m_pAlternativeShootTargetActorBeingUpdated;
	unsigned int m_nUpdateAlternativeShootTargetIndex;
	ZGridJobRequest<ZGridNodeRef> m_alternativeShootPositionRequest;

	ZShootTargetSensor() = default;
	~ZShootTargetSensor() = default;
	void Reset();
	void Update(const TArrayRef<TEntityRef<ZActor>>& actors);
	void CleanupRays();
	void QueueRayCast(const TEntityRef<ZActor>& pActor, const ZSharedKnowledgeRef& targetShared);
	void UpdateRayCasts();
	void UpdateShootTargetInfoAsync(TEntityRef<ZActor> pActor, const SRayCast& ray);
};
