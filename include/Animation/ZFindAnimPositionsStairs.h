#pragma once

#include "SMatrix.h"
#include "SAnimSample.h"
#include "ZPF5Location.h"
#include "SVector2.h"
#include "ZPF5LineHitInfo.h"
#include "ZPathfinder2.h"

class ZFindAnimPositionsStairs
{
public:
	SMatrix m_mAnimSample1;
	SAnimSample m_AnimSample[2];
	ZPF5Location m_PFLocMid;
	bool m_bSolved;
	int m_nNumIter;
	float m_fTimeSpent;
	int m_nCompNorm;
	float4 m_vTraceLength;
	float m_fLengthContrainAnim;
	SVector2 m_vCollisionNormal;
	float m_fCollisionOffset;
	bool m_abCollision[2];
	float4 m_avEndPoints[2];
	ZPF5LineHitInfo m_aLineHitInfo[2];
	float4 m_vTraceDir;
	ZPathfinder2* m_pPathfinder;

	ZFindAnimPositionsStairs() = default;
	~ZFindAnimPositionsStairs() = default;
	void Init(const SMatrix& mAnimSample1, const ZPF5Location& StartLoc);
	SAnimSample& GetAnimSample(int nIndex);
	bool DistConstrainSatisfied() const;
	SMatrix GetWorldMatrix(int nIndex);
	const ZPF5Location& GetLocation(int nIndex);
	bool Solve(int nNumIter);
	static int GetValidNormal(const ZPF5Location& Pf5Loc);
	bool SolveInternal(int nNumIter);
	void UpdateMidPoint();
	void TraceMidPoint(const float4& vEndPoint);
	bool SolveDistConstrain();
	void TraceEndPoints();
	void UpdateCollision(const ZPF5LineHitInfo& Collision, const float4& vEndPoint);
};
