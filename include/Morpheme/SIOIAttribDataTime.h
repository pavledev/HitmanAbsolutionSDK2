#pragma once

struct SIOIAttribDataTime
{
	float m_time;
	float m_timeFraction;
	float m_deltaTimeFraction;
	float m_prevTimeFraction;

	SIOIAttribDataTime() = default;
	~SIOIAttribDataTime() = default;
};
