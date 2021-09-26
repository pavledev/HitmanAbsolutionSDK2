#pragma once

#include "EHUDIconType.h"
#include "SVector2.h"
#include "ZString.h"

struct SHUDIconInfo
{
	EHUDIconType eIconType;
	SVector2 screenPos;
	float fScale;
	float fValue;
	ZString sText;
	unsigned short nIconID;
	unsigned int nDirtyFlags;

	void ResetData();
	SHUDIconInfo(const SHUDIconInfo& __that);
	SHUDIconInfo() = default;
	~SHUDIconInfo() = default;
	SHUDIconInfo& operator=(const SHUDIconInfo& __that);
};
