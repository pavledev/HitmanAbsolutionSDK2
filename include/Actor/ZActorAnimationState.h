#pragma once

#include "TEntityRef.h"
#include "EActorAnimationStatusUpdate.h"
#include "TSharedPointer.h"

class ZActor;
class ZActorAnimationProgram;
class ZMorphemeNetworkInstance;

class ZActorAnimationState
{
public:
	const TEntityRef<ZActor> m_pActor;
	ZMorphemeNetworkInstance* m_pNetwork;
	TSharedPointer<ZActorAnimationProgram> m_pCurrentAnimationProgram;
	EActorAnimationStatusUpdate m_eCurrentStatusUpdate;

	ZActorAnimationState() = default;
	ZActorAnimationState(const TEntityRef<ZActor>& pActor, ZMorphemeNetworkInstance* pNetwork);
	void FrameUpdateForControlledAnimPrograms(float fDeltaTime);
	bool IsCurrentProgram(const ZActorAnimationProgram* pProgram);
	bool HasProgram();
	void StopProgram(bool bStopFacial);
	void StartProgram(TSharedPointer<ZActorAnimationProgram> pProgram);
	const TEntityRef<ZActor>& Actor();
	void StartTransition(unsigned int nParentState, unsigned int nTargetState, unsigned int nRequestID);
	~ZActorAnimationState() = default;
};
