#pragma once

#include "ZEntityImpl.h"
#include "IHM5ActionEntityListener.h"
#include "ZHM5Outfit.h"

class ZHM5DisguiseSafeZoneEntity : public ZEntityImpl, public IHM5ActionEntityListener
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	TEntityRef<IChildNetworkEntity> m_pSafeZoneNetwork;
	TEntityRef<ZHM5Action> m_pAction;
	TArray<TEntityRef<ZHM5Outfit>> m_OutfitList;
	TEntityRef<ZSpatialEntity> m_pSafeZoneOrigin;
	TEntityRef<IEventConsumerCollection> m_pEventConsumerCollection;
	bool m_bHideItems;
	bool m_bHideHitman;
	bool m_bEnabled;
	bool m_bAlignYawAngle;
	float m_fYawAngle;
	bool m_bAlignPitchAngle;
	float m_fPitchAngle;
	bool m_bSafeZoneInUse;

	static SComponentMapEntry s_componentMap[0];
	static unsigned int m_snEnterSafeZone;
	static unsigned int m_snExitSafeZone;
	static unsigned int m_snCheckHitmanOutfit;
	static unsigned int m_snHitmanHasOutfit;

	~ZHM5DisguiseSafeZoneEntity() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void Activate(const ZString& sSubset) override;
	void Deactivate(const ZString& sSubset) override;
	void Init() override;

	bool GetActionAABB(const ZHM5Action* pAction, float4& vMin, float4& vMax) const override;
	bool IsActionValid(ZHM5Action* pAction, const TEntityRef<ZHM5BaseCharacter>& pOperator) override;
	bool DisplayFarFeedback(ZHM5Action* pAction, const TEntityRef<ZHM5BaseCharacter>& pOperator) override;
	bool ActivateAction(ZHM5Action* pAction, const TEntityRef<ZHM5BaseCharacter>& pOperator) override;

	ZHM5DisguiseSafeZoneEntity() = default;
	static void RegisterType();
	ZHM5DisguiseSafeZoneEntity(ZComponentCreateInfo& info);
	ZSpatialEntity* GetSafeZoneOrigin() const;
	TEntityRef<IChildNetworkEntity> GetSafeZoneNetwork() const;
	void SetActionType(EActionType eActionType) const;
	EActionType GetActionType() const;
	void SetSafeZoneActionEnter() const;
	void SetSafeZoneActionInvalid() const;
	void SetSafeZoneActionExit() const;
	bool IsInValidState(ZHM5Action* pAction, const TEntityRef<ZHM5BaseCharacter>& pOperator);
	void OnExitSafeZone();
	void OnEnterSafeZone();
	void OnEnable();
	void OnDisable();
	TEntityRef<IEventConsumerCollection> GetEventConsumerCollection();
	void OnCheckHitmanOutfit();
	bool IsSafeZoneValid();
	bool GetAlignYawAngle() const;
	float GetYawAngle() const;
	bool GetAlignPitchAngle() const;
	float GetPitchAngle() const;
	bool GetHideItems() const;
	TEntityRef<ZHitman5> Hitman() const;
	void EnterSafeZone();
	void ExitSafeZone();
};
