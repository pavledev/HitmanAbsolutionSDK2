#pragma once

#include "ESBWeaponType.h"
#include "ESBPose.h"

struct SSBAnim
{
	enum ESBHand
	{
		eSBHand_None = 0,
		eSBHand_Left = 1,
		eSBHand_Right = 2,
		eSBHand_Both = 3
	};

	enum ESBRecoil
	{
		eSBRecoil_Pistol90 = 0,
		eSBRecoil_ShotgunLow = 1,
		eSBRecoil_ShotgunHigh = 2,
		eSBRecoil_Default = 3
	};

	const char* m_pszStartPose;
	const char* m_pszEndPose;
	const char* m_pszWeaponAnimName;
	float m_fRotation;
	ESBHand m_eExecutingHand;
	ESBRecoil m_eRecoil;
	unsigned int m_nAnimNodeID;
	float m_fAnimationDuration;
	unsigned int m_nParentNodeID;
	bool m_bHipPose;
	bool m_bFromTagPose;
	bool m_bReloadAnim;
	bool m_bCamAnim1;
	bool m_bCamAnim2;
	ESBWeaponType m_eWeaponType;
	ESBPose m_eSBPose;

	SSBAnim() = default;
	~SSBAnim() = default;
};
