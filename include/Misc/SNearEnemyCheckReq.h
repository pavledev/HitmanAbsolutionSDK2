#pragma once

#include "ZRayQueryInput.h"
#include "ZRayQueryOutput.h"
#include "IAsyncRayHandle.h"
#include "ZActor.h"
#include "ZCrowdActor.h"

class alignas(16) SNearEnemyCheckReq
{
public:
    ZRayQueryInput m_NECInputs[3];
    ZRayQueryOutput m_NECOutputs[3];
    IAsyncRayHandle* m_pHandles[3];
    TEntityRef<ZActor> m_pActor;
    TEntityRef<ZCrowdActor> m_pCrowdActor;
    unsigned __int8 m_nNumCasts;
    unsigned __int8 m_nIsReadyBits;
};
