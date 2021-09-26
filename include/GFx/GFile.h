#pragma once

#include "GRefCountBase.h"
#include "GFileConstants.h"

class __declspec(novtable) GFile : public GRefCountBase<GFile, 2>, public GFileConstants
{
public:
	~GFile() override = default;
	virtual const char* GetFilePath() = 0;
	virtual bool IsValid() = 0;
	virtual bool IsWritable() = 0;
	virtual int Tell() = 0;
	virtual long long LTell() = 0;
	virtual int GetLength() = 0;
	virtual long long LGetLength() = 0;
	virtual int GetErrorCode() = 0;
	virtual int Write(const unsigned char* param1, int param2) = 0;
	virtual int Read(unsigned char* param1, int param2) = 0;
	virtual int SkipBytes(int param1) = 0;
	virtual int BytesAvailable() = 0;
	virtual bool Flush() = 0;
	virtual int Seek(int param1, int param2) = 0;
	virtual long long LSeek(long long param1, int param2) = 0;
	virtual bool ChangeSize(int param1) = 0;
	virtual int CopyFromStream(GFile* file, int param2) = 0;
	virtual bool Close() = 0;

	GFile() = default;
};
