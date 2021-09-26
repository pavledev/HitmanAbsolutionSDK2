#pragma once

struct SGBufferUsingTechniqueParameters
{
	unsigned int m_TUDeferred0;
	unsigned int m_TUDeferred1;
	unsigned int m_TUDeferred2;
	unsigned int m_TUDeferred3;
	unsigned int m_TUOcclusion;
	unsigned long long m_nVTextureSizeInv;
	unsigned long long m_nVProjectionT_VS;
	unsigned long long m_nVProjectionT_PS;
	unsigned long long m_nVProjectionTI;

	SGBufferUsingTechniqueParameters() = default;
	~SGBufferUsingTechniqueParameters() = default;
};
