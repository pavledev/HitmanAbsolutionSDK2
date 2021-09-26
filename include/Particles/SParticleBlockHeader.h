#pragma once

struct SParticleBlockHeader
{
	SParticleBlockHeader* NextBlock;
	unsigned int nNumParticles;
	unsigned int m_n1a0eb01d;
	unsigned int nTemp;

	SParticleBlockHeader() = default;
	~SParticleBlockHeader() = default;
};
