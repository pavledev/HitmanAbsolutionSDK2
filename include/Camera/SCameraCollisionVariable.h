#pragma once

#include "ZMapPoly.h"

struct SCameraCollisionVariable
{
	float m_fCollisionVariable;
	float m_fDelayTime;
	float m_fDelayDuration;
	float m_fMaxVelocity;
	bool m_bBlending;
	bool m_bColliding;
	ZMapPoly m_MapPoly;

	SCameraCollisionVariable() = default;
	void Update(bool bCollided, float fCollisionVariable, float fDeltaTime, bool bResetDelay);
	void Reset();
	~SCameraCollisionVariable() = default;
};
