#pragma once

#include "ZEntityImpl.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
struct STypeID;

class ZShootingBalletConfig : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	float m_fSBEnemyRadius;
	int m_iSBMaxNumTags;
	float m_fSBTagSequenceTimeMultiplier;
	float m_fSBTagTime;
	float m_fSBTagTimeRampUpFraction;
	float m_fSBTagTimeRampUpFocus;
	float m_fSBTagRampUpMultiplier;
	float m_fSBExecutionMultiplier;
	float m_fSBExecutionGameTime;
	float m_fSBImpulseMultiplier;
	float m_fSBDamageMultiplier;
	float m_fSBMinTagDistance;
	float m_fSBRushZoomTimeMul;
	int m_iSBTagSlots;
	float m_fSBTagSlotTime;
	float m_fSBTagSlotBonus;
	float m_fSBExecutionTimeMultiplier;

	static SComponentMapEntry s_componentMap[0];

	~ZShootingBalletConfig() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZShootingBalletConfig() = default;
	static void RegisterType();
	ZShootingBalletConfig(ZComponentCreateInfo& info);
};
