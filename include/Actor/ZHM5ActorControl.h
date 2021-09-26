#pragma once

#include "float4.h"
#include "TList.h"
#include "TEntityRef.h"

class ZHitman5;
class ZActor;
class ZCrowdActor;
struct SNearEnemyCheckReq;

class ZHM5ActorControl
{
public:
	enum
	{
		CLIPPLANESNUM = 6
	};

	float4 m_vClipPlanes[6];
	TList<SNearEnemyCheckReq> m_NearEnemyChecks;
	TEntityRef<ZActor> m_pNearestEnemy;
	TEntityRef<ZActor> m_pNearestDeadActor;
	TEntityRef<ZActor> m_pNearestOutfitActor;
	TEntityRef<ZCrowdActor> m_pNearestCrowdActor;
	TEntityRef<ZCrowdActor> m_pMostFacingNearCrowdActor;
	TEntityRef<ZCrowdActor> m_pNearestBackfacingCrowdActor;
	TEntityRef<ZHitman5> m_pHitman;

	ZHM5ActorControl() = default;
	ZHM5ActorControl(const TEntityRef<ZHitman5>& pHitman);
	~ZHM5ActorControl() = default;
	void Init();
	void Update();
	void UpdateRayHandles();
	void DeactivateCheckPoint();
	TEntityRef<ZHitman5> Hitman();
	const TEntityRef<ZActor> GetNearestEnemy() const;
	const TEntityRef<ZActor> GetNearestDeadActor() const;
	const TEntityRef<ZActor> GetNearestOutfitActor() const;
	TEntityRef<ZCrowdActor> GetNearestBackfacingCrowdActor() const;
	TEntityRef<ZCrowdActor> GetMostFacingNearCrowdActor() const;
	bool IsActorOnScreen(const TEntityRef<ZActor>& pActor, const float4* pvPlanes, int nNumOfPlanes);
	void UpdateNearestEnemy();
	void UpdateNearestEnemyStandard();
	void UpdateNearestEnemyAtWindow();
	void UpdateNearestEnemyLedgeHang();
	void UpdateNearestEnemyCover();
	void UpdateNearestDeadActor();
	bool IgnoreActor(const TEntityRef<ZActor>& pActor, bool bCheckOnScreen);
	void CollectNearEnemyChecks();
	void CollectNearDeadActorChecks();
	void CreateNearEnemyCheckRequest(const TEntityRef<ZActor>& pActor);
	void PurgeNECRequests();
	void UpdateNearestCrowdActor();
	void CollectNearCrowdActorChecks();
	void CreateNearCrowdActorCheckRequest(TEntityRef<ZCrowdActor> pActor);
	void ZeroPlanes();
	void ResetPointers();
};
