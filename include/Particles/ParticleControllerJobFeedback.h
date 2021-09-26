#pragma once

struct ParticleControllerJobFeedback
{
	unsigned int m_nNumParticles;
	unsigned int m_nNumDeadParticles;

	ParticleControllerJobFeedback() = default;
	~ParticleControllerJobFeedback() = default;
};
