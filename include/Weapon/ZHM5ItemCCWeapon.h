#pragma once

#include "ZHM5Item.h"
#include "IHM5ItemWeapon.h"
#include "EUseTypes.h"
#include "ECCWeaponAnimSet.h"
#include "ZCCEffectSetEntity.h"
#include "SActorSoundDefs.h"
#include "EHM5DeadlyThrowType.h"

class alignas(16) ZHM5ItemCCWeapon : public ZHM5Item, public IHM5ItemWeapon
{
public:
    TEntityRef<ZHM5Action> m_pUseAction;
    EUseTypes m_eUseType;
    ECCWeaponAnimSet m_eAnimSetFrontSide;
    ECCWeaponAnimSet m_eAnimSetBack;
    TArray<TEntityRef<ZCCEffectSetEntity>> m_aEffectSetsFrontSide;
    TArray<TEntityRef<ZCCEffectSetEntity>> m_aEffectSetsBack;
    SActorSoundDefs::EDefinition m_eDeathSpeakFront;
    SActorSoundDefs::EDefinition m_eDeathSpeakBack;
    SActorSoundDefs::EDefinition m_eReactionSpeak;
    EActorDeathType m_eDeathTypeFront;
    EActorDeathType m_eDeathTypeBack;
    ZEntityRef m_pVariationResource;
    int m_nLifeSpan;
    bool m_bPercievedAsWeapon;
    ZRuntimeResourceID m_EquippedMaterial;
    bool m_bCountsAsFiberWire;
    EHM5DeadlyThrowType m_eDeadlyThrowTypeFiberWire;
    unsigned __int16 m_nImpactCount;
    __int8 m_bTurnedOn : 1;
    __int8 m_bBroken : 1;
    __int8 m_bForcePickupDisabled : 1;

    virtual void SetAIBurstCount(int);
    virtual bool Reload();
    virtual bool IsReloading();
    virtual void OnImpact(const ZEntityRef*);
    virtual void TurnOn();
    virtual void TurnOff();
};
