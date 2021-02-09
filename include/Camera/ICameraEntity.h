#pragma once

#include "IComponentInterface.h"
#include "SRenderViewport.h"
#include "SVector3.h"
#include "EProjectionType.h"
#include "float4.h"
#include "SMatrix44.h"
#include "SVector2.h"
#include "ZEntityRef.h"
#include "SMatrix.h"

class ICameraEntity : public IComponentInterface
{
public:
    virtual const SRenderViewport* GetViewport();
    virtual const SRenderViewport* GetDestinationViewport();
    virtual SVector3* GetClearColor(SVector3* result);
    virtual EProjectionType GetProjectionType();
    virtual float GetNearZ();
    virtual float GetFarZ();
    virtual float4* GetRoomReferencePos(float4* result);
    virtual float GetDepthExportNearZ();
    virtual float GetDepthExportFarZ();
    virtual float GetAspectWByH();
    virtual float GetFovYDeg();
    virtual const SMatrix44* GetProjectionMatrix();
    virtual const SMatrix44* GetFPSProjectionMatrix();
    virtual float4* Project(float4* result, const float4*);
    virtual float4* Unproject(float4* result, const float4*);
    virtual void CalculateBoundingRect(SVector2*, SVector2*, const SVector3*, unsigned int);
    virtual const ZEntityRef* GetPostfilter();
    virtual const ZEntityRef* GetRootNode();
    virtual const ZEntityRef* GetOSDRootNode();
    virtual bool IsOrthographic();
    virtual float4* GetOrthographicWindowSize(float4* result);
    virtual float4* GetOrthographicPixelSize(float4* result);
    virtual void LoadDefaultProjection(bool);
    virtual void LoadDefaultPerspectiveProjection();
    virtual void LoadDefaultOrthographicProjection(float);
    virtual void SetViewport(const SRenderViewport*);
    virtual void SetDestinationViewport(const SRenderViewport*);
    virtual void SetClearColor(SVector3);
    virtual void SetPerspectiveFovRH(float, float, float, float);
    virtual void SetOrthogonalRH(float, float, float, float);
    virtual void SetCustomProjection(const SMatrix*);
    virtual void SetAutoSize(bool);
    virtual void SetAutoAspect(bool);
    virtual bool GetAutoAspect();
    virtual void SetPostfilter(const ZEntityRef*);
    virtual void SetPostfilterOverride(bool, const ZEntityRef*);
    virtual void SetRootNode(const ZEntityRef*);
    virtual void SetOSDRootNode(const ZEntityRef*);
    virtual void SetOrthographicPixelSize(float);
    virtual void SetForceUpdateDependencies(bool);
    virtual bool GetForceUpdateDependencies();
    virtual bool GetSeperateFPSFovEnabled();
    virtual float4* GetListenerPos(float4* result);
    virtual void SetSeperateFPSFovEnabled(bool);
    virtual void SetAspectWByH(float);
    virtual void SetFPSFovYDeg(float);
    virtual float GetFPSFovYDeg();
    virtual void GetGlowActive(bool*, bool*);
    virtual void SetGlowActive(bool, bool);
    virtual bool WantCameraCut();
    virtual void SetWantCameraCut(bool);
    virtual bool GetAllowAutoCameraCuts();
    virtual float GetCameraCutTriggerDistance();
    virtual float GetCameraCutTriggerAngleDeg();
    virtual bool GetFPSDrawLocal();
    virtual void SetFPSDrawLocal(bool);
};
