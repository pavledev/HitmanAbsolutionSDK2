#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ZStreamingRootEntity.h"

class alignas(4) ZStreamingStateEntity : public ZEntityImpl
{
public:
    ZString m_Name;
    TArray<TEntityRef<ZStreamingRootEntity> > m_StreamingRoots;
    bool m_bIsReady;
};
