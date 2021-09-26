#pragma once

struct SHM5InputControllerAnalog
{
	float m_fRightStickY;
	float m_fRightStickX;
	float m_fLeftStickY;
	float m_fLeftStickX;
	float m_fRightStickYRaw;
	float m_fRightStickXRaw;
	float m_fLeftStickXRaw;
	float m_fLeftStickYRaw;
	float m_fTriggerRight;
	float m_fTriggerLeft;

	SHM5InputControllerAnalog() = default;
	~SHM5InputControllerAnalog() = default;
	void Reset();
};
