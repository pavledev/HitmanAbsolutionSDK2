#pragma once

#include "ZSpatialEntity.h"
#include "TResourcePtr.h"
#include "IEntityFactory.h"
#include "IHM5Outfit.h"
#include "ZBoxVolumeEntity.h"
#include "EActorGroup.h"
#include "ZActor.h"

class ZSpawnPointEntity : public ZSpatialEntity
{
public:
    TResourcePtr<IEntityFactory> m_actorTemplate0;
    TResourcePtr<IEntityFactory> m_actorTemplate1;
    TResourcePtr<IEntityFactory> m_actorTemplate2;
    TResourcePtr<IEntityFactory> m_actorTemplate3;
    TResourcePtr<IEntityFactory> m_actorTemplate4;
    TEntityRef<IHM5Outfit> m_OutfitEntity;
    TEntityRef<ZBoxVolumeEntity> m_ExcludeBox;
    bool m_bHighPriority;
    ZResourcePtr m_pGizmo;
    ZResourcePtr m_pAlignGizmo;
    EActorGroup m_eActorGroup;
    __int8 m_bStreamedIn : 1;
    __int8 m_bNoOutfitErrorSent : 1;
    unsigned int m_nNumberOfSpawnedActorsSoFar;
    unsigned int m_nSpawnPositionIndex;

    virtual TEntityRef<ZActor>* Spawn(TEntityRef<ZActor>* result);
};
