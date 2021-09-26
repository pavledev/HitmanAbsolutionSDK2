#pragma once

struct GameOverlayActivated_t
{
	enum
	{
		k_iCallback = 331
	};

	unsigned char m_bActive;

	GameOverlayActivated_t() = default;
	~GameOverlayActivated_t() = default;
};
