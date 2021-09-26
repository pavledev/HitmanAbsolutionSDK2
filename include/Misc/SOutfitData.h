#pragma once

#include "STokenID.h"
#include "SActorSoundDefs.h"

struct SOutfitData
{
	STokenID m_eTokenId;
	int m_nArmorRating;
	int m_nOutfitRatingAgainstSame;
	int m_nOutfitRatingAgainstOther;
	SActorSoundDefs::EDefinition m_eRespondHitmanDialog;

	SOutfitData() = default;
	~SOutfitData() = default;
};
