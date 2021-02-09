#pragma once

#include <wtypes.h>
#include "ZString.h"

class alignas(4) WindowCreationParameters
{
public:
    HINSTANCE__* m_hInstance;
    HWND__* m_hParent;
    ZString m_sSceneFile;
    int m_nX;
    int m_nY;
    unsigned int m_nWidth;
    unsigned int m_nHeight;
    int m_nShowWindowCmd;
    bool m_bFullScreen;
};
