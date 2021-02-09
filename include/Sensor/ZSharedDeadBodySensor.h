#pragma once

#include "TMaxArray.h"
#include "SDeadBodyInfo.h"
#include "ZEvent.h"
#include "ZEventNull.h"

class alignas(8) ZSharedDeadBodySensor
{
public:
    TMaxArray<SDeadBodyInfo, 100> m_bodies;
    int m_nBodyIndex;
    ZEvent<ZEventNull, ZEventNull, ZEventNull, ZEventNull, ZEventNull> m_LastWitnessKilledEvent;
};
