#pragma once

struct HandReTargetMode
{
    enum eHandReTargetMode : __int32
    {
        eRetargetNone = 0x0,
        eRetargetBoth = 0x1,
        eRetargetLeftOnly = 0x2,
        eRetargetRigthOnly = 0x3
    };
};