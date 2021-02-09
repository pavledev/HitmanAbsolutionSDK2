#pragma once

#include "STokenID.h"
#include "SActorSoundDefs.h"

class SOutfitData
{
public:
    STokenID m_eTokenId;
    int m_nArmorRating;
    int m_nOutfitRatingAgainstSame;
    int m_nOutfitRatingAgainstOther;
    SActorSoundDefs::EDefinition m_eRespondHitmanDialog;
};
