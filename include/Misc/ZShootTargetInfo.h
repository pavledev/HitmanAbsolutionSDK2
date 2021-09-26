#pragma once

#include "TMaxArray.h"
#include "ZGridNodeRef.h"
#include "float4.h"
#include "SShootTargetEntry.h"

class ZShootTargetInfo
{
public:
	TMaxArray<SShootTargetEntry, 32> m_ShootTargetInfo;
	unsigned int m_LastUpdateEntryIndex;
	ZGridNodeRef m_alternativeShootTargetNode;
	float m_fAlternativeShootTargetDistanceToTarget;

	ZShootTargetInfo() = default;
	~ZShootTargetInfo() = default;
	float4 GetPrimaryShootTarget(unsigned int nIndex);
	SShootTargetEntry& GetEntry(unsigned int nIndex);
	unsigned int GetEntryCount();
	float4 GetAlternativeShootTarget();
	float GetAlternativeShootTargetDistanceToTarget();
	bool HasAlternativeShootTarget();
	void ResetShootTargetInfo();
};
