#pragma once

#include "TEntityRef.h"
#include "ZActor.h"

class SDeadBodyInfo
{
public:
    TEntityRef<ZActor> m_rActor;
    TMaxArray<TEntityRef<ZActor>, 100> m_knownByActors;
    bool m_bPoolKnownOnly;
    bool m_bPoolInvestigated;
    bool m_bBodyInvestigated;
    bool m_bHidden;
    bool m_bDeadByAccident;
    bool m_bDeadByUnnoticed;
    bool m_bHitmanSuspectedInCurrentOutfit;
    ZGameTime m_tDeadSince;
    ZGameTime m_tKnownSince;
    ZGameTime m_tInvestigatedSince;
};
