#pragma once

#include "GFxFileConstants.h"

struct GFxExporterInfo
{
	enum ExportFlagConstants
	{
		EXF_GlyphTexturesExported = 1,
		EXF_GradientTexturesExported = 2,
		EXF_GlyphsStripped = 16
	};

	GFxFileConstants::FileFormatType Format;
	const char* pPrefix;
	const char* pSWFName;
	unsigned short Version;
	unsigned int ExportFlags;

	GFxExporterInfo() = default;
	~GFxExporterInfo() = default;
};
