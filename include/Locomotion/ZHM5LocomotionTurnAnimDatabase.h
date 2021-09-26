#pragma once

#include "STurnAnim.h"
#include "ETurnAnimType.h"

class ZMorphemeNetworkInstance;

class ZHM5LocomotionTurnAnimDatabase
{
public:
	STurnAnim m_anTurnAnims[48];
	int m_nNumAnims;
	unsigned int m_nRootNodeId;
	ZMorphemeNetworkInstance* m_pNetwork;

	static const int MAX_ANIMS;

	ZHM5LocomotionTurnAnimDatabase() = default;
	~ZHM5LocomotionTurnAnimDatabase() = default;
	const STurnAnim* SetTurnAnim(float fRotation, ETurnAnimType eTurnAnimType, bool bRightLeg, bool bHalfStep) const;
	void FindAnimations(ZMorphemeNetworkInstance* pNetwork, unsigned int nRootNodeId);
	float GetFraction(const STurnAnim* pTurnAnim) const;
	float GetDeltaRotation(const STurnAnim* pTurnAnim, float fFrom, float fTo) const;
	ETurnAnimType GetType(const char* pszType) const;
	bool GetRightLeg(const char* pszRightLeg) const;
	bool GetHalfStep(const char* pszHalfStep) const;
};
