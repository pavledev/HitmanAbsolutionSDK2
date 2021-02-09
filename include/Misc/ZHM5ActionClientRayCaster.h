#pragma once

#include "TMap.h"
#include "ZHM5Action.h"
#include "SRayResults.h"
#include "IAsyncRayHandle.h"
#include "EResultType.h"
#include "EQueryState.h"

class ZHM5ActionClient;

class alignas(4) ZHM5ActionClientRayCaster
{
public:
    TMap<ZHM5Action*, SRayResults> m_ActionQueries;
    ZHM5ActionClient* m_pActionClient;
    IAsyncRayHandle* m_pRayCastHandle;
    ZHM5Action* m_pRayCastKey;
    EResultType m_eRayCastType;
    bool m_bOpenForNewQuerries;

    class alignas(8) SActionRayResult
    {
    public:
        ZGameTime m_tLastQuery;
        EQueryState m_eState;
        float m_fDistanceSq;
        unsigned __int8 m_iRayStyle;
        unsigned __int8 m_iRayResults;
    };

    enum UnkEnum : __int32
    {
        RAY_ORIGINS = 0x2,
        RAY_TARGETS = 0x3
    };
};
