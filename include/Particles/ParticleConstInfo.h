#pragma once

struct ParticleConstInfo
{
	unsigned int m_nShaderId;
	unsigned int m_nConstSize;
	unsigned int m_nParticlesRequested;
	unsigned int m_nOffset;

	ParticleConstInfo(unsigned int nShaderId, unsigned int nConstSize);
	ParticleConstInfo() = default;
	~ParticleConstInfo() = default;
};
