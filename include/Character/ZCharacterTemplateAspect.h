#pragma once

#include "ZEntityImpl.h"
#include "ZResourcePtr.h"
#include "ZRuntimeResourceID.h"
#include "EActorCCPreset.h"
#include "TEntityRef.h"
#include "ZLinkedProxyEntity.h"
#include "SBodyPartDamageMultipliers.h"
#include "SSettingsParamMultiplier.h"

class alignas(4) ZCharacterTemplateAspect : public ZEntityImpl
{
public:
    ZResourcePtr m_NudeResource;
    ZRuntimeResourceID m_HMAsResID;
    TArray<ZString> m_CharacterStatLabelList;
    EActorCCPreset m_eActorCCClass;
    bool m_bIsFemale;
    TEntityRef<ZLinkedProxyEntity> m_NudeEntity;
    TResourcePtr<ZEntityRef> m_sHUDPortraitShared;
    float m_fHitPoints;
    SBodyPartDamageMultipliers m_DamageMultipliers;
    bool m_bAllowRadioAct;
    bool m_bDisableRating;
    TArray<SSettingsParamMultiplier> m_SettingsParamMultipliers;
    __int8 m_bStreamedIn : 1;
    __int8 m_bIsNude : 1;
};
