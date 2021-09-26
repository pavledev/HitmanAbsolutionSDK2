#pragma once

struct SHM5GameCamTransition
{
	float m_fTransitionTime;
	bool m_bTransitionWhileMoving;
	bool m_bAlignToBaseAngles;
	bool m_bIgnoreProfileAlignment;

	SHM5GameCamTransition() = default;
	~SHM5GameCamTransition() = default;
};
