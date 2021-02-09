#pragma once

#include "ZEntityImpl.h"
#include "TBlockArray.h"
#include "TQueue.h"
#include "ZGameTime.h"
#include "TEntityRef.h"
#include "ZSpatialEntity.h"
#include "ISequenceTrack.h"
#include "ESequencePreviewState.h"
#include "ECommand.h"
#include "RunData.h"

class ZSequenceEntity : ZEntityImpl, ISequenceEntity
{
public:
    ZEvent<ISequenceEntity*, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_OnStopEvent;
    ZEvent<ISequenceEntity*, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_OnAbortEvent;
    ZEvent<ISequenceEntity*, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_OnStartEvent;
    TArray<ZEntityRef> m_aTracksAndGroups;
    TQueue<ECommand, TBlockArray<ECommand>> m_commandQueue;
    ZGameTime m_sequenceTime;
    ZGameTime m_duration;
    ZGameTime m_startTime;
    ZGameTime m_previewTime;
    TEntityRef<ZSpatialEntity> m_sequenceOrigin;
    RunData* m_pRunData;
    int m_nLoopCount;
    ESequencePreviewState m_ePreviewState;
    unsigned __int16 m_eStateFlags;
    bool m_bPausedOnStart;
    __int8 m_bActivatedByIActivatable : 1;
    __int8 m_bGettingDeactivated : 1;
    __int8 m_bOnGameStopped : 1;
    bool m_bLetterbox;
    ZGameTime m_letterboxFadeIn;
    ZGameTime m_letterboxFadeOut;

    virtual bool CheckIfItemsReady(ZGameTime, ZGameTime);
    virtual void ResetPrefetchedData();
};
