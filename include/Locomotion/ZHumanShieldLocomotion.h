#pragma once

#include "ZActorAnimationProgram.h"
#include "TEntityRef.h"
#include "ZHitman5.h"
#include "SActorHSState.h"
#include "ZActor.h"

class ZHumanShieldLocomotion : public ZActorAnimationProgram
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZString m_sAnimAction;
	ZString m_sAnimStates;
	TEntityRef<ZHitman5> m_pHitman;
	SActorHSState::eActorHSState m_eCurrentHSState;
	ZActor* m_pActor;
	float m_fBlendInTime;

	~ZHumanShieldLocomotion() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	EActorAnimationStatusUpdate Update(float fDeltaTime) override;

	static void RegisterType();
	ZHumanShieldLocomotion(ZActorAnimationState* pContext, ZActor* pActor, SActorHSState::EHSEnterAnimation eEnterAnimation);
	ZHumanShieldLocomotion() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	void ReleaseHumanShield();
	void UpdateHumanShieldAnim(const ZString& sRequest);
	void SetDefaultHumansShieldState(const unsigned int nStrafeID);
	SMatrix43 UpdateHumanShieldPos();
};
