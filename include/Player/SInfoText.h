#pragma once

#include "ZString.h"

class SInfoText
{
public:
    __int16 nHUDIDGame;
    __int16 nHUDIDMenu;
    int nAnchor;
    int nAlign;
    int nXOffset;
    int nYOffset;
    ZString m_sText;
};
