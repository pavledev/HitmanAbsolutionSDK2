#pragma once

#include "SGBufferUsingTechniqueParameters.h"
#include "ZRenderShader.h"

class SDeferredLightTechniqueParameters : public SGBufferUsingTechniqueParameters
{
public:
    ZRenderShader* m_pFShader;
    ZRenderShader* m_pVShader;
    unsigned int m_TULightModel;
    unsigned int m_TUShadowColorBBlack[4];
    unsigned int m_TULightProjectorMap[4];
    unsigned int m_TUShadowColorCube[4];
    unsigned int m_TULightCubeProjectorMap[4];
    unsigned int m_TUShadowColorBWhite[3];
    unsigned __int64 m_nVEyeUpperLeft_VS;
    unsigned __int64 m_nVEyeUpperLeft_PS;
    unsigned __int64 m_nVEyeLowerRight_VS;
    unsigned __int64 m_nVEyeLowerRight_PS;
};