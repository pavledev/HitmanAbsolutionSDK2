#pragma once

#include "ZReusablePropEntity.h"
#include "IHM5ActionEntityListener.h"
#include "EClosetType.h"
#include "ZHM5BodyContainer.h"

class ZHM5Closet : public ZReusablePropEntity, public IHM5ActionEntityListener
{
public:
    TArray<TEntityRef<ZSpatialEntity>> m_Doors;
    TEntityRef<ZSpatialEntity> m_rCloset;
    TEntityRef<ISequenceEntity> m_rEnterSequence;
    TEntityRef<ISequenceEntity> m_rExitSequence;
    TEntityRef<ISequenceEntity> m_rPeekExitSequence;
    TEntityRef<ISequenceEntity> m_rPeekSequence;
    TEntityRef<ZHM5Action> m_rAction;
    TEntityRef<ZSpatialEntity> m_rPeekCameraPosition;
    EClosetType m_eClosetType;
    TEntityRef<ZHM5BodyContainer> m_rBodyContainer;
    float m_fHorizontalAngleLimit;
    float m_fVerticalAngleLimit;

    virtual void FrameUpdate(const SGameUpdateEvent*);
};
