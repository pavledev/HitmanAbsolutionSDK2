#pragma once

#include "IAsyncRayHandle.h"
#include "EHandleState.h"
#include "ERayType.h"
#include "NxRayHit.h"

class ZAsyncRayHandle : public IAsyncRayHandle
{
public:
    ZAsyncRayHandle* m_pNext;
    ZAsyncRayHandle* m_pPrevious;
    EHandleState m_eState;
    ZRayQueryInput m_Input;
    ZRayQueryOutput m_Output;
    ERayType m_eRayType;
    TArray<NxRayHit> m_aHits;
};