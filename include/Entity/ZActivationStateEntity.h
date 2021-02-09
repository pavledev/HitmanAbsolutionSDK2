#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ZStreamingStateEntity.h"
#include "ZActivatableRootEntity.h"

class ZActivationStateEntity : public ZEntityImpl
{
public:
    TEntityRef<ZStreamingStateEntity> m_pRequiredStreamingState;
    TArray<TEntityRef<ZActivatableRootEntity>> m_aActivatableRoots;
};
