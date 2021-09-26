#pragma once

#include "ZRenderableEntity.h"
#include "ICameraEntity.h"
#include "SColorRGB.h"
#include "ZResourcePtr.h"
#include "SComponentMapEntry.h"
#include "SMatrix44.h"
#include "SRenderViewport.h"
#include "SVector3.h"
#include "TEntityRef.h"
#include "ZEntityRef.h"
#include "ZVariantRef.h"
#include "float4.h"

class IRenderPostfilterControllerEntity;
class ZComponentCreateInfo;
class ZSpatialEntity;
struct SMatrix;
struct STypeID;
struct SVector2;

class ZCameraEntity : public ZRenderableEntity, public ICameraEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ICameraEntity::EProjectionType m_eProjectionType;
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
	bool m_bOverridePostfilter : 1;
	bool m_bForceUpdated : 1;
	bool m_bGlowActive : 1;
	bool m_bHintsActive : 1;
	bool m_bWantCameraCut : 1;
	bool m_bFPSDrawLocal : 1;
	bool m_bRoomReferencePosOverrideCode : 1;

	static SComponentMapEntry s_componentMap[0];

	~ZCameraEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	void Start() override;
	virtual float GetFov() const;
	virtual float CalculateNearZ() const;
	virtual float CalculateFarZ() const;
	virtual void SetFovYDeg(float fFovYDeg);

	const SRenderViewport& GetViewport() const override;
	const SRenderViewport& GetDestinationViewport() const override;
	SVector3 GetClearColor() const override;
	ICameraEntity::EProjectionType GetProjectionType() const override;
	float GetNearZ() const override;
	float GetFarZ() const override;
	float4 GetRoomReferencePos() const override;
	float GetDepthExportNearZ() const override;
	float GetDepthExportFarZ() const override;
	float GetAspectWByH() const override;
	float GetFovYDeg() const override;
	const SMatrix44& GetProjectionMatrix() const override;
	const SMatrix44& GetFPSProjectionMatrix() const override;
	float4 Project(const float4& vViewPos) const override;
	float4 Unproject(const float4& vDevicePos) const override;
	void CalculateBoundingRect(SVector2& vDeviceMin, SVector2& vDeviceMax, const SVector3* pViewVertices, unsigned int nNumVertices) const override;
	const ZEntityRef& GetPostfilter() const override;
	const ZEntityRef& GetRootNode() const override;
	const ZEntityRef& GetOSDRootNode() const override;
	bool IsOrthographic() const override;
	float4 GetOrthographicWindowSize() const override;
	float4 GetOrthographicPixelSize() const override;
	void LoadDefaultProjection(bool bPerspective) override;
	void LoadDefaultPerspectiveProjection() override;
	void LoadDefaultOrthographicProjection(float fPixelSize) override;
	void SetViewport(const SRenderViewport& viewport) override;
	void SetDestinationViewport(const SRenderViewport& viewport) override;
	void SetClearColor(SVector3 vClearColor) override;
	void SetPerspectiveFovRH(float fFovY, float fAspectWByH, float fNear, float fFar) override;
	void SetOrthogonalRH(float fWidth, float fAspectWByH, float fNear, float fFar) override;
	void SetCustomProjection(const SMatrix& mProjection) override;
	void SetAutoSize(bool bAutoSize) override;
	void SetAutoAspect(bool bAutoAspect) override;
	bool GetAutoAspect() const override;
	void SetPostfilter(const ZEntityRef& rPostfilter) override;
	void SetPostfilterOverride(bool bOverridePostfilter, const ZEntityRef& rPostfilter) override;
	void SetRootNode(const ZEntityRef& pRootNode) override;
	void SetOSDRootNode(const ZEntityRef& pOSDRootNode) override;
	void SetOrthographicPixelSize(float fPixelSize) override;
	void SetForceUpdateDependencies(bool bForceUpdate) override;
	bool GetForceUpdateDependencies() const override;
	bool GetSeperateFPSFovEnabled() const override;
	float4 GetListenerPos() const override;
	void SetSeperateFPSFovEnabled(bool bEnabled) override;
	void SetAspectWByH(float fAspectWByH) override;
	void SetFPSFovYDeg(float fDegrees) override;
	float GetFPSFovYDeg() const override;
	void GetGlowActive(bool& bShowGlow, bool& bShowHints) const override;
	void SetGlowActive(bool bShowGlow, bool bShowHints) override;
	bool WantCameraCut() const override;
	void SetWantCameraCut(bool bCut) override;
	bool GetAllowAutoCameraCuts() const override;
	float GetCameraCutTriggerDistance() const override;
	float GetCameraCutTriggerAngleDeg() const override;
	bool GetFPSDrawLocal() const override;
	void SetFPSDrawLocal(bool bDrawLocal) override;

	ZCameraEntity() = default;
	static void RegisterType();
	void OnCameraCut();
	void OnSetFovYDeg(float fVal);
	void OnSetFPSFovYDeg(float fVal);
	void OnSetAspectWByH(float fVal);
	void OnSetNearZ(float fVal);
	void OnSetFarZ(float fVal);
	void OnSetClearColor(SColorRGB vColor);
	ZCameraEntity(const ZCameraEntity& __that);
	ZCameraEntity(ZComponentCreateInfo& Info);
	void SetNearZ(float fNearZ);
	void SetFarZ(float fFarZ);
	bool IsPointOnScreen(const float4& vWorldSpacePoint) const;
	void SetRoomReferencePosOverrideCode(const float4& vPos);
	void UpdateProjection();
	void OnProjectionTypeChanged();
	void OnFovYDegChanged();
	void OnWidthChanged();
	void OnAspectWByHChanged();
	void OnNearZChanged();
	void OnFarZChanged();
	void OnActiveChanged();
	void OnRootNodeChanged();
	void OnOSDRootNodeChanged();
	void OnClearColorChanged();
	void OnAutoSizeChanged();
	void OnAutoAspectChanged();
	void OnPostfilterChanged(const TEntityRef<IRenderPostfilterControllerEntity>& oldFilter);
	void OnDepthExportNearZChanged();
	void OnDepthExportFarZChanged();
	void OnFPSFovYDegChanged();
	void OnFPSSeperateFOVChanged();
	void OnRoomReferencePosOverrideChanged(const TEntityRef<ZSpatialEntity>& oldValue);
	ZCameraEntity& operator=(const ZCameraEntity& __that);
};
