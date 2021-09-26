#pragma once

#include "IInputDeviceManager.h"
#include "IInputDevice.h"
#include "ZGameTime.h"
#include "ZString.h"

class ZInputDevice;

class ZInputDeviceManager : public IInputDeviceManager
{
public:
	ZInputDevice* m_devices[32];
	int m_devicecount;
	bool m_bDebugKeysEnabled;
	int m_nDefaultGameControllerIndex;
	bool keyhist[256];
	ZGameTime keyEventHist[256];
	int m_iConsoleGroup;

	~ZInputDeviceManager() override = default;
	void Preupdate() override;
	int Update(IInputDevice::EDeviceType type, bool bIgnoreOldEvents) override;
	int Update(bool bIgnoreOldEvents) override;
	void DetectDeviceInput() override;
	IInputDevice* GetLastUsedDevice() override;
	bool IsLastDeviceChanged() override;
	void ResetTables(bool bClearKeys) override;
	IInputDevice* GetDevice(int id) override;
	ZString GetDeviceName(int id) override;
	int GetDeviceIdByName(const char* name) override;
	int GetNthDevice(IInputDevice::EDeviceType type, int nth) override;
	void SetDefaultGameControllerIndex(int nIndex) override;
	int DeviceCount(IInputDevice::EDeviceType type) override;
	int DeviceType(int id) override;
	int GetPrimaryDevice(IInputDevice::EDeviceType type) override;
	IInputDevice* GetPrimaryDevicePtr(IInputDevice::EDeviceType type) override;
	IInputDevice* GetNthDevicePtr(IInputDevice::EDeviceType type, int nth) override;
	int MapDigital(const char* devname, const char* ctrlname, int& devid, int& ctrlid) override;
	int MapAnalog(const char* devname, const char* ctrlname, int& devid, int& ctrlid) override;
	float Analog(int devid, int ctrlid) override;
	float AnalogMotion(int devid, int ctrlid) override;
	int Digital(int devid, int ctrlid) override;
	void DeactivateDevices() override;
	void ActivateDevices() override;
	bool InstallHandler(int device, int (*handler)(int param1, int param2, void* param3), void* userdata, bool bExclusive) override;
	bool UninstallHandler(int device, int (*handler)(int param1, int param2, void* param3)) override;
	bool OpenControllerMissingWindow() override;
	bool CheckForKeyPress(int& device, int& controlid) override;
	bool HasGamepadConnected() override;
	bool CheckKey(const char* cKeyName, unsigned int eState) override;
	bool DebugKeysEnabled() const override;
	void EnableDebugKeys(bool bEnable) override;
	void SetEnableHaptics(bool bEnableHaptics) override;
	void TrapAllKeys() override;

	ZInputDeviceManager() = default;
	int AddDevice(ZInputDevice* dev);
};
