#pragma once

#include "SActOrderParams.h"
#include "EActorEmotionState.h"
#include "ZPositionTarget.h"

class ZString;

struct SReactOrderParams : SActOrderParams
{
	EActorEmotionState m_targetEmotionState;
	bool m_bDeadbody;
	bool m_bExplosion;
	bool m_bExplosionNear;
	bool m_bTrespassing;

	~SReactOrderParams() override = default;

	SReactOrderParams() = default;
	SReactOrderParams(const SReactOrderParams& __that);
	SReactOrderParams(EActorEmotionState targetEmotionState, ZString sReaction);
	SReactOrderParams(EActorEmotionState targetEmotionState);
	SReactOrderParams& EndState(EActorEmotionState targetEmotionState);
	SReactOrderParams& Face(const ZPositionTarget& target);
	SReactOrderParams& AimAndFace(const ZPositionTarget& target);
	SReactOrderParams& DeadBody();
	SReactOrderParams& Explosion();
	SReactOrderParams& Trespassing();
	EActorEmotionState GetTargetEmotionState() const;
	bool IsValid();
};
