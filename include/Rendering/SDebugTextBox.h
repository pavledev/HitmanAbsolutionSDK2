#pragma once

#include "SMatrix.h"
#include "EAnchorTypeHorizontal.h"
#include "EAnchorTypeVertical.h"

class alignas(16) SDebugTextBox
{
public:
    SMatrix m_mWorldTransform;
    float m_fRectHeight;
    EAnchorTypeHorizontal m_eHorizontalAnchorType;
    EAnchorTypeVertical m_eVerticalAnchorType;
    unsigned int m_nColor;
    float m_fFontSize;
};
