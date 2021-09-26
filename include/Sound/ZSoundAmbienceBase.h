#pragma once

#include "ZEntityImpl.h"
#include "ISoundAmbienceElement.h"

class ZSoundAmbienceBase : public ZEntityImpl, public ISoundAmbienceElement
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	static SComponentMapEntry s_componentMap[0];

	~ZSoundAmbienceBase() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	void ForceStart() override;
	void ForceStop() override;
	void SetGamePaused(bool bGamePaused) override;
	void SetTempSpatialPosition(const SVector3& vPos, unsigned int nRecursionTag) override;
	void SetTempSpatialOcclusionAttenuation(float fOcclusionAttenuation, unsigned int nRecursionTag) override;
	void SetTempSpatialOcclusionLowpassCutoff(float fOcclusionLowpassCutoff, unsigned int nRecursionTag) override;
	void AddDynamicParameters(float fWeight, float fHybridWeight, bool bClearAndSet) override;
	void AmbienceTraverse(unsigned int nRecursionTag, ESoundAmbienceOperation eOperation, SSoundAmbienceDynamicParameters* pDynamicParameters) override;
	void UpdatePause() override;
	bool IsInside() override;

	ZSoundAmbienceBase() = default;
	static void RegisterType();
	ZSoundAmbienceBase(ZComponentCreateInfo& info);
	void Restore();
	void ForceRestart();
	void OnDEBUG_MakeCurrent();
};
