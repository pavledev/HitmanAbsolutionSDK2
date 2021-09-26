#pragma once

#include "GFxState.h"
#include "GFxFontResource.h"
#include "GFxFontLibImpl.h"

class GFxMovieDef;

class GFxFontLib : public GFxState
{
public:
	class FontResult
	{
	public:
		GFxMovieDef* pMovieDef;
		GFxFontResource* pFontResource;

		FontResult() = default;
		~FontResult() = default;
	};

	GFxFontLibImpl* pImpl;

	~GFxFontLib() override = default;

	GFxFontLib() = default;
};
