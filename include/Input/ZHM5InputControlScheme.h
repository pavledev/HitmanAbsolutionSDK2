#pragma once

#include "SGameInput.h"
#include "SHM5InputControllerAnalog.h"
#include "TEntityRef.h"
#include "SControlSchemeMappings.h"
#include "SGameStateForInput.h"
#include "SPersistentState.h"
#include "EControlSchemes.h"

class ZHM5InputConverter;

class alignas(8) ZHM5InputControlScheme
{
public:
    SGameInput m_GameInput;
    float m_Thresholds[6];
    const SHM5InputControllerAnalog* m_fInputControllerAnalog;
    ZHM5InputConverter* const m_pInputConverter;
    TEntityRef<ZHitman5> m_pHitman;
    SControlSchemeMappings m_mappings;
    IHM5InputControlMapping* m_pCurrentMapping;
    SGameStateForInput m_gameState;
    SPersistentState m_PersistentState;
    bool m_iInputControlFlags[95];
    ZGameTime m_tLastControlMappingChange;
    ZGameTime m_tInstinctButtonHold;
    ZGameTime m_tDragBodyCounter;
    EControlSchemes m_controlScheme;

    enum eThresholds : __int32
    {
        eThresh_Shoot = 0x0,
        eThresh_PrecisionShoot = 0x1,
        eThresh_AimOTS = 0x2,
        eThresh_CamSensitivityVer = 0x3,
        eThresh_CamSensitivityHor = 0x4,
        eThresh_MouseSensitivity = 0x5,
        eThresh_NUM = 0x6
    };
};
