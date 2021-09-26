#pragma once

struct STurnToMoveData
{
	float m_afRotation[4];
	unsigned int m_anNodes[4];
	float m_afTurnOnSpotFraction[4];
	float m_afRotationFraciton[4];

	STurnToMoveData() = default;
	~STurnToMoveData() = default;
};
