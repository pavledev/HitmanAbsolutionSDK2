#pragma once

#include "TEntityRef.h"
#include "ZActor.h"
#include "ZActorAnimationProgram.h"
#include "EActorAnimationStatusUpdate.h"

class alignas(4) ZActorAnimationState
{
public:
    const TEntityRef<ZActor> m_pActor;
    ZMorphemeNetworkInstance* m_pNetwork;
    TSharedPointer<ZActorAnimationProgram> m_pCurrentAnimationProgram;
    EActorAnimationStatusUpdate m_eCurrentStatusUpdate;
};
