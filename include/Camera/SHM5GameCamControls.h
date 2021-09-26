#pragma once

struct SHM5GameCamControls
{
	bool m_bEnableSmoothing;
	bool m_bEnableAimAssist;
	bool m_bEnablePitchLevelOut;

	SHM5GameCamControls() = default;
	~SHM5GameCamControls() = default;
};
