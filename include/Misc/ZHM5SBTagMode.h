#pragma once

#include "ZHM5SBTag.h"
#include "SHM5SBShared.h"
#include "ESBTagMode.h"
#include "SCharacterTagInfo.h"

class alignas(16) ZHM5SBTagMode
{
public:
    ZHM5SBTag m_aTags[32];
    unsigned int m_nNumTags;
    unsigned int m_nMaxNumTags;
    TArray<ZHM5SBTag> m_aUntaggableActorTags;
    bool m_bZoom;
    bool m_bTriggerAimAssist;
    bool m_bLastTag;
    bool m_bPropCostOverride;
    float m_fPropCost;
    float m_fFocalDist;
    float m_fWeaponMinFractionBetweenTags;
    float m_fAutoModeFireRate;
    float m_fTagTimeAutoMode;
    unsigned int m_nNumAutoShotsMade;
    const SHM5SBShared* m_SBShared;
    bool m_bCanTag;
    TEntityRef<IHM5ItemWeapon> m_arWeapons[2];
    unsigned int m_anStartAmmo[2];
    ESBTagMode m_eTagMode;
    TFixedArray<SCharacterTagInfo, 32> m_aHitCharacters;
    unsigned int m_nHitCharacters;
    SAimCandidate m_LastCandidate;
    TArray<float4> m_ArcPositions;
    bool m_bLookAtPosInitialized;
    float4 m_vLookAtPos;
    float4 m_vLookAtDir;
    bool m_bAllowPlayerToExecute;
    bool m_bExecuteWhenInstinctRunsOut;
};
