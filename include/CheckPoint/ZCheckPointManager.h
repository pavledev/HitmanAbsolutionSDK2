#pragma once

#include "IComponentInterface.h"
#include "ZEvent.h"
#include "TEntityRef.h"
#include "ZCheckPointEntity.h"
#include "ZCheckPointManagerEntity.h"
#include "ZCheckPointFlow.h"
#include "SCheckpointSaveData.h"

class ZCheckPointManager : public IComponentInterface
{
public:
    ZEvent<TEntityRef<ZCheckPointEntity> const&, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_CheckPointActivatedEvent;
    ZEvent<TEntityRef<ZCheckPointEntity> const&, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_CheckPointDeactivatedEvent;
    TEntityRef<ZCheckPointManagerEntity> m_pCheckPointManagerEntity;
    ZCheckPointFlow* m_pCheckPointFlow;
    int m_iInitialCheckpointIndexContracts;
    TArray<ZEntityRef> m_aConstructedItems;
    TArray<ZEntityRef> m_aConstructedItemsReferenced;
    int m_nEditorStartCheckpoint;
    int m_nForwardSpawnCheckpoint;
    int m_nForwardSpawnIndex;
    SCheckpointSaveData m_ForwadSpawnSaveData;
    TArray<STokenID> m_ForwardSpawnDeadActors;
    unsigned __int16* m_ForwardSpawnRatingSave;
    TArray<bool> m_bForwardSpawnTitleAchieved;
    TArray<ZString> m_ForwardSpawnActiveObjectives;
    TArray<ZString> m_ForwardSpawnCompletedObjectives;
    bool m_bLoadScrenActive;
    bool m_bIsRestoring;
    bool m_bCheckpointRestarting;
    bool m_bForwardSpawnSpottetOnCheckpoint;
};
