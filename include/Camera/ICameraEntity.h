#pragma once

#include "IComponentInterface.h"
#include "SVector3.h"
#include "float4.h"
#include "ZEntityRef.h"

struct SMatrix44;
struct SMatrix;
struct SRenderViewport;
struct SVector2;

class __declspec(novtable) ICameraEntity : public IComponentInterface
{
public:
	enum EProjectionType
	{
		ePerspectiveRH = 0,
		eOrtogonalRH = 1,
		eCustom = 2
	};

	~ICameraEntity() override = default;
	virtual const SRenderViewport& GetViewport() const = 0;
	virtual const SRenderViewport& GetDestinationViewport() const = 0;
	virtual SVector3 GetClearColor() const = 0;
	virtual EProjectionType GetProjectionType() const = 0;
	virtual float GetNearZ() const = 0;
	virtual float GetFarZ() const = 0;
	virtual float4 GetRoomReferencePos() const = 0;
	virtual float GetDepthExportNearZ() const = 0;
	virtual float GetDepthExportFarZ() const = 0;
	virtual float GetAspectWByH() const = 0;
	virtual float GetFovYDeg() const = 0;
	virtual const SMatrix44& GetProjectionMatrix() const = 0;
	virtual const SMatrix44& GetFPSProjectionMatrix() const = 0;
	virtual float4 Project(const float4& param1) const = 0;
	virtual float4 Unproject(const float4& param1) const = 0;
	virtual void CalculateBoundingRect(SVector2& vector2, SVector2& vector22, const SVector3* vector3, unsigned int param4) const = 0;
	virtual const ZEntityRef& GetPostfilter() const = 0;
	virtual const ZEntityRef& GetRootNode() const = 0;
	virtual const ZEntityRef& GetOSDRootNode() const = 0;
	virtual bool IsOrthographic() const = 0;
	virtual float4 GetOrthographicWindowSize() const = 0;
	virtual float4 GetOrthographicPixelSize() const = 0;
	virtual void LoadDefaultProjection(bool param1) = 0;
	virtual void LoadDefaultPerspectiveProjection() = 0;
	virtual void LoadDefaultOrthographicProjection(float param1) = 0;
	virtual void SetViewport(const SRenderViewport& renderViewport) = 0;
	virtual void SetDestinationViewport(const SRenderViewport& renderViewport) = 0;
	virtual void SetClearColor(SVector3 vector3) = 0;
	virtual void SetPerspectiveFovRH(float param1, float param2, float param3, float param4) = 0;
	virtual void SetOrthogonalRH(float param1, float param2, float param3, float param4) = 0;
	virtual void SetCustomProjection(const SMatrix& matrix) = 0;
	virtual void SetAutoSize(bool param1) = 0;
	virtual void SetAutoAspect(bool param1) = 0;
	virtual bool GetAutoAspect() const = 0;
	virtual void SetPostfilter(const ZEntityRef& entityRef) = 0;
	virtual void SetPostfilterOverride(bool param1, const ZEntityRef& entityRef) = 0;
	virtual void SetRootNode(const ZEntityRef& entityRef) = 0;
	virtual void SetOSDRootNode(const ZEntityRef& entityRef) = 0;
	virtual void SetOrthographicPixelSize(float param1) = 0;
	virtual void SetForceUpdateDependencies(bool param1) = 0;
	virtual bool GetForceUpdateDependencies() const = 0;
	virtual bool GetSeperateFPSFovEnabled() const = 0;
	virtual float4 GetListenerPos() const = 0;
	virtual void SetSeperateFPSFovEnabled(bool param1) = 0;
	virtual void SetAspectWByH(float param1) = 0;
	virtual void SetFPSFovYDeg(float param1) = 0;
	virtual float GetFPSFovYDeg() const = 0;
	virtual void GetGlowActive(bool& param1, bool& param2) const = 0;
	virtual void SetGlowActive(bool param1, bool param2) = 0;
	virtual bool WantCameraCut() const = 0;
	virtual void SetWantCameraCut(bool param1) = 0;
	virtual bool GetAllowAutoCameraCuts() const = 0;
	virtual float GetCameraCutTriggerDistance() const = 0;
	virtual float GetCameraCutTriggerAngleDeg() const = 0;
	virtual bool GetFPSDrawLocal() const = 0;
	virtual void SetFPSDrawLocal(bool param1) = 0;

	static void RegisterType();
	ICameraEntity(const ICameraEntity& __that);
	ICameraEntity() = default;
	ICameraEntity& operator=(const ICameraEntity& __that);
};
