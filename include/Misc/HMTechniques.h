#pragma once

namespace HMTechniques
{
    enum ETechnique
    {
        eTEC_Focus = 0,
        eTEC_Gunman = 1,
        eTEC_Breathing = 2,
        eTEC_Chameleon = 3,
        eTEC_PainSupression = 4,
        eTEC_InstictiveShot = 5,
        eTEC_HandToHand = 6,
        eTEC_DualWield = 7,
        eTEC_RunSpeed = 8,
        eTEC_ThrowingForce = 9,
        eTEC_NUM = 10
    };

    enum
    {
        eTECHNIQUELEVELS = 0x3,
        eTECHNIQUELEVELSTOTAL = 0x1E
    };

	enum ETechniquesAttribute
	{
		eTAT_FocusGain = 0,
		eTAT_FocusMax = 1,
		eTAT_GunmanRecoil = 2,
		eTAT_GunmanReload = 3,
		eTAT_BreathingBobbing = 4,
		eTAT_BreathingHairTrigger = 5,
		eTAT_ChameleonHideInPlainSightRate = 6,
		eTAT_ChameleonBlendInBurnRate = 7,
		eTAT_PainSuppressionRegenDelay = 8,
		eTAT_PainSuppressionMaxHP = 9,
		eTAT_InstictiveTagMode = 10,
		eTAT_InstictiveTaggingCost = 11,
		eTAT_HandToHandWindow = 12,
		eTAT_HandToHandChoke = 13,
		eTAT_DualWieldPrecision = 14,
		eTAT_DualWieldAutoFireRate = 15,
		eTAT_RunSpeedFactor = 16,
		eTAT_RunSpeed_Dummy = 17,
		eTAT_ThrowingForceHeavy = 18,
		eTAT_ThrowingForceLight = 19,
		eTAT_NUM = 20
	};
};
