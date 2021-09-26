#pragma once

#include "float4.h"

class ZParametricCurve;
class ZSplinePosition;
class ZSplineKnot;

class ZSpline
{
public:
	enum EType
	{
		TypeLinear = 0,
		TypeHermite = 1,
		TypeBezier = 2,
		TypeManual = 3
	};

	EType m_eType;
	unsigned int m_iNumberOfKnots;
	ZSplineKnot* m_pKnots;
	bool m_bLooping;

	virtual ~ZSpline() = default;

	ZSpline(EType eType, unsigned int iNumberOfKnots);
	ZSpline(EType eType);
	ZSpline(const ZSpline& rhs);
	ZSpline() = default;
	ZSpline& operator=(const ZSpline& rhs);
	unsigned int GetNumberOfKnots() const;
	void SetKnot(unsigned int iIdx, const float4& p0, const float4& v0, const float4& v1);
	void SetKnot(unsigned int iIdx, const float4& p0);
	const ZSplineKnot* GetKnot(unsigned int iIdx) const;
	void LoadCurve(ZParametricCurve& Curve, unsigned int iIdx) const;
	void LoadCurve(ZSplinePosition& SplinePosition, unsigned int iIdx) const;
	float4 GetTangent(unsigned int iIdx, int iTangentIndex) const;
	float GetLength() const;
	void AllocateKnots(unsigned int i);
	void ResetSplinePosition(ZSplinePosition& SplinePosition) const;
	float AdvanceSplinerPosition(ZSplinePosition& SplinePosition, float fDistance) const;
	void SetPositionAtIdx(ZSplinePosition& SplinePosition, unsigned int iIdx) const;
	float4 GetLocalPositionFromSplinePosition(const ZSplinePosition& SplinePosition) const;
	float4 GetLocalVelocityFromSplinePosition(const ZSplinePosition& SplinePosition) const;
	void SetSplinePositionAtClosestDistanceToPoint(ZSplinePosition& SplinePosition, const float4& vPosition, const float fDeltaIterateDistance) const;
	void SetSplinePositionAtStart(ZSplinePosition& SplinePosition) const;
	void SetSplinePositionAtEnd(ZSplinePosition& SplinePosition) const;
	bool IsSplinePositionAtStart(const ZSplinePosition& SplinePosition, const float fDelta) const;
	bool IsSplinePositionAtEnd(const ZSplinePosition& SplinePosition, const float fDelta) const;
	float CalcDeltaMovement(const ZSplinePosition& SplinePos0, const ZSplinePosition& SplinePos1) const;
	void CalculateBezierHelpers2(const float4& vMiddle, const float4& vPrev, const float4& vNext, float4& pv1, float4& pv2) const;
	void CalculateBezierHelpers(const ZSplineKnot* pMiddle, const ZSplineKnot* pPrev, const ZSplineKnot* pNext, float4& pv1, float4& pv2) const;
};
