#pragma once

#include "float4.h"

struct SMatrix;

class ZParametricCurve
{
public:
	float4 m_vA;
	float4 m_vB;
	float4 m_vC;
	float4 m_vD;
	float m_fLength;

	ZParametricCurve() = default;
	~ZParametricCurve() = default;
	void Reset();
	void DefineBezier(const float4& vStart, const float4& vTangent0, const float4& vTangent1, const float4& vEnd, const float fCalcLenStepSize);
	void DefineHermite(const float4& p0, const float4& p1, const float4& v0, const float4& v1, const float fCalcLenStepSize);
	void Transform(const SMatrix& m0);
	float4 GetCurvePosition(const float t) const;
	float4 GetCurveVelocity(const float t) const;
	float4 GetCurveAcceleration(const float t) const;
	float4 GetEvenCurvePosition(const float t, const float fStepSize) const;
	float ToSplineTime(const float t, const float fStepSize) const;
	float ToSplineTimeFrom(const float fPct, const float fPct0, const float t0, float& fLen, const float fStepSize) const;
	const float CalculateLength(const float fStepSize);
	const float GetStraightLineLength() const;
	const float GetLength() const;
	float GetClosestPoint(const float4& p0, float t, float4& vClosestPoint, int iIterations) const;
	const float CalcVal(const float t) const;
};
