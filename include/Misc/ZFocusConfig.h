#pragma once

#include "ZEntityImpl.h"
#include "ZResourcePtr.h"
#include "SVector2.h"

class alignas(4) ZFocusConfig : public ZEntityImpl
{
public:
    float m_fMax;
    float m_fInitial;
    float m_fGainFromHealthStation;
    float m_fGainNoKillsOnCP;
    float m_fGainHeadShot;
    float m_fGainFiberwireKill;
    float m_fGainEnvironmentKill;
    float m_fGainAccidentKill;
    float m_fGainHideBody;
    float m_fGainFromDisguiseUnlock;
    float m_fGainUnspottedOnCP;
    float m_fGainChokeOut;
    float m_fGainKnockOut;
    float m_fGainSnapNeck;
    float m_fGainItemKillFront;
    float m_fGainItemKillBack;
    float m_fGainItemThrowKill;
    float m_fGainPistolExecute;
    float m_fGainObjectiveComplete;
    float m_fGainObjectiveCompleteInStealth;
    float m_fBlendInMin;
    float m_fSBMinimumFocus;
    float m_fSBFocusToDamageRatio;
    float m_fSBPropDamageCost;
    float m_fKillCivilanDrain;
    float m_fSniperSlowDownUseRate;
    float m_fFocusShotUseRate;
    float m_fPreciseShotUseRate;
    float m_fDamageThreshold;
    float m_fFocusCostOnDamage;
    float m_fFocusMinUseRate;
    float m_fFocusMaxUseRate;
    float m_fInstinctMinFocus;
    bool m_bSniperSlowDownCostEnable;
    bool m_bFocusShotCostEnable;
    float m_fHideInPlainSight_GainCap;
    ZResourcePtr m_mHighlightMaterialHigh;
    ZResourcePtr m_mHighlightMaterialLow;
    ZResourcePtr m_mHighlightMaterialCounter;
    SVector2 m_vHighlightSize;
    bool m_bIsForDifficulty;
};
