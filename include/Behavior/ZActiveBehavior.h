#pragma once

#include "TEntityRef.h"
#include "MR.h"
#include "SReactOrderParams.h"
#include "SActorSoundDefs.h"
#include "EActorEmotionState.h"
#include "EActorRank.h"
#include "EActorType.h"
#include "TRefCountPtr.h"

class ZActor;
class ZActorDialog;
class ZSituationBase;
class ZGridFloatField;
class ZKnowledge;
class ZHitman5;
class ZActorAnimationState;
class ZAnimatedActor;
struct SKnownEntity;
template <class T> class TRefCountPtrArg;

class ZActiveBehavior
{
public:
	TEntityRef<ZActor> m_pActor;

	virtual ~ZActiveBehavior() = default;
	virtual void OnAnimationEvents(const MR::TriggeredEventsBuffer& animationEvents);

	ZActiveBehavior() = default;
	void SetActor(const TEntityRef<ZActor>& pActor);
	TEntityRef<ZActor> GetActor() const;
	ZAnimatedActor* GetAnimatedActor() const;
	TRefCountPtr<ZActorDialog> StartDialog(SActorSoundDefs::EDefinition eSoundDefinition);
	void InterruptDialog(TRefCountPtrArg<ZActorDialog>& pDialog, bool bStopSpeak);
	ZKnowledge& Knowledge();
	TEntityRef<ZHitman5> GetHitman();
	ZActorAnimationState* GetAnimationState();
	void StopAct(EActorEmotionState eEndState);
	void SwitchToEmotionStateIfNeeded(EActorEmotionState eEmotionState);
	SReactOrderParams GetReactParameters(const TEntityRef<ZSituationBase>& pSituation, const TRefCountPtr<SKnownEntity>& rTarget, bool bStanddown);
	TEntityRef<ZActor> FindMinAliveActorFromFloatField(TRefCountPtrArg<ZGridFloatField> field, float& fDistance, float fMaxValue, EActorType type, EActorRank rank, bool bConsiderCombatants);
	TEntityRef<ZActor> FindMaxAliveActorFromFloatField(TRefCountPtrArg<ZGridFloatField> field, float fMinValue, EActorType type, EActorRank rank, bool bConsiderCombatants);
};
