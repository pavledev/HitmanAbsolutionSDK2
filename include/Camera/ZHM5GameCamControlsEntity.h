#pragma once

#include "ZEntityImpl.h"
#include "ECameraControls.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

struct SHM5GameCamParams;
class ZComponentCreateInfo;
struct STypeID;

class ZHM5GameCamControlsEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	float m_fYawSpeed;
	float m_fYawSpeedFast;
	float m_fPitchSpeed;
	float m_fPitchSpeedFast;
	float m_fFastSpeedDelay;
	float m_fFastSpeedBlendInTime;
	ECameraControls m_eCameraControls;

	static SComponentMapEntry s_componentMap[0];

	~ZHM5GameCamControlsEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;

	ZHM5GameCamControlsEntity() = default;
	static void RegisterType();
	ZHM5GameCamControlsEntity(ZComponentCreateInfo& pInfo);
	void GetControls(SHM5GameCamParams& Ret) const;
};
