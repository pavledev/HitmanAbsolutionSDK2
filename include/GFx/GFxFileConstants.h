#pragma once

class GFxFileConstants
{
public:
    enum FileFormatType : __int32
    {
        File_Unopened = 0x0,
        File_Unknown = 0x1,
        File_SWF = 0x2,
        File_GFX = 0x3,
        File_JPEG = 0xA,
        File_PNG = 0xB,
        File_GIF = 0xC,
        File_TGA = 0xD,
        File_DDS = 0xE,
        File_HDR = 0xF,
        File_BMP = 0x10,
        File_DIB = 0x11,
        File_PFM = 0x12,
        File_TIFF = 0x13,
        File_WAVE = 0x14,
        File_NextAvail = 0x15,
        File_Original = 0xFFFF
    };
};
