#pragma once

class ZInputTokenStream
{
public:
	enum
	{
		MAX_SYMBOL_LENGTH = 64
	};

	enum EToken
	{
		eEND = 0,
		eINVALID = 1,
		eSEMICOLON = 2,
		eEQUAL = 3,
		eCOMMA = 4,
		eLBRACE = 5,
		eRBRACE = 6,
		eLPAR = 7,
		eRPAR = 8,
		eVTRUE = 9,
		eVFALSE = 10,
		eGET = 11,
		eOR = 12,
		eAND = 13,
		eGT = 14,
		eLT = 15,
		ePLUS = 16,
		eMINUS = 17,
		eMULT = 18,
		eUMINUS = 19,
		eBANG = 20,
		eSYMBOL = 21,
		eNUMBER = 22,
		eTAP = 23,
		eRELEASE = 24,
		eDOWNEDGE = 25,
		eFASTTAP = 26,
		eHOLDDOWN = 27,
		eFIREONCEHOLDDOWN = 28,
		eCLICKHOLD = 29,
		ePRESS = 30,
		eHOLD = 31,
		eREPEAT = 32,
		eANA = 33,
		eANARAW = 34,
		eREL = 35,
		eSEQ = 36
	};

	struct ZTokenData
	{
		EToken eType;
		float fVal;
		char acVal[64];
	};

	const char* m_szData;
	ZTokenData kaTokens[1];

	ZInputTokenStream() = default;
	ZInputTokenStream(const char* data);
	~ZInputTokenStream() = default;
	EToken Peek();
	bool Swallow(EToken eToken, float& fValue);
	bool Swallow(EToken eToken, char* szName);
	bool Swallow(EToken eToken);
	EToken Swallow();
	ZTokenData ParseToken();
};
