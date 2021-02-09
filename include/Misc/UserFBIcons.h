#pragma once

#include "TEntityRef.h"
#include "ZGameTime.h"
#include "float4.h"

class UserFBIcons
{
public:
    class IHM5TimerToOSD
    {
    public:
        virtual void OSDTimerFireTimeOut();
        virtual float OSDTimerGetTimer();
        virtual void OSDTimerStart();
        virtual void OSDTimerStop();
        virtual unsigned int OSDTimerGetHash();
        virtual const float4* OSDTimerGet3DPos(const float4* result);
        virtual ~IHM5TimerToOSD();
    };

    class alignas(8) STimerToOSDElement
    {
    public:
        TEntityRef<IHM5TimerToOSD> m_Key;
        ZGameTime m_tStarted;
        ZGameTime m_tEnding;
        char m_iDispTextIndex;
    };
};
