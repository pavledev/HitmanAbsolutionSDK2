#pragma once

struct SHM5InputKeyboardFlags
{
	union 
	{
		unsigned long long m_nInputFlags;

		struct 
		{
			bool m_bKeyboardAlphaNum1_Holddown : 1;
			bool m_bKeyboardAlphaNum1_Repeat : 1;
			bool m_bKeyboardAlphaNum2_Repeat : 1;
			bool m_bKeyboardE_FastTap : 1;
			bool m_bKeyboardE_HoldDown : 1;
			bool m_bKeyboardE_Release : 1;
			bool m_bKeyboardG_Tap : 1;
			bool m_bMouseButton1_Hold : 1;
			bool m_bMouseButton2_Hold : 1;
			bool m_bMouseWheelUp_Tap : 1;
			bool m_bMouseWheelDown_Tap : 1;
		};
	};

	SHM5InputKeyboardFlags() = default;
	~SHM5InputKeyboardFlags() = default;
};
