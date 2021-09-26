#pragma once

#include "TArray.h"
#include "ZPF5Location.h"
#include "float4.h"

class ZChunkAllocator;
struct SPathCorner;
struct SPathPoint;
struct SPathPointData;
template <class T> class TRefCountPtr;

class ZPF5Path
{
public:
	int m_nRefCount;
	int m_nPathPointCount;
	SPathPoint* m_pPathPointList;
	bool m_bStrict;
	unsigned short m_nCrossedRegions;

	static ZChunkAllocator* s_pPathPointAllocator;
	static SPathPointData* s_aPathPointData;
	static long s_currentPathCount;

	ZPF5Path(const ZPF5Path& rhs);
	ZPF5Path() = default;
	~ZPF5Path() = default;
	ZPF5Path& operator=(const ZPF5Path& rhs);
	int AddRef() const;
	int Release() const;
	static void AllocatePathPoints(unsigned int nPathPointCount);
	static unsigned int GetFreePathPointCount();
	void CalcRemaining();
	void AppendPath(const TRefCountPtr<ZPF5Path> path);
	void PrependPath(TRefCountPtr<ZPF5Path> path, const bool bRemoveFollower);
	void MergeInFront(TRefCountPtr<ZPF5Path> origPath);
	float GetCornerCurveSize(const SPathPoint* pCorner) const;
	ZPF5Location GetCurveLocationAtDistance(float fDistance, const int nIterSteps) const;
	float GetCurveCost(const int nIterSteps) const;
	float GetCornerCost(const SPathPoint* pCorner) const;
	bool GetClosestPointOnPath(const float4& vPoint, float4& vProjectedToPath, float& fPathDistanceTravelled, float fMaxDistanceToTravel, const SPathPoint* pStartNode) const;
	bool GetPathCollision(const TRefCountPtr<ZPF5Path>& otherPath, const float fFollowerRadius, float& fMyPathEnter, float& fMyPathExit, float& fOtherPathEnter, float& fOtherPathExit) const;
	ZPF5Location GetLocationAtDistance(float fDistance, const SPathPoint* pStartFrom) const;
	ZPF5Location GetPositionAtEuclideanDistance(const float4& vCenter, const float fEuclideanDistance, const float fMaxPathDistance, float& fPathDistance) const;
	float4 GetDirectionAtDistance(float fDistance, const SPathPoint* pStartFrom) const;
	const ZPF5Location& GetEndLocation() const;
	const ZPF5Location& GetStartLocation() const;
	void* GetFirstUserData(int nUserDataType, ZPF5Location& lUserData) const;
	float GetCost() const;
	void Set(ZPF5Path& path);
	TArray<SPathCorner> GetCorners(float fMinAngle, float fMaxAngle) const;
	SPathPoint* AppendPathPoint(SPathPoint* pBefore);
	SPathPoint* PrependPathPoint(SPathPoint* pAfter);
	SPathPoint* Unlink(SPathPoint* u);
	int GetPathPointCount() const;
	const SPathPoint* GetFirstPathPoint() const;
	const SPathPoint& GetPathPoint(unsigned int index) const;
	bool VerifyPath() const;
	static SPathPointData* GetPathPointData(const SPathPoint* pPathPoint);
	void Clear();
	SPathPoint* AllocPathPoint();
	void FreePathPoint(SPathPoint* pathPoint);
	void CopyData(SPathPoint* pDest, SPathPoint* pSrc);
};
