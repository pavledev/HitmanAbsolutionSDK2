#pragma once

#include "ZPath.h"

class ZFilePath
{
    ZPath m_path;

    enum UnkEnum : __int32
    {
        DIRECTORY_SEPARATOR = 0x2F,
        EXTENSION_SEPARATOR = 0x2E,
        DRIVE_SEPARATOR = 0x3A,
    };
};
