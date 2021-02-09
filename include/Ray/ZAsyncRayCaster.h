#pragma once

#include "NxScene.h"
#include "ZAsyncQueryReport.h"
#include "TFixedArray.h"
#include "ZAsyncRayHandle.h"
#include "TStack.h"
#include "TIntrusiveList.h"
#include "TIntrusiveListAccessor.h"
#include "TMap.h"

class ZAsyncRayCaster
{
    alignas(16) NxScene* m_pPhysXWorld;
    NxSceneQuery* m_pSceneQuery;
    bool m_bExecute;
    ZAsyncQueryReport m_QueryReport;
    TFixedArray<ZAsyncRayHandle, 750> m_HandlePool;
    TStack<ZAsyncRayHandle*, TArray<ZAsyncRayHandle*> > m_FreeHandles;
    TIntrusiveList<ZAsyncRayHandle, TIntrusiveListAccessor<ZAsyncRayHandle> > m_ActiveHandles;
    TArray<ZAsyncRayHandle*> m_QueuedHandles;
    int m_nSuspendCount;
    TMap<ZRayQueryOutput*, ZRuntimeResourceID> m_storedBlockingMaterials;

    virtual ~ZAsyncRayCaster();
};
