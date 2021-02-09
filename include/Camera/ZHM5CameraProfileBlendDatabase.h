#pragma once

#include "ZEntityImpl.h"
#include "TEntityRef.h"
#include "ZHM5GameCamProfileEntity.h"
#include "ZHM5GameCamTransition.h"
#include "ZHM5GameCamControlsEntity.h"
#include "SHM5GameCamParams.h"
#include "SBlendNode.h"
#include "ZMapPoly.h"

class ZHitman5;

class ZHM5CameraProfileBlendDatabase : public ZEntityImpl
{
public:
    TArray<TEntityRef<ZHM5GameCamProfileEntity>> m_GameCamProfiles;
    TArray<TEntityRef<ZHM5GameCamTransition>> m_GameCamTransitions;
    TArray<TEntityRef<ZHM5GameCamControlsEntity>> m_GameCamControls;
    bool m_abUpdateParams[49];
    SHM5GameCamParams m_aBlendedGameCamParams[49];
    SBlendNode m_aBlendNodes[49][4];
    ZMapPoly m_BlendMap;
    TEntityRef<ZHitman5> m_rHitman;
};
