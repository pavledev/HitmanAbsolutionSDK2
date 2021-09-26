#pragma once

class ZActionMapTree;

class ZInputAction
{
public:
	const char* m_szName;
	ZActionMapTree* m_pkMap;
	int m_iSeq;

	ZInputAction() = default;
	ZInputAction(const char* name);
	~ZInputAction() = default;
	bool Digital();
	float Analog();
	int ActivatedBy();
	int Override(int* piDeviceIds, int* piControlIds);
	void SetDevice(int iDeviceId);
	void SetEnabled(bool bEnabled);
	bool CheckMap();
	void ClearInputKeys();
	int GetControlId() const;
	int GetControlType() const;
	int GetDeviceId() const;
	bool IsActionActivating() const;
	static float GetHOLDFEEDBACKSTART();
	ZActionMapTree* GetMap();
};
