#pragma once

#include "SMatrix.h"

struct SDebugTextBox
{
	enum EAnchorTypeHorizontal
	{
		DEBUGTEXTANCHORH_LEFT = 0,
		DEBUGTEXTANCHORH_CENTER = 1,
		DEBUGTEXTANCHORH_RIGHT = 2
	};

	enum EAnchorTypeVertical
	{
		DEBUGTEXTANCHORV_TOP = 0,
		DEBUGTEXTANCHORV_CENTER = 1,
		DEBUGTEXTANCHORV_BOTTOM = 2
	};

	SMatrix m_mWorldTransform;
	float m_fRectHeight;
	EAnchorTypeHorizontal m_eHorizontalAnchorType;
	EAnchorTypeVertical m_eVerticalAnchorType;
	unsigned int m_nColor;
	float m_fFontSize;

	SDebugTextBox() = default;
	~SDebugTextBox() = default;
};
