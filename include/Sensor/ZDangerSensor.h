#pragma once

#include "TArrayRef.h"
#include "TEntityRef.h"
#include "ZActor.h"
#include "SDisturbance.h"
#include "ZGridJobRequest.h"
#include "ZGridFloatField.h"

class ZDangerSensor
{
public:
    TArrayRef<TEntityRef<ZActor>> m_aActors;
    TArray<SDisturbance> m_aDisturbances;
    ZGridJobRequest<TRefCountPtr<ZGridFloatField>> m_dangerFieldRequest;
    TRefCountPtr<ZGridFloatField> m_dangerField;
    int m_eState;
    int m_nCandidateIndex;
    ZGameTime m_tLastDecayTime;
    float m_fDecayRate;
    float m_fInfluenceMaxDistance;
};
