#pragma once

#include "ZEntityImpl.h"
#include "ICharacterAct.h"
#include "IActListener.h"
#include "TEntityRef.h"
#include "ZBoneAttachEntity.h"
#include "IActorAction.h"
#include "IChildNetworkEntity.h"
#include "EActorPerceptionSensitivity.h"
#include "EActorEmotionState.h"

class alignas(4) ZChildNetworkActEntity : public ZEntityImpl, public ICharacterAct, public IActListener
{
public:
    TArray<TEntityRef<ZBoneAttachEntity>> m_aBoneAttachers;
    TArray<TEntityRef<IActorAction>> m_aActorItemActions;
    TEntityRef<IChildNetworkEntity> m_pChildNetwork;
    TEntityRef<ZSpatialEntity> m_pApproachLookAtPoint;
    bool m_bEnableAmbientLookat;
    bool m_bBlendDirectFromWalk;
    bool m_bBlendUpperBodyAtStart;
    bool m_bBlendUpperBodyAtEnd;
    bool m_bEnabled;
    alignas(4) float m_fDuration;
    EActorPerceptionSensitivity m_ePerceptionSensitivity;
    EActorEmotionState m_eRequiredEmotionState;
    bool m_bAllowRagdollDamageReactions;
    bool m_bAllowReactToSillyHitman;
    alignas(4) TEntityRef<ZActor> m_pActor;
    __int8 m_bStoredReactToSilly : 1;
    __int8 m_bCleanupRequired : 1;
};
