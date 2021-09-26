#pragma once

#include "IComponentInterface.h"
#include "ZSharedPointerTarget.h"
#include "EActorAnimationStatusUpdate.h"
#include "MR.h"
#include "ZString.h"
#include "ZVariantRef.h"

class ZActorAnimationState;
class ZAnimatedActor;
class ZMorphemeNetworkInstance;
struct SComponentMapEntry;
struct STypeID;

class ZActorAnimationProgram : public IComponentInterface, public ZSharedPointerTarget
{
public:
	enum
	{
		COPYABLE = 0,
		ASSIGNABLE = 0
	};

	ZActorAnimationState* m_pState;
	bool m_bCompleted;
	float m_fLogTimer;
	ZMorphemeNetworkInstance* m_pNetwork;
	unsigned int nodeControlled;
	unsigned int nodeHumanShield;
	unsigned int nodeHumanShieldMove;
	unsigned int nodeHumanShieldMoveForward;
	unsigned int nodeHumanShieldMoveBackward;
	unsigned int nodeHumanShieldMoveLeft;
	unsigned int nodeHumanShieldMoveRight;
	unsigned int nodeHumanShieldIdle;
	unsigned int nodeCarryCivilian;
	unsigned int nodeCarryCivilianMove;
	unsigned int nodeCarryCivilianMoveForward;
	unsigned int nodeCarryCivilianMoveBackward;
	unsigned int nodeCarryCivilianMoveLeft;
	unsigned int nodeCarryCivilianMoveRight;
	unsigned int nodeCarryCivilianIdle;
	unsigned int nodeHumanShieldExit;
	unsigned int nodeHumanShieldExitKill;
	unsigned int paramAnimPrct;
	unsigned int paramCloseCombatBlend;
	unsigned int paramCloseCombatBossBlend;
	unsigned int paramCloseCombatFraction1;
	unsigned int paramCloseCombatFraction2;
	unsigned int paramControlled;
	unsigned int requestHumanShieldMove;
	unsigned int requestHumanShieldStop;
	unsigned int requestHumanShieldForward;
	unsigned int requestHumanShieldBackward;
	unsigned int requestHumanShieldLeft;
	unsigned int requestHumanShieldRight;
	unsigned int requestHumanShieldKnockOutVictim;
	unsigned int requestHumanShieldKillVictim;
	unsigned int requestCarryCivilianMove;
	unsigned int requestCarryCivilianIdle;
	unsigned int requestCarryCivilianForward;
	unsigned int requestCarryCivilianBackward;
	unsigned int requestCarryCivilianLeft;
	unsigned int requestCarryCivilianRight;

	~ZActorAnimationProgram() override = default;
	ZVariantRef GetVariantRef() const override;
	int AddRef() override;
	int Release() override;
	void* QueryInterface(STypeID* iid) override;
	virtual void OnComplete();
	virtual void OnAnimationEvents(const MR::TriggeredEventsBuffer& animationEvents);
	virtual EActorAnimationStatusUpdate Update(float fDeltaTime);
	virtual ZString GetDebugName();

	ZActorAnimationProgram(ZActorAnimationState* pContext);
	ZActorAnimationProgram() = default;
	const SComponentMapEntry* GetComponentInterfacesInternal() const;
	void SetCompleted();
	ZAnimatedActor& AnimatedActor() const;
	ZActorAnimationState* GetState() const;
	void RefreshNodeCache();
};
