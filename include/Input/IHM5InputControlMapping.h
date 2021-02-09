#pragma once

#include "ZHM5InputControlScheme.h"
#include "SGameplayInputControlBind.h"

class IHM5InputControlMapping
{
public:
    ZHM5InputControlScheme* const m_pControlScheme;
    TArray<SGameplayInputControlBind> m_GameplayInputControlBinds;

    enum UnkEnum : __int32
    {
        eSCRight_Triggers = 0x0,
        eSCRight_Bumpers = 0x1,
        eSCLeft_Triggers = 0x2,
        eSCLeft_Bumpers = 0x3,
        eSC_NUM = 0x4
    };

    virtual ~IHM5InputControlMapping();
    virtual void HandleFaceButtons();
    virtual void HandleStickButtons();
    virtual void HandleShoulderControls();
    virtual void HandleDPad();
    virtual void HandleGeneric();
    virtual void HandleCollisions();
    virtual void InitFaceButtons();
    virtual void InitStickButtons();
    virtual void InitShoulderControls();
    virtual void InitDpad();
    virtual void InitGeneric();
};
