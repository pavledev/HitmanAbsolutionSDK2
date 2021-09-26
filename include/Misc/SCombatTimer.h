#pragma once

struct SCombatTimer
{
	float m_fStartTime;
	float m_fDuration;
	float m_fDurationMin;
	float m_fDurationMax;

	SCombatTimer(float fDurationMin, float fDurationMax);
	SCombatTimer() = default;
	~SCombatTimer() = default;
	bool HasExpired();
	void Expire();
	void Reset(float fMinDuration, float fMaxDuration);
};
