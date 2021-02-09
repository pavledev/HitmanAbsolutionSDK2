#pragma once

#include "EHUDIconType.h"
#include "SVector2.h"
#include "ZString.h"

class SHUDIconInfo
{
public:
    EHUDIconType eIconType;
    SVector2 screenPos;
    float fScale;
    float fValue;
    ZString sText;
    unsigned __int16 nIconID;
    unsigned int nDirtyFlags;
};
