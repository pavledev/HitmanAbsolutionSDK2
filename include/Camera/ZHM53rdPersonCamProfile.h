#pragma once

#include "ZEntityImpl.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
struct STypeID;

class ZHM53rdPersonCamProfile : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	float m_fLevelOutThresholdTimeAim;
	float m_fLevelOutThresholdTimeStand;
	float m_fLevelOutThresholdTimeStickVert;
	float m_fLevelOutAngle;
	float m_fSideChangeTime;

	static SComponentMapEntry s_componentMap[0];

	~ZHM53rdPersonCamProfile() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZHM53rdPersonCamProfile() = default;
	static void RegisterType();
	ZHM53rdPersonCamProfile(ZComponentCreateInfo& pInfo);
	float GetLevelOutThresholdTimeAim() const;
	float GetLevelOutThresholdTimeStand() const;
	float GetLevelOutThresholdTimeStickVert() const;
	float GetLevelOutAngle() const;
	float GetSideChangeTime() const;
};
