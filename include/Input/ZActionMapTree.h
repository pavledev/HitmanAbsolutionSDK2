#pragma once

#pragma pack(push, 4)

#include "ZGameTime.h"
#include "ZInputTokenStream.h"

class ZActionMapTree
{
public:
	enum EType
	{
		eUNDEFINED = 0,
		eGET = 1,
		eCONSTANT = 2,
		eHOLD = 3,
		eREPEAT = 4,
		eTAP = 5,
		eRELEASE = 6,
		eDOWNEDGE = 7,
		eFASTTAP = 8,
		eHOLDDOWN = 9,
		eFIREONCEHOLDDOWN = 10,
		eCLICKHOLD = 11,
		ePRESS = 12,
		eAND = 13,
		eOR = 14,
		eGT = 15,
		eLT = 16,
		eSEQUENCE = 17,
		eANALOG = 18,
		eANALOGRAW = 19,
		eRELATIVE = 20,
		ePLUS = 21,
		eMINUS = 22,
		eMULT = 23
	};

	enum EModifiers
	{
		eNONE = 0,
		eNEG = 1,
		eDISABLED = 2,
		eOVERRIDDEN = 4,
		eSTATIC = 8,
		eDEBUGKEYS = 16,
		eALWAYS = 32
	};

	ZActionMapTree* m_pkParent;
	ZActionMapTree* m_pkFirstChild;
	ZActionMapTree* m_pkNext;
	unsigned char m_eType;
	unsigned char m_eMods;
	short m_iLastDevice;
	short m_iDeviceId;
	short m_iControlId;
	short m_iOrgDeviceId;
	short m_iOrgControlId;
	char m_acName[64];
	float m_fConstant;
	ZGameTime m_tLastFired;
	ZActionMapTree* m_pkGetTree;

	virtual ~ZActionMapTree() = default;

	ZActionMapTree() = default;
	void Init(bool bv);
	void Init(float fv);
	void Init(ZInputTokenStream::EToken token);
	void Init(ZInputTokenStream::EToken token, int devid, int ctrlid);
	void Init(ZActionMapTree* gettree);
	void Init();
	void Display(int indent, char* buf);
	int Count();
	void SetLastFired(ZGameTime newValue);
	char* GetKeyName();
	char* GetSystemKeyName(bool firstKey);
	int GetDeviceId();
	int GetControlId() const;
	int GetControlType() const;
	void ClearInputKeys();
	bool Digital();
	float Analog();
	bool IsMapActivating() const;
	int ActivatedBy();
	void RevertToDefault();
	int Override(int* piDeviceIds, int* piControlIds);
	void SetDevice(int iDeviceId);
	int AddChild(ZActionMapTree* child);
	void RemoveFromTree();
	void Neg();
	void Not();
	void Minus();
	void SetName(char* name);
	ZActionMapTree* FirstChild();
	ZActionMapTree* Next();
	ZActionMapTree* Parent();
	char* GetName();
	int SaveBitsSize();
	int GetBits(unsigned char* buf, int bitpos, int bits, short* val);
	int SetBits(unsigned char* buf, int bitpos, int bits, short val);
	void SetEnabled(bool bEnabled);
	bool IsEnabled();
	bool IsSelfOrAncestorDisabled();
};

#pragma pack(pop)
