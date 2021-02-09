#pragma once

#include "ZAnimationClipEntity.h"
#include "TEntityRef.h"

class ZTransitionClipEntity : public ZAnimationClipEntity
{
public:
    bool m_bMustAlwaysBeUsed;
    TArray<TEntityRef<ZAnimationClipEntity> > m_sourceClips;
    TArray<TEntityRef<ZAnimationClipEntity> > m_targetClips;
};
