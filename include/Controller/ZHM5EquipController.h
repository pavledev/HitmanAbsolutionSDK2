#pragma once

#include "ZHM5BaseController.h"
#include "EHM5BaseControllerType.h"
#include "EHM5ResetReason.h"
#include "TEntityRef.h"

class IHM5Item;
class IMorphemeEntity;
class ZHitman5;
class ZMorphemeNetworkInstance;
struct SHM5ControllerUpdateEvent;

class ZHM5EquipController : public ZHM5BaseController
{
public:
	TEntityRef<ZHitman5> m_pHitman;
	ZMorphemeNetworkInstance* m_pMrNetwork;
	float m_fGripBlendFraction;
	float m_fEquipAnimFraction;
	float m_fAnimDuration;
	float m_fAnimTime;
	bool m_bInitialized;
	bool m_bIsEquiping;
	bool m_bSetItemHandlingFlag;
	unsigned int m_nEquipAnimNodeID;
	unsigned int m_nCrouchEquipAnimNodeID;

	~ZHM5EquipController() override = default;
	void Update(const SHM5ControllerUpdateEvent& HM5ControllerUpdateEvent) override;
	void Reset(EHM5ResetReason eResetReason) override;

	ZHM5EquipController() = default;
	ZHM5EquipController(const TEntityRef<ZHitman5>& pHitman, EHM5BaseControllerType eType);
	void Initialize(const TEntityRef<IMorphemeEntity>& rMorphemeEntity);
	bool IsEquiping() const;
	bool ShowWeapon() const;
	void QueueEquipItem(const TEntityRef<IHM5Item>& rRightItem, const TEntityRef<IHM5Item>& rLeftItem);
	TEntityRef<ZHitman5> Hitman();
};
