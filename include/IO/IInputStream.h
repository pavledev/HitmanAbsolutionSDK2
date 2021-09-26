#pragma once

#include "IBaseInputStream.h"

class __declspec(novtable) IInputStream : public IBaseInputStream
{
public:
	~IInputStream() override = default;
	virtual int Read(void* param1, int param2) = 0;
	virtual int GetChar();

	IInputStream() = default;
};
