#pragma once

#include "ZRenderableEntity.h"
#include "ICameraEntity.h"
#include "EProjectionType.h"
#include "SColorRGB.h"
#include "ZResourcePtr.h"
#include "IRenderPostfilterControllerEntity.h"

class alignas(16) ZCameraEntity : public ZRenderableEntity, public ICameraEntity
{
public:
    EProjectionType m_eProjectionType;
    float m_fFovYDeg;
    float m_fFPSFovYDeg;
    float m_fWidth;
    float m_fAspectWByH;
    float m_fNearZ;
    float m_fFarZ;
    ZEntityRef m_pRootNode;
    ZEntityRef m_pOSDRootNode;
    SColorRGB m_vClearColor;
    bool m_bAutoSize;
    bool m_bAutoAspect;
    bool m_bFPSSeperateFOV;
    bool m_bAllowAutoCameraCuts;
    float m_fCameraCutTriggerDistance;
    float m_fCameraCutTriggerAngleDeg;
    ZResourcePtr m_pHelper;
    TEntityRef<IRenderPostfilterControllerEntity> m_rPostfilter;
    TEntityRef<ZSpatialEntity> m_pRoomReferencePosOverride;
    float4 m_vRoomReferencePosOverrideCode;
    float m_fDepthExportNearZ;
    float m_fDepthExportFarZ;
    float m_fFovY;
    float m_fFPSFovY;
    SMatrix44 m_mProjection;
    SMatrix44 m_mFPSProjection;
    SRenderViewport m_Viewport;
    SRenderViewport m_DestinationViewport;
    float m_fAutoAspectWByH;
    TEntityRef<IRenderPostfilterControllerEntity> m_rPostfilterOverride;
    __int8 m_bOverridePostfilter : 1;
    __int8 m_bForceUpdated : 1;
    __int8 m_bGlowActive : 1;
    __int8 m_bHintsActive : 1;
    __int8 m_bWantCameraCut : 1;
    __int8 m_bFPSDrawLocal : 1;
    __int8 m_bRoomReferencePosOverrideCode : 1;

    virtual float GetFov();
    virtual float CalculateNearZ();
    virtual float CalculateFarZ();
    virtual void SetFovYDeg(float);
};
