#pragma once

#include "IInputDevice.h"
#include "ZGameTime.h"

class ZInputDevice : public IInputDevice
{
public:
	enum
	{
		DigHistSize = 2
	};

	struct CtrlInfo
	{
		char* name;
		int nr;
	};

	char m_name[32];
	ZGameTime* m_dighist[2];
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
	unsigned char m_iDeviceID;
	int (*m_pHandler)[2];
	void* m_pHandlerData[2];
	int m_nExclusiveIndex;
	IInputDevice::EDeviceType m_type;

	~ZInputDevice() override = default;
	IInputDevice::EDeviceType Type() const override;
	int DigitalCount() const override;
	int DigitalState(int nr) const override;
	char* DigitalName(int nr) const override;
	int DigitalId(const char* name) const override;
	ZGameTime DigitalHist(int nr, int nth) const override;
	int AnalogCount() const override;
	float AnalogState(int nr) const override;
	float AnalogStateRaw(int nr) const override;
	char* AnalogName(int nr) const override;
	int AnalogId(const char* name) const override;
	float AnalogMotion(int nr) const override;
	void ResetTables(bool bClearKeys) override;
	void ClearKey(int id) override;
	bool HapticEnabled() override;
	void RumbleSetPitch(int axis, float p) override;
	bool StartHaptic(unsigned int iEffect, float fTimeOffset, float fTimeScale, bool bRunAlways) override;
	void StopHaptics() override;
	void SetRumbleBGPitch(float fLeft, float fRight) override;
	void SetRumblePitchDirect(float fLeft, float fRight) override;
	void Activate() override;
	void Deactivate() override;
	char* GetName() override;
	void PrintInfo() override;
	virtual int Initialize(bool bBackground);
	virtual int Terminate();
	virtual void Update(bool bIgnoreOldEvents);
	virtual void Preupdate();
	virtual int Acquire();
	virtual int Acquire(int retries);
	virtual int Unacquire();
	virtual char* lookupDeviceName(CtrlInfo* list, int nr) const;

	ZInputDevice() = default;
	ZInputDevice(const ZInputDevice& __that);
	ZInputDevice(IInputDevice::EDeviceType type, int digcount, int anacount);
	ZInputDevice(IInputDevice::EDeviceType type);
	void TrapAllKeys();
	bool UninstallHandler(int (*pHandler)(int param1, int param2, void* param3));
	bool InstallHandler(int (*pHandler)(int param1, int param2, void* param3), void* pUserData, bool bExclusive);
	bool HandlerInstalled();
	void SendToHandlers(int iKey, int iMask);
	bool IsExclusive() const;
	char* DigitalDeviceName(int nr) const;
	void clear();
	void setControlCount(int digcount, int anacount);
	void buttonSample(int nr, bool state, const ZGameTime& time);
	void AnalogSample(int nr, float state, float raw, const ZGameTime& time);
	void AnalogMotionSample(int nr, float state, const ZGameTime& time);
	char* lookupName(CtrlInfo* list, int nr) const;
	int lookupNr(CtrlInfo* list, const char* name) const;
	void DeviceUnplugged();
	ZInputDevice& operator=(const ZInputDevice& __that);
};
