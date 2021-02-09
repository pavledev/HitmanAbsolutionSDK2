#pragma once

#include "IComponentInterface.h"
#include "IInputDevice.h"

class IInputDeviceManager : public IComponentInterface
{
public:
    virtual void CreateDevices(int, bool) = 0;
    virtual void Preupdate() = 0;
    virtual int Update(IInputDevice::EDeviceType, bool) = 0;
    virtual int Update(bool) = 0;
    virtual void DetectDeviceInput() = 0;
    virtual IInputDevice* GetLastUsedDevice() = 0;
    virtual bool IsLastDeviceChanged() = 0;
    virtual void ResetTables(bool) = 0;
    virtual IInputDevice* GetDevice(int) = 0;
    virtual ZString* GetDeviceName(ZString* result, int) = 0;
    virtual int GetDeviceIdByName(const char*) = 0;
    virtual int GetNthDevice(IInputDevice::EDeviceType, int) = 0;
    virtual void SetDefaultGameControllerIndex(int) = 0;
    virtual int DeviceCount(IInputDevice::EDeviceType) = 0;
    virtual int DeviceType(int) = 0;
    virtual int GetPrimaryDevice(IInputDevice::EDeviceType) = 0;
    virtual IInputDevice* GetPrimaryDevicePtr(IInputDevice::EDeviceType) = 0;
    virtual IInputDevice* GetNthDevicePtr(IInputDevice::EDeviceType, int) = 0;
    virtual int MapDigital(const char*, const char*, int*, int*) = 0;
    virtual int MapAnalog(const char*, const char*, int*, int*) = 0;
    virtual float Analog(int, int) = 0;
    virtual float AnalogMotion(int, int) = 0;
    virtual int Digital(int, int) = 0;
    virtual void DeactivateDevices() = 0;
    virtual void ActivateDevices() = 0;
    virtual bool InstallHandler(int, int(__cdecl*)(int, int, void*), void*, bool) = 0;
    virtual bool UninstallHandler(int, int(__cdecl*)(int, int, void*)) = 0;
    virtual bool OpenControllerMissingWindow() = 0;
    virtual bool CheckForKeyPress(int*, int*) = 0;
    virtual bool HasGamepadConnected() = 0;
    virtual bool CheckKey(const char*, unsigned int) = 0;
    virtual bool DebugKeysEnabled() = 0;
    virtual void EnableDebugKeys(bool) = 0;
    virtual void SetEnableHaptics(bool) = 0;
    virtual void TrapAllKeys() = 0;
};
