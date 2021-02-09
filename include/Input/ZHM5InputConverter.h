#pragma once

#include "ZHM5InputControl.h"
#include "EControlSchemes.h"

class alignas(4) ZHM5InputConverter
{
public:
    ZHM5InputControl* const m_pInputControl;
    ZHM5InputControlScheme* m_pControlSchemeAlpha;
    ZHM5InputControlScheme* m_pControlSchemeBETA;
    ZHM5InputControlScheme* m_pControlSchemeGamma;
    ZHM5InputControlScheme* m_pControlSchemeKeyboard;
    TEntityRef<ZHitman5> m_pHitman;
    EControlSchemes m_eActiveControlScheme;
    EControlSchemes m_eSelectedControlScheme;
};
