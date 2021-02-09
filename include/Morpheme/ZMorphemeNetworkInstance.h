#pragma once

#include "IComponentInterface.h"
#include "MR.h"
#include "SMatrix.h"
#include "ZMutex.h"
#include "ZDelegate.h"
#include "TMap.h"
#include "SCutSequenceData.h"
#include "SMorphemeDataImpl.h"
#include "ZEntityRef.h"
#include "THashMap.h"
#include "SInterpolatingParameter.h"
#include "IJob.h"
#include "SAsyncData.h"

class ZMorphemeNetworkInstance : public IComponentInterface
{
public:
    ZString m_sLastError;
    ZString m_sDebugName;
    MR::Network* m_pNetwork;
    MR::NetworkDef* m_pNetworkDef;
    SMatrix* m_pTransForms;
    ZMutex m_asyncMutex;
    ZDelegate<void __cdecl(int)> m_networkUpdateCompleteDelegate;
    TMap<ZString, SCutSequenceData> m_CutSequenceDataMap;
    SMorphemeDataImpl m_morphemeData;
    float m_fPlayBackSpeedFactor;
    unsigned __int16 m_nBipIndex;
    bool m_bIsUpdatedByMediator;
    bool m_bDeferTransformUpdate;
    ZEntityRef m_pOwnerEntity;
    TMap<unsigned int, ZChildNetworkEntry> m_aChildNetworkSlots;
    THashMap<unsigned int, SInterpolatingParameter, TDefaultHashMapPolicy<unsigned int, SInterpolatingParameter>> m_InterpolatingControls;
    IJob* m_pJob;
    SAsyncData m_asyncUpdateData;

    struct __cta_13
    {
        unsigned __int32 bf : 1;
    };
};
