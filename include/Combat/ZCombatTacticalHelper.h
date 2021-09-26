#pragma once

#include "ZGridNodeRef.h"
#include "ZHM5CoverPlane.h"
#include "ZGridJobRequest.h"
#include "ZGridFloatField.h"
#include "TMaxArray.h"
#include "ZGridByteField.h"
#include "ZCombatSituationMember.h"
#include "SFindBestTacticalPositionOutput.h"

class ZCombatTacticalHelper
{
public:
	ZGridNodeRef m_threatNode;
	float4 m_wsThreatPosition;
	ZHM5CoverPlane* m_pThreatCover;
	ZGridJobRequest<TRefCountPtr<ZGridFloatField>> m_distanceFieldRequest;
	TRefCountPtr<ZGridFloatField> m_distanceFieldFromTarget;
	ZGameTime m_distanceFieldLastUpdate;
	TMaxArray<ZGridJobRequest<TRefCountPtr<ZGridByteField>>, 32> m_hazardZoneRequests;
	TRefCountPtr<ZGridByteField> m_hazardZoneField;
	TMaxArray<ZGridJobRequest<TRefCountPtr<ZGridByteField>>, 32> m_guardPointRequests;
	TRefCountPtr<ZGridByteField> m_guardPointField;
	ZGameTime m_tLastGuardPointUpdateTime;
	ZGridJobRequest<TRefCountPtr<ZGridFloatField>> m_occupancyFieldRequest;
	TRefCountPtr<ZGridFloatField> m_occupancyField;
	TArray<TMaxArray<ZHM5CoverPlane*, 4>> m_coversForNode;
	ZGridJobRequest<TRefCountPtr<ZGridFloatField>> m_coverFieldRequest;
	TRefCountPtr<ZGridFloatField> m_coverField;
	ZGridJobRequest<ZGridNodeRef> m_bestTacticalPositionRequest;
	TRefCountPtr<ZCombatSituationMember> m_pMemberBeingUpdated;
	unsigned int m_nCurrentMemberUpdateIndex;

	virtual ~ZCombatTacticalHelper() = default;

	ZCombatTacticalHelper() = default;
	void Update(const float4& wsThreatPosition, const ZGridNodeRef& threatNode, ZHM5CoverPlane* pThreatCover, const TMaxArray<TRefCountPtr<ZSituationMember>, 64>& members);
	void UpdateDistanceField(bool bTargetNodeChanged);
	void UpdateCoverField();
	void UpdateOccupancyField();
	void UpdateGuardPoints();
	void UpdateHazardZones();
	void AlterHazardZone(const float4& wsHazardPosition, float fRadius, bool bAdd);
	bool HasGuardPointsChanged();
	bool IsInsideGuardPoint(const ZGridNodeRef& tacticalNode) const;
	float GetTacticalRating(const ZGridNodeRef& tacticalNode, TRefCountPtr<ZCombatSituationMember> pRequestingMember);
	ZHM5CoverPlane* GetCoverPlane(const ZGridNodeRef& tacticalNode, const float4& vThreatPosition, unsigned int nIgnoreActorReservation);
	void BuildCoverToNodeMap();
	const TRefCountPtr<ZGridFloatField>& GetDistanceFieldFromTarget() const;
	bool HasDistanceFieldFromTarget() const;
	float GetDistanceToTarget(const ZGridNodeRef& node);
	ZGridJobRequest<TRefCountPtr<ZGridFloatField>> RequestOccupancyField(TRefCountPtr<ZCombatSituationMember> pRequestingMember, const TMaxArray<TRefCountPtr<ZSituationMember>, 64>& members);
	ZGridJobRequest<SFindBestTacticalPositionOutput> RequestTacticalPosition(TRefCountPtr<ZCombatSituationMember> pRequestingMember);
	bool CanRequestTacticalPosition();
};
