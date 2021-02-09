#pragma once

#include "SMorphemeData.h"

class SMorphemeDataImpl : public SMorphemeData
{
public:
    TMap<ZString, SCutSequenceData> m_EvaluationCutSequenceDataMap;
};
