#pragma once

#include "ZParametricCurve.h"
#include "float4.h"

class ZSpline;

class ZSplinePosition
{
public:
	float m_fT;
	float m_fDone;
	float m_fLength;
	int m_iCurveIdx;
	const ZSpline* m_pSpline;
	ZParametricCurve m_Curve;

	ZSplinePosition(const ZSpline* pSpline);
	ZSplinePosition() = default;
	~ZSplinePosition() = default;
	void Reset();
	void MoveToClosestDistanceToPoint(const float4& p0, const float fDeltaIterateDistance);
	float Advance(float fDistance);
	void SetAtPoint(unsigned int iIdx);
	void Invalidate();
	bool IsValid() const;
	bool IsAtStart() const;
	bool IsAtEnd() const;
	void SetAtStart();
	void SetAtEnd();
	const ZParametricCurve& GetCurve() const;
	ZParametricCurve& GetCurve();
	float GetLength() const;
	void ReloadCurve();
	float4 GetPosition() const;
	float4 GetVelocity() const;
	int GetCurveIdx() const;
	float GetDone() const;
	float CalcDeltaMovementToSplinePosition(const ZSplinePosition& p0) const;
	bool operator>=(const ZSplinePosition& rhs) const;
	bool operator>(const ZSplinePosition& rhs) const;
	bool operator<=(const ZSplinePosition& rhs) const;
	bool operator<(const ZSplinePosition& rhs) const;
};
