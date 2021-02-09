#pragma once

class HMTechniques
{
public:
    enum ETechnique : __int32
    {
        eTEC_Focus = 0x0,
        eTEC_Gunman = 0x1,
        eTEC_Breathing = 0x2,
        eTEC_Chameleon = 0x3,
        eTEC_PainSupression = 0x4,
        eTEC_InstictiveShot = 0x5,
        eTEC_HandToHand = 0x6,
        eTEC_DualWield = 0x7,
        eTEC_RunSpeed = 0x8,
        eTEC_ThrowingForce = 0x9,
        eTEC_NUM = 0xA
    };

    enum
    {
        eTECHNIQUELEVELS = 0x3,
        eTECHNIQUELEVELSTOTAL = 0x1E
    };

    enum ETechniquesAttribute : __int32
    {
        eTAT_FocusGain = 0x0,
        eTAT_FocusMax = 0x1,
        eTAT_GunmanRecoil = 0x2,
        eTAT_GunmanReload = 0x3,
        eTAT_BreathingBobbing = 0x4,
        eTAT_BreathingHairTrigger = 0x5,
        eTAT_ChameleonHideInPlainSightRate = 0x6,
        eTAT_ChameleonBlendInBurnRate = 0x7,
        eTAT_PainSuppressionRegenDelay = 0x8,
        eTAT_PainSuppressionMaxHP = 0x9,
        eTAT_InstictiveTagMode = 0xA,
        eTAT_InstictiveTaggingCost = 0xB,
        eTAT_HandToHandWindow = 0xC,
        eTAT_HandToHandChoke = 0xD,
        eTAT_DualWieldPrecision = 0xE,
        eTAT_DualWieldAutoFireRate = 0xF,
        eTAT_RunSpeedFactor = 0x10,
        eTAT_RunSpeed_Dummy = 0x11,
        eTAT_ThrowingForceHeavy = 0x12,
        eTAT_ThrowingForceLight = 0x13,
        eTAT_NUM = 0x14
    };
};
