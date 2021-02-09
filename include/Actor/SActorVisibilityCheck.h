#pragma once

#include "TEntityRef.h"
#include "ZActor.h"

class SActorVisibilityCheck
{
public:
    TEntityRef<ZActor> m_pActor;
    TArray<IAsyncRayHandle*> m_aRayHandles;
};
