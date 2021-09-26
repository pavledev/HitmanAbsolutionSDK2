#pragma once

#include "TArray.h"

class ZCurve;
struct SVector3;

struct SFMODRolloffCurve
{
	TArray<SVector3> m_aCurve;

	SFMODRolloffCurve(const ZCurve& curve);
	SFMODRolloffCurve() = default;
	bool operator==(const SFMODRolloffCurve& rhs) const;
	unsigned int GetHashCode() const;
	void SetCurve(const ZCurve& curve);
	~SFMODRolloffCurve() = default;
	SFMODRolloffCurve& operator=(const SFMODRolloffCurve& __that);
};
