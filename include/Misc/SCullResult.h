#pragma once

struct SCullResult
{
	unsigned short m_nActorIndex;
	float m_nDistance;
	unsigned char m_nNewLODFlag;

	SCullResult() = default;
	~SCullResult() = default;
	unsigned char GetCurrentLOD() const;
	bool IsCulled() const;
};
