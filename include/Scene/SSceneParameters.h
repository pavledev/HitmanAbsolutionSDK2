#pragma once

#include "ZString.h"
#include "ECheckpointGameMode.h"
#include "STokenID.h"

class alignas(4) SSceneParameters
{
public:
    ZString sSceneResource;
    ECheckpointGameMode eGameMode;
    STokenID BonusWeapon;
    STokenID BonusOutfit;
    int nCheckpointIndex;
    bool bRestoring;
    bool bUseSaveGame;
    STokenID sStartCheckpointID;
    bool bGameCompleted;
};
