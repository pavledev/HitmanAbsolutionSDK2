#pragma once

#include "SVector2.h"
#include "EHM5OSDSprite.h"

struct SSpriteData
{
    SVector2 m_aVertices[4];
    EHM5OSDSprite m_eSprite;
    unsigned __int8 m_nPriority;
    unsigned int m_nColor;
};
