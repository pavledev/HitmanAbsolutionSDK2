#pragma once

#include "ZSpatialEntity.h"
#include "SComponentMapEntry.h"
#include "SMatrix.h"
#include "TEntityRef.h"
#include "ZString.h"
#include "ZVariantRef.h"

class ZComponentCreateInfo;
class ZLinkedEntity;
struct STypeID;

class ZHM5WeaponHandPosBox : public ZSpatialEntity
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TEntityRef<ZLinkedEntity> m_linkedEntity;
	ZString m_BoneName;
	float m_fSwivelAngle;
	float m_fSwivelContribution;

	static SComponentMapEntry s_componentMap[0];

	~ZHM5WeaponHandPosBox() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZHM5WeaponHandPosBox() = default;
	static void RegisterType();
	ZHM5WeaponHandPosBox(ZComponentCreateInfo& pInfo);
	SMatrix GetLeftHandTransform() const;
	float GetSwivelAngle() const;
	float GetSwivelContribution() const;
};
