#pragma once

#include "IInputDevice.h"
#include "CtrlInfo.h"

class alignas(8) ZInputDevice : public IInputDevice
{
public:
    char m_name[32];
    ZGameTime(*m_dighist)[2];
    bool* m_pbDigital;
    bool* m_pbDigitalTrap;
    int m_digcount;
    CtrlInfo* m_diginf;
    int m_diginfcount;
    float* m_anamotion;
    float* m_analog;
    float* m_anaraw;
    int m_anacount;
    CtrlInfo* m_anainf;
    int m_anainfcount;
    ZGameTime m_updatetime;
    bool m_active;
    bool m_connected;
    unsigned __int8 m_iDeviceID;
    int(__cdecl * m_pHandler[2])(int, int, void*);
    void* m_pHandlerData[2];
    int m_nExclusiveIndex;
    IInputDevice::EDeviceType m_type;

    virtual int Initialize(bool);
    virtual int Terminate();
    virtual void Update(bool);
    virtual void Preupdate();
    virtual int Acquire();
    virtual int Acquire(int);
    virtual int Unacquire();
    virtual char* lookupDeviceName(CtrlInfo*, int);
};
