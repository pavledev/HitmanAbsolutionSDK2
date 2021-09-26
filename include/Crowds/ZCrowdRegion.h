#pragma once

#include "CrowdRegionType.h"
#include "CrowdUtil.h"
#include "float4.h"
#include "float1.h"

class ZCrowdEntity;
class ZCrowdActorCore;
template <class T> class TEntityRef;

class ZCrowdRegion
{
public:
	ZCrowdActorCore* m_pOwner;
	CrowdRegionType m_eType;
	CrowdUtil::ECrowdActorMood m_eActorMood;
	float4 m_vCenter;
	float m_nDirection;
	float m_nRadius;
	unsigned int m_nAngle;
	float m_nLifetime;
	float m_nAge;
	float m_nTimeSinceLastPulse;
	float1 m_vCosAng;
	float m_nReactionDelayNear;
	float m_nReactionDelayFar;
	bool m_bIsPointOfInterest;
	bool m_bTurnTowards;
	bool m_bRemoveNeverFlee;
	float m_nPOIHeightOffset;

	ZCrowdRegion() = default;
	~ZCrowdRegion() = default;
	void Clear();
	void Update(TEntityRef<ZCrowdEntity> pCrowd, float nDt);
	void Set(CrowdRegionType eType, const float4& vCenter, float nDirection, float nRadius, unsigned int nAngle, float nLifetime, ZCrowdActorCore* pObstacle);
	bool Matches(CrowdRegionType eType, float nRadius, unsigned int nAngle, float nLifetime, ZCrowdActorCore* pObstacle);
	void SendPulse(TEntityRef<ZCrowdEntity> pCrowd);
	ZCrowdActorCore* GetOwner() const;
	CrowdRegionType GetType() const;
	CrowdUtil::ECrowdActorMood GetInflictedMood() const;
	float4 GetCenter() const;
	float GetDirection() const;
	float GetRadius() const;
	float GetLifetime() const;
	void SetLifetime(float nLifetime);
	float GetAge() const;
	float GetRemainingTime() const;
	void SetRemainingTime(float nTime);
	bool IsClaimed() const;
	bool IsPointOfInterest() const;
	bool GetTurnTowards() const;
	void SetPointOfInterest(const bool isPOI);
	void SetTurnTowards(const bool bTT);
	void SetPOIHeightOffset(float nOffset);
	float GetPOIHeightOffset() const;
	void SetRemoveNeverFlee(bool bNeverFlee);
	bool GetRemoveNeverFlee() const;
	bool IsActive() const;
	bool Contains(const float4& vCrowdPos, float nExtraRange) const;
	void SetReactionDelayNear(float nDelay);
	float GetReactionDelayNear() const;
	void SetReactionDelayFar(float nDelay);
	float GetReactionDelayFar() const;
	ZCrowdRegion& operator=(const ZCrowdRegion& __that);
};
