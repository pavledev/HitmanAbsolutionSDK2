#pragma once

#include "SOrderParamsBase.h"
#include "TEntityRef.h"
#include "EActorAnimationOrder.h"
#include "SMatrix.h"
#include "ZPositionTarget.h"
#include "ZString.h"
#include "float4.h"

class IActListener;
class IChildNetworkEntity;
class ZChildNetworkActEntity;

struct SActOrderParams : SOrderParamsBase
{
	bool m_bLockOnNavmesh;
	bool m_bOverrideExistingActIfAny;
	ZString m_sAct;
	TEntityRef<IChildNetworkEntity> m_pChildNetworkEntity;
	float m_fDuration;
	SMatrix m_mActMatrix;
	float m_fPositionThreshold;
	bool m_bPreciseOrientation;
	bool m_bUpperbodyOnly;
	IActListener* m_pActListener;
	bool m_bMovingStart;
	bool m_bResumeOriginalPosition;
	bool m_bWaitUntilFullyCompleted;
	float4 m_csActPositionOffset;
	bool m_bHasActPositionOffset;
	bool m_bDisableShooting;
	bool m_bBlendOutImmediatelyUponTimeout;

	~SActOrderParams() override = default;

	SActOrderParams() = default;
	SActOrderParams(const SActOrderParams& __that);
	SActOrderParams(EActorAnimationOrder type);
	SActOrderParams(const TEntityRef<ZChildNetworkActEntity>& pChildNetworkActEntity);
	SActOrderParams(const TEntityRef<IChildNetworkEntity>& pChildNetworkEntity);
	SActOrderParams(const ZString& sAct);
	SActOrderParams& Duration(float fDuration);
	SActOrderParams& UpperbodyOnly(bool bUpperbodyOnly);
	SActOrderParams& Thresholds(float fPositionThreshold, float fAttitudeThreshold);
	SActOrderParams& ActMatrix(const SMatrix& mMatrix, bool bResumeOriginalPosition);
	SActOrderParams& Aim(const ZPositionTarget& target);
	SActOrderParams& LookAt(const ZPositionTarget& target);
	SActOrderParams& Face(const ZPositionTarget& target);
	SActOrderParams& FaceAndLookAt(const ZPositionTarget& target);
	SActOrderParams& OverrideExistingActIfAny();
	SActOrderParams& MovingStart(bool bMovingStart);
	SActOrderParams& WaitUntilFullyCompleted(bool bWaitUntilFullyCompleted);
	SActOrderParams& LockOnNavmesh(bool bLock);
	SActOrderParams& DisableShooting();
	SActOrderParams& BlendOutImmediatelyUponTimeout();
	void ApplyDefaultValues();
	SActOrderParams& ActPositionOffset(const float4& csPositionOffset, bool bResumeOriginalPosition);
};
