#pragma once

#include "ZEntityImpl.h"
#include "ESBCamProfileBone.h"
#include "ESBPose.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
struct SSBCamHitmanProfile;
struct STypeID;

class ZHM5SBCamHitmanProfile : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	float m_fHeight;
	float m_fStickLength;
	float m_fRadius;
	float m_fFOV;
	float m_fRoll;
	float m_fYawAngle;
	float m_fPitchAngle;
	ESBCamProfileBone m_eBone;
	ESBPose m_ePose;

	static SComponentMapEntry s_componentMap[0];

	~ZHM5SBCamHitmanProfile() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZHM5SBCamHitmanProfile() = default;
	static void RegisterType();
	ZHM5SBCamHitmanProfile(ZComponentCreateInfo& pInfo);
	void GetSBCamHitmanProfile(SSBCamHitmanProfile& Ret);
};
