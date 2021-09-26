#pragma once

#include "ZEntityImpl.h"
#include "IGamePostfilterControllerEntity.h"
#include "SColorRGB.h"
#include "TResourcePtr.h"
#include "TEntityRef.h"
#include "SComponentMapEntry.h"
#include "SRenderPostfilterPerScreenDecalParametersInternal.h"
#include "SVector2.h"
#include "SVector3.h"
#include "ZEntityRef.h"
#include "ZResourcePtr.h"
#include "ZVariantRef.h"

struct SGameUpdateEvent;
class IRenderPostfilterParametersEntity;
class ZComponentCreateInfo;
class ZRenderTextureResource;
struct SRenderPostfilterParameters;
struct SRenderPostfilterParametersScreenDecals;
struct SRenderPostfilterPerScreenDecalParameters;
struct STypeID;

class ZHM5PostfilterController : public ZEntityImpl, public IGamePostfilterControllerEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum
	{
		NUM_SCREEN_DECAL_TEXTURES = 3
	};

	enum
	{
		MAX_NUM_SCREEN_DECALS_PER_FRAME = 4
	};

	float m_fSpatialBlurStart;
	SVector3 m_fSpatialBlurCenter;
	float m_fSpatialBlurFade;
	float m_fSpatialBlurriness;
	float m_fRadialBluriness;
	float m_fRadialBlurStart;
	SVector2 m_vRadialBlurCenter;
	float m_fRadialBlurFadeFactor;
	bool m_bScreenDecalsEnabled;
	float m_fScreenDecalsTTL;
	float m_fScreenDecalsSettleTime;
	float m_fScreenDecalsFadeTime;
	float m_fScreenDecalsScaleTime;
	float m_fScreenDecalsOpacity;
	float m_fScreenDecalsRefractionScale;
	float m_fScreenDecalsBlurrinessScale;
	float m_fScreenDecalsColorScale;
	SColorRGB m_ScreenDecalsColor;
	SVector2 m_vScreenDecalsTiles;
	float m_fScreenDecalsSizeDeviation;
	SVector3 m_vScreenDecalsSingleSize;
	ZResourcePtr m_pScreenDecalsSingleTex;
	SVector3 m_vScreenDecalsPairASize;
	ZResourcePtr m_pScreenDecalsPairATex;
	SVector3 m_vScreenDecalsPairBSize;
	ZResourcePtr m_pScreenDecalsPairBTex;
	TResourcePtr<ZRenderTextureResource> m_pScreenDecalsTexRPs[3];
	SRenderPostfilterPerScreenDecalParametersInternal m_ScreenDecals[4];
	unsigned int m_nScreenDecalsNumAdded;
	TEntityRef<IRenderPostfilterParametersEntity> m_rCurrentGameMode;
	bool m_bSpatialBlurEnabled;
	bool m_bSpatialBlurUpdate;
	bool m_bRadialBlurUpdate;
	bool m_bRadialBlurEnabled;
	bool m_bSniperUpdate;
	bool m_bSniperEnabled;
	bool m_bDepthBlurUpdate;
	float m_fDepthBlurValue;
	float m_fSniperBlur;
	ZEntityRef m_rPostfilterControllerEntity;
	bool m_bHitmanRegistered;

	static SComponentMapEntry s_componentMap[0];

	~ZHM5PostfilterController() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	void UpdateParameters(SRenderPostfilterParameters& parameters) override;
	void SetDefaultParameters(const SRenderPostfilterParameters& parameters, float fTransitionDuration) override;
	void SetRenderPostfilterControllerEntity(ZEntityRef rPostfilterControllerEntity) override;
	unsigned int GetGameLerpMask() override;
	unsigned int UpdateScreenDecals(SRenderPostfilterPerScreenDecalParametersInternal* pScreenDecalArray, unsigned int nArrayOffset) override;

	ZHM5PostfilterController() = default;
	static void RegisterType();
	ZHM5PostfilterController(ZComponentCreateInfo& pInfo);
	void SetSpatialBlurSetStart(float fSpatialBlurStart, const SVector3& vCenter);
	void SetSpatialBlurSetFadeDist(float fSpatialBlurFadeDist);
	void SetSpatialBlurSetBluriness(float fSpatialBluriness);
	void SetRadialBluriness(float fRadialBluriness);
	void SetRadialBlurStart(float fRadialBlurStart);
	void SetRadialBlurCenter(SVector2 vRadialBlurCenter);
	void ScreenDecalsAdd(SRenderPostfilterPerScreenDecalParameters& params);
	void SetDepthBlurValue(float fValue);
	void FrameUpdate(const SGameUpdateEvent& updateEvent);
	void OnScreenDecalsSingleTexChanged();
	void OnScreenDecalsPairATexChanged();
	void OnScreenDecalsPairBTexChanged();
	void SetSniperBlur(bool bEnabled);
	bool UpdateParametersScreenDecals(SRenderPostfilterParametersScreenDecals& parameters);
};
