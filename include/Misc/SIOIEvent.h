#pragma once

struct SIOIEvent
{
	float m_fTimeFraction;
	unsigned int m_nEventUserData;

	SIOIEvent() = default;
	~SIOIEvent() = default;
};
