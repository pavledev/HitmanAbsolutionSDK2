#pragma once

#include "ZRayQueryInput.h"
#include "ZRayQueryOutput.h"
#include "IAsyncRayHandle.h"
#include "ZActor.h"
#include "ZCrowdActor.h"

struct SNearEnemyCheckReq
{
	ZRayQueryInput m_NECInputs[3];
	ZRayQueryOutput m_NECOutputs[3];
	IAsyncRayHandle* m_pHandles[3];
	TEntityRef<ZActor> m_pActor;
	TEntityRef<ZCrowdActor> m_pCrowdActor;
	unsigned char m_nNumCasts;
	unsigned char m_nIsReadyBits;

	SNearEnemyCheckReq(const SNearEnemyCheckReq& __that);
	SNearEnemyCheckReq() = default;
	void ReleaseRaycastHandles();
	void ColiFetchedForRequest();
	bool AreAllReady() const;
	bool HasHit(unsigned int iIndex) const;
	void SetReady(unsigned int iIndex);
	void ResetReady(unsigned int iIndex);
	~SNearEnemyCheckReq() = default;
};
