#pragma once

#include "SGBufferUsingEffectParametersBase.h"
#include "SDeferredLightTechniqueParameters.h"

class SEffectParametersDeferred : public SGBufferUsingEffectParametersBase
{
    SDeferredLightTechniqueParameters m_DeferredLightsParams[3][17][7];
    SDeferredLightTechniqueParameters m_DirLightsWithFadeParams[3][2];
    SDeferredLightTechniqueParameters m_DebugDirectionalCSMParams[3];
    SDeferredLightTechniqueParameters m_DirectionalCSMParams[3][8];
    ZRenderShader* m_pFDeferredClearFB;
    ZRenderShader* m_pVGlobalLight;
    ZRenderShader* m_pFGlobalLight[3];
    unsigned int m_Deferred0_FGlobalLight[3];
    unsigned int m_Deferred1_FGlobalLight[3];
    unsigned int m_Deferred2_FGlobalLight[3];
    unsigned int m_Deferred3_FGlobalLight[3];
    unsigned int m_Occlusion_FGlobalLight[3];
    unsigned int m_Depth_FGlobalLight[3];
    unsigned int m_LightModel_FGlobalLight[3];
    unsigned int m_STLC0_GlobalLightPS[3];
    unsigned int m_GlobalLight_NSSAO_TPC1_PS;
    unsigned int m_GlobalLight_NSSAO_TPC2_PS;
    unsigned int m_GlobalLight_NSSAO_TPC3_PS;
    unsigned int m_GlobalLight_NSSAO_TPC4_PS;
    unsigned int m_GlobalLight_NSSAO_TPC5_PS;
    unsigned __int64 m_nVGlobalLight_Params0_PS[3];
    unsigned __int64 m_nVGlobalLight_ParamsPC_PS[3];
    unsigned __int64 m_nMGlobalLight_ProjectionTI_PS[3];
    unsigned __int64 m_nVGlobalLight_EyeUpperLeft_VS;
    unsigned __int64 m_nVGlobalLight_EyeLowerRight_VS;
    unsigned __int64 m_GlobalLight_NSSAO_Params1_PS;
    unsigned __int64 m_GlobalLight_NSSAO_Params2_PS;
    unsigned __int64 m_GlobalLight_NSSAO_Params3_PS;
    bool m_bIsInit;
    bool m_bRebind;
    SEffectResourceLoader m_EffectLoader;
};
