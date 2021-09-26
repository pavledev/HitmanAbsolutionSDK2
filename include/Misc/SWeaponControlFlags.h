#pragma once

struct SWeaponControlFlags
{
	union 
	{
		unsigned int m_nWeaponControlFlags;

		struct 
		{
			bool m_bFireWeapon : 1;
			bool m_bFireWeaponRelease : 1;
			bool m_bFireWeaponTap : 1;
			bool m_bFireStartedRight : 1;
			bool m_bFireStartedLeft : 1;
			bool m_bLastFireWeaponRight : 1;
			bool m_bPrecisionShoot : 1;
			bool m_bPrecisionShootRelease : 1;
			bool m_bPrecisionShootDownedge : 1;
			bool m_bPrecisionShootAudioSignalsBlocked : 1;
			bool m_bLastAimWeaponRight : 1;
			bool m_bFireBlocked : 1;
		};
	};

	SWeaponControlFlags() = default;
	~SWeaponControlFlags() = default;
};
