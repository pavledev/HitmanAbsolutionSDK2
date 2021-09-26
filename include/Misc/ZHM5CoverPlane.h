#pragma once

#include "ZBoundedEntity.h"
#include "IHM5CoverPlane.h"
#include "SVector2.h"
#include "sNeighbourInfo.h"
#include "eCoverEdge.h"
#include "SComponentMapEntry.h"
#include "SMatrix.h"
#include "SVector3.h"
#include "ZEntityRef.h"
#include "ZVariantRef.h"
#include "float4.h"

struct sCoverCorner;
struct SSphere;
class ZDebugRender;
class ZComponentCreateInfo;
class ZSpatialEntity;
class ZString;
struct SMatrix43;
struct STypeID;
struct float1;
template <class A, class B> class THashSet;
template <class T> class TDefaultHashSetPolicy;

class ZHM5CoverPlane : public ZBoundedEntity, public IHM5CoverPlane
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum eCoverSize
	{
		eLowCover = 0,
		eMediumCover = 1,
		eHighCover = 2
	};

	enum eExtraPlaneProperty
	{
		eCoverOnly = 0,
		eCoverAndRail = 1,
		eRailOnly = 2
	};

	enum ESide
	{
		RIGHT = 0,
		LEFT = 1
	};

	enum eEdgePointIndex
	{
		EDGE00 = 0,
		EDGE01 = 1,
		EDGE10 = 2,
		EDGE11 = 3
	};

	sNeighbourInfo m_Neighbours[2];
	SVector3 m_vCoverPos;
	SVector3 m_vCoverSideDir;
	SVector2 m_vCoverDir;
	float m_fCornerT;
	unsigned char m_nCornerFlags;
	unsigned int m_nAIReservingActorIdentifier;
	unsigned char m_nAIFlags;
	bool m_bDisableNPC;
	bool m_bDisablePush;
	bool m_bShootOverDisabled;
	bool m_bDisableCornerRight;
	bool m_bDisableCornerLeft;
	bool m_bGiveFocusOnDumpBody;
	bool m_bDumpedBodyHidden;
	bool m_bIgnoreCoverSpeedRestriction;
	float m_fCoverLength;
	float m_fCoverDepth;
	eCoverSize m_CoverSize;
	eExtraPlaneProperty m_ExtraPlaneProperty;
	bool m_bForceCoverSpot;
	bool m_bWindowCover;
	bool m_bIgnoreCornerAngle;
	bool m_bActivated : 1;
	bool m_bEnabled : 1;
	bool m_bPlaneValidForColiWorld : 1;
	bool m_bInEditMode : 1;
	bool m_bStreamedIn : 1;
	bool m_bAddedStateReadyEvent : 1;

	static SComponentMapEntry s_componentMap[0];
	static const float m_fLowCoverHeight;
	static const float m_fMediumCoverHeight;
	static const float m_fHighCoverHeight;
	static const float m_fCoverSpotThresholdSqr;
	static const float m_fCoverClearZoneDepth;
	static const float m_fCoverMaxDepth;
	static const float m_fCoverPullInLength;
	static const float m_fCoverMinWidth;
	static const float m_fCornerThresholdAngle;
	static unsigned int m_snCoverEnabled;
	static unsigned int m_snCoverDisabled;
	static unsigned int m_snOnHitmanEnterCover;
	static unsigned int m_snOnHitmanLeaveCover;
	static const unsigned char CORNERFLAG_VALID;
	static const unsigned char CORNERFLAG_HIGHCOVERCORNER;
	static const unsigned char CORNERFLAG_WINDOWCORNER;
	static const unsigned char CORNERFLAG_DISABLED;

	~ZHM5CoverPlane() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void StreamIn() override;
	void StreamOut() override;
	bool IsStreamedIn() override;
	void GetStreamableIncludes(THashSet<ZEntityRef, TDefaultHashSetPolicy<ZEntityRef>>& streamableIncludes) const override;
	void OnEnterEditMode() override;
	void OnExitEditMode() override;
	void Init() override;
	void Start() override;
	bool GetEditorVisible() const override;
	void CalculateBounds(float4& vMin, float4& vMax, const unsigned int nIncludeFlags, const unsigned int nExcludeFlags) override;

	float GetCoverDepth() const override;
	bool IsHighCover() const override;
	bool IsMediumCover() const override;
	bool IsLowCover() const override;
	float GetCoverLength() const override;
	ZSpatialEntity* GetNeighborCoverPlane(const float4& vPoint, float4& vOtherCorner) const override;
	float GetCoverHeight() const override;
	float4 GetCoverDir() const override;
	bool IsWindowCover() const override;

	ZHM5CoverPlane() = default;
	static void RegisterType();
	ZHM5CoverPlane(ZComponentCreateInfo& pInfo);
	void OnStateReadyEvent(const ZEntityRef& __formal);
	bool IsEnabledAndActivated() const;
	bool IsNPCDisabled() const;
	bool IsPushDisabled() const;
	void OnEnableCover();
	void OnDisableCover();
	void OnEnableChain();
	void OnDisableChain();
	void SetCoverChainEnabled(ZHM5CoverPlane* pStart, bool bEnabled);
	float4 GetCoverSideDir() const;
	void CalcEdgePoints(float4* avEdgePoints) const;
	float4 GetCoverPos() const;
	float4 GetClosestPointToCoverPlane(const float4& vPoint, bool bClampToCoverCorners, bool bCheckSide, ESide cornerSide) const;
	float4 GetEdgePoint(ESide eSide) const;
	float4 GetEdgePoint(bool bRight) const;
	void GetExtends(float4& vCen, float4& vHalfSize) const;
	float4 GetCoverCenter() const;
	float4 GetCoverLocalHalfSize() const;
	SMatrix GetCoverObjectToWorldMatrix() const;
	ESide GetCoverPosSide(const float4& vPoint) const;
	bool GiveFocusOnDumpBody() const;
	bool GetDumpedBodyHidden() const;
	float4 Calc3dPromptPos(const float4& vPoint) const;
	bool IsPointOnCoverCorner(const float4& vWorldPos, sCoverCorner& coverCorner, bool bExcludeWindowCorners, bool bCheckSide, ESide cornerSide);
	float4 GetCoverCornerPoint(ESide eSide);
	float4 GetCoverCornerPoint(bool bRight);
	ZHM5CoverPlane* GetNeighbor(ESide eSide);
	eCoverEdge IsPointOnCoverEdgeEnd(const float4& vWorldPoint);
	bool IsRayIntersectCoverPlane(float4& vInt, const float4& vRayStart, const float4& vRayDir, bool bTwoSided, bool bCheckHeight, bool bAccurateHighCoverCheck);
	bool SweptSphereIntersectCoverPlane(const SSphere& sphere, const float4& vSweepEnd, float1& vSweepDist, float4& vContactPoint, bool bCheckHeight, bool bAccurateHighCoverCheck);
	bool SphereIntersectsPlane(const SSphere& sphere, float4& vContactPoint, bool bCheckHeight, bool bAccurateHighCoverCheck);
	bool IsPointInsideCoverPlane(const float4& vPoint, bool bCheckHeight, bool bAccurateHighCoverCheck) const;
	bool GetReachableSideCoverPlane(ZHM5CoverPlane** pResult, sCoverCorner& ResultCorner, bool bRightSide, ZDebugRender* pDebugRender) const;
	bool IsWindowCornerOnSide(bool bRightSide);
	bool IsPointBetweenWindowCornerAndEdge(const float4& vWorldPoint);
	bool IsPointBetweenCornerAndCoverEdge(const float4& vWorldPoint, bool bCheckSide, ESide eCheckSide);
	bool IsPointInRangeOfCoverEdge(const float4& vWorldPoint, const float1& vRange, ESide eCheckSide);
	float1 GetDistanceToCoverEdge(const float4& vWorldPoint, const float1& vRange, ESide eCheckSide);
	bool GetClosestCoverCorner(const float4& vWorldPoint, sCoverCorner& ccorner, bool bCheckSide, ESide cornerSide, float fThreshold);
	sNeighbourInfo* GetNeighBorInfo(ESide eSide);
	bool IsCoverPlaneACoverSpot() const;
	bool IsPlaneARail() const;
	bool IsPlaneACover() const;
	eExtraPlaneProperty GetExtraProperty();
	float4 AIGetAimingEdgePoint(const float4& vThreatPosition, bool bRight);
	float4 AIGetShootTestPosition(bool bRight) const;
	bool AIIsPointInsideEdgeAimingArea(const float4& vPoint, const float4& vThreatPosition);
	bool AIIsPointSafelyInsideCover(const float4& vPoint, const float4& vThreatPosition);
	float4 AIGetSafeEdgePoint(const float4& vThreatPosition, bool bRight);
	float4 AIGetEnterCoverPosition(const float4& vThreatPosition);
	bool AIIsCloserToSideDir(const float4& vWorldPoint);
	float4 AIGetClosestPointToCoverPlane(const float4& vWorldPoint, bool bUseEdges);
	bool ShootOverDisabled() const;
	bool AIIsValidCover(const float4& vThreatPosition, bool* pbFlanked);
	bool AIIsValidCover();
	bool AIIsRightSideCloserToTarget(const float4& vThreatPosition);
	float AIGetNPCRadiusX() const;
	float AIGetNPCRadiusY() const;
	bool HasAIFlag(unsigned char nFlag) const;
	void SetAIFlag(unsigned char nFlag);
	void RemoveAIFlag(unsigned char nFlag);
	void AIReserveCover(unsigned int nID);
	void AIFreeCover();
	unsigned int AIGetReservingActorID();
	bool AIIsCornerValid(bool bRight) const;
	bool AIIsCoverReserved() const;
	bool AIIsCoverReserved(unsigned int nIgnoreID) const;
	void ResetNeighbor(unsigned int iIdx);
	void ResetNeighborReference(const ZHM5CoverPlane* pPlane);
	void InvalidateNeighbor(unsigned int iIdx);
	sCoverCorner UnpackCoverCorner(ESide eSide) const;
	bool IsCornerValid(ESide eSide) const;
	void SignalOutputPinOnHitmanEnterCover();
	void SignalOutputPinOnHitmanLeaveCover();
	void ReCalcCoverAndNeighbors();
	void OnCoverSizeChanged();
	void OnDisableNPCChanged();
	void OnDisableCornerRightChanged();
	void OnDisablePushChanged();
	void OnDisableCornerLeftChanged();
	void OnCoverLengthChanged();
	void OnExtraPlanePropertyChanged();
	void OnCoverDepthChanged();
	void OnForceCoverSpotChanged();
	void OnWindowCoverChanged();
	void OnIgnoreCornerAngleChanged();
	void OnShootOverDisabledChanged();
	void AISetReservingActorID(unsigned int nID);
	bool IsPlaneValid() const;
	void ObjectToWorldChangeCallBack(const ZEntityRef& entity, const SMatrix43& mNewValue);
	void ReCalcPlanePropertiesInternal();
	void ReSetNeighbourProperties();
	void ReSetNeighborProperty(ZHM5CoverPlane* pPlane);
	void ReSetNeighbourPropertiesInternal();
	void HookUpWithNeighbor(ZHM5CoverPlane* pPlane, unsigned int iIdx, unsigned int iNeighborIdx);
	void ReCalcCornerSpotsInternal();
	void CalcGetCoverSpot(bool bRight);
	bool IsCornerBetweenPlanes(ZHM5CoverPlane* pPlane2, bool bRightNeighbour);
	bool IsHighLowCornerConnection(ZHM5CoverPlane* pPlane2, bool bRightNeighbour);
	void CheckSetPlaneCollisionWorldValidity();
	void AddModifyPlaneToManager();
	float GetHorizontalLength() const;
	void SetCornerFlags(unsigned char nFlag, ESide eSide);
	void ClearCornerFlags(unsigned char nFlag, ESide eSide);
	bool IsCornerFlagsSet(unsigned char nFlag, ESide eSide) const;
};
