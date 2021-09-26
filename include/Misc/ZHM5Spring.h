#pragma once

class ZHM5Spring
{
public:
	float m_fStiffness;
	float m_fUpdatedPos;
	float m_fMaxDiff;
	bool m_bActive;
	bool m_bPullStiffnessFromZero;
	float m_fCurStiffness;
	float m_fDelta;
	float m_fPullTime;

	ZHM5Spring() = default;
	~ZHM5Spring() = default;
	void SetStiffness(float fStiffness);
	void Activate();
	void DeActivate();
	void SetUpdatedPos(float fPos);
	void SetMaxDiff(float fMaxDiff);
	float UpdateSpring(float fNewValue, float fDeltaTime);
	bool IsActive();
	void SetPullStiffnessFromZero(bool bValue);
	void SetPullTime(float fValue);
	float UpdateStiffnes(float fDeltaTime);
};
