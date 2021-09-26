#pragma once

struct SPoseBone
{
	float m_quat[4];
	float m_pos[4];

	SPoseBone() = default;
	~SPoseBone() = default;
};
