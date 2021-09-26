#pragma once

#include "ZGameTime.h"
#include "ENetworkState.h"
#include "PullToAngle.h"
#include "ENetworkRequest.h"

class ZHM5LocomotionNetwork;
class ZHM5LocomotionInput;
struct STurnOnSpotAnim;

class ZHM5LocomotionState
{
public:
	unsigned int m_nStateNodeID;
	ZGameTime m_TimeInState;
	bool m_bTransitionIn;
	bool m_bTransitionOut;
	bool m_bActive;
	float m_fTransitFraction;
	bool m_bCanSendRequestsDuringTransitionIn;
	bool m_bCanSendRequestsDuringTransitionOut;
	ENetworkState m_eStateType;
	float m_fBankWeightTarget;
	float m_fBankWeight;
	float m_fRemappedBankWeight;

	static ZHM5LocomotionNetwork* m_pLocomotionNetwork;
	static ZHM5LocomotionInput* m_pLocomotionInput;
	static const float m_fBankingThreshold;
	static const STurnOnSpotAnim* m_pTurnOnSpotAnim;
	static float m_fBlendInTurnAngle;
	static float m_fTurnAnimFraction;
	static float m_fTurnTimer;
	static float m_fTurnBlendTarget;
	static float m_fTurnBlend;
	static bool m_bFadeOutTurnOnSpot;
	static PullToAngle m_TurnAnglePull;
	static PullToAngle m_HeadAnglePull;
	static float m_fPrevOffset;

	virtual ~ZHM5LocomotionState() = default;
	virtual void Init(ENetworkState eStateType);
	virtual void Activate();
	virtual void Update(float fDeltaTime);
	virtual void Deactivate();

	ZHM5LocomotionState() = default;
	static void SetLocomotionNetwork(ZHM5LocomotionNetwork* pLocomotionNetwork);
	static void SetLocomotionInput(ZHM5LocomotionInput* pLocomotionInput);
	void SetIgnoreTransitionIn(bool bVal);
	void SetIgnoreTransitionOut(bool bVal);
	bool CanSendRequest() const;
	bool SendRequest(ENetworkRequest eRequest) const;
	float ClampDeltaTurn(float fDeltaTurn, float fDeltaTime) const;
	void SetDeltaTurnAngle(float fDeltaTime);
	ENetworkState GetNetworkState() const;
	float ApplyDeadZoneRemap(float fInput, float fDeadZone);
	void SetBankParameters(float fDeltaTime, const float fCharAngle);
	void Reset();
};
