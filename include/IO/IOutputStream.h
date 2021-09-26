#pragma once

#include "IComponentInterface.h"
#include "ZString.h"

class __declspec(novtable) IOutputStream : public IComponentInterface
{
public:
	enum ESeekOrigin
	{
		ORIGIN_END = 1,
		ORIGIN_BEGIN = 2,
		ORIGIN_CURRENT = 3
	};

	~IOutputStream() override = default;
	virtual bool IsValid() const = 0;
	virtual int Write(const void* param1, int param2) = 0;
	virtual bool Flush() = 0;
	virtual bool Close() = 0;
	virtual bool IsSeekable() const = 0;
	virtual int Seek(int param1, ESeekOrigin seekOrigin) = 0;
	virtual ZString GetLastErrorMessage() = 0;

	IOutputStream() = default;
};
