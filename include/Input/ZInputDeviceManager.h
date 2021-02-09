#pragma once

#include "IInputDeviceManager.h"
#include "ZInputDevice.h"

class alignas(8) ZInputDeviceManager : public IInputDeviceManager
{
public:
    ZInputDevice* m_devices[32];
    int m_devicecount;
    bool m_bDebugKeysEnabled;
    int m_nDefaultGameControllerIndex;
    bool keyhist[256];
    ZGameTime keyEventHist[256];
    int m_iConsoleGroup;
};
