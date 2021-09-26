#pragma once

#include "ZGameTime.h"

class ZHM5WeaponControlInputRepeater
{
public:
	enum eInputRepeaterMode
	{
		eMode_Inactive = 0,
		eMode_PASS = 1,
		eMode_CUT = 2
	};

	eInputRepeaterMode m_eMode;
	ZGameTime m_tLastModeChange;
	ZGameTime m_tINTERVAL_PASS;
	ZGameTime m_tINTERVAL_CUT;

	ZHM5WeaponControlInputRepeater() = default;
	~ZHM5WeaponControlInputRepeater() = default;
	void ResetMode();
	void SetupIntervals(float fPASS, float fCUT);
	bool GetRepeaterOutput();
	void SetMode(eInputRepeaterMode newMode);
};
