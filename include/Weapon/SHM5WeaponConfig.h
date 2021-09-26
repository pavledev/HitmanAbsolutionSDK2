#pragma once

struct SHM5WeaponConfig
{
	float m_fDamageMultiplier;
	float m_fInitialMagazines;
	float m_fPrecisionMinDegree;
	float m_fPrecisionMaxDegree;
	float m_fRecoilX;
	float m_fRecoilZ;
	float m_fDamageClose;
	float m_fDamageNear;
	float m_fDamageMedium;
	float m_fDamageFar;
	float m_fRangeClose;
	float m_fRangeNear;
	float m_fRangeMedium;
	float m_fRangeFar;
	float m_fReloadSpeedFactor;
	int m_iBulletsPerMagazine;
	short m_iShotsPerMinute;
	char m_iPrecisionNumBullets;
	unsigned char m_iOperModes;

	union
	{
		unsigned char m_nBools;

		struct
		{
			bool m_bInitialized : 1;
			bool m_bIsSilenced : 1;
			bool m_bIsRedDot : 1;
			bool m_bStartDualWield : 1;
		};
	};

	SHM5WeaponConfig() = default;
	~SHM5WeaponConfig() = default;
};
