#pragma once

#include "ZSoundBlendContainerBase.h"
#include "SSBCExternalParametersData.h"

class ZSoundBlendContainerExternalParameters : public ZSoundBlendContainerBase
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	bool m_bAutoDestruct;
	SSBCExternalParametersData* m_pData;

	static SComponentMapEntry s_componentMap[0];

	~ZSoundBlendContainerExternalParameters() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;
	void RegisterSpatialParameter(ZSoundSpatialParameter* pSpatial) override;
	void Stop() override;
	bool IsPlaying() const override;
	void SetupAndStartEvent(bool bStartedFromGUI, const float4& vTargetPos) override;
	float GetAbsoluteFromNormal(int nIndex, float fNormalizedParam) const override;
	float GetNormalizedParameter(int nIndex, float fParam) const override;
	virtual bool IsDistanceControlled(unsigned int index) const;

	void ReleaseSustainPointAt(unsigned int nSustainSourceIndex) override;
	int GetNumSourceParameters() const override;
	int GetSourceParameterIndexFromID(unsigned int nParameterID) override;

	ZSoundBlendContainerExternalParameters() = default;
	static void RegisterType();
	ZSoundBlendContainerExternalParameters(ZComponentCreateInfo& Info);
	void UpdateListenerPosition(const SMatrix& mListenerTransform);
	bool IsDistanceControlled() const;
	bool IsAutomatedSource(unsigned int index) const;
	const SSBCExternalParametersProperties& GetProps(unsigned int index) const;
	void OnParameterChangedViaPin(const ZVariant& value, unsigned int nExtraData);
	void OnParameterPinReleased(const ZVariant& value, unsigned int nSustainSourceIndex);
	bool HasAutomatedSources() const;
	void SetParameterOnEvents(int nIndex, float fValue);
	float* GetParameterPtr();
};
