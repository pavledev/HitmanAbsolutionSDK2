#pragma once

#include "TArray.h"

template <class A, int B> class TFixedArray;

class ZCurve
{
public:
	TArray<TFixedArray<float, 8>> data;

	static void RegisterType();
	ZCurve(const ZCurve& other);
	ZCurve() = default;
	float Evaluate(float time) const;
	void GetForwardEvalCoefficients(float fStepSize, unsigned int nKey, float* pfC0, float* pfC1, float* pfC2, float* pfC3, float* pfC4, float* pfC5) const;
	bool IsEmpty() const;
	int KeyCount() const;
	void GetKeyPoint(int i, float* pPoint) const;
	void SetKeyPoint(int i, float* pPoint);
	float Duration() const;
	unsigned int PackCurve2(void* pOut) const;
	unsigned int GetHashCode() const;
	bool operator==(const ZCurve& rhs) const;
	float GetKeyTime(unsigned int i) const;
	~ZCurve() = default;
	ZCurve& operator=(const ZCurve& __that);
};
