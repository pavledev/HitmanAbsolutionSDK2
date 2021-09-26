#pragma once

#include "ZRenderableEntity.h"
#include "IRenderPostfilterControllerEntity.h"

class ZRenderPostfilterControllerEntity : public ZRenderableEntity, public IRenderPostfilterControllerEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum
	{
		eLerpStopState = 0,
		eLerpProgressState = 1,
		eLerpStartState = 2
	};

	ZEntityRef m_PostfilterParametersEntity;
	ZEntityRef m_GamePostfilterControllerEntity;
	bool m_bLerpGaussian;
	bool m_bLerpMotion;
	bool m_bLerpRadial;
	bool m_bLerpSpatial;
	bool m_bLerpColorCorrection;
	bool m_bLerpDepthOfField;
	bool m_bLerpDistortionBarrel;
	bool m_bLerpDistortionWobble;
	bool m_bLerpDoubleVision;
	bool m_bLerpFastFog;
	bool m_bLerpFog;
	bool m_bLerpHDR;
	bool m_bLerpMisc;
	bool m_bLerpNoise;
	bool m_bLerpSSAO;
	bool m_bLerpVideo;
	bool m_bLerpVignette;
	float m_fBlendTime;
	bool m_bRoomLerpEnabled;
	float m_fLuminance;
	ZEntityRef m_CurrentPostfilterParametersEntity;
	SRenderPostfilterParameters m_sourcePostfilterParameters;
	SRenderPostfilterParameters m_targetPostfilterParameters;
	SRenderPostfilterParameters m_currentPostfilterParameters;
	SRenderPostfilterParameters m_roomParameters;
	SRenderPostfilterPerScreenDecalParametersInternal m_RingBuffer[64];
	unsigned int m_nNumDecalsAdded;
	int m_nLerpState;
	float m_fLerpValue;
	float m_fLerpTime;
	unsigned int m_nLerpMask;

	static SComponentMapEntry s_componentMap[0];

	~ZRenderPostfilterControllerEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	TEntityRef<IRenderPostfilterParametersEntity> GetCurrentParametersEntity() const override;
	TEntityRef<IRenderPostfilterParametersEntity> GetParametersEntity() const override;
	void UpdateParameters(SRenderPostfilterParameters& parameters) override;
	void LerpParameters(ZEntityRef pPostfilterParametersEntity) override;
	void ReportParametersChanged() override;
	void RestartLerp(const float fTime) override;
	void SetRoomLerp(const bool bOn) override;
	bool GetRoomLerp() const override;
	float GetLuminance() const override;
	unsigned int GetScreenDecals(SRenderPostfilterPerScreenDecalParametersInternal** pScreenDecals) override;
	void ClearScreenDecals() override;

	ZRenderPostfilterControllerEntity() = default;
	static void RegisterType();
	ZRenderPostfilterControllerEntity(ZComponentCreateInfo& Info);
	void FrameUpdate(const SGameUpdateEvent& updateEvent);
	void OnRoomLerpEnabledChanged();
	void OnPostfilterParametersEntityChanged(const ZEntityRef& oldPostfilterParametersEntity);
	void UpdateParametersEntity();
	void SetModifiedLerpMask();
	void InitiateLerp(const float fTime);
	bool ParametersCompareNotEqual(const SRenderPostfilterParameters& pBufA, const SRenderPostfilterParameters& pBufB) const;
};
