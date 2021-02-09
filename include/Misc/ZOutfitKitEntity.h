#pragma once

#include "ZContentKitEntity.h"
#include "SActorSoundDefs.h"

class ZOutfitKitEntity : public ZContentKitEntity
{
public:
    bool m_bIsNewPickup;
    SActorSoundDefs::EDefinition m_eSpeakSound;
    int m_nRatingAgainstSame;
    int m_nRating;
    int m_nArmorRating;
    bool m_bWeaponsAllowed;
    bool m_bAuthorityFigure;
    TArray<TEntityRef<ZTokenIDEntity> > m_aAllowedWeapons;
    ZRuntimeResourceID m_sHiResNotebookImage;

    virtual bool PickedUp(int, int);
    virtual bool WasPickedUp(int, int);
    virtual bool IsNewPickUp(int, int);
    virtual int GetRatingAgainstSame();
    virtual int GetRatingAgainstOther();
    virtual int GetArmorRating();
    virtual bool IsWeaponAllowed(const STokenID*);
    virtual bool IsAuthorityFigure();
    virtual SActorSoundDefs::EDefinition GetRespondHitmanSpeak();
};
