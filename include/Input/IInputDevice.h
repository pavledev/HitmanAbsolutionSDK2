#pragma once

#include "ZGameTime.h"

class IInputDevice
{
public:
    enum EDeviceType : __int32
    {
        eMOUSE_TYPE = 0x0,
        eKEYBOARD_TYPE = 0x1,
        eGAMECONTROL_TYPE = 0x2,
        eCOMBOCONTROL_TYPE = 0x4
    };

    virtual ~IInputDevice();
    virtual IInputDevice::EDeviceType Type();
    virtual int DigitalCount();
    virtual int DigitalState(int);
    virtual char* DigitalName(int);
    virtual int DigitalId(const char*);
    virtual ZGameTime* DigitalHist(ZGameTime* result, int, int);
    virtual int AnalogCount();
    virtual float AnalogState(int);
    virtual float AnalogStateRaw(int);
    virtual char* AnalogName(int);
    virtual int AnalogId(const char*);
    virtual float AnalogMotion(int);
    virtual void ResetTables(bool);
    virtual void ClearKey(int);
    virtual bool HapticEnabled();
    virtual void RumbleSetPitch(int, float);
    virtual bool StartHaptic(unsigned int, float, float, bool);
    virtual void StopHaptics();
    virtual void SetRumbleBGPitch(float, float);
    virtual void SetRumblePitchDirect(float, float);
    virtual void Activate();
    virtual void Deactivate();
    virtual char* GetName();
    virtual void PrintInfo();
    virtual bool Connected();
};
