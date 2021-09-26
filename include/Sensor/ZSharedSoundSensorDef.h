#pragma once

#include "ZEntityImpl.h"
#include "EAIEventType.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
struct STypeID;

class ZSharedSoundSensorDef : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	float m_fHearRangeFootstep;
	float m_fHearRangeLoudFootstep;
	float m_fHearRangeBulletImpact;
	float m_fHearRangeBark;
	float m_fHearRangePain;
	float m_fHearRangeScream;
	float m_fHearRangeAlarm;
	float m_fHearRangeAccident;
	float m_fHearRangeExplosion;
	float m_fHearRangeGunShot;
	float m_fHearRangeGunSilenced;
	float m_fHearRangeEmptyGun;
	float m_fHearRangeCloseCombat;
	float m_fHearRangeCCBreakNeck;
	float m_fHearRangeCCFiberWire;
	float m_fHearRangeCCChoke;
	float m_fHearRangeCCHitFromBehind;
	float m_fHearRangeRadio;
	float m_fHearThrownItemCollision;
	float m_fHearRangeFootstepLimitVisionAreaRun;
	float m_fHearRangeFootstepLimitVisionAreaWalk;
	float m_fHearRangeFootstepLimitVisionAreaSneakWalk;

	static SComponentMapEntry s_componentMap[0];

	~ZSharedSoundSensorDef() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZSharedSoundSensorDef() = default;
	static void RegisterType();
	ZSharedSoundSensorDef(ZComponentCreateInfo& info);
	float GetFootstepHearRange(bool bLoud) const;
	float GetEventHearRange(EAIEventType eventType) const;
	float GetFootstepHearRangeLimitVisionAreaRun() const;
	float GetFootstepHearRangeLimitVisionAreaWalk() const;
	float GetFootstepHearRangeLimitVisionAreaSneakWalk() const;
};
