#pragma once

struct SHM5InputKeyboardFlags
{
    union
    {
        unsigned __int64 m_nInputFlags;
        
        struct
        {
            __int8 m_bKeyboardAlphaNum1_Holddown : 1;
            __int8 m_bKeyboardAlphaNum1_Repeat : 1;
            __int8 m_bKeyboardAlphaNum2_Repeat : 1;
            __int8 m_bKeyboardE_FastTap : 1;
            __int8 m_bKeyboardE_HoldDown : 1;
            __int8 m_bKeyboardE_Release : 1;
            __int8 m_bKeyboardG_Tap : 1;
            __int8 m_bMouseButton1_Hold : 1;
            __int8 m_bMouseButton2_Hold : 1;
            __int8 m_bMouseWheelUp_Tap : 1;
            __int8 m_bMouseWheelDown_Tap : 1;
        };
    };
};
