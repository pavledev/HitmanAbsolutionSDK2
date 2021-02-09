#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ZSpatialEntity.h"
#include "ZHM5ValueEntity_bool.h"
#include "ISoundAmbienceElement.h"
#include "IMusicComposition.h"

enum EState : __int32
{
    eState_Undefined = 0x0,
    eState_Enabled = 0x1,
    eState_Triggered = 0x2,
    eState_DisabledByTension = 0x3,
    eState_NotSupportedInLevel = 0x4
};

class alignas(4) ZHM5ForwardSpawnEntity : public ZEntityImpl
{
public:
    EState m_eState;
    TEntityRef<ZSpatialEntity> m_rPosToSpawnHitmanOn;
    bool m_eDifficulty_Level1;
    bool m_eDifficulty_Level2;
    bool m_eDifficulty_Level3;
    bool m_eDifficulty_Level4;
    bool m_eDifficulty_Level5;
    TEntityRef<ZHM5ValueEntity_bool> m_pStateEnabled;
    TEntityRef<ZHM5ValueEntity_bool> m_pStateTriggered;
    TEntityRef<ZHM5ValueEntity_bool> m_pStateDisabledByTension;
    TEntityRef<ZHM5ValueEntity_bool> m_pStateNotSupported;
    TEntityRef<ISoundAmbienceElement> m_pInitialSoundAmbience;
    TEntityRef<IMusicComposition> m_pInitialComposition;
    __int8 m_bTriggered : 1;
    __int8 m_bSupportedInLevel : 1;
};
