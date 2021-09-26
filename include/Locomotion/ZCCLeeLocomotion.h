#pragma once

#include "ZActorAnimationProgram.h"
#include "ZHM5CCAnimDatabase.h"
#include "SAnimTime.h"

class ZCCLeeLocomotion : public ZActorAnimationProgram
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	enum ECCLocoState
	{
		eCCLocoState_CloseCombat = 0,
		eCCLocoState_TransitIdle = 1,
		eCCLocoState_Idle = 2,
		eCCLocoState_Ragdoll = 3
	};

	ECCLocoState m_eState;
	TEntityRef<ZHitman5> m_pHitman;
	TEntityRef<ZHM5ItemCCWeapon> m_pCCWeapon;
	ZHM5CCAnimDatabase* m_pAnimDatabase;
	const SAnimNodeNPC* m_pCurrentNode;
	bool m_bCloseCombatStarted;
	unsigned int m_nCCRootNode;
	unsigned int m_nCCBlendNode;
	bool m_bIdle;
	bool m_bCloseCombatIdleRequestSend;
	bool m_bBoss;
	bool m_bGetUpFromPacify;
	ZHM5CCTargetController* m_pTargetController;
	int m_nHitmanFreeAttacher;
	float m_fBackInPosTime;
	float4 m_vLastPos;
	SAnimTime m_aAnimTime[2];
	unsigned int m_nNetworkIndex;
	bool m_bSingleNetworkActive;
	bool m_bFirstAnim;
	float m_fControlledBlend;
	bool m_bFightIdle;
	bool m_bPacifyIdle;
	bool m_bHitmanStartedCloseCombat;
	bool m_bTakeDownOverride;
	float m_fContactTime;
	float m_fBlendToContactTime;
	bool m_bIsMoving;
	ZMorphemeNetworkInstance* m_pChildNetwork;

	~ZCCLeeLocomotion() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	void OnComplete() override;
	EActorAnimationStatusUpdate Update(float fDeltaTime) override;

	static void RegisterType();
	ZCCLeeLocomotion(ZActorAnimationState* pContext);
	ZCCLeeLocomotion() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	void UpdateCloseCombat(const float fDeltaTime);
	void UpdateInCombat(const float fDeltaTime);
	void UpdateNotInCombat(const float fDeltaTime);
	void UpdateControlParameters(float fAnimTime, float fDeltaTime);
	void SetupTransitToIdle();
	bool HandleNodes();
};
