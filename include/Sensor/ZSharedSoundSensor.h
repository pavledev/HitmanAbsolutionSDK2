#pragma once

#include "TEntityRef.h"
#include "ZSharedSoundSensorDef.h"
#include "TMaxArray.h"
#include "ZAISoundConnector.h"
#include "ZAISoundModifierVolume.h"
#include "SAISoundEvent.h"
#include "ZGridJobRequest.h"
#include "ZGridFloatField.h"

class ZSharedSoundSensor
{
public:
    __declspec(align(16)) TEntityRef<ZSharedSoundSensorDef> m_pSensorDef;
    TMaxArray<TEntityRef<ZAISoundConnector>, 64> m_connectors;
    TMaxArray<TEntityRef<ZAISoundModifierVolume>, 64> m_modifierVolumes;
    TMaxArray<unsigned short, 8> m_hitmanRoomIds;
    __declspec(align(16)) SAISoundEvent m_processingEvent;
    float1 m_processingEventZDistance;
    ZGridNodeRef m_processingEventNode;
    ZGridJobRequest<TRefCountPtr<ZGridFloatField> > m_pSoundDistanceRequest;
    TRefCountPtr<ZGridFloatField> m_pSoundDistanceField;
    TMaxArray<TEntityRef<ZActor>, 64> m_affectedActors;
    TMaxArray<SAISoundEvent, 32> m_Events;
    TMaxArray<SAISoundEvent, 8> m_PulseEvents;
    TMaxArray<ZSharedKnowledgeRef, 32> m_soundLocations;
    ZGameTime m_fPulseTime;
    ZGameTime m_tLastGunShot;
    ZGameTime m_tLastHitmanGunShot;
    ZGameTime m_tLastBulletImpact;
    ZGameTime m_tLastThrownItemCollision;
    int m_nActorCleanupIndex;

    virtual ~ZSharedSoundSensor();
};
