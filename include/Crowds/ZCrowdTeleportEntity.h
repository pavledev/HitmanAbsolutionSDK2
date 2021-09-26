#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "TeleportActionType.h"
#include "SComponentMapEntry.h"
#include "ZVariantRef.h"

class ZCrowdActor;
class IBoxVolumeEntity;
class ZComponentCreateInfo;
struct STypeID;

class ZCrowdTeleportEntity : public ZEntityImpl
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TEntityRef<IBoxVolumeEntity> m_rExitZone;
	TEntityRef<IBoxVolumeEntity> m_rEnterZone;
	TeleportActionType m_eExitActionAmbient;
	TeleportActionType m_eExitActionScared;
	bool m_bOnlyCulled;
	bool m_bEnabled;
	unsigned int m_nFlowIndex;

	static SComponentMapEntry s_componentMap[0];

	~ZCrowdTeleportEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Init() override;

	ZCrowdTeleportEntity() = default;
	static void RegisterType();
	ZCrowdTeleportEntity(ZComponentCreateInfo& Info);
	TEntityRef<IBoxVolumeEntity> GetExitZone() const;
	TEntityRef<IBoxVolumeEntity> GetEnterZone() const;
	TeleportActionType GetScaredExitAction() const;
	bool GetOnlyCulled() const;
	unsigned short GetExtraCost() const;
	void TeleportActor(ZCrowdActor* pCrowdActor);
	void OnSetScaredActionStay();
	void OnSetScaredActionLeave();
	void OnSetScaredActionTeleport();
	void OnSetEnabled(bool bEnabled);
	void OnEnable();
	void OnDisable();
	void TryMoveToFreeLocation(ZCrowdActor* pCrowdActor);
};
