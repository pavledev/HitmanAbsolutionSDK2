#pragma once

#include "ZHM5LocomotionState.h"
#include "ZHM5LocomotionIdleState.h"
#include "ZHM5LocomotionToMoveState.h"
#include "ZHM5LocomotionTurnToMoveState.h"
#include "ZHM5LocomotionMoveState.h"
#include "ZHM5LocomotionTurnState.h"
#include "ZHM5LocomotionStrafeStandState.h"
#include "ZHM5LocomotionStrafeState.h"
#include "ZHM5LocomotionStandRootState.h"
#include "ZHM5LocomotionMoveRootState.h"
#include "ZHM5LocomotionRootState.h"
#include "ZHM5LocomotionStrafeRootState.h"
#include "ZVariant.h"
#include "ENetworkEvent.h"
#include "ENetworkControlParam.h"

class ZHM5LocomotionNetwork
{
public:
	ZHM5LocomotionState* m_apnNetworkState[18];
	ZHM5LocomotionState* m_apnStatesToDeactivate[18];
	ZHM5LocomotionState* m_apnStatesToActivate[18];
	ZHM5LocomotionState* m_apnStatesToUpdate[18];
	unsigned int m_nStatesToDeactivate;
	unsigned int m_nStatesToActivate;
	unsigned int m_nStatesToUpdate;
	ZHM5LocomotionIdleState m_IdleState;
	ZHM5LocomotionToMoveState m_ToMoveState;
	ZHM5LocomotionTurnToMoveState m_TurnToMoveLeftState45;
	ZHM5LocomotionTurnToMoveState m_TurnToMoveRightState45;
	ZHM5LocomotionTurnToMoveState m_TurnToMoveLeftState135;
	ZHM5LocomotionTurnToMoveState m_TurnToMoveRightState135;
	ZHM5LocomotionMoveState m_NormalMoveState;
	ZHM5LocomotionState m_ToStandState;
	ZHM5LocomotionTurnState m_TurnState;
	ZHM5LocomotionTurnState m_TurnState1;
	ZHM5LocomotionState m_IdleAnimation;
	ZHM5LocomotionStrafeStandState m_StrafeStand;
	ZHM5LocomotionStrafeState m_StrafeFoward;
	ZHM5LocomotionStrafeState m_StrafeBackward;
	ZHM5LocomotionStandRootState m_StandRootState;
	ZHM5LocomotionMoveRootState m_MoveRootState;
	ZHM5LocomotionRootState m_LocomotionRoot;
	ZHM5LocomotionStrafeRootState m_LocomotionStrafeRoot;
	ZMorphemeNetworkInstance* m_pNetwork;
	ZString m_sLocomotionPath;
	unsigned int m_nNodeIdRoot;
	unsigned int m_nNodeIdLocomotionRoot;
	unsigned int m_nNodeIdStrafeRoot;
	unsigned int m_anRequest[18];
	unsigned int m_anControlParameters[32];
	bool m_bFootStepEventTriggered;
	float m_fCharAngle;
	float m_fDeltaAngle;
	float m_fHeadAngle;
	bool m_bIdleAnimationsAllowed;
	unsigned int m_nRequestsSend;
	ZVariant m_aInitialControlParamValues[32];

	ZHM5LocomotionNetwork() = default;
	~ZHM5LocomotionNetwork() = default;
	void Init(bool bIsFullHitmanNetwork);
	void SetNetwork(ZMorphemeNetworkInstance* pNetwork);
	ZMorphemeNetworkInstance* GetNetwork();
	bool VerifyNetworkData() const;
	void Reset();
	void SetDefaultControlParams();
	const ZHM5LocomotionState* GetNetworkState(ENetworkState eState) const;
	ZHM5LocomotionMoveRootState& GetLocomotionMoveRootState();
	ZHM5LocomotionTurnState& GetTurnState();
	ZHM5LocomotionTurnState& GetTurnState1();
	void Update(float fDeltaTime, const float4& vHitmanDir, float fTimeMultiplier, bool bIdleAnimationAllowed);
	bool IsEventTriggered(ENetworkEvent eEvent) const;
	void GetControlParameter(ENetworkControlParam eControlParam, ZVariant& output);
	float GetControlParameterAsFloat(const ENetworkControlParam eControlParam) const;
	void SetControlParameter(ENetworkControlParam eControlParam, const ZVariantRef& newValue);
	bool IsNodeActive(unsigned int nNodeID);
	bool SendRequest(ENetworkRequest eNetworkRequest);
	bool IsRequestSend(ENetworkRequest eNetworkRequest);
	float GetCharAngle() const;
	float GetAnimationLength(ZString animPath) const;
	void SetCurrentState(ENetworkState eNetworkState, bool bRecurse);
	void SetCurrentStateAndParentState(ENetworkState eNetworkState);
	ENetworkState GetNetworkStateForNodeID(unsigned int nNodeID);
	void GetActiveStates(unsigned int& nActiveStates, unsigned int& nTransitionIn, unsigned int& nTransitionOut);
	float GetStrafeWeight() const;
	void GetStrafeWeights(float& fStrafeStandWeight, float& fStrafeSneakWeight) const;
	bool IsStrafeStateActive() const;
	bool IsStateActive(ENetworkState networkState) const;
	const ZString& GetLocomotionPath() const;
	unsigned int GetNodeID(const ZString& nodePath) const;
	float GetAnimTimeFraction(unsigned int animNodeID) const;
	void ResetInitialControlParamValues();
	float GetDeltaAngle() const;
	void SetDeltaAngle(float fDeltaAngle);
	void SetHeadAngle(float angle);
	void ClearStateArrays();
};
