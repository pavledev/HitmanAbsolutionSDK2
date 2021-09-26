#pragma once

#include "GFxState.h"
#include "GString.h"
#include "GFxFontMapImpl.h"

class GFxFontMap : public GFxState
{
public:
	enum MapFontFlags
	{
		MFF_Original = 16,
		MFF_NoAutoFit = 32,
		MFF_Normal = 0,
		MFF_Italic = 1,
		MFF_Bold = 2,
		MFF_BoldItalic = 3,
		MFF_FauxItalic = 4,
		MFF_FauxBold = 8,
		MFF_FauxBoldItalic = 12
	};

	class MapEntry
	{
	public:
		GString Name;
		float ScaleFactor;
		float GlyphOffsetX;
		float GlyphOffsetY;
		MapFontFlags Flags;

		MapEntry() = default;
		~MapEntry() = default;
	};

	GFxFontMapImpl* pImpl;

	~GFxFontMap() override = default;

	GFxFontMap() = default;
};
