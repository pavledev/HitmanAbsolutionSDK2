#pragma once

#include "ZActorAnimationProgram.h"

class ZCarryCivilianLocomotion : public ZActorAnimationProgram
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
	SCarryCivilianActorHSState::eActorHSState m_eCurrentHSState;
	ZGameTime m_tEnterTime;
	SMatrix43 m_mvEnterMatPos;
	ZActor* m_pActor;
	bool m_bDirectToStandIdle;

	~ZCarryCivilianLocomotion() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	EActorAnimationStatusUpdate Update(float fDeltaTime) override;

	static void RegisterType();
	ZCarryCivilianLocomotion(ZActorAnimationState* pContext, ZActor* pActor, bool bDirectToStandIdle);
	ZCarryCivilianLocomotion() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	void ReleaseCarryCivilian();
	void UpdateCarryCivilianAnim(const ZString& sRequest);
	void SetDefaultCarryCivilianState(const unsigned int nStrafeID);
	SMatrix43 SlideIntoStartPos();
	SMatrix43 EnterCarryCivilianPos();
	SMatrix43 UpdateCarryCivilianPos();
};
