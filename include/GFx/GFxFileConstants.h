#pragma once

class GFxFileConstants
{
public:
	enum FileFormatType
	{
		File_Unopened = 0,
		File_Unknown = 1,
		File_SWF = 2,
		File_GFX = 3,
		File_JPEG = 10,
		File_PNG = 11,
		File_GIF = 12,
		File_TGA = 13,
		File_DDS = 14,
		File_HDR = 15,
		File_BMP = 16,
		File_DIB = 17,
		File_PFM = 18,
		File_TIFF = 19,
		File_WAVE = 20,
		File_NextAvail = 21,
		File_Original = 65535
	};

	GFxFileConstants() = default;
	~GFxFileConstants() = default;
};
