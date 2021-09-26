#pragma once

#include "ZEvent.h"
#include "TEntityRef.h"
#include "TArray.h"
#include "float4.h"

class IAsyncRayHandle;
class ZActor;
class ZEventNull;
struct SGameUpdateEvent;

class ZTargetTracker
{
public:
	struct SActorVisibilityCheck
	{
		TEntityRef<ZActor> m_pActor;
		TArray<IAsyncRayHandle*> m_aRayHandles;

		SActorVisibilityCheck(const SActorVisibilityCheck& __that);
		SActorVisibilityCheck() = default;
		~SActorVisibilityCheck() = default;
		SActorVisibilityCheck& operator=(const SActorVisibilityCheck& __that);
	};

	ZEvent<TEntityRef<ZActor>&, ZEventNull, ZEventNull, ZEventNull, ZEventNull> OnTargetChanged;
	float4 m_vFrustum[6];
	TArray<SActorVisibilityCheck> m_aVisibilityChecks;
	TEntityRef<ZActor> m_pCurrentTarget;
	float m_fNearDist;
	float m_fFarDist;
	bool m_bUseFarPlane;

	virtual ~ZTargetTracker() = default;

	ZTargetTracker() = default;
	void Update(const SGameUpdateEvent& updateEvent);
	void VisibilityUpdate();
	const TEntityRef<ZActor>& GetCurrentTarget();
	void Reset();
	void SetFarDist(float fFarDist);
	void ResetNearFarDistDefault();
	void CreateFrustum();
	void FindTarget();
	void CheckVisible(const TEntityRef<ZActor>& pActorRef);
	bool IsCloser(const TEntityRef<ZActor>& pMark0, const TEntityRef<ZActor>& pMark1);
	void SetTarget(TEntityRef<ZActor> pTarget);
};
