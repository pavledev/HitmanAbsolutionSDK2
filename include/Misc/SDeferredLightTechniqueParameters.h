#pragma once

#include "SGBufferUsingTechniqueParameters.h"
#include "ZRenderShader.h"

struct SDeferredLightTechniqueParameters : SGBufferUsingTechniqueParameters
{
	ZRenderShader* m_pFShader;
	ZRenderShader* m_pVShader;
	unsigned int m_TULightModel;
	unsigned int m_TUShadowColorBBlack[4];
	unsigned int m_TULightProjectorMap[4];
	unsigned int m_TUShadowColorCube[4];
	unsigned int m_TULightCubeProjectorMap[4];
	unsigned int m_TUShadowColorBWhite[3];
	unsigned long long m_nVEyeUpperLeft_VS;
	unsigned long long m_nVEyeUpperLeft_PS;
	unsigned long long m_nVEyeLowerRight_VS;
	unsigned long long m_nVEyeLowerRight_PS;

	SDeferredLightTechniqueParameters() = default;
	~SDeferredLightTechniqueParameters() = default;
};
