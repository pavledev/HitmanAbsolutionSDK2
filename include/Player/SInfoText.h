#pragma once

#include "ZString.h"

struct SInfoText
{
	short nHUDIDGame;
	short nHUDIDMenu;
	int nAnchor;
	int nAlign;
	int nXOffset;
	int nYOffset;
	ZString m_sText;

	SInfoText() = default;
	~SInfoText() = default;
};
