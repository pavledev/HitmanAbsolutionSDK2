#pragma once

#include "GFxState.h"
#include "GFile.h"
#include "GFxLog.h"

class __declspec(novtable) GFxFileOpenerBase : public GFxState
{
public:
	~GFxFileOpenerBase() override = default;
	virtual GFile* OpenFile(const char* param1, int param2, int param3) = 0;
	virtual long long GetFileModifyTime(const char* param1) = 0;
	virtual GFile* OpenFileEx(const char* param1, GFxLog* fxLog, int param3, int param4) = 0;

	GFxFileOpenerBase() = default;
};
