#pragma once

#include "IComponentInterface.h"
#include "ZString.h"

class __declspec(novtable) IBaseInputStream : public IComponentInterface
{
public:
	enum ESeekOrigin
	{
		ORIGIN_END = 1,
		ORIGIN_BEGIN = 2,
		ORIGIN_CURRENT = 3,
		ORIGIN_LAST = 4
	};

	~IBaseInputStream() override = default;
	virtual bool IsValid() = 0;
	virtual bool IsSeekable() = 0;
	virtual int GetLength() = 0;
	virtual int GetPosition() = 0;
	virtual void Close() = 0;
	virtual ZString GetLastErrorMessage() = 0;
	virtual int Skip(int param1) = 0;
	virtual int Seek(int param1, ESeekOrigin seekOrigin) = 0;
	virtual void OpenCallback();

	IBaseInputStream() = default;
};
