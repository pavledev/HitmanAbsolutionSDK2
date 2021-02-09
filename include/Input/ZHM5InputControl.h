#pragma once

#include "TEntityRef.h"
#include "ZHitman5.h"
#include "SHM5InputControllerAnalog.h"
#include "SHM5InputKeyboardFlags.h"
#include "ZInputAction.h"
#include "InputControlNamesp.h"

class ZHM5InputConverter;

class ZHM5InputControl
{
public:
    TEntityRef<ZHitman5> m_pHitman;
    SHM5InputControllerAnalog m_AnalogInputs;
    SHM5InputKeyboardFlags m_InputKeyboardFlags;
    ZHM5InputConverter* m_pInputConverter;
    bool m_iInputControllerFlags[95];
    ZGameTime m_tReturnedFromMenu;
    bool m_bActive;
    int m_nBindingsDisabledCount;

    class SInputBinding
    {
    public:
        InputControlNamesp::eHM5InputAction m_eInput;
        ZInputAction m_InputAction;
    };
};
