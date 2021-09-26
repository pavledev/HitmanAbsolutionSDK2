#pragma once

#include "SVector3.h"

struct SVector2;
struct float4;
struct SBaseMovmentCollisionInfo;

struct SInputRestriction
{
	bool m_bBlocked;
	bool m_bInput;
	float m_fBlockAngle;
	float m_fBlockRange;
	SVector3 m_vBlockingNormal;
	float m_fInputAngle;
	bool m_bExplicitNormal;

	SInputRestriction() = default;
	~SInputRestriction() = default;
	void Reset();
	void UpdateInput(SVector2& vInput, const float4& vCamDir);
	void UpdateWorldInput(SVector2& vWorldInput);
	void SetRestriction(const SBaseMovmentCollisionInfo& CollisionInfo);
};
